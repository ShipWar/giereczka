#include <SFML/Graphics.hpp>
#include<boost/filesystem.hpp>

#include<iostream>



int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Texture texture;
    texture.loadFromFile("space.jpg");
    sf::Sprite sprite(texture);
    std::cout<<boost::filesystem::current_path();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(sprite);
        window.display();
    }

    return 0;
}
