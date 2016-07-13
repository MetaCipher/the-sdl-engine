//==============================================================================
/*
	Primary application class

	3/11/2014
	SDLTutorials.com
	Tim Jones
*/
//==============================================================================
#ifndef __APP_H__
	#define __APP_H__

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "TextureBank.h"

#include "CAppStateManager.h"

#include "CEvent.h"

class App : public CEvent {
	private:
		static App Instance;

		bool Running = true;

		SDL_Window* Window = NULL;
		SDL_Renderer* Renderer = NULL;
		SDL_Surface* PrimarySurface = NULL;

		static const int WindowWidth = 760;
		static const int WindowHeight = 440;

		Texture* TestTexture;

	private:
		App();

		// Capture SDL Events
		void OnEvent(SDL_Event* Event);
            void OnExit();

		// Initialize our SDL game / app
		bool Init();

		// Logic loop
		void Loop();

		// Render loop (draw)
		void Render();

		// Free up resources
		void Cleanup();

	public:
		int Execute(int argc, char* argv[]);

	public:
		SDL_Renderer* GetRenderer();

	public:
		static App* GetInstance();

		static int GetWindowWidth();
		static int GetWindowHeight();
};

#endif
