#include "./page.hpp"

//!CONSTRUCTORS
Page::Page() : _name("no name"), _description("no description") {
	
}

Page::Page(std::string name) : _name(name), _description("no description") {
	
}

Page::Page(std::string name, std::string description) : \
	_name(name), _description(description)	{
}

Page::~Page() {
}


//?FUNCTIONS
void	Page::displayElements() {
	for(size_t i = 0; i < _elements.size(); i++)
		_elements[i]->displayElement();
}

//?GETTERS
std::string &Page::name() {
	return (_name);
}

std::string &Page::description() {
	return (_description);
}

std::vector<AElement*> &Page::elements() {
	return (_elements);
}

//?SETTERS

void	Page::addElement(AElement *newElement) {
	if (!newElement)
		throw(std::runtime_error("FAILED TO ADD NULL ELEMENT"));
	_elements.push_back(newElement);
}
