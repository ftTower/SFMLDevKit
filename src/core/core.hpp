#pragma once

class AElement;
class Button;
class Page;
class Core {
	
	private :
		sf::RenderWindow 	_window;
		sf::Event		 	_event;
		
		std::vector<Page *> _pages;
		size_t			 	_currentPage;
	
	public :
		//!CONSTRUCTORS
		Core(unsigned int W, unsigned int H, std::string appName);
		~Core();
		
		//?SETTERS
		void	addPage(Page& newPage);
		
		//?GETTERS
		const sf::RenderWindow &window() const;
		
		//?FUNCTIONS
		void	loop();
		void	displayPage();
};
