// The block class
//
// Created by loona on 12/06/22.
//

#ifndef REVAMPED_MINECRAFT_GENERATION_BLOCK_H
#define REVAMPED_MINECRAFT_GENERATION_BLOCK_H
#include <SFML/Graphics.hpp>
#include <vector>
#include "../globvars.h"


class Block : public sf::Sprite {
private:
    //sf::Texture texture;
    float biomeNoise; // responsible for determining the texture of the block
    float blockNoise; // responsible for the block's heightmap
    std::vector<sf::Texture> textures;

public:
    float height; // the height of the block.
    float biome; // the block's biome
    std::vector<int> position; // the coordinates the block is located at. these are gridCoords()

public:
    /* Determines the noise and then the height/texture. */
    void render();

    /* Draws the block to the screen. */
    static void draw(sf::RenderWindow* window, Block block);

    // Switches TEXTURES every frame
    void animate();

    /* likely takes in the position?
     * From there, we can calculate the noise and height, biome etc
     * size and scale are easily taken care of
     */
    Block(std::vector<int> position);

    /* Destructor */
    //~Block();

private:
    /* Given a filepath, set the texture, called by render(). */
    //void setTexture(const char* filepath);

    /* Given the noise for the position, calculate the texture of the block and biome noise. */
    float calcBiome();

    /* Using the noise for the position and biome, calculate the height. */
    float calcHeight();

    /* Loads TEXTURES based on the biome noise value. */
    void loadTextures();

    /* Sets the scale and position of a block and adds it to the chunk array. does not draw it. */
    void reload();

};


void loadTextures();

#endif //REVAMPED_MINECRAFT_GENERATION_BLOCK_H
