#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib>
#include <filesystem>
#include <thread>
#include <string>

using namespace sf;

std::string resource_path;

void get_resource_directory(char *path)
{
    resource_path = std::filesystem::path(path).parent_path().string() + "/resources";
}

std::string get_resource_path(char *name)
{
    return (resource_path + "/" + name);
}

int main(int argc, char *argv[])
{
    RenderWindow window(VideoMode(800, 600), "Game", Style::Titlebar | Style::Close);
    Texture texture;

    window.setFramerateLimit(60);

    get_resource_directory(argv[0]);

    if (!texture.loadFromFile(get_resource_path("miku.png").c_str()))
    {
        exit(1);
    }

    Sprite sprite(texture);
    int x = 0;
    auto texture_size = texture.getSize();
    auto window_size = window.getSize();
    sprite.setOrigin(Vector2f(texture_size.x / 2, texture_size.y / 2));
    sprite.setPosition(Vector2f(window_size.x / 2, window_size.y / 2));

    Shader shader;
    if (!shader.loadFromFile(get_resource_path("shader.frag"), sf::Shader::Fragment))
    {
        exit(1);
    }

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
        }

        window.clear(Color::Black);

        auto mouse_position = Mouse::getPosition(window);
        double angle = ((float)mouse_position.y / window_size.y) * 5;
        if (angle < 0)
        {
            angle = 0;
        }

        sprite.rotate(angle);
        window.draw(sprite, &shader);

        window.display();
    }
}