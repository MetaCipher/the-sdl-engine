#include "CAppStateManager.h"

// Refer to your Other App States Here
#include "CAppStateIntro.h"
//#include "CAppStateMainMenu.h"
//#include "CAppStateGameTetrisClassic.h"
//#include "CAppStateGameTetrisDual.h"


CAppState* CAppStateManager::ActiveAppState = 0;

void CAppStateManager::OnEvent(SDL_Event* EventHolder) {
    if(ActiveAppState) ActiveAppState->OnEvent(EventHolder);
}

void CAppStateManager::OnLoop() {
    if(ActiveAppState) ActiveAppState->OnLoop();
}

void CAppStateManager::OnRender() {
    if(ActiveAppState) ActiveAppState->OnRender();
}

void CAppStateManager::SetActiveAppState(int AppStateID) {
    if(ActiveAppState) ActiveAppState->OnDeactivate();

    // Also, add your App State Here so that the Manager can switch to it
    if(AppStateID == APPSTATE_NONE)        ActiveAppState = 0;
    if(AppStateID == APPSTATE_INTRO)    ActiveAppState = CAppStateIntro::GetInstance();
//    if(AppStateID == APPSTATE_MAIN_MENU)    ActiveAppState = CAppStateMainMenu::GetInstance();
//    if(AppStateID == APPSTATE_GAME_TETRIS_CLASSIC)    ActiveAppState = CAppStateGameTetrisClassic::GetInstance();
//    if(AppStateID == APPSTATE_GAME_TETRIS_DUAL)    ActiveAppState = CAppStateGameTetrisDual::GetInstance();

    if(ActiveAppState) ActiveAppState->OnActivate();
}

CAppState* CAppStateManager::GetActiveAppState() {
    return ActiveAppState;
}
