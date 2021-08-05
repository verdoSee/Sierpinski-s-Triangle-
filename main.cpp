#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(960, 540), "SFML tutorial", sf::Style::None);
    sf::RenderTexture texture;
    srand(time(0));

    if (!texture.create(960, 540))
        return -1;

    int x[3] = {460, 0, 960};
    int y[3] = {0, 540, 540};

    float last_x = 960;
    float last_y = 540;

    texture.clear(sf::Color::Black);

    while (window.isOpen()) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) 
            window.close();   

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
        window.clear();
        sf::Sprite sprite(texture.getTexture());
        window.draw(sprite);
        window.display();
    }

    return 0;
}
