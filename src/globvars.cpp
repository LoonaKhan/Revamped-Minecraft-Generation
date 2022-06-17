//
// Created by loona on 06/06/22.
//

#include "globvars.h"

const int screenRes[] = {1920, 1080};
const int midPoint[] = {screenRes[0]/2, screenRes[1]/2};
float zoomFactor = 4.0f; // min of 0.25, max of 4.0. todo: raise the minimum?
const int blockSize = 32; // 32 seems like a nice sweet-spot.
const int chunkSize = 16; // subject to chage.
const char appName[] = "Revamped Minecraft Generation";

std::unordered_map<std::string , sf::Texture> TEXTURES;

float FPS;
float frameTime;
int FPSLimit = 60;

std::unordered_map<std::string, sf::Font> FONTS;

int playerCoords[] = {0,0};

void loadTextures(){

    sf::Texture flower1;
    flower1.loadFromFile("../assets/blocks/plains/flower1.png");
    flower1.setSmooth(false);

    sf::Texture flower2;
    flower2.loadFromFile("../assets/blocks/plains/flower2.png");
    flower2.setSmooth(false);

    sf::Texture grass1;
    grass1.loadFromFile("../assets/blocks/plains/grass1.png");
    grass1.setSmooth(false);

    sf::Texture grass2;
    grass2.loadFromFile("../assets/blocks/plains/grass2.png");
    grass2.setSmooth(false);

    sf::Texture tree1;
    tree1.loadFromFile("../assets/blocks/plains/tree1.png");
    tree1.setSmooth(false);

    sf::Texture tree2;
    tree2.loadFromFile("../assets/blocks/plains/tree2.png");
    tree2.setSmooth(false);

    sf::Texture rock;
    rock.loadFromFile("../assets/blocks/rocks/rock.png");
    rock.setSmooth(false);

    sf::Texture sand;
    sand.loadFromFile("../assets/blocks/sand/sand.png");
    sand.setSmooth(false);

    sf::Texture water1;
    water1.loadFromFile("../assets/blocks/water/water1.png");
    water1.setSmooth(false);

    sf::Texture water2;
    water2.loadFromFile("../assets/blocks/water/water2.png");
    water2.setSmooth(false);

    TEXTURES["flower1"] = flower1;
    TEXTURES["flower2"] = flower2;
    TEXTURES["grass1"] = grass1;
    TEXTURES["grass2"] = grass2;
    TEXTURES["tree1"] = tree1;
    TEXTURES["tree2"] = tree2;
    TEXTURES["rock"] = rock;
    TEXTURES["sand"] = sand;
    TEXTURES["water1"] = water1;
    TEXTURES["water2"] = water2;
}

void loadFonts(){
    sf::Font mcFont;
    mcFont.loadFromFile("../assets/fonts/blockgame.ttf");

    FONTS["MC"] = mcFont;
}