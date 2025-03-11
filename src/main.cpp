#include "../src/core/core.hpp"


int main() {
        
    try {
        Core App(700, 800, "SFMLDevKit");
        
        Page mainPage("main page", "little test");
        App.addPage(mainPage);
        
        App.loop();
        
    } catch (std::exception &e) {
        std::cerr << "ERROR : " << e.what() << std::endl;
    }
    
    return 0;
}
