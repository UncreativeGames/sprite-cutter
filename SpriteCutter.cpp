#include <SFML/Graphics.hpp>
#include <iostream>

#define screen_size_x 800
#define screen_size_y 600

using namespace std;
int error()
{
    std::cout << "Failed to load spritesheet!" << std::endl;
    return 1;
}

int main()
{
    int frame_count = 0;
    sf::Vector2i screenDimensions(screen_size_x, screen_size_y);
    sf::RenderWindow window(sf::VideoMode(screenDimensions.x, screenDimensions.y), "Sprite Cutter! v0.1");
    window.setFramerateLimit(60);
    // Set câmera
    sf::View view = window.getDefaultView();
    // load texture (spritesheet)
    sf::Texture texture;
    if (!texture.loadFromFile("player.png")) {
        return error();
    }
    int pos_x = 0;
    int pos_y = 0;
    int size_x = 32;
    int size_y = 32;
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setPosition(screen_size_x/2,screen_size_y/2);
    while (window.isOpen()) {
        sprite.setTextureRect(sf::IntRect(pos_x, pos_y, size_x, size_y));
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            pos_y++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            pos_y--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            pos_x--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            pos_x++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            size_y++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            size_y--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            size_x--;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            size_x++;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            cout << ".addFrame(sf::IntRect("<< pos_x << ","<< pos_y << ","<< size_x << ","<< size_y << "));" << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)) {
            cout << "frame" << frame_count << ":" << "X:"<< pos_x << ","<< pos_y << ","<< size_x << ","<< size_y << endl;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        {
		    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	        {
	            view.setCenter(view.getCenter().x+1, view.getCenter().y);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	        {
	            view.setCenter(view.getCenter().x-1, view.getCenter().y);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	        {
	            view.setCenter(view.getCenter().x, view.getCenter().y-1);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	        {
	            view.setCenter(view.getCenter().x, view.getCenter().y+1);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
	        {
	            view.rotate(-0.1f);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	        {
	            view.rotate(0.1f);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	        {
	            view.zoom(1.1f);
	        }
	        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	        {
	            view.zoom(0.9f);
	        }
	    }
        // draw
        window.setView(view);
        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
