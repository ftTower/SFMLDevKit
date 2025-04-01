//#include "../src/core/core.hpp"
//#include "../src/elements/button.hpp"

#include "./utils/headers.hpp"

Page* graphDemoPage() {
    Page* graphDemoPage = new Page("graphiques");
    
    //*BACKGROUND
    Background* mainBackground = new Background(sf::Vector2f(WINDOW_W, WINDOW_H), sf::Color(30, 30, 30));
    graphDemoPage->addElement(mainBackground);
    
    Graph* demoGraph1 = new Graph(sf::Vector2f(600, 300), sf::Vector2f(50, 100));
    graphDemoPage->addElement(demoGraph1);
    
    Graph* demoGraph2 = new Graph(sf::Vector2f(400, 200), sf::Vector2f(150, 450));
    graphDemoPage->addElement(demoGraph2);
    
    return graphDemoPage;
}

Page* settingsPage() {
    Page* settingsPage = new Page("parametres");
    
    //*BACKGROUND
    Background* mainBackground = new Background(sf::Vector2f(WINDOW_W, WINDOW_H), sf::Color(50, 50, 50));
    settingsPage->addElement(mainBackground);
    
    static sf::Font font;
    if (!font.loadFromFile("./fonts/Movistar Text Regular.ttf")) {
        throw(std::runtime_error("failed to load Font"));
    }
    
    Button* resolution = new Button(sf::Color(128, 128, 128), sf::Vector2f(250, 200), sf::Vector2f(200, 80), 20, "Resolution", font, 30);
    settingsPage->addElement(resolution);
    
    Button* theme = new Button(sf::Color(128, 128, 128), sf::Vector2f(250, 300), sf::Vector2f(200, 80), 20, "Theme", font, 30);
    settingsPage->addElement(theme);
    
    Button* volume = new Button(sf::Color(128, 128, 128), sf::Vector2f(250, 400), sf::Vector2f(200, 80), 20, "Volume", font, 30);
    settingsPage->addElement(volume);
    
    return settingsPage;
}

Page* mainPage() {
    Page* mainPage = new Page("accueil");
        
    //* BACKGROUND
    Background* mainBackground = new Background(sf::Vector2f(WINDOW_W, WINDOW_H), sf::Color(50, 50, 50));
    mainPage->addElement(mainBackground);
    
    ////* SIDEBAR
    //SideBar* sidebar = new SideBar(sf::Vector2f(50, 800) , sf::Color::Black);
    //mainPage->addElement(sidebar);
    
    //* BOX
    //Box* mainBox = new Box(sf::Vector2f(100, 100), sf::Vector2f(100, 100),sf::Color::White);
    //mainPage->addElement(mainBox);
    
    static sf::Font font;
    if (!font.loadFromFile("./fonts/Movistar Text Regular.ttf")) {
        throw(std::runtime_error("failed to load Font"));
    }
    
    
    //* BUTTONS
    sf::Vector2f buttonSize(200, 80);
    sf::Color buttonColor(100, 100, 100);
    int borderRadius = 20;
    
    Button* btnStart = new Button(buttonColor, sf::Vector2f(250, 350), buttonSize, borderRadius, "Commencer", font, 30);
    mainPage->addElement(btnStart);
    
    Button* btnSettings = new Button(buttonColor, sf::Vector2f(250, 450), buttonSize, borderRadius, "Parametres", font, 30);
    mainPage->addElement(btnSettings);
    
    Button* btnQuit = new Button(buttonColor, sf::Vector2f(250, 550), buttonSize, borderRadius, "Quitter", font, 30);
    mainPage->addElement(btnQuit);
    
    return mainPage;
}

Page* complexPage() {
    Page* complexPage = new Page("complexe");

    //* BACKGROUND
    Background* mainBackground = new Background(sf::Vector2f(WINDOW_W, WINDOW_H), sf::Color(70, 70, 70));
    complexPage->addElement(mainBackground);

    static sf::Font font;
    if (!font.loadFromFile("./fonts/Movistar Text Regular.ttf")) {
        throw(std::runtime_error("failed to load Font"));
    }

    
    //* BOXES
    Box* box1 = new Box(sf::Vector2f(100, 300), sf::Vector2f(200, 100), sf::Color(150, 150, 150));
    complexPage->addElement(box1);

    Box* box2 = new Box(sf::Vector2f(400, 300), sf::Vector2f(200, 100), sf::Color(180, 180, 180));
    complexPage->addElement(box2);

    //* BUTTONS
    sf::Vector2f buttonSize(150, 50);
    sf::Color buttonColor(120, 120, 120);
    int borderRadius = 15;

    Button* btn1 = new Button(buttonColor, sf::Vector2f(100, 150), buttonSize, borderRadius, "Button 1", font, 20);
    complexPage->addElement(btn1);

    Button* btn2 = new Button(buttonColor, sf::Vector2f(275, 150), buttonSize, borderRadius, "Button 2", font, 20);
    complexPage->addElement(btn2);

    Button* btn3 = new Button(buttonColor, sf::Vector2f(450, 150), buttonSize, borderRadius, "Button 3", font, 20);
    complexPage->addElement(btn3);

    
    //* LOADING
    Loading* loading = new Loading(sf::Vector2f(WINDOW_W, WINDOW_H));
    complexPage->addElement(loading);

    return complexPage;
}

int main() {
        
    //!INITING
    try {
        Core App(WINDOW_W, WINDOW_H, "SFMLDevKit");
                
        
        ////*GRAPHIC
        
        
        App.addPage(*mainPage());
        App.addPage(*complexPage()); 
        App.addPage(*settingsPage());
        App.addPage(*graphDemoPage());
        
        
        
        //!RUNNING CATCH
        try {
            App.loop();
        
        
        
        } catch (std::exception &e) {
            std::cerr << "RUNNING ERROR : " << std::endl << ANSI_BG_RED << e.what() << ANSI_RESET << std::endl << std::endl;
        }        
    } catch (std::exception &e) {
        std::cerr << "INITING ERROR : " << std::endl << ANSI_BG_RED << e.what() << ANSI_RESET << std::endl << std::endl;
    }
        
        
    
    return 0;
}
