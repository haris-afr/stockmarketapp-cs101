#include <SFML/Graphics.hpp>
using namespace std;

int main()
{
    //creates a window and titles it 
    sf::Window window(sf::VideoMode(1200, 600), "Stock Market App", sf::Style::Close | sf::Style::Titlebar);
    sf::RectangleShape button(sf::Vector2f(100, 50));

    while (window.isOpen()) {

        sf::Event event;
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

        window.draw(button);
        window.display();

    }

    return 0;

   
}