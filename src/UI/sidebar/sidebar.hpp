
#pragma once

//#include "../utils/headers.hpp"
#include "../../elements/AElement.hpp"
#include <functional>

class AElement;

class SideBar : public AElement {

	private :
	
		bool				  _mouseIn;
		std::function<void()> _callback;
		sf::Color			  _color;
		sf::Vector2f		  _sideBarSize;
		
	public :
	
		SideBar(sf::Vector2f SideBarSize, sf::Color color);
		
		~SideBar();
		
		void handleEvent(const sf::Event& event);
};