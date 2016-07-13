#ifndef _CEVENT_H_
    #define _CEVENT_H_

#include <SDL2/SDL.h>

class CEvent {
    public:
        CEvent();

        virtual ~CEvent();

        virtual void OnEvent(SDL_Event* Event);

        virtual void OnKeyDown(SDL_Keycode sym);

        virtual void OnKeyUp(SDL_Keycode sym);

        virtual void OnMouseFocus();

        virtual void OnMouseBlur();

        virtual void OnMouseMove(int mX, int mY, int relX, int relY, bool Left,bool Right,bool Middle);

        virtual void OnMouseWheel(bool Up, bool Down);    //Not implemented

        virtual void OnLButtonDown(int mX, int mY);

        virtual void OnLButtonUp(int mX, int mY);

        virtual void OnRButtonDown(int mX, int mY);

        virtual void OnRButtonUp(int mX, int mY);

        virtual void OnMButtonDown(int mX, int mY);

        virtual void OnMButtonUp(int mX, int mY);

        virtual void OnExit();

        virtual void OnUser(Uint8 type, int code, void* data1, void* data2);
};

#endif
