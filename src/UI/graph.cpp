
#include "../utils/headers.hpp"

Graph::Graph(sf::Vector2f size, sf::Vector2f pos) {
	_rectangles.emplace_back(sf::Vector2f(size.x, size.y));
	_rectangles.back().setFillColor(sf::Color::Black);
	_rectangles.back().setPosition(pos);

	_rectangles.emplace_back(sf::Vector2f(size.x - 20, size.y - 20));
	_rectangles.back().setFillColor(sf::Color::White);
	_rectangles.back().setPosition(pos.x + 10, pos.y + 10);
	
	for (size_t i = 0; i < size.x; i += 10) {
		_lines.push_back(sf::VertexArray(sf::Lines, 2));
		_lines.back()[0].position = sf::Vector2f(pos.x + i, pos.y);
		_lines.back()[1].position = sf::Vector2f(pos.x + i, pos.y + size.y);
		_lines.back()[0].color = sf::Color::Black;
		_lines.back()[1].color = sf::Color::Black;
	}

	for (size_t i = 0; i < size.y; i += 10) {
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