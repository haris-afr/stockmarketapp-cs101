#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    //creates a window and titles it 
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Stock Market App", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape button(sf::Vector2f(100, 50));

    sf::Texture chartTexture;
    sf::Sprite chartSprite;
 
    if (!chartTexture.loadFromFile("assets/chart-blank.png")) {
        cout << "can;t print" << endl;
    }
    chartSprite.setTexture(chartTexture);


    while (window.isOpen()) {

        sf::Event event;
        //this is used to create the event loop
        while (window.pollEvent(event))
        {
            // check the type of the event...
            switch (event.type)
            {
                // window closed
            case sf::Event::Closed:
                window.close();
                break;


            default:
                break;
            }
        }

        button.setFillColor(sf::Color(154, 166, 178));
        window.clear(sf::Color(217, 234, 253, 0));

        window.draw(button);
        window.draw(chartSprite);
        window.display();


    }

    return 0;

   
}