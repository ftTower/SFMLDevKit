
#pragma once

//#include "../utils/headers.hpp"

class AElement;

class Graph : public AElement {

	private :
	
		std::function<void()> _callback;
		
	public :
	
		Graph(sf::Vector2f size, sf::Vector2f pos);
		~Graph();
		
		void handleEvent(const sf::Event& event);
		
};