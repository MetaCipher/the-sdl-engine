#ifndef __CAPPSTATE_H__
    #define __CAPPSTATE_H__

#include "CEvent.h"

class CAppState : public CEvent {
    public:
        CAppState();

    public:
        virtual void OnActivate() = 0;

        virtual void OnDeactivate() = 0;

        virtual void OnLoop() = 0;

        virtual void OnRender() = 0;
};

#endif
