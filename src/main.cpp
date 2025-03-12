#include "../src/core/core.hpp"
#include "../src/elements/button.hpp"

int main() {
        
    //!INITING
    try {
        Core App(700, 800, "SFMLDevKit");
        
        
        Page mainPage("main page", "little test");
        Button test(sf::Color::Red);
        mainPage.addElement(&test);
        //App.addPage(mainPage);
        
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
