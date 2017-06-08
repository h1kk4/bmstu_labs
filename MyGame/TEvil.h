//
// Created by Алексей Долматов on 14.05.17.
//

#ifndef SLAYIN_TEVIL_H
#define SLAYIN_TEVIL_H

#include "TEnemy.h"

class Evil : public Enemy {
public:
    Evil(sf::Image &image, float X, float Y, int W, int H)
            : Enemy(image, X, Y, W, H) {
        Set_dx(0.45);
        SetHP(10);
        SetDamage(10);
        SetSprite(0, 0, W, H);
    }

    void checkCollisionWithMap(float Dx, float Dy) {
        for (int i = Get_Y() / 32; i < (Get_Y() + Get_H()) / 32; i++)
            for (int j = Get_X() / 32; j < (Get_X() + Get_W()) / 32; j++) {
                if (TileMap[i][j] == '0') {
                    if (Dx > 0) {
                        Set_X(j * 32 - Get_W());
                        Set_dx(-0.45);
                    }
                    if (Dx < 0) {
                        Set_X(j * 32 + 32);
                        Set_dx(0.45);
                    }
                }
            }
    }

    virtual void update(float time) override {
        checkCollisionWithMap(Get_dx(), 0);
        Set_X(Get_X() + Get_dx() * time);
        SetPosition(Get_X(), Get_Y());
        if (GetHp() <= 0)
            SetLife(false);
    }
};

#endif //SLAYIN_TEVIL_H
