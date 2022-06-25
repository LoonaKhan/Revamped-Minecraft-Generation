//
// Created by loona on 24/06/22.
//

/*
 * The particle class.
 *
 * Particles are small sprites that can decay over time.
 *
 * Particles can move, accelerate, decay and be deleted when they become too small.
 * */

#ifndef REVAMPED_MINECRAFT_GENERATION_PARTICLE_H
#define REVAMPED_MINECRAFT_GENERATION_PARTICLE_H

#include <SFML/Graphics.hpp>
#include <vector>

namespace ptc {

class Particle : public sf::CircleShape {

private:
    std::vector<float> position; // position TODO: make this work with gridCoords?
    std::vector<int> colour; // colour. RGB values
    std::vector<float> v; // velocity
    std::vector<float> a; // acceleration
    float radius; // size of the particle
    float decayRate; // how fast the particle decays. can be negative too

public:
    Particle(std::vector<float> position, std::vector<int> colour, float radius,
             std::vector<float> v, std::vector<float> a,
             float decayRate=0.1);

    static void draw(sf::RenderWindow* window, Particle p); // draws the particle to the window

    void simulate(); // simulates the particle

    // The getter methods

    std::vector<float> getVelocity();

    std::vector<float> getAccel();


    float getDecayRate();

private:
    void decay(); // decays the particle

    void move(); // moves the particle

    void accelerate(); // accelerates the particle

    void randomizeVelocity(); // randomizes the direction and magnitude of the particle's velocity

    };

}

#endif //REVAMPED_MINECRAFT_GENERATION_PARTICLE_H
