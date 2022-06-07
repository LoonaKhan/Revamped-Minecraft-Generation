//
// Created by loona on 06/06/22.
//
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../globvars.h"

using namespace std;

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
    }
}