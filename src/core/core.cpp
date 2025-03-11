#include "./core.hpp"

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
void	Core::addPage(const	Page& newPage) {
    _pages.push_back(newPage);
}

//?FUNCTIONS
void Core::loop(){
	
    if (_pages.empty())
        throw(std::runtime_error("NO PAGES LOADED IN CORE"));
    system("clear");
    while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
			_window.close();
        }

        // Effacer l'écran
        _window.clear(sf::Color::Black);
        
        
        
        displayPage();
        
        // Afficher le rendu
        _window.display();
    
    }
}

void    Core::displayPage() {
    std::vector<AElement *>elements = _pages[_currentPage].elements();

    //for(size_t i = 0; i < elements.size(); i++) {
    //    for(size_t y = 0; y < elements[i].)
    //}
}