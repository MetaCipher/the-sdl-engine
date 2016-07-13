#ifndef __CAPPSTATEMANAGER_H__
    #define __CAPPSTATEMANAGER_H__

#include "CAppState.h"

enum {
    // Add your Other App States Here
    APPSTATE_NONE,
    APPSTATE_INTRO,
    APPSTATE_MAIN_MENU,
    APPSTATE_GAME_TETRIS_CLASSIC,
    APPSTATE_GAME_TETRIS_DUAL
};

class CAppStateManager {
    private:
        static CAppState* ActiveAppState;

    public:
        static void OnEvent(SDL_Event* Event);

        static void OnLoop();

        static void OnRender();

    public:
        static void SetActiveAppState(int AppStateID);

        static CAppState* GetActiveAppState();
};

#endif
