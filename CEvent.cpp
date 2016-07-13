#include "CEvent.h"

CEvent::CEvent() {
}

CEvent::~CEvent() {
    //Do nothing
}

void CEvent::OnEvent(SDL_Event* Event) {
    switch(Event->type) {

        case SDL_KEYDOWN: {
            OnKeyDown(Event->key.keysym.sym);
            break;
        }

        case SDL_KEYUP: {
            OnKeyUp(Event->key.keysym.sym);
            break;
        }

        case SDL_MOUSEMOTION: {
            OnMouseMove(Event->motion.x,Event->motion.y,Event->motion.xrel,Event->motion.yrel,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_LEFT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_RIGHT))!=0,(Event->motion.state&SDL_BUTTON(SDL_BUTTON_MIDDLE))!=0);
            break;
        }

        case SDL_MOUSEBUTTONDOWN: {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonDown(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonDown(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonDown(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_MOUSEBUTTONUP:    {
            switch(Event->button.button) {
                case SDL_BUTTON_LEFT: {
                    OnLButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_RIGHT: {
                    OnRButtonUp(Event->button.x,Event->button.y);
                    break;
                }
                case SDL_BUTTON_MIDDLE: {
                    OnMButtonUp(Event->button.x,Event->button.y);
                    break;
                }
            }
            break;
        }

        case SDL_QUIT: {
            OnExit();
            break;
        }

        case SDL_SYSWMEVENT: {
            //Ignore
            break;
        }

        default: {
            OnUser(Event->user.type,Event->user.code,Event->user.data1,Event->user.data2);
            break;
        }
    }
}

void CEvent::OnKeyDown(SDL_Keycode sym) {
    //Pure virtual, do nothing
}

void CEvent::OnKeyUp(SDL_Keycode sym) {
    //Pure virtual, do nothing
}

void CEvent::OnMouseFocus() {
    //Pure virtual, do nothing
}

void CEvent::OnMouseBlur() {
    //Pure virtual, do nothing
}

void CEvent::OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle) {
    //Pure virtual, do nothing
}

void CEvent::OnMouseWheel(bool Up, bool Down) {
    //Pure virtual, do nothing
}

void CEvent::OnLButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::OnLButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::OnRButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::OnRButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::OnMButtonDown(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::OnMButtonUp(int mX, int mY) {
    //Pure virtual, do nothing
}

void CEvent::OnExit() {
    //Pure virtual, do nothing
}

void CEvent::OnUser(Uint8 type, int code, void* data1, void* data2) {
    //Pure virtual, do nothing
}
