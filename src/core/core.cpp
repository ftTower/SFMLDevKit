#include "./core.hpp"

Core::Core(unsigned int W, unsigned int H, std::string appName) : _window(sf::VideoMode(W, H), appName) {
	
}


Core::~Core() {
	
}

void Core::loop(){
	while (_window.isOpen()) {
        sf::Event event;
        while (_window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
			_window.close();
        }

        // Effacer l'écran
        _window.clear(sf::Color::Black);

        // Afficher le rendu
        _window.display();
    }
}

void	Core::addPage(const	Page& newPage) {
    _pages.push_back(newPage);
}
