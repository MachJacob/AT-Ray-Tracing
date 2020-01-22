#include <SFML/Graphics.hpp>
#include "Vector3.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();

		Vector3 d = Vector3(1, 2, 3);
		Vector3 g = Vector3(5, 4, 3);
		Vector3 h = d + g;
		Vector3 k = d - g;
		Vector3 j = d * 3;
		Vector3 l = d / 3;
		Vector3 m = d % g;
		float n = d.magnitude();
		float o = d * g;
		d.normalise();
		float n2 = d.magnitude();
		d += g;
	}

	return 0;
}