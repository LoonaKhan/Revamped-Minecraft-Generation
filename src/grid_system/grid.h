// Contains methods and functionality for the grid system
//
// Created by loona on 06/06/22.

#include <vector>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "../globvars.h"

#ifndef REVAMPED_MINECRAFT_GENERATION_GRID_H
#define REVAMPED_MINECRAFT_GENERATION_GRID_H

namespace grid {
    std::vector<int> convertCoords(std::vector<int> gridCoords);

    std::vector<int> getGridDimensions();

    void setZoom(float delta);

    void drawMidpoint(sf::RenderWindow* window);

    void calcFrameData(sf::Clock* clock);

    void drawFPS(sf::RenderWindow* window);
}



#endif //REVAMPED_MINECRAFT_GENERATION_GRID_H
