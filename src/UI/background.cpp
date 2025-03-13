
#include "../utils/headers.hpp"

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
	if (event.type == sf::Event::Resized) {
		_rectangles.emplace_back(sf::Vector2f(event.size.width, event.size.height));
		_rectangles.back().setFillColor(_color);
		
		//! A AMELIORER //devrait push un nv rectangle puis enlever le precedent
		//_rectangles.push_back(sf::RectangleShape(event.size.width, event.size.height));
	}
}