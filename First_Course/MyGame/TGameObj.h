//
// Created by Алексей Долматов on 09.05.17.
//

#ifndef SLAYIN_TGAMEOBJ_H
#define SLAYIN_TGAMEOBJ_H

class GameObj {

private:
    bool life, onGround;
    float dx, dy, x, y;
    int w, h, health, damage;
    sf::Texture texture;
    sf::Sprite sprite;
public:
    GameObj(sf::Image &image, float X, float Y, int W, int H) {
        x = X;
        y = Y;
        w = W;
        h = H;
        dx = 0;
        dy = 0;
        life = true;
        texture.loadFromImage(image);
        sprite.setTexture(texture);

    }

    sf::Sprite GetSprite() {
        return sprite;
    }

    void SetSprite(const int x, const int y, const int w, const int h) {
        sprite.setTextureRect(sf::IntRect(x, y, w, h));
    }

    float Get_Y() {
        return y;
    }

    float Get_X() {
        return x;
    }

    int GetDamage() {
        return damage;
    }

    int Get_H() {
        return h;
    }

    int Get_W() {
        return w;
    }

    int GetHp() {
        return health;
    }

    float Get_dx() {
        return dx;
    }

    float Get_dy() {
        return dy;
    }

    bool is_onGround() {
        return onGround;
    };

    bool Alive() {
        return life;
    }

    void SetOnGround(const bool ground) {
        onGround = ground;
    }

    void SetDamage(const int dmg) {
        damage = dmg;
    }

    void SetHP(const int hp) {
        health = hp;
    }

    void Set_dy(const float DY) {
        dy = DY;
    }

    void Set_dx(const float DX) {
        dx = DX;
    }

    void Set_Y(const float Y) {
        y = Y;
    }

    void Set_X(const float X) {
        x = X;
    }

    void SetPosition(const float x, const float y) {
        sprite.setPosition(x, y);
    }

    void SetLife(const bool Life) {
        life = Life;
    }

    virtual sf::FloatRect getRect()=0;

    virtual void update(const float time)=0;

    virtual void checkCollisionWithMap(const float Dx, const float Dy)=0;


};

#endif //SLAYIN_TGAMEOBJ_H
