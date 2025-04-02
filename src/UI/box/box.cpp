
#include "../../utils/headers.hpp"

Box::Box(sf::Vector2f boxSize, sf::Vector2f pos, sf::Color color) {
    _color = color;
	_rectangles.emplace_back(boxSize);
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(pos);
}


Box::~Box() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void Box::handleEvent(const sf::Event& event) {
	(void)event;
}