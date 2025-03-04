#include "./page.hpp"

Page::Page() : _name("no name"), _description("no description") {
	
}

Page::Page(std::string name) : _name(name), _description("no description") {
	
}

Page::Page(std::string name, std::string description) : \
	_name(name), _description(description)	{
	
}


Page::~Page() {
	
}
		
std::string Page::name() {
	return (_name);
}

std::string Page::description() {
	return (_description);
}