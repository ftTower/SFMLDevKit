
#pragma once

//#include "../utils/headers.hpp"
#include "../elements/AElement.hpp"
#include <functional>

class AElement;

class Button : public AElement {

	private :
	
		std::function<void()> _callback;
		bool				  _pressed;
		sf::Color			  _color;
		
	public :
	
		Button(sf::Color color, sf::Vector2f pos, sf::Vector2f size, float borderRadius, const std::string& text, const sf::Font& font, unsigned int characterSize);
		
		~Button();
		
		void handleEvent(const sf::Event& event);
		
		void colorButton(sf::Color primary);
};