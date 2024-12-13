#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

class visEye {
public:
    sf::Texture T_EyeClosed;
    sf::Texture T_EyeOpen;
    bool CurrentTexture;
    sf::Sprite S_CurrentSprite;
    int xPos, yPos;

    void initialize(int givenXPos, int givenYPos) {
        T_EyeClosed.loadFromFile("assets/eye-close.png");
        T_EyeOpen.loadFromFile("assets/eye-open.png");
        S_CurrentSprite.setTexture(T_EyeClosed);
        CurrentTexture = 0;
        xPos = givenXPos;
        yPos = givenYPos;
        S_CurrentSprite.setPosition(xPos, yPos);
    }

    void setState(bool state) {
        if (state == 0) {
            S_CurrentSprite.setTexture(T_EyeClosed);
            CurrentTexture = 0;
        }
        else {
            S_CurrentSprite.setTexture(T_EyeOpen);
            CurrentTexture = 1;
        }
    }

    void flip() {
        if (CurrentTexture == 0) {
            S_CurrentSprite.setTexture(T_EyeOpen);
            CurrentTexture = 1;
        }
        else {
            S_CurrentSprite.setTexture(T_EyeClosed);
            CurrentTexture = 0;
        }
    }

};

class buySell {
public:
    sf::Texture Texture;
    sf::Sprite Sprite;
    int xPos, yPos;
    int setStock;

    void initialize(int stock, int givenXPos, int givenYPos) {
        Texture.loadFromFile("assets/buy-sell.png");
        setStock = stock;
        xPos = givenXPos;
        yPos = givenYPos;
        Sprite.setTexture(Texture);
        Sprite.setPosition(xPos, yPos);

    }
};

class stockLine {
public:
    int xPos = 0;
    int yPos = 0;
    int setStock = 0;
    sf::VertexArray lines;
    
    stockLine(int stock, int givenYPos) : lines(sf::TrianglesStrip, 12) {
        setStock = stock;
        for (int i = 0; i < 12; i++) {
            lines[i].color = sf::Color::Red;

            if ((i + 1) % 2 == 0) {
                lines[i].position.y = givenYPos;
            }
            else {
                lines[i].position.y = givenYPos + 8;
            }

            lines[i].position.x = 35 + ( (i/2) * 145);
        }
    }
    
};

int main()
{
    //creates a window and titles it 
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Stock Market App", sf::Style::Close | sf::Style::Titlebar);
    
    sf::Font font;
    font.loadFromFile("assets/Swansea.ttf");

    int cashMoney = 10000;
    int stockMoney = 0;

    sf::Texture T_StockOption_Coin;
    sf::Texture T_StockOption_Tech1;
    sf::Texture T_StockOption_Tech2;
    sf::Texture T_StockOption_Insurance;
    sf::Texture T_StockOption_War;
    sf::Texture T_StockOption_Gold;
    sf::Texture T_StockOption_Nvid;
    sf::Texture T_StockOption_Oil;


    sf::Sprite S_StockOption_Coin;
    sf::Sprite S_StockOption_Tech1;
    sf::Sprite S_StockOption_Tech2;
    sf::Sprite S_StockOption_Insurance;
    sf::Sprite S_StockOption_War;
    sf::Sprite S_StockOption_Gold;
    sf::Sprite S_StockOption_Nvid;
    sf::Sprite S_StockOption_Oil;
    

    sf::Texture chartTexture;
    sf::Sprite chartSprite;
    chartTexture.loadFromFile("assets/chart-blank.png");
    chartSprite.setTexture(chartTexture);
    
    
    T_StockOption_Coin.loadFromFile("assets/coin.png");
    T_StockOption_Tech1.loadFromFile("assets/apple.png");
    T_StockOption_Tech2.loadFromFile("assets/google.png");
    T_StockOption_Insurance.loadFromFile("assets/insurance.png");
    T_StockOption_War.loadFromFile("assets/tank.png");
    T_StockOption_Gold.loadFromFile("assets/gold.png");
    T_StockOption_Nvid.loadFromFile("assets/nvidia.png");
    T_StockOption_Oil.loadFromFile("assets/oil.png");

    S_StockOption_Coin.setTexture(T_StockOption_Coin);
    S_StockOption_Tech1.setTexture(T_StockOption_Tech1);
    S_StockOption_Tech2.setTexture(T_StockOption_Tech2);
    S_StockOption_Insurance.setTexture(T_StockOption_Insurance);
    S_StockOption_War.setTexture(T_StockOption_War);
    S_StockOption_Gold.setTexture(T_StockOption_Gold);
    S_StockOption_Nvid.setTexture(T_StockOption_Nvid);
    S_StockOption_Oil.setTexture(T_StockOption_Oil);

    S_StockOption_Coin.setPosition(850, 100);
    S_StockOption_Tech1.setPosition(1225, 75);
    S_StockOption_Tech2.setPosition(850, 200);
    S_StockOption_Insurance.setPosition(1225, 200);
    S_StockOption_War.setPosition(850, 300);
    S_StockOption_Gold.setPosition(1225, 300);
    S_StockOption_Nvid.setPosition(850, 400);
    S_StockOption_Oil.setPosition(1225, 400);

    stockLine stockLine1(0, 500);
    
    sf::Text moneyTitleText;
    sf::Text cashmoneyTitleText;
    sf::Text stockmoneyTitleText;
    sf::Text textCashMoney;
    sf::Text textStockMoney;

    moneyTitleText.setString("Total Assets");
    moneyTitleText.setFont(font);
    moneyTitleText.setFillColor(sf::Color::Black);
    moneyTitleText.setCharacterSize(48);
    moneyTitleText.setPosition(1000, 550);

    cashmoneyTitleText.setString("Money in Hand");
    cashmoneyTitleText.setFont(font);
    cashmoneyTitleText.setFillColor(sf::Color::Black);
    cashmoneyTitleText.setCharacterSize(32);
    cashmoneyTitleText.setPosition(800, 650);

    stockmoneyTitleText.setString("Money in Stocks");
    stockmoneyTitleText.setFont(font);
    stockmoneyTitleText.setFillColor(sf::Color::Black);
    stockmoneyTitleText.setCharacterSize(32);
    stockmoneyTitleText.setPosition(800, 700);

    textCashMoney.setFont(font);
    textCashMoney.setFillColor(sf::Color::Black);
    textCashMoney.setCharacterSize(32);
    textCashMoney.setPosition(1200, 650);

    textStockMoney.setFont(font);
    textStockMoney.setFillColor(sf::Color::Black);
    textStockMoney.setCharacterSize(32);
    textStockMoney.setPosition(1200, 700);
    
    sf::Text iconTextArray[8];
    iconTextArray[0].setString("Apple");
    iconTextArray[1].setString("Binance");
    iconTextArray[2].setString("UHC");
    iconTextArray[3].setString("Google");
    iconTextArray[4].setString("Newmont Gold");
    iconTextArray[5].setString("Lockheed Martin");
    iconTextArray[6].setString("Shell Oil");
    iconTextArray[7].setString("Nvidea");

    for (int i = 0; i < 8; i++) {
        int xPos = (950 + 375 * ((i + 1) % 2));
        int yPos = (105 * ((i + 2) / 2) + 25);
        iconTextArray[i].setFont(font);
        iconTextArray[i].setFillColor(sf::Color::Black);
        iconTextArray[i].setCharacterSize(24);
        iconTextArray[i].setPosition(xPos, yPos);
    }

    visEye visEyeArray[8];
    buySell buySellArray[8];

    for (int i = 0; i < 8; i++) {
        int xPos = (800 + 375 * ((i + 1) % 2));
        int yPos = (100 * ((i + 2) / 2) + 25);
        visEyeArray[i].initialize(xPos, yPos);
    }

    for (int i = 0; i < 8; i++) {
        int xPos = (950 + 375 * ((i + 1) % 2));
        int yPos = (150 + (100 * ((i) / 2)));
        buySellArray[i].initialize(i, xPos, yPos);
    }


    while (window.isOpen()) {

        bool lockClick = false;

        string stringCashMoney = to_string(cashMoney);
        string stringStockMoney = to_string(stockMoney);
        textCashMoney.setString(to_string(cashMoney));
        textStockMoney.setString(to_string(stockMoney));

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

            case sf::Event::MouseButtonPressed:{
                int mouseXPos = sf::Mouse::getPosition(window).x;
                int mouseYPos = sf::Mouse::getPosition(window).y;
                for (int i = 0; i < 8; i++) {
                    bool xCheck = mouseXPos >= visEyeArray[i].xPos && mouseXPos <= visEyeArray[i].xPos + 50;
                    bool yCheck = mouseYPos >= visEyeArray[i].yPos && mouseYPos <= visEyeArray[i].yPos + 50;
                    if (xCheck && yCheck && !lockClick) {
                        visEyeArray[i].flip();
                        lockClick = true;
                        break;
                    }
                }
                break;
            }

            case sf::Event::MouseButtonReleased:
                lockClick = false;
                break;


            default:
                break;
            }
        }


        window.clear(sf::Color(217, 234, 253, 0));

        window.draw(chartSprite);
        window.draw(moneyTitleText);
        window.draw(cashmoneyTitleText);
        window.draw(stockmoneyTitleText);
        window.draw(textCashMoney);
        window.draw(textStockMoney);
        window.draw(S_StockOption_Coin);
        window.draw(S_StockOption_Tech1);
        window.draw(S_StockOption_Tech2);
        window.draw(S_StockOption_Insurance);
        window.draw(S_StockOption_War);
        window.draw(S_StockOption_Gold);
        window.draw(S_StockOption_Nvid);
        window.draw(S_StockOption_Oil);
        window.draw(stockLine1.lines);
        
        for (int i = 0; i < 8; i++) {
            window.draw(visEyeArray[i].S_CurrentSprite);
            window.draw(iconTextArray[i]);
            window.draw(buySellArray[i].Sprite);
        }
        

        window.display();
    }
    return 0;
}