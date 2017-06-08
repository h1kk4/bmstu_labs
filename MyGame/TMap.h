//
// Created by Алексей Долматов on 08.05.17.
//

#ifndef SLAYIN_TMAP_H
#define SLAYIN_TMAP_H

const int HEIGHT_MAP = 12;
const int WIDTH_MAP = 30;



sf::String TileMap[HEIGHT_MAP] = {
    "0                        tttt0",
    "0                        tttt0",
    "0                            0",
    "0                            0",
    "0                            0",
    "0                            0",
    "0                            0",
    "0                            0",
    "0                            0",
    "0                            0",
    "000000000000000000000000000000",
    "000000000000000000000000000000",

};
void Draw(sf::Sprite s_map, sf::RenderWindow &window)
{
    for (int i = 0; i < HEIGHT_MAP; i++)
        for (int j = 0; j < WIDTH_MAP; j++) {

            if (TileMap[i][j] == ' ') (s_map).setTextureRect(sf::IntRect(0, 0, 32, 32));
            if (TileMap[i][j] == 't') (s_map).setTextureRect(sf::IntRect(0,32, 32, 32));
            if ((TileMap[i][j] == '0')) (s_map).setTextureRect(sf::IntRect(32, 32, 32, 32));
            (s_map).setPosition(j * 32, i * 32);

            window.draw(s_map);
        }
}

#endif //SLAYIN_TMAP_H
