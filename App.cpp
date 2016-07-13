//==============================================================================
#include "App.h"
#include "Log.h"

App App::Instance;

//==============================================================================
App::App() {
}

//------------------------------------------------------------------------------
void App::OnEvent(SDL_Event* Event) {
    CAppStateManager::OnEvent(Event);

    CEvent::OnEvent(Event);
}

//------------------------------------------------------------------------------
bool App::Init() {
	if(SDL_Init(SDL_INIT_VIDEO) < 0) {
		Log("Unable to Init SDL: %s", SDL_GetError());
		return false;
	}

	if (TTF_Init() < 0) {
        Log("Couldn't initialize SDL_ttf: %s\n", SDL_GetError());
        return false;
    }

	if(!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
		Log("Unable to Init hinting: %s", SDL_GetError());
	}

	if((Window = SDL_CreateWindow(
		"Tetris",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WindowWidth, WindowHeight, SDL_WINDOW_SHOWN)
	) == NULL) {
		Log("Unable to create SDL Window: %s", SDL_GetError());
		return false;
	}

	PrimarySurface = SDL_GetWindowSurface(Window);

	if((Renderer = SDL_CreateRenderer(Window, -1, SDL_RENDERER_ACCELERATED)) == NULL) {
	    Log("Unable to create renderer");
	    return false;
	}

	SDL_SetRenderDrawColor(Renderer, 0x00, 0x00, 0x00, 0xFF);

	// Initialize image loading for PNGs
	if(!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		Log("Unable to init SDL_image: %s", IMG_GetError());
		return false;
	}

	// Load all of our Textures (see TextureBank class for expected folder)
	if(TextureBank::Init() == false) {
		Log("Unable to init TextureBank");
		return false;
	}

	CAppStateManager::SetActiveAppState(APPSTATE_INTRO);

	return true;
}

//------------------------------------------------------------------------------
void App::Loop() {
    CAppStateManager::OnLoop();

    if(CAppStateManager::GetActiveAppState() == NULL) {
        OnExit();
    }
}

//------------------------------------------------------------------------------
void App::Render() {
	SDL_RenderClear(Renderer);

//	SDL_Rect Rect;
//    Rect.x = 0;
//    Rect.y = 0;
//    Rect.w = 100;
//    Rect.h = 100;
//    SDL_SetRenderDrawColor(Renderer, 100, 0, 0, 0);
//    SDL_RenderFillRect(Renderer, &Rect);

    CAppStateManager::OnRender();

//	TextureBank::Get("tex1")->Render(0, 0); // You should really check your pointers

	SDL_RenderPresent(Renderer);
}

//------------------------------------------------------------------------------
void App::Cleanup() {
    CAppStateManager::SetActiveAppState(APPSTATE_NONE);

	TextureBank::Cleanup();

	if(Renderer) {
		SDL_DestroyRenderer(Renderer);
		Renderer = NULL;
	}

	if(Window) {
		SDL_DestroyWindow(Window);
		Window = NULL;
	}

	IMG_Quit();
	SDL_Quit();
}

//------------------------------------------------------------------------------
int App::Execute(int argc, char* argv[]) {
	if(!Init()) return 0;

	SDL_Event Event;

	while(Running) {
		while(SDL_PollEvent(&Event) != 0) {
			OnEvent(&Event);

//			if(Event.type == SDL_QUIT) Running = false;
		}

		Loop();
		Render();

		SDL_Delay(1); // Breath
	}

	Cleanup();

	return 1;
}
//------------------------------------------------------------------------------
void App::OnExit() {
    Running = false;
}
//==============================================================================
SDL_Renderer* App::GetRenderer() { return Renderer; }

//==============================================================================
App* App::GetInstance() { return &App::Instance; }

int App::GetWindowWidth()  { return WindowWidth; }
int App::GetWindowHeight() { return WindowHeight; }

//==============================================================================
