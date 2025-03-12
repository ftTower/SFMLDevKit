#include "../src/core/core.hpp"
#include "../src/elements/button.hpp"

int main() {
        
    try {
        Core App(700, 800, "SFMLDevKit");
        
        Page mainPage("main page", "little test");
        
        Button test(sf::Color::Red);
        
        mainPage.addElement(&test);
        App.addPage(mainPage);
        
        
        App.loop();
        
    } catch (std::exception &e) {
        std::cerr << "ERROR : " << e.what() << std::endl;
    }
    
    return 0;
}
