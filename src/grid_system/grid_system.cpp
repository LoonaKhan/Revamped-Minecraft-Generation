//
// Created by loona on 06/06/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../globvars.h"
#include "grid.h"
using namespace std;

const char name[] = "Grid_system";

int main(){
    // setup
    sf::RenderWindow window( // creates a window.
            sf::VideoMode(screenRes[0], screenRes[1]),
            name,
            sf::Style::Close | sf::Style::Resize
            );
    sf::Clock clock; // the clock. basically what we can use to regulate frame rate



    while (window.isOpen()) { // the main while loop of the program

        // handles events, namely exiting
        sf::Event evnt{};
        while (window.pollEvent(evnt)) {
            if (evnt.type == evnt.Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
            }
        }


        // draws the grid
        vector<int> gridDims = getGridDimensions(); // gets the dimensions of the grid

        for (int x=-gridDims[0]; x<=gridDims[0]; x++) // draws all points.
            for (int y=-gridDims[1]; y<=gridDims[1]; y++){

                vector<int> drawCoords = convertCoords({x,y}); // drawCoords. where the block will be drawn

                sf::Sprite block; // creates the block

                // sets all the properties of the block
                sf::Texture texture; // initializes the texture
                texture.loadFromFile("../../assets/blocks/sand/sand.png"); // loads the texture
                texture.setSmooth(false); // makes it look more pixelly

                block.setTexture(texture);
                //block.setSize({blockSize * zoomFactor, blockSize * zoomFactor}); // sets size
                block.setPosition(drawCoords[0], drawCoords[1]); // sets the position at the drawCoords

                window.draw(block); // draws the block
            }


        window.display(); // displays the window
        window.clear(); // clears the screen.
    }
}