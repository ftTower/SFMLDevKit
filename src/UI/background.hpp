
#pragma once

//#include "../utils/headers.hpp"
#include "../elements/AElement.hpp"
#include <functional>

class AElement;

class Background : public AElement {

	private :
	
		std::function<void()> _callback;
		sf::Color			  _color;
	public :
	
		Background(sf::Vector2f windowSize, sf::Color color);
		
		~Background();
		
		void handleEvent(const sf::Event& event);
};