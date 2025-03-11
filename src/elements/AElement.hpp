
#pragma once

#include "../core/core.hpp"

class AElement {
	
	protected :
		std::vector<sf::CircleShape> 	_circles;
		std::vector<sf::RectangleShape> _rectangles;
		std::vector<sf::Text> 			_texts;
		std::vector<sf::VertexArray> 	_lines;
		
	public 	  :
		//!CONSTRUCTORS
		AElement();
		
		virtual ~AElement();
		
		//?FUNCTIONS
		virtual void displayElement() = 0;
	
	
};