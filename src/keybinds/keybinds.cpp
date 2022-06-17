//
// Created by loona on 17/06/22.
//

#include "keybinds.h"

void key::arrowKeys() {
    /*
     * Handles the movements of the player.
     *
     * up:move up
     * down: move down
     * right: move to the right
     * left: move to the left
     * */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        playerCoords[1]++;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        playerCoords[1]--;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        playerCoords[0]++;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        playerCoords[0]--;
}