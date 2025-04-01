
#pragma once

//#include "../core/core.hpp"
//#include "../utils/headers.hpp"

class AElement {
	protected:
		std::vector<sf::CircleShape> 	_circles;
		std::vector<sf::RectangleShape> _rectangles;
		std::vector<sf::Text> 			_texts;
		std::vector<sf::VertexArray> 	_lines;
		sf::RectangleShape				_hitbox;
	public:
		//!CONSTRUCTORS
					AElement();
		
		virtual 	~AElement();
		
		//?FUNCTIONS
		virtual void handleEvent(const sf::Event& event) = 0;
	
		//?GETTERS
		const std::vector<sf::CircleShape> 		&circles() const;
		const std::vector<sf::RectangleShape> 	&rectangles() const;
		const std::vector<sf::Text> 			&texts() const;
		const std::vector<sf::VertexArray> 		&lines() const;
		const sf::RectangleShape				&hitbox() const;
		
		//?SETTERS
		void							addCircle(sf::CircleShape  &Circle);
		void							addRectangle(sf::RectangleShape &Rectangle);
		void							addText(sf::Text &Text);
		void							addLine(sf::VertexArray &Line);
		
		
};