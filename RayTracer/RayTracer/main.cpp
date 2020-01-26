#include <SFML/Graphics.hpp>
#include "Vector3.h"
#include "Matrix4x4.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	Matrix4x4 test = Matrix4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 6, 3, 31, 1);
	test.Print();
	Matrix4x4 test2 = Matrix4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 6, 3, 31, 1);
	test2.Print();
	Matrix4x4 test3 = test + test2;
	test3.Print();

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
	}

	return 0;
}