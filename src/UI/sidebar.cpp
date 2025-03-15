
#include "../utils/headers.hpp"

SideBar::SideBar(sf::Vector2f SideBarSize, sf::Color color) {
    _sideBarSize = SideBarSize;
	_color = color;
	//!SIDEBAR
	_rectangles.emplace_back(SideBarSize);
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(0,0);
	//!HITBOX
	_hitbox = sf::RectangleShape(SideBarSize);
	_hitbox.setPosition(0,0);
}


SideBar::~SideBar() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void SideBar::handleEvent(const sf::Event& event) {
	sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
	if (event.type == sf::Event::MouseMoved) {
		sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
		if (_hitbox.getGlobalBounds().contains(mousePos)) {
			_rectangles.emplace_back(sf::Vector2f(_sideBarSize.x + 100, _sideBarSize.y));
			_rectangles.back().setFillColor(_color);
		} else if(_rectangles.size() > 1) {
			_rectangles.pop_back();
		}
		
	}
	
	
	//if (event.type == sf::Event::Resized) {
	//	_rectangles.emplace_back(sf::Vector2f(_rectangles.back().getSize().x , event.size.height));
	//	_rectangles.back().setFillColor(_color);
	//}
}