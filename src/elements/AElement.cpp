#include "../utils/headers.hpp"

AElement::AElement() {
	
}
		
AElement::~AElement() {
	
}

//?GETTERS

const std::vector<sf::CircleShape> 	&AElement::circles() const{
	return (_circles);
}

const std::vector<sf::RectangleShape> &AElement::rectangles() const{
	return (_rectangles);
}

const std::vector<sf::Text> 			&AElement::texts() const{
	return (_texts);
}

const std::vector<sf::VertexArray> 	&AElement::lines() const{
	return (_lines);
}

const sf::RectangleShape				&AElement::hitbox() const {
	return (_hitbox);
}


//?SETTERS

void							AElement::addCircle(sf::CircleShape &Circle) {
	_circles.push_back(Circle);
}

void							AElement::addRectangle(sf::RectangleShape &Rectangle) {
	_rectangles.push_back(Rectangle);
}

void							AElement::addText(sf::Text &Text) {
	_texts.push_back(Text);
}

void							AElement::addLine(sf::VertexArray &Line) {
	_lines.push_back(Line);
}