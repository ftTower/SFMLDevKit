#include "../elements/AElement.hpp"
#include "../UI/button.hpp"

void	Button::colorButton() {
	
	sf::Color newColor = sf::Color::Red;
	
	if (!_circles.empty() && _circles[0].getFillColor() == sf::Color::Red)
		newColor = sf::Color::Black;
		
	for (auto& circle : _circles)
		circle.setFillColor(newColor);
	for (auto& rectangle : _rectangles)
		rectangle.setFillColor(newColor);
	
		
}

Button::Button(sf::Color color) {
    _rectangles.emplace_back(sf::Vector2f(100, 100));
    _rectangles.back().setFillColor(color);
	_rectangles.back().setPosition(350, 400);
	_circles.emplace_back(50.f);
	_circles.back().setFillColor(color);
	_circles.back().setPosition(500, 500);
	
	_callback = std::bind(&Button::colorButton, this);
}


Button::~Button() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void Button::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::MouseButtonPressed) {
		sf::Vector2f mousePos(event.mouseButton.x, event.mouseButton.y);
		
		auto checkAndTriggerCallback = [&](const auto& shape) {
			if (shape.getGlobalBounds().contains(mousePos) && _callback) {
				_callback();
			}
		};
		for (const auto& rectangle : _rectangles) {
			checkAndTriggerCallback(rectangle);
		}
		for (const auto& circle : _circles) {
			checkAndTriggerCallback(circle);
		}
	}
}
