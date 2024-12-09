#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

int main()
{
    //creates a window and titles it 
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Stock Market App", sf::Style::Close | sf::Style::Titlebar);

    sf::Texture T_StockOption_Coin;
    sf::Texture T_StockOption_Tech1;
    sf::Texture T_StockOption_Tech2;
    sf::Texture T_StockOption_Insurance;
    sf::Texture T_StockOption_War;
    sf::Texture T_StockOption_Gold;
    sf::Texture T_StockOption_Dollar;
    sf::Texture T_StockOption_Oil;

    sf::Sprite S_StockOption_Coin;
    sf::Sprite S_StockOption_Tech1;
    sf::Sprite S_StockOption_Tech2;
    sf::Sprite S_StockOption_Insurance;
    sf::Sprite S_StockOption_War;
    sf::Sprite S_StockOption_Gold;
    sf::Sprite S_StockOption_Dollar;
    sf::Sprite S_StockOption_Oil;

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
        window.clear(sf::Color(217, 234, 253, 0));

        window.draw(chartSprite);
        
        
        
        
        
        window.display();


    }

    return 0;

   
}