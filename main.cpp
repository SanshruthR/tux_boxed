#include <SFML/Graphics.hpp>
#include "player.h"
#include "Animation.h"
#include <iostream>

using namespace sf;

int main()
{
    RenderWindow window(VideoMode(800, 600), "Tux stuck in windows (Press WASD to move)");

    Texture playertexture;
    if (!playertexture.loadFromFile("tux.png"))
    {
        
        // Handle the error if the texture fails to load
        return 1;
    }

    Animation animation(&playertexture, Vector2u(3, 2), 0.3f); // Create an Animation object

    player player(&playertexture, Vector2u(3, 2.0), 0.3f, 100.0f);
    player.setPosition(206.0f, 206.0f); // Move the player after creation

    float deltaTime = 0.0f;
    Clock clock;

    Vector2u texturesize = playertexture.getSize();
    texturesize.x /= 3;
    texturesize.y /= 1; // Adjust this value as needed

    player.setTextureRect(IntRect(texturesize.x * 2, texturesize.y * 2, texturesize.x, texturesize.y));

    while (window.isOpen())
    {
        deltaTime = clock.restart().asSeconds();
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        animation.Update(0, deltaTime, true);
        player.setTextureRect(animation.uvRect);

        // Player update
        player.update(deltaTime);

        window.clear(Color::White);

        // Draw the player's body shape
        player.Draw(window);

        window.display();

        if (Keyboard::isKeyPressed(Keyboard::Key::A)) {
            player.move(-0.1f, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::D)) {
            player.move(0.1f, 0.0f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::W)) {
            player.move(0.0f, -0.1f);
        }
        if (Keyboard::isKeyPressed(Keyboard::Key::S)) {
            player.move(0.0f, 0.1f);
        }
    }

    return 0;
}
