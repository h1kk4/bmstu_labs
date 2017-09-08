//
// Created by Алексей Долматов on 10.05.17.
//
#include "TEnemy.h"
#include <iostream>

#ifndef SLAYIN_DARKLORD_H
#define SLAYIN_DARKLORD_H

class DarkLord : public Enemy {
private:


public:
    DarkLord(sf::Image &image, float X, float Y, int W, int H)
            : Enemy(image, X, Y, W, H) {
        Set_dy(0.2);
        SetHP(10);
        SetDamage(5);
        SetSprite(0, 0, W, H);
    }

    void checkCollisionWithMap(float Dx, float Dy) {
        for (int i = Get_Y() / 32; i < (Get_Y() + Get_H()) / 32; i++)
            for (int j = Get_X() / 32; j < (Get_X() + Get_W()) / 32; j++) {
                if (TileMap[i][j] == '0') {
                    if (Dy > 0) {
                        Set_Y(i * 32 - Get_H());
                        SetOnGround(true);
                    }
                    if (is_onGround()) {
                        Set_dx(0.4);
                        Set_dy(0);
                        //SetOnGround(false);
                    }

                    if (Dx > 0) {
                        Set_X(j * 32 - Get_W());
                        Set_dx(-0.4);
                        Set_Y(Get_Y());
                        SetSprite(67, 0, -67, Get_H());
                    }
                    if (Dx < 0) {
                        Set_X(j * 32 + 32);
                        Set_dx(0.4);
                        Set_Y(Get_Y());
                        SetSprite(0, 0, Get_W(), Get_H());
                    }
                }
            }
    }

    virtual void update(float time) override {
        checkCollisionWithMap(0, Get_dy());
        checkCollisionWithMap(Get_dx(), 0);
        Set_X(Get_X() + Get_dx() * time);
        Set_Y(Get_Y() + Get_dy() * time);
        SetPosition(Get_X(), Get_Y());
        if (GetHp() <= 0)
            SetLife(false);
    }


};

#endif //SLAYIN_DARKLORD_H
