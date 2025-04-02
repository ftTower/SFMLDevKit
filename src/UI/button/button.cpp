//#include "../elements/AElement.hpp"
//#include "../UI/button.hpp"

#include "../../utils/headers.hpp"

void	Button::colorButton(sf::Color primary) {
	
	//sf::Color newColor = primary;
	
	//if (!_rectangles.empty() && _rectangles[0].getFillColor() == primary)
	//	newColor = sf::Color(192,192,192);
		
	for (auto& circle : _circles)
		circle.setFillColor(primary);
	for (auto& rectangle : _rectangles)
		rectangle.setFillColor(primary);
	
		
}

Button::Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, float borderRadius, const std::string& text, const sf::Font& font, unsigned int characterSize) {
	_pageName = "";
	_color = color;
	_rectangles.emplace_back(sf::Vector2f(size.x - 2 * borderRadius, size.y));
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(pos.x + borderRadius, pos.y);

	_rectangles.emplace_back(sf::Vector2f(size.x, size.y - 2 * borderRadius));
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(pos.x, pos.y + borderRadius);

	for (int i = 0; i < 4; ++i) {
		_circles.emplace_back(borderRadius);
		_circles.back().setFillColor(_color);
	}

	_circles[0].setPosition(pos.x, pos.y);
	_circles[1].setPosition(pos.x + size.x - 2 * borderRadius, pos.y);
	_circles[2].setPosition(pos.x, pos.y + size.y - 2 * borderRadius);
	_circles[3].setPosition(pos.x + size.x - 2 * borderRadius, pos.y + size.y - 2 * borderRadius);

	_hitbox.setSize(size);
	_hitbox.setPosition(pos);
	_hitbox.setFillColor(sf::Color(0, 0, 0, 100));

	sf::Text textElement;
	textElement.setFont(font);
	textElement.setString(text);
	textElement.setCharacterSize(characterSize);
	textElement.setFillColor(sf::Color::Black);
	sf::FloatRect textBounds = textElement.getLocalBounds();
	textElement.setPosition(pos.x + (size.x - textBounds.width) / 2, pos.y + (size.y - textBounds.height) / 2 - textBounds.top);
	_texts.push_back(textElement);

	_hover = std::bind(&Button::colorButton, this, _color);
	_pressed = false;
}

Button::Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, float borderRadius, const std::string& text, const sf::Font& font, unsigned int characterSize, std::string pageName) {
	_pageName = pageName;
	_color = color;
	_rectangles.emplace_back(sf::Vector2f(size.x - 2 * borderRadius, size.y));
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(pos.x + borderRadius, pos.y);

	_rectangles.emplace_back(sf::Vector2f(size.x, size.y - 2 * borderRadius));
	_rectangles.back().setFillColor(_color);
	_rectangles.back().setPosition(pos.x, pos.y + borderRadius);

	for (int i = 0; i < 4; ++i) {
		_circles.emplace_back(borderRadius);
		_circles.back().setFillColor(_color);
	}

	_circles[0].setPosition(pos.x, pos.y);
	_circles[1].setPosition(pos.x + size.x - 2 * borderRadius, pos.y);
	_circles[2].setPosition(pos.x, pos.y + size.y - 2 * borderRadius);
	_circles[3].setPosition(pos.x + size.x - 2 * borderRadius, pos.y + size.y - 2 * borderRadius);

	_hitbox.setSize(size);
	_hitbox.setPosition(pos);
	_hitbox.setFillColor(sf::Color(0, 0, 0, 100));

	sf::Text textElement;
	textElement.setFont(font);
	textElement.setString(text);
	textElement.setCharacterSize(characterSize);
	textElement.setFillColor(sf::Color::Black);
	sf::FloatRect textBounds = textElement.getLocalBounds();
	textElement.setPosition(pos.x + (size.x - textBounds.width) / 2, pos.y + (size.y - textBounds.height) / 2 - textBounds.top);
	_texts.push_back(textElement);

	_hover = std::bind(&Button::colorButton, this, _color);
	_pressed = false;
	
	
}


//sf::Color(128,128,128), 
Button::~Button() {
	
}

void Button::handleEvent(const sf::Event& event) {
	if (event.type == sf::Event::MouseMoved) {
		sf::Vector2f mousePos(event.mouseMove.x, event.mouseMove.y);
		if (_hitbox.getGlobalBounds().contains(mousePos)) {
			if (_hover) {
				_hover = std::bind(&Button::colorButton, this, sf::Color(192,192,192));
				_hover();
			}
		}
		else {
			if (_hover) {
				_hover = std::bind(&Button::colorButton, this, _color);
				_hover();				
			}
		}
	}
	
	if (event.type == sf::Event::MouseButtonPressed) {
		_pressed = true;
	}
	if (event.type == sf::Event::MouseButtonReleased && _pressed) {
		_pressed = false;
	}
	
	
}
