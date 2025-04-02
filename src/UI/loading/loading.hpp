
#pragma once

#include "../../elements/AElement.hpp"
#include <functional>

class AElement;

struct s_loadingCirle {
	sf::Vector2f	pos;
	unsigned int	colorGrade;
	sf::CircleShape circle;
};


class Loading : public AElement {

	private :
	
		std::function<void()> _callback;
		sf::Color			  _color;
		std::vector<s_loadingCirle> loadingCircles; 
	public :
	
		Loading(sf::Vector2f windowSize);
		
		~Loading();
		
		void handleEvent(const sf::Event& event);
};