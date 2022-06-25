//
// Created by loona on 24/06/22.
//
#include <iostream>
#include "../particle.h"
#include "../../globvars.h"
#include "../../grid_system/grid.h"

#define vLog(x)  x.x << " " << x.y
#define logVal(x)  x

const char name[] = "Particle test";

void drawTest(){

    // setup
    sf::RenderWindow window( // creates a window.
            sf::VideoMode(screenRes[0], screenRes[1]),
            name,
            sf::Style::Close | sf::Style::Resize
    );
    sf::Clock clock; // the clock. basically what we can use to regulate frame rate
    loadFonts();

    std::vector<ptc::Particle> particles;

    while (window.isOpen()) {
        // handles events, namely exiting
        sf::Event evnt{};
        while (window.pollEvent(evnt)) {
            if (evnt.type == evnt.Closed or sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
                window.close();
            }

        }

        // TEST IS HERE

        particles.push_back(ptc::Particle({(float)midPoint[0], (float)midPoint[1]},
                                          {2,150,240},
                                          5,
                                          {2, 4},
                                          {2,-0.25},
                                          0.08));

        for (int i=0; i<particles.size(); i++) {
            ptc::Particle::draw(&window, particles[i]);
            particles[i].simulate();

            if (particles[i].getRadius() <= 0.0)
                particles.erase(particles.begin() + i);
        }

        // END OF TESTS

        grid::calcFrameData(&clock);
        grid::drawFPS(&window);
        window.setFramerateLimit(FPSLimit);

        window.display();
        window.clear();

    }

}

void initParticleTest(){

    ptc::Particle p = ptc::Particle(
            {960, 540},
            {255, 255, 255},
            5,
            {0,0},
            {0,0}
            );
    //std::cout << "Position: " << vLog(p.getPosition()) << std::endl;
    std::cout << "Velocity: " << p.getVelocity()[0] << " " << p.getVelocity()[1] << std::endl;
    //std::cout << "Colour: " << vLog(p.getFillColor()) << std::endl;
    std::cout << "Accel: " << p.getAccel()[0] << " " << p.getAccel()[1] << std::endl;
    std::cout << "Radius: " << p.getRadius() << std::endl;
    std::cout << "Decay rate: " << p.getDecayRate() << std::endl;

}

int main(){
    drawTest();
    //initParticleTest();
}