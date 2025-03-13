
#pragma once

//#include "../utils/headers.hpp"

class AElement;

class Graph : public AElement {

	private :
	
		std::function<void()> _callback;
	public :
	
		Graph();
		
		~Graph();
		
		void handleEvent(const sf::Event& event);
		
};