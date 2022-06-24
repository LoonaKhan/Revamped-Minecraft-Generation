//
// Created by loona on 06/06/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../globvars.h"
#include "grid.h"
#include "Block.h"
#include "../utils/directory/directory.h"
#include "../keybinds/keybinds.h"

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
    //float dt; // the number of seconds since the last frame
    loadTextures();
    loadFonts();



    while (window.isOpen()) { // the main while loop of the program

        // handles events, namely exiting
        sf::Event evnt{};
        while (window.pollEvent(evnt)) {
            if (evnt.type == evnt.Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
            }

            // zooms in/out when scrolling
            if (evnt.type == sf::Event::MouseWheelScrolled and evnt.mouseWheelScroll.wheel == sf::Mouse::VerticalWheel) {
                grid::setZoom(0.25f * evnt.mouseWheelScroll.delta);
            }
        }

        // keybinds
        key::arrowKeys();

        // draws the grid
        auto blocks = grid::getBlocks(grid::getGridDimensions()); // all blocks currently visible

        for (auto i : blocks){
            auto drawCoords =grid::convertCoords({i[0], i[1]});

            Block block = Block({i[0],i[1]});

            block.render(); // TODO: make all blocks rendered at first, but not afterward
            Block::draw(&window, block);

            // TODO: put this into a method; grid::showCoords()
            sf::Text posText;
            posText.setFont(FONTS["MC"]);
            posText.setString(std::to_string(i[0])+","+std::to_string(i[1]));
            posText.setCharacterSize(16);
            posText.setFillColor(sf::Color::White);
            posText.setPosition(drawCoords[0], drawCoords[1]);
            window.draw(posText);
        }


        grid::drawMidpoint(&window);

        // calcs, draws and sets fps
        grid::calcFrameData(&clock);
        grid::drawFPS(&window);
        window.setFramerateLimit(FPSLimit); // limits fps

        window.display(); // displays the window
        window.clear(); // clears the screen.
    }
}