#include <iostream>
#include <SFML/Graphics.hpp>

int main() {
    sf::RenderTexture texture;

    if (!texture.create(960, 540))
        return -1;

    srand(time(0));

    int x[3] = {460, 0, 960};
    int y[3] = {0, 540, 540};

    float last_x = 960;
    float last_y = 540;

    texture.clear(sf::Color::Black);
    sf::Sprite sprite(texture.getTexture());

    int iterations = 1000000; //You can change this to whatever value you want... More value more detail but after some point it remains the same
    int i = 0;

    while (i < iterations) {
        int dice = rand() % 3;

        if (last_x >= x[dice])
            last_x = (last_x + x[dice]) / 2;
        else if (last_x < x[dice])
            last_x = (last_x + x[dice]) / 2;

        if (last_y >= y[dice])
            last_y = (last_y + y[dice]) / 2;
        else if (last_y < y[dice])
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
            std::cout << "100%" <<std:: endl;
    }

    sf::RenderWindow window(sf::VideoMode(960, 540), "Fractal", sf::Style::Close);

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
