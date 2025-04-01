
#include "../utils/headers.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

Loading::Loading(sf::Vector2f windowSize) {
    _rectangles.push_back(sf::RectangleShape(windowSize));
	_rectangles[0].setFillColor(sf::Color(128, 128, 128, 128));
	
	const int numCircles = 12; // Number of circles in the loading animation
	const float radius = 15.0f; // Radius of each circle
	const float centerX = windowSize.x / 2.0f;
	const float centerY = windowSize.y / 2.0f;
	const float circleRadius = 100.0f; // Radius of the circular path

	for (int i = 0; i < numCircles; ++i) {
		float angle = (2 * M_PI / numCircles) * i;
		sf::Vector2f position(
			centerX + circleRadius * std::cos(angle),
			centerY + circleRadius * std::sin(angle)
		);

		s_loadingCirle loadingCircle;
		loadingCircle.pos = position;
		loadingCircle.colorGrade = i * (255 / numCircles);
		loadingCircle.circle = sf::CircleShape(radius);
		loadingCircle.circle.setFillColor(sf::Color(255, 255, 255, loadingCircle.colorGrade));
		loadingCircle.circle.setPosition(position - sf::Vector2f(radius, radius));

		loadingCircles.push_back(loadingCircle);
		_circles.push_back(loadingCircle.circle);
	}
}


Loading::~Loading() {
	
}

//void Button::displayElement() {
//	std::cout << "mon button" << std::endl;
//}

void Loading::handleEvent(const sf::Event& event) {
	(void)event;
	for (auto& loadingCircle : loadingCircles) {
		loadingCircle.colorGrade = (loadingCircle.colorGrade + 5) % 256;
		sf::Color currentColor = loadingCircle.circle.getFillColor();
		loadingCircle.circle.setFillColor(sf::Color(currentColor.r, currentColor.g, currentColor.b, loadingCircle.colorGrade));

		auto it = std::find_if(_circles.begin(), _circles.end(), [&](const sf::CircleShape& circle) {
			return circle.getPosition() == loadingCircle.circle.getPosition();
		});
		if (it != _circles.end()) {
			*it = loadingCircle.circle;
		}
	}
}