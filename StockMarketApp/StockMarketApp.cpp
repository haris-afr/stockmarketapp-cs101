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
 
    chartTexture.loadFromFile("assets/chart-blank.png");
    T_StockOption_Coin.loadFromFile("assets/coin.png");
    T_StockOption_Tech1.loadFromFile("assets/apple.png");
    T_StockOption_Tech2.loadFromFile("assets/google.png");
    T_StockOption_Insurance.loadFromFile("assets/insurance.png");
    T_StockOption_War.loadFromFile("assets/tank.png");
    T_StockOption_Gold.loadFromFile("assets/gold.png");
    T_StockOption_Dollar.loadFromFile("assets/dollar.png");
    T_StockOption_Oil.loadFromFile("assets/oil.png");

    chartSprite.setTexture(chartTexture);
    S_StockOption_Coin.setTexture(T_StockOption_Coin);
    S_StockOption_Tech1.setTexture(T_StockOption_Tech1);
    S_StockOption_Tech2.setTexture(T_StockOption_Tech2);
    S_StockOption_Insurance.setTexture(T_StockOption_Insurance);
    S_StockOption_War.setTexture(T_StockOption_War);
    S_StockOption_Gold.setTexture(T_StockOption_Gold);
    S_StockOption_Dollar.setTexture(T_StockOption_Dollar);
    S_StockOption_Oil.setTexture(T_StockOption_Oil);

    S_StockOption_Coin.setPosition(850, 100);
    S_StockOption_Tech1.setPosition(1225, 75);
    S_StockOption_Tech2.setPosition(850, 200);
    S_StockOption_Insurance.setPosition(1225, 200);
    S_StockOption_War.setPosition(850, 300);
    S_StockOption_Gold.setPosition(1225, 300);
    S_StockOption_Dollar.setPosition(850, 400);
    S_StockOption_Oil.setPosition(1225, 400);


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
        window.draw(S_StockOption_Coin);
        window.draw(S_StockOption_Tech1);
        window.draw(S_StockOption_Tech2);
        window.draw(S_StockOption_Insurance);
        window.draw(S_StockOption_War);
        window.draw(S_StockOption_Gold);
        window.draw(S_StockOption_Dollar);
        window.draw(S_StockOption_Oil);
        
        
        
        
        
        window.display();


    }

    return 0;

   
}