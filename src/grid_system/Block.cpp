//
// Created by loona on 12/06/22.
//

#include "Block.h"
#include "grid.h"
#include "../utils/directory.h"
#include <string>



void loadTextures(){

    sf::Texture flower1;
    flower1.loadFromFile("../../assets/blocks/plains/flower2.png");
    flower1.setSmooth(false);

    sf::Texture flower2;
    flower2.loadFromFile("../../assets/blocks/plains/flower2.png");
    flower2.setSmooth(false);

    TEXTURES["flower1"] = flower1;
    TEXTURES["flower2"] = flower2;
}

Block::Block(std::vector<int> position) {
    /*
     * Initializes the block and assigns its position.
     * */
    this->position = std::move(position); // sets the position
}

void Block::reload() {
    /*
     * Reloads a block.
     *
     * we reload the block every frame.
     * This is called every frame because zoom factors and the playerCoords can change every frame.
     *
     * This method sets the scale and position of the block.
     * the block's position is in gridCoords, so it must be converted to drawCoords first.
     *
     * Ex:
     *  zoomFactor = 2.0f
     *  gridCoords = (0,0)
     *  >>> block is scaled 2x, and the block is drawn at (960, 540).
     * */
    this->setScale(zoomFactor, zoomFactor); // sets the scale. move to draw

    std::vector<int> drawCoords = grid::convertCoords(this->position); // converts the coordinates

    this->setPosition(drawCoords[0], drawCoords[1]); // sets the position based on those converted coordinates.
}

void Block::draw(sf::RenderWindow *window, Block block) {
    /*
     * draws a block to the window.
     *
     * Is called every frame.
     *
     * Starts by reloading the block position and scale.
     * then it draws it to the screen.
     * */

    block.reload(); // reloads

    window->draw(block);
}

void Block::render() {
    /*
     * Renders a block.
     *
     * is used once to set the biome and TEXTURES for a block.
     *
     * Starts by using perlin noise to calculate the biome noise value based on the position.
     * this biomeNoise dictates what biome the block is in.
     * Then, using biomeNoise and position, it can calculate what the block's height is.
     * Once those are calculated, it loads the TEXTURES into the TEXTURES vector using loadTextures()
     * Lastly, it sets the texture as the first index of TEXTURES. TEXTURES[0].
     * */
    this->loadTextures(); // loads TEXTURES

    this->setTexture(this->textures[0]); // sets the texture
}

void Block::loadTextures() {
    /*
     * Loads the TEXTURES based on the biome value.
     *
     * There are 6 biomes and each has their own texture:
     *  plains: grass texture
     *  flower_field: flower texture
     *  forest: tree texture
     *  desert: sand texture
     *  beach: sand texture
     *  lake: water texture
     *
     * based on biomeNoise's value, it will assign one of these 5 biomes.
     *
     * TODO:
     *  get the noise stuff working. for now it just loads flowers
     * */

    this->textures.push_back(TEXTURES["flower1"]);
    //this->textures.push_back(flower2);


}

