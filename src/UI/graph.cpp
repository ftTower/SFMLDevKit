
#include "../utils/headers.hpp"

Graph::Graph() {
    _rectangles.emplace_back(sf::Vector2f(100, 100));
	_rectangles.back().setFillColor(sf::Color::Red);
	_rectangles.back().setPosition(0, 0);
}


Graph::~Graph() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void Graph::handleEvent(const sf::Event& event) {
	(void)event;
}