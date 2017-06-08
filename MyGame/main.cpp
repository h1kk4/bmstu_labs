#include <SFML/Graphics.hpp>
#include <iostream>
#include "TPlayer.h"
#include "TMap.h"
#include <sstream>
#include "TGameObj.h"
#include "TEnemy.h"
#include <list>
#include "DarkLord.h"
#include "TBoss.h"

#include "TEvil.h"

using namespace sf;

int main() {
    RenderWindow window(sf::VideoMode(960, 384), "TEST");
    Font font;
    font.loadFromFile("Avenir.ttc");
    Text ScoreText("", font, 25);
    Text HPText("", font, 25);
    Text EndText("", font, 96);
    HPText.setFillColor(Color::Black);
    ScoreText.setFillColor(Color::Black);
    EndText.setFillColor(Color::Black);
    Clock clock;
    Image map_image;
    map_image.loadFromFile("images/blockset21.png");
    Texture map;
    map.loadFromImage(map_image);
    Sprite s_map;
    s_map.setTexture(map);
    Image PlayerImage;
    PlayerImage.loadFromFile("images/knight.png");
    Player p(PlayerImage, 600, 322, 66, 62);
    Image DarkLordImage;
    Image EvilImage;
    Image BossImage;
    EvilImage.loadFromFile("images/evil.png");
    DarkLordImage.loadFromFile("images/boss1.png");
    BossImage.loadFromFile("images/boss2.png");
    std::list<Enemy *> EnemiesList;
    std::list<Enemy *>::iterator it;
    bool BOSSLVL(true);
    float timer1 = 0;
    float timer2 = 0;
    EnemiesList.push_back(new DarkLord(DarkLordImage, 456, 0, 67, 62));
    int i=0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();

        clock.restart();
        time = time / 2800;

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (p.GetScore() > 15) {
            if (BOSSLVL) {
                EnemiesList.clear();
                EnemiesList.push_back(new Boss(BossImage, 120, 0, 97, 89));
                BOSSLVL = false;
            }

        } else {
            if (timer1 > 580) {
                int k = rand() % 800 + 80;
                EnemiesList.push_back(new DarkLord(DarkLordImage, k, 0, 67, 62));
                timer1 = 0;
                double val = (double) rand() / RAND_MAX;
                int random;
                if (val < 0.25)
                    EnemiesList.push_back(new Evil(EvilImage, k, 175, 60, 41));

            }

        }

        for (it = EnemiesList.begin(); it != EnemiesList.end(); it++) {
            if ((*it)->getRect().intersects(p.getRect())) {

                    std::cout << i << '\n';
                    i++;
                    if ((p.Get_dy() > 0) && (!p.is_onGround())) {

                        p.Set_dy(-0.2);
                        (*it)->SetHP((*it)->GetHp() - p.GetDamage());
                        //std::cout << (*it)->Get_X();
                        p.SetHP(p.GetHp() - (*it)->GetDamage());
                    } else {
                        if (p.Get_dx() == 0) {
                            (*it)->SetHP((*it)->GetHp() - p.GetDamage());
                            p.SetHP(p.GetHp() - (*it)->GetDamage());
                        } else {
                            if ((((*it)->getRect().intersects(p.getRectShovel()) && p.Get_dx() > 0)) ||
                                    (((*it)->getRect().intersects(p.getInvertRectShovel())) && p.Get_dx() < 0)) {
                                (*it)->SetHP((*it)->GetHp() - p.GetDamage());
                            } else {
                                (*it)->SetHP((*it)->GetHp() - p.GetDamage());
                                p.SetHP(p.GetHp() - (*it)->GetDamage());
                            }
                        }
                    }
            }

        }
        if (p.GetHp() > 0 &&p.GetScore()<17) {
            p.update(time);
            for (it = EnemiesList.begin(); it != EnemiesList.end();) {
                (*it)->update(time);
                if ((*it)->Alive() == false) {
                    p.Score_ink();
                    delete (*it);
                    it = EnemiesList.erase(it);
                } else
                    it++;

            }
            timer1 += time;

        }else{
            if(p.GetHp()<=0) {
                EndText.setString("You Lose");
                for (it = EnemiesList.begin(); it != EnemiesList.end();) {
                        delete (*it);
                        it = EnemiesList.erase(it);
                    }

                EnemiesList.clear();
            }
            else
                EndText.setString("You WIN");
        }

        window.clear();
        Draw(s_map, window);


        std::ostringstream playerScoreString;
        std::ostringstream playerHPString;
        playerScoreString << p.GetScore();
        ScoreText.setString("Score: " + playerScoreString.str());
        ScoreText.setPosition(800, 5);
        playerHPString << p.GetHp();
        HPText.setString("HP:" + playerHPString.str());
        HPText.setPosition(800, 32);
        window.draw(ScoreText);
        window.draw(HPText);
        EndText.setPosition(384,46);
        for (it = EnemiesList.begin(); it != EnemiesList.end(); it++) {
            window.draw((*it)->GetSprite());
        }

        window.draw(p.GetSprite());
        window.draw(EndText);
        window.display();

    }
    return 0;
}

