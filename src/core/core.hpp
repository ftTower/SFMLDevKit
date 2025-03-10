
#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include "../page/page.hpp"

class Page;
class Core {
	
	private :
		sf::RenderWindow _window;
		std::vector<Page> _pages;
	
	
	public :
		//!CONSTRUCTORS
		Core(unsigned int W, unsigned int H, std::string appName);
		~Core();
		
		//?FUNCTIONS
		void	loop();
		
		void	addPage(const	Page& newPage);
		
		//?GETTERS
		const sf::RenderWindow &window() const;
};
