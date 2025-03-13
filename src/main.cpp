//#include "../src/core/core.hpp"
//#include "../src/elements/button.hpp"

#include "./utils/headers.hpp"

int main() {
        
    //!INITING
    try {
        Core App(700, 800, "SFMLDevKit");
                
        Page mainPage("main page", "little test");
        
        //*BACKGROUND
        Background mainBackground(sf::Vector2f(700, 800), sf::Color(64,64,64));
        mainPage.addElement(&mainBackground);
        ////*BUTTONS
        Button test(sf::Color(128,128,128), sf::Vector2f(350, 400), sf::Vector2f(200, 100), 20);
        mainPage.addElement(&test);
        ////*GRAPHIC
        //Graph utils;
        //mainPage.addElement(&utils);
        
        App.addPage(mainPage);
        App.addPage(mainPage);
        
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
