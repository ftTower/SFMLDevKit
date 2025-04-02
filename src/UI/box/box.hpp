
#pragma once

//#include "../utils/headers.hpp"
#include "../../elements/AElement.hpp"
#include <functional>

class AElement;

class Box : public AElement {

	private :
	
		std::function<void()> _callback;
		sf::Color			  _color;
	public :
	
		Box(sf::Vector2f boxSize, sf::Vector2f pos, sf::Color color);
		
		~Box();
		
		void handleEvent(const sf::Event& event);
};