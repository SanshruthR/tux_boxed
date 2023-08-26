// player.cpp
#include "player.h"
using namespace sf;

player::player(Texture* texture, Vector2u imageCount, float switchTime, float speed)
    : animation(texture, imageCount, switchTime) {
    this->speed = speed;
    row = 0;
    faceRight = true;

    body.setSize(Vector2f(100.0f, 150.0f));
    body.setTexture(texture);
    body.setPosition(206.0f, 206.0f);
}

player::~player() {}

void player::update(float deltaTime) {
    Vector2f movement(0.0f, 0.0f);
    if (Keyboard::isKeyPressed(Keyboard::A))
        movement.x -= speed * deltaTime;
    if (Keyboard::isKeyPressed(Keyboard::D))
        movement.x += speed * deltaTime;
    if (movement.x == 0.0f) {
        row = 0;
    }
    else {
        row = 1;
        if (movement.x > 0.0f)
            faceRight = true;
        else
            faceRight = false;
        animation.Update(row, deltaTime, faceRight);
        body.setTextureRect(animation.uvRect);
        body.move(movement);
    }
}

void player::Draw(RenderWindow& window) {
    window.draw(body);
}

void player::setPosition(float x, float y) {
    body.setPosition(x, y);
}

void player::move(float offsetX, float offsetY) {
    body.move(offsetX, offsetY);
}

void player::setTextureRect(const IntRect& rect) {
    body.setTextureRect(rect);
}
