//
// Created by Алексей Долматов on 08.05.17.
//
#include <iostream>
#include "TMap.h"
#include "TGameObj.h"

#ifndef SLAYIN_TPLAYER_H
#define SLAYIN_TPLAYER_H
using namespace sf;

class Player : public GameObj {
private:
    int Score;
public:

    Player(Image &image, float X, float Y, int W, int H) : GameObj(image, X, Y, W, H) {
        Score = 15;
        SetHP(10);
        SetDamage(10);
        SetSprite(0, 0, W, H);
    }


    int GetScore() {
        return Score;
    }


    void Score_ink() {
        ++Score;
    }

    void control() {
        if (Keyboard::isKeyPressed(Keyboard::Left)) {
            Set_dx(-0.5);
            SetSprite(66, 0, -66, 62);
        }
        if (Keyboard::isKeyPressed(Keyboard::Right)) {
            Set_dx(0.5);
            SetSprite(0, 0, 66, 62);
        }

        if ((Keyboard::isKeyPressed(Keyboard::Up)) && (is_onGround())) {
            Set_dy(-1.2);
            SetOnGround(false);
        }

    }

    void checkCollisionWithMap(float Dx, float Dy) {
        for (int i = (Get_Y() / 32); i < ((Get_Y() + Get_H()) / 32); i++)
            for (int j = Get_X() / 32; j < (Get_X() + Get_W()) / 32; j++) {
                if (TileMap[i][j] == '0') {
                    if (Dy > 0) {
                        Set_Y(i * 32 - Get_H());
                        Set_dy(0);
                        SetOnGround(true);
                    }
                    if (Dy < 0) {
                        Set_Y(i * 32 + 32);
                        Set_dy(0);
                    }
                    if (Dx > 0) {
                        Set_X(j * 32 - Get_W());
                        Set_dx(0);
                    }
                    if (Dx < 0) {
                        Set_X(j * 32 + 32);
                        Set_dx(0);
                    }
                }

            }
    }

    void update(float time) {
        control();

        Set_X(Get_X() + Get_dx() * time);
        checkCollisionWithMap(Get_dx(), 0);
        Set_Y(Get_Y() + Get_dy() * time);
        checkCollisionWithMap(0, Get_dy());
        SetPosition(Get_X(), Get_Y());
        if (GetHp() <= 0)
            SetLife(false);
        Set_dy(Get_dy() + 0.0043 * time);


    }

    sf::FloatRect getRect() {

        return FloatRect(Get_X(), Get_Y(), Get_W(), Get_H());
    }

    sf::FloatRect getRectShovel() {

        return FloatRect(Get_X() + 56, Get_Y() + 38, 10, 16);
    }

    sf::FloatRect getInvertRectShovel() {

        return FloatRect(Get_X(), Get_Y() + 38, 10, 16);
    }


};

#endif //SLAYIN_TPLAYER_H
