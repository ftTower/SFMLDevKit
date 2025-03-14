
#include "../utils/headers.hpp"

Graph::Graph(sf::Vector2f size, sf::Vector2f pos) {
	_rectangles.emplace_back(sf::Vector2f(size.x, size.y));
	_rectangles.back().setFillColor(sf::Color::Black);
	_rectangles.back().setPosition(pos);

	_rectangles.emplace_back(sf::Vector2f(size.x - 70, size.y - 20));
	_rectangles.back().setFillColor(sf::Color::White);
	_rectangles.back().setPosition(pos.x + 60, pos.y + 10);
	
	//! GRID
	for (size_t i = 0; i < size.x; i += size.x / 10) {
		if (i + size.x / 10 >= size.x) break;
		_lines.push_back(sf::VertexArray(sf::Lines, 2));
		_lines.back()[0].position = sf::Vector2f(pos.x + i + 60, pos.y);
		_lines.back()[1].position = sf::Vector2f(pos.x + i + 60, pos.y + size.y);
		_lines.back()[0].color = sf::Color::Black;
		_lines.back()[1].color = sf::Color::Black;
	}

	for (size_t i = 0; i < size.y; i += size.y / 10) {
		if (i + size.y / 10 >= size.y) break;
		_lines.push_back(sf::VertexArray(sf::Lines, 2));
		_lines.back()[0].position = sf::Vector2f(pos.x, pos.y + i);
		_lines.back()[1].position = sf::Vector2f(pos.x + size.x, pos.y + i);
		_lines.back()[0].color = sf::Color::Black;
		_lines.back()[1].color = sf::Color::Black;
	}
}


Graph::~Graph() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void Graph::handleEvent(const sf::Event& event) {
	(void)event;
}