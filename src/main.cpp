#include "../src/core/core.hpp"
#include "../src/page/page.hpp"


int main() {
    
    Core App(700, 800, "SFMLDevKit");
    
    App.loop();
    
    Page();
    
    return 0;
}
