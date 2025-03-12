#include "./AElement.hpp"
#include "../elements/button.hpp"

Button::Button(sf::Color color) {
    _rectangles.emplace_back(sf::Vector2f(100, 100));
    _rectangles.back().setFillColor(color);
    _rectangles.back().setPosition(350, 400); // Centre de la fenêtre 700x800
}


Button::~Button() {
	
}

void Button::displayElement() {
	std::cout << "mon button" << std::endl;
}
