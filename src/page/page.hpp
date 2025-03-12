#pragma once

#include "../core/core.hpp"
#include "../elements/AElement.hpp"

class AElement;

class Page {
	
	private :
		//!DETAILS
		std::string _name;
		std::string _description;
	
		//?PAGE ELEMENT
		std::vector<AElement *> _elements;
		
	public :
		//!CONSTRUCTORS
		Page(); 
		Page(std::string name);
		Page(std::string name, std::string description);
		~Page();
		
		//?FUNCTIONS
		
		//?GETTERS
		std::string &name();
		std::string &description();
		std::vector<AElement*> &elements();
		
		//?SETTERS
		void	addElement(AElement *newElement);
};
