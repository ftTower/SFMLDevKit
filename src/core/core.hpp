
#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "../page/page.hpp"

class Page;
class Core {
	
	private :
		sf::RenderWindow _window;
		
		std::vector<Page> _pages;
		size_t			  _currentPage;
	
	public :
		//!CONSTRUCTORS
		Core(unsigned int W, unsigned int H, std::string appName);
		~Core();
		
		//?SETTERS
		void	addPage(const	Page& newPage);
		
		//?GETTERS
		const sf::RenderWindow &window() const;
		
		//?FUNCTIONS
		void	loop();
		void	displayPage();
};
