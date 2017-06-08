//
// Created by Алексей Долматов on 09.05.17.
// 64 80 16 16
#include <iostream>
#include "TGameObj.h"

#ifndef SLAYIN_TENEMY_H
#define SLAYIN_TENEMY_H

class Enemy : public GameObj {


public:

    Enemy(sf::Image &image, float X, float Y, int W, int H)
            : GameObj(image, X, Y, W, H) {
    }

    FloatRect getRect() {
        return FloatRect(Get_X(), Get_Y(), Get_W(), Get_H());
    }



};

#endif //SLAYIN_TENEMY_H
