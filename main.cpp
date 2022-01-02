#include <SFML/Graphics.hpp>
#include <iostream>

int main() {
    sf::RenderTexture texture;

    if (!texture.create(1200, 800))
        return -1;

    srand(time(0));

    int x[3] = {600, 0, 1200};
    int y[3] = {0, 800, 800};

    float last_x = 1200;
    float last_y = 800;

    texture.clear(sf::Color::Black);
    sf::Sprite sprite(texture.getTexture());

    int iterations = 10000000;  //You can change this to whatever value you want... More value more detail
    int i = 0;

    while (i < iterations) {
        int dice = rand() % 3;

        last_x = (last_x + x[dice]) / 2;

        last_y = (last_y + y[dice]) / 2;

        sf::Vertex point(sf::Vector2f(last_x, last_y), sf::Color::Green);
        texture.draw(&point, 1, sf::Points);
        texture.display();
        sf::Sprite sprite(texture.getTexture());
        i++;
        if (i == iterations / 4)
            std::cout << "25%" << std::endl;
        else if (i == iterations / 2)
            std::cout << "50%" << std::endl;
        else if (i == int(iterations / 1.33))
            std::cout << "75%" << std::endl;
        else if (i == iterations)
            std::cout << "100%" << std::endl;
    }

    sf::RenderWindow window(sf::VideoMode(1200, 800), "Fractal", sf::Style::Close);

    window.clear();
    window.draw(sprite);
    window.display();

    while (window.isOpen()) {
        sf::Event evnt;
        while (window.pollEvent(evnt))
            if (evnt.type == evnt.Closed)
                window.close();
    }

    return 0;
}
