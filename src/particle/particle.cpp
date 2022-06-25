//
// Created by loona on 24/06/22.
//

#include "particle.h"
#include <effolkronium/random.hpp>

namespace ptc {

    Particle::Particle(std::vector<float> position, std::vector<int> colour, float radius,
                       std::vector<float> v, std::vector<float> a, float decayRate)
                       : position(position),
                       colour(colour),
                       radius(radius),
                       v(v),
                       a(a),
                       decayRate(decayRate)
    {
        this->setPosition(this->position[0], this->position[1]); // sets the position
        this->setFillColor(sf::Color(colour[0], colour[1], colour[2])); // sets the colour
        this->setRadius(this->radius); // sets the size
        this->setOrigin(this->radius/2, this->radius/2); // sets the origin to the centre

        // randomizes the direction of the velocity
        this->randomizeVelocity();
    }

    // The private methods

    void Particle::decay() {
        /*
         * Decays a particle.
         *
         * simply subtracts the decay rate from the radius.
         * if the radius falls below 0, it will be deleted.
         *
         * issue:
         *  if instead of decaying, the particle is enlarging, it could get infinitely bigger.
         * */
        this->radius -= decayRate;

        this->setRadius(this->radius);
    }

    void Particle::move(){
        for (int i=0; i<this->v.size(); i++) // adds the velocity to the position
            this->position[i] += this->v[i];

        this->setPosition(this->position[0], this->position[1]);
    }

    void Particle::accelerate() {
        for (int i=0; i<this->a.size(); i++) // add the acceleration to the velocity
            this->v[i] += this->a[i];
    }

    void Particle::randomizeVelocity() {
        /*
         * randomizes velocity.
         *
         * If velocity is not randomized, all particles will follow the same direction.
         * This just draws a boring curve.
         * To make the particles fly in many directions, we randomize the magnitude and direction of the velocity
         *
         * */
        using Random = effolkronium::random_static;

        // generates a number from [-1, 1] inclusively
        for (int i=0; i< this->v.size(); i++) {
            auto val = Random::get<float>(-1, 1);

            this->v[i] *= val; // multiplies it by v's contents
        }
    }


    // Public methods

    void Particle::draw(sf::RenderWindow * window, Particle p) {
        window->draw(p);
    }

    void Particle::simulate() {
        /*
         * Simulates the particle.
         *
         * This would be called alongside Particle::draw() every frame.
         *
         * recalculates the velocity,
         * recalculates the acceleration
         * and then decays the particle.
         * */
        this->move();
        this->accelerate();
        this->decay();
    }


    // Getters

    std::vector<float> Particle::getVelocity() {
        return this->v;
    }

    std::vector<float> Particle::getAccel() {
        return this->a;
    }

    float Particle::getDecayRate() {
        return this->decayRate;
    }

} // ptc