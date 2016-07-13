#include "CAppStateIntro.h"

#include "CAppStateManager.h"
#include "TextureBank.h"
#include "Log.h"
#include "App.h"

CAppStateIntro CAppStateIntro::Instance;

CAppStateIntro::CAppStateIntro() {
//    Surf_Logo = NULL;
}

void CAppStateIntro::OnKeyDown(SDL_Keycode sym) {
    switch(sym) {
        case SDLK_ESCAPE : {

        }
    }
    CAppStateManager::SetActiveAppState(APPSTATE_NONE);
}

void CAppStateIntro::OnActivate() {
    const char* file = "fonts/Century_Gothic_Bold_Italic.ttf";
    int ptsize = 30;

    if((Font = TTF_OpenFont(file, ptsize)) == NULL) {
//        fprintf(stderr,
//                "Couldn't initialize SDL_ttf: %s\n", TTF_GetError());
        Log("Couldn't initialize SDL_ttf: %s\n", TTF_GetError());
        CAppStateManager::SetActiveAppState(APPSTATE_NONE);
    }

    SDL_Color color;
    color.r = 255;
    color.g = 255;
    color.b = 0;

    const char* Text1 = "\"1\" - Одиночная игра";

    if((Surf_Text = TTF_RenderUTF8_Blended(Font, Text1, color)) == NULL) {
//        fprintf(stderr,
//                "TTF_RenderText_Blended Error: %s\n", TTF_GetError());
        Log("TTF_RenderText_Blended Error: %s\n", TTF_GetError());
        CAppStateManager::SetActiveAppState(APPSTATE_NONE);
    }

    App* AppInstance = App::GetInstance();
    SDL_Renderer* Renderer = AppInstance->GetRenderer();

    if((SDL_Text_Texture = SDL_CreateTextureFromSurface(Renderer, Surf_Text)) == NULL) {
		Log("Unable to create SDL Texture Font : %s", IMG_GetError());
		return;
	}

    // Grab dimensions
	SDL_QueryTexture(SDL_Text_Texture, NULL, NULL, 0, 0);

	//Log("Texture Dimensions: %s : %d %d", Filename.c_str(), Width, Height);



    // Load Simple Logo
//    Surf_Logo = CSurface::OnLoad("images/logo.png");

    StartTime = SDL_GetTicks();
}

void CAppStateIntro::OnDeactivate() {
    if(Surf_Text) {
        SDL_FreeSurface(Surf_Text);
        Surf_Text = NULL;
    }

    if(Font) {
        TTF_CloseFont(Font);
        Font = NULL;
    }

    if(SDL_Text_Texture) {
		SDL_DestroyTexture(SDL_Text_Texture);
		SDL_Text_Texture = NULL;
	}
//    if(Surf_Logo) {
//        SDL_FreeSurface(Surf_Logo);
//        Surf_Logo = NULL;
//    }

}

void CAppStateIntro::OnLoop() {
    if(StartTime + 3000 < SDL_GetTicks()) {
        CAppStateManager::SetActiveAppState(APPSTATE_NONE);
    }
}

void CAppStateIntro::OnRender() {

    TextureBank::Get("logo")->Render(0, 0);
    App* AppInstance = App::GetInstance();
    SDL_Renderer* Renderer = AppInstance->GetRenderer();

    SDL_Rect Destination = {0, 0, 0, 0};

	SDL_RenderCopy(Renderer, SDL_Text_Texture, NULL, &Destination);

//    if(Surf_Logo) {
//        CSurface::OnDraw(Surf_Display, Surf_Logo, 0, 0);
//    }
}

CAppStateIntro* CAppStateIntro::GetInstance() {
    return &Instance;
}
