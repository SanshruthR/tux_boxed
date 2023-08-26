// player.h
#pragma once
#include <SFML/Graphics.hpp>
#include "Animation.h"

class player {
public:
    player(sf::Texture* texture, sf::Vector2u imageCount, float switchTime, float speed);
    ~player();

    void update(float deltaTime);
    void Draw(sf::RenderWindow& window);

    void setPosition(float x, float y);
    void move(float offsetX, float offsetY);
    void setTextureRect(const sf::IntRect& rect);

public:
    sf::RectangleShape body;
    Animation animation;
    unsigned int row;
    float speed;
    bool faceRight;
};
