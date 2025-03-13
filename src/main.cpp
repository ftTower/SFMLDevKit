//#include "../src/core/core.hpp"
//#include "../src/elements/button.hpp"

#include "./utils/headers.hpp"

Page* mainPage() {
    Page* mainPage = new Page("main page", "little test");
        
    //*BACKGROUND
    Background* mainBackground = new Background(sf::Vector2f(700, 800), sf::Color(64, 64, 64));
    mainPage->addElement(mainBackground);
    Graph *utils = new Graph(sf::Vector2f(500, 250), sf::Vector2f(50, 50));
    mainPage->addElement(utils);
    ////*BUTTONS
    Button* test = new Button(sf::Color(128, 128, 128), sf::Vector2f(350, 400), sf::Vector2f(200, 100), 20);
    mainPage->addElement(test);
    
    return mainPage;
}

Page* deuxiemePage() {
    Page* deuxiemePage = new Page("deuxieme page");
        
    //*BACKGROUND
    Background* mainBackground = new Background(sf::Vector2f(700, 800), sf::Color(64, 64, 64));
    deuxiemePage->addElement(mainBackground);
    
    ////*BUTTONS
    Button* test = new Button(sf::Color(128, 128, 128), sf::Vector2f(350, 400), sf::Vector2f(200, 100), 20);
    deuxiemePage->addElement(test);
    
    Button* test2 = new Button(sf::Color(128, 128, 128), sf::Vector2f(100, 100), sf::Vector2f(200, 100), 20);
    deuxiemePage->addElement(test2);
    
    return deuxiemePage;
}

int main() {
        
    //!INITING
    try {
        Core App(700, 800, "SFMLDevKit");
                
        
        ////*GRAPHIC
        
        
        App.addPage(*mainPage());
        App.addPage(*deuxiemePage());
        
        //!RUNNING CATCH
        try {
            App.loop();
        
        
        
        } catch (std::exception &e) {
            std::cerr << "RUNNING ERROR : " << std::endl << e.what() << std::endl << std::endl;
        }        
    } catch (std::exception &e) {
        std::cerr << "INITING ERROR : " << std::endl << e.what() << std::endl << std::endl;
    }
        
        
    
    return 0;
}
