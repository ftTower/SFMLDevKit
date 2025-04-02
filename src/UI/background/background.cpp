
#include "../../utils/headers.hpp"

Background::Background(sf::Vector2f windowSize, sf::Color color) {
    _color = color;
	_rectangles.emplace_back(windowSize);
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(0, 0);
}


Background::~Background() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void Background::handleEvent(const sf::Event& event) {
	(void)event;
}