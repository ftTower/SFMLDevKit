#pragma once

#include "../core/core.hpp"

class Page {
	
	private :
		std::string _name;
		std::string _description;
	
	public :
		//!CONSTRUCTORS
		Page(); 
		Page(std::string name);
		Page(std::string name, std::string description);
		~Page();
		
		//?FUNCTIONS
		
		//?GETTERS
		std::string name();
		std::string description();
		
};