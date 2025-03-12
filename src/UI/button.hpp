
#pragma once

#include "../core/core.hpp"
#include <functional>

class AElement;

class Button : public AElement {

	private :
	
		std::function<void()> _callback;
	public :
	
		Button(sf::Color color);
		
		~Button();
		
		void handleEvent(const sf::Event& event);
		
		void colorButton();
};