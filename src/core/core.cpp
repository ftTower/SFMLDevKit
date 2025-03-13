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
    _pages.push_back(&newPage);
}

//?FUNCTIONS
void Core::loop(){
    
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
            else if (_event.type == sf::Event::KeyPressed) {
                if (_event.key.code == sf::Keyboard::Num0) _currentPage = 0;
                else if (_event.key.code == sf::Keyboard::Num1 && _pages.size() > 1) _currentPage = 1;
                else if (_event.key.code == sf::Keyboard::Num2 && _pages.size() > 2) _currentPage = 2;
                else if (_event.key.code == sf::Keyboard::Num3 && _pages.size() > 3) _currentPage = 3;
                else if (_event.key.code == sf::Keyboard::Num4 && _pages.size() > 4) _currentPage = 4;
                else if (_event.key.code == sf::Keyboard::Num5 && _pages.size() > 5) _currentPage = 5;
                else if (_event.key.code == sf::Keyboard::Num6 && _pages.size() > 6) _currentPage = 6;
                else if (_event.key.code == sf::Keyboard::Num7 && _pages.size() > 7) _currentPage = 7;
                else if (_event.key.code == sf::Keyboard::Num8 && _pages.size() > 8) _currentPage = 8;
                else if (_event.key.code == sf::Keyboard::Num9 && _pages.size() > 9) _currentPage = 9;
            }
        }

        
        _window.clear(sf::Color::Black);
        displayPage();
        _window.display();  
        
        system("clear");
        //!PAGES DISPLAY WITH NUMBERS OF ELEMENTS
        for(size_t i = 0; i < _pages.size(); i++) {
            if (_currentPage == i)
                std::cout << ANSI_BG_GREEN << i << ANSI_RESET;
            else
                std::cout << ANSI_BG_BLUE << i << ANSI_RESET;
            
            std::cout << ANSI_BG_CYAN << " " <<_pages[i]->name() << ANSI_RESET << ANSI_BG_YELLOW << " " << _pages[i]->description() << ANSI_RESET << " ";
            for (size_t y = 0; y < _pages[i]->elements().size(); y++)
                std::cout << ANSI_BG_GREEN << " " << ANSI_RESET << " ";
            std::cout << "/" << _pages[i]->elements().size() << "\n";
        }
        
        
        //! Ajout d'un délai pour éviter les freezes
        sf::sleep(sf::milliseconds(7)); // 144 FPS
        //sf::sleep(sf::milliseconds(16)); // 60 FPS
    }
}

void Core::displayPage() {
    std::vector<AElement *> &elements = _pages[_currentPage]->elements();
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