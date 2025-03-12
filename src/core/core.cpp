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
void	Core::addPage(Page& newPage) {
    _pages.push_back(newPage);
}

//?FUNCTIONS
void Core::loop(){
    system("clear");
	
    if (_pages.empty())
        throw(std::runtime_error("NO PAGES LOADED IN CORE"));
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
        sf::sleep(sf::milliseconds(16)); // Permet de voir l'affichage
    
    }
}

void    Core::displayPage() {
        std::vector<AElement *> &elements = _pages[_currentPage].elements();

        std::cout << "Elements: " << elements.size() << " objects\n";
        for(size_t i = 0; i < elements.size(); i++) {
            std::cout << "Element " << i << " contains:\n";
            std::cout << "  Circles: " << elements[i]->circles().size() << "\n";
            std::cout << "  Rectangles: " << elements[i]->rectangles().size() << "\n";
            std::cout << "  Texts: " << elements[i]->texts().size() << "\n";
            std::cout << "  Lines: " << elements[i]->lines().size() << "\n";
        }
        for(size_t i = 0; i < elements.size(); i++) {
            for(size_t y = 0; y < elements[i]->circles().size(); y++)
                _window.draw(elements[i]->circles()[y]);
            for(size_t y = 0; y < elements[i]->rectangles().size(); y++) {
                _window.draw(elements[i]->rectangles()[y]);
                std::cout << "Rectangle !\n";
            }
            for(size_t y = 0; y < elements[i]->texts().size(); y++)
                _window.draw(elements[i]->texts()[y]);    
            for(size_t y = 0; y < elements[i]->lines().size(); y++)
                _window.draw(elements[i]->lines()[y]);
            std::cout << "CIIICICIICC\n";
        }
}