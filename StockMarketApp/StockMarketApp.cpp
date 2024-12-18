#include <SFML/Graphics.hpp> //for graphics
#include "price change.cpp" //for normal price change: Usman
#include "hamza mohsin.cpp" //for extreme price change: Ali Ahsan
#include "CS STOCK MARKET PROJECT.cpp" //for news:: Daniyal

using namespace std;

int cashMoney = 10000; //creation of a global variable to store money
sf::Font font;


class buySell {
public:
    sf::Texture Texture;
    sf::Sprite Sprite;
    int xPos, yPos;
    int setStock;
    double stockVal = 100;
    int stocksOwned = 0;
    double stocksOwnedVal = 0;
    int daysOfExtreme = 0;
    int newsStockChangeInValue = 0;

    sf::Text stocksOwnedtext;
    sf::Text stockPricetext;

    void initialize(int stock, int givenXPos, int givenYPos) {
        Texture.loadFromFile("assets/buy-sell.png");
        setStock = stock;
        xPos = givenXPos;
        yPos = givenYPos;
        Sprite.setTexture(Texture);
        Sprite.setPosition(xPos, yPos);

        stockVal = 100 - rand() % 100;

        stocksOwnedtext.setString("0");
        stocksOwnedtext.setFont(font);
        stocksOwnedtext.setFillColor(sf::Color::Black);
        stocksOwnedtext.setCharacterSize(24);
        stocksOwnedtext.setPosition(xPos + 180, yPos + 30);

        stockPricetext.setString("0");
        stockPricetext.setFont(font);
        stockPricetext.setFillColor(sf::Color::Black);
        stockPricetext.setCharacterSize(24);
        stockPricetext.setPosition(xPos + 180, yPos - 30);
    }

    void Buy() {
        if (cashMoney > stockVal) {
            stocksOwned += 1;
            cashMoney -= stockVal;
            stocksOwnedtext.setString(to_string(stocksOwned));
            updatedStocksOwnedVal();
        }
    }

    void Sell() {
        if (stocksOwned > 0) {
            stocksOwned -= 1;
            cashMoney += stockVal;
            stocksOwnedtext.setString(to_string(stocksOwned));
            updatedStocksOwnedVal();
        }
    }

    int updateStockValue() {
        float multiplier = updateprice(1.01, .35);
        int extremeDice = rand() % 20;
        bool extremeUpOrDown = 0;
        if (stockVal < 10) {
            multiplier = updateprice(1.2, .2);
            stockVal = 10;
        }

        else if (extremeDice == 0 && daysOfExtreme == 0) {
            daysOfExtreme = DaysOfExtreme();
            extremeUpOrDown = rand() % 2;
        }

        else if (daysOfExtreme > 1) {
            multiplier = extremePrice(extremeUpOrDown, daysOfExtreme);
            daysOfExtreme -= 1;
        }
        else if (stockVal < 300) {
            multiplier = updateprice(1.1, .2);
        }
        
        if (stockVal > 550) {
            daysOfExtreme = 0;
            multiplier = updateprice(0.8, .2);
            stockVal = 550;
        }

        if (newsStockChangeInValue != 0) {
            daysOfExtreme = 0;
            switch (newsStockChangeInValue) {
            case 1:
                extremePrice(0, 1);
                break;
            case 2:
                multiplier = updateprice(0.7, 0.1);
                break;
            case 3:
                multiplier = updateprice(1.3, 0.1);
                break;
            case 4:
                extremePrice(1, 1);
                break;
            default:
                break;
            }
        }

        stockVal *= multiplier;
        updatedStocksOwnedVal();

        int displayValue = stockVal;
        stockPricetext.setString(to_string(displayValue));
        return stockVal;
    }

    void updatedStocksOwnedVal() {
        stocksOwnedVal = stockVal * stocksOwned;
    }

};

class stockLine {
public:
    int xPos = 0;
    int yPos = 0;
    int setStock = 0;
    sf::VertexArray lines;
    int stocksArray[6];
    sf::Color stockColor = sf::Color(0, 0, 0, 0);
    
    stockLine(int stock = -1, int givenYPos = 0) : lines(sf::TrianglesStrip, 12) {
        setStock = stock;
        for (int i = 0; i < 12; i++) {
            lines[i].color = stockColor;
            lines[i].position.x = 35 + ( (i/2) * 145);
        }

        for (int i = 0; i < 6; i++) {
            stocksArray[i] = 0;
        }
        updateStocks(givenYPos);
        updateColor(0);
        displayStocks();
    }

    void displayStocks() {
        for (int i = 0; i < 6; i++) {
            lines[2 * i].position.y = stocksArray[i];
            lines[2 * i + 1].position.y = stocksArray[i] + 8;
        }
    }

    void updateStocks(int latestYPos) {
        for (int i = 0; i < 5; i++) {
            stocksArray[i] = stocksArray[i + 1];
        }
        stocksArray[5] = latestYPos;
        displayStocks();
    }
    
    void updateColor(bool vis) {
        if (!vis) {
            stockColor = sf::Color(0, 0, 0, 0); //transparent
        }
        else {
            switch (setStock) {
            case 1:
                stockColor = sf::Color(184, 115, 51, 255); //copper
                break;
            case 0:
                stockColor = sf::Color(128, 128, 128, 255); //grey
                break;
            case 3:
                stockColor = sf::Color(66, 133, 244, 255); //blue
                break;
            case 2:
                stockColor = sf::Color::Red; //light red
                break;
            case 5:
                stockColor = sf::Color(35, 35, 142, 255); //navy blue
                break;
            case 4:
                stockColor = sf::Color(255, 215, 0, 255); //gold
                break;
            case 7:
                stockColor = sf::Color(118, 185, 0, 255); //green
                break;
            case 6:
                stockColor = sf::Color(0, 4, 13, 255); //black
                break;
            default:
                cout << "something has gone wrong in colors" << endl;
            }


        }
        for (int i = 0; i < 12; i++) {
            lines[i].color = stockColor;
        }
    }
};

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

    void flip(stockLine& stocktoUpdate) {
        if (CurrentTexture == 0) {
            S_CurrentSprite.setTexture(T_EyeOpen);
            CurrentTexture = 1;
            stocktoUpdate.updateColor(1);
        }
        else {
            S_CurrentSprite.setTexture(T_EyeClosed);
            CurrentTexture = 0;
            stocktoUpdate.updateColor(0);
        }
    }

};

int main()
{
    srand(time(0));
    //creates a window and titles it 
    sf::RenderWindow window(sf::VideoMode(1600, 900), "Stock Market App", sf::Style::Close | sf::Style::Titlebar);
    
    font.loadFromFile("assets/Swansea.ttf");

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

    sf::Texture T_NextDay;
    sf::Sprite S_NextDay;
    T_NextDay.loadFromFile("assets/next.png");
    S_NextDay.setTexture(T_NextDay);
    S_NextDay.setPosition(1050, 15);
    
    
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

    sf::Text NewsTitleText;
    sf::Text NewsText;
    NewsTitleText.setFont(font);
    NewsTitleText.setFillColor(sf::Color::Black);
    NewsTitleText.setCharacterSize(48);
    NewsTitleText.setPosition(50, 600);
    NewsTitleText.setString("Today's News");

    NewsText.setFont(font);
    NewsText.setFillColor(sf::Color::Black);
    NewsText.setCharacterSize(24);
    NewsText.setPosition(50, 750);
    NewsText.setLineSpacing(3);
    NewsText.setString("No news today");


    for (int i = 0; i < 8; i++) {
        int xPos = (950 + 375 * ((i + 1) % 2));
        int yPos = (105 * ((i + 2) / 2) + 25);
        iconTextArray[i].setFont(font);
        iconTextArray[i].setFillColor(sf::Color::Black);
        iconTextArray[i].setCharacterSize(24);
        iconTextArray[i].setPosition(xPos, yPos);
    }
   
    stockLine stocksArray[8];
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

    for (int i = 0; i < 8; i++) {
        stocksArray[i] = stockLine(i, buySellArray[i].stockVal);
    }

    for (int j = 0; j < 6; j++) {
        for (int i = 0; i < 8; i++) {
            stocksArray[i].updateStocks(550 - buySellArray[i].updateStockValue());
        }
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

                //hide stocks check
                for (int i = 0; i < 8; i++) {
                    bool xCheck = mouseXPos >= visEyeArray[i].xPos && mouseXPos <= visEyeArray[i].xPos + 50;
                    bool yCheck = mouseYPos >= visEyeArray[i].yPos && mouseYPos <= visEyeArray[i].yPos + 50;
                    if (xCheck && yCheck && !lockClick) {
                        visEyeArray[i].flip(stocksArray[i]);
                        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                            lockClick = true;
                        }
                        break;
                    }
                }
                //next day check
                if (mouseXPos >= 1050 && mouseXPos <= 1150 && mouseYPos >= 15 && mouseYPos <= 115 && !lockClick) {
                    stockMoney = 0;
                    lockClick = true;
                    int stockoftheday = rand() % 8;
                    int changeinStock = (rand() % 4) + 1;;

                    for (int i = 0; i < 8; i++) {
                        stocksArray[i].updateStocks(550 - buySellArray[i].updateStockValue());
                     }
                    buySellArray[stockoftheday].newsStockChangeInValue = changeinStock;

                    switch (changeinStock)
                    {
                    case 1:
                        changeinStock = 20;
                        break;
                    case 2:
                        changeinStock = 90;
                        break;
                    case 3:
                        changeinStock = 110;
                        break;
                    case 4:
                        changeinStock = 150;
                        break;
                    default:
                        break;
                    }

                    for (int i = 0; i < 8; i++) {
                        stockMoney += buySellArray[i].stocksOwnedVal;
                        NewsText.setString(returnNews(changeinStock, stockoftheday));
                    }
                    


                    break;
                }

                //buy and sell check
                for (int i = 0; i < 8; i++) {
                    bool xCheckBuy = mouseXPos >= buySellArray[i].xPos + 5 && mouseXPos <= buySellArray[i].xPos + 50;
                    bool xCheckSell = mouseXPos >= buySellArray[i].xPos + 60 && mouseXPos <= buySellArray[i].xPos + 110;
                    bool yCheck = mouseYPos >= buySellArray[i].yPos + 25 && mouseYPos <= buySellArray[i].yPos + 55;
                    if (xCheckBuy && yCheck && !lockClick) {
                        if (cashMoney > buySellArray[i].stockVal) {
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && cashMoney > 10 * buySellArray[i].stockVal) {
                                for (int j = 0; j < 10; j++) {
                                    buySellArray[i].Buy();
                                    stockMoney += buySellArray[i].stockVal;
                                }
                            }
                            else {
                                buySellArray[i].Buy();
                                stockMoney += buySellArray[i].stockVal;
                            }
                            lockClick = true;
                        }
                        break;
                    }
                    if (xCheckSell && yCheck && !lockClick) {
                        if (buySellArray[i].stocksOwned > 0) {
                            if (sf::Mouse::isButtonPressed(sf::Mouse::Right) && (buySellArray[i].stocksOwned > 10)) {
                                for (int j = 0; j < 10; j++) {
                                    buySellArray[i].Sell();
                                    stockMoney -= buySellArray[i].stockVal;
                                }
                            }
                            else {
                                buySellArray[i].Sell();
                                stockMoney -= buySellArray[i].stockVal;
                            }
                        }

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
        window.draw(S_NextDay);
        window.draw(NewsText);
        window.draw(NewsTitleText);
        

        for (int i = 0; i < 8; i++) {
            window.draw(visEyeArray[i].S_CurrentSprite);
            window.draw(iconTextArray[i]);
            window.draw(buySellArray[i].Sprite);
            window.draw(stocksArray[i].lines);
            window.draw(buySellArray[i].stocksOwnedtext);
            window.draw(buySellArray[i].stockPricetext);
        }    

        window.display();
    }
    return 0;
}