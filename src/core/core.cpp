#include "../utils/headers.hpp"

//!CONSTRUCTORS
Core::Core(unsigned int W, unsigned int H, std::string appName) : _window(sf::VideoMode(W, H), appName), _currentPage(0) {
	
}

Core::~Core() {
	
}

//?GETTERS
const sf::RenderWindow &Core::window() const {
    return (_window);
}

//?SETTERS
void	Core::addPage(Page& newPage) {
    _pages.push_back(newPage);
}

//?FUNCTIONS
void Core::loop(){
    system("clear");
    
    //!PAGES DISPLAY WITH NUMBERS OF ELEMENTS
    for(size_t i = 0; i < _pages.size(); i++) {
        std::cout << ANSI_BG_BLUE << i << ANSI_RESET << ANSI_BG_CYAN << " " <<_pages[i].name() << ANSI_RESET << ANSI_BG_YELLOW << " " << _pages[i].description() << ANSI_RESET << " ";
        for (size_t y = 0; y < _pages[i].elements().size(); y++)
            std::cout << ANSI_BG_GREEN << " " << ANSI_RESET << " ";
        std::cout << "/" << _pages[i].elements().size() << "\n";
    }
    
    if (_pages.empty()) {
        std::string error = std::string(ANSI_BG_RED) + "NO PAGES LOADED IN CORE" + std::string(ANSI_RESET);
        throw(std::runtime_error(error));
    }
    while (_window.isOpen()) {
        while (_window.pollEvent(_event)) {
            if (_event.type == sf::Event::Closed)
                _window.close();
            else if (_event.type == sf::Event::Resized) {
                sf::FloatRect visibleArea(0, 0, _event.size.width, _event.size.height);
                _window.setView(sf::View(visibleArea));
            }
        }

        
        _window.clear(sf::Color::Black);
        displayPage();
        _window.display();  
        
        
        //! Ajout d'un délai pour éviter les freezes
        sf::sleep(sf::milliseconds(7)); // 144 FPS
        //sf::sleep(sf::milliseconds(16)); // 60 FPS
    }
}

void Core::displayPage() {
    std::vector<AElement *> &elements = _pages[_currentPage].elements();
    for(size_t i = 0; i < elements.size(); i++) {
        for(size_t y = 0; y < elements[i]->circles().size(); y++)
            _window.draw(elements[i]->circles()[y]);
        for(size_t y = 0; y < elements[i]->rectangles().size(); y++)
            _window.draw(elements[i]->rectangles()[y]);
        for(size_t y = 0; y < elements[i]->texts().size(); y++)
            _window.draw(elements[i]->texts()[y]);    
        for(size_t y = 0; y < elements[i]->lines().size(); y++)
            _window.draw(elements[i]->lines()[y]);
        elements[i]->handleEvent(_event);
    }
}