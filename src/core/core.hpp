
#pragma once

#include <SFML/Graphics.hpp>

class Core {
	
	private :
		sf::RenderWindow _window;
		
	
	
	public :
		//!CONSTRUCTORS
		Core(unsigned int W, unsigned int H, std::string appName);
		~Core();
		
		//?FUNCTIONS
		void	loop();
		
		//?GETTERS
		const sf::RenderWindow &window() const;
};
