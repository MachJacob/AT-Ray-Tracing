#include <SFML/Graphics.hpp>
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Ray.h"

Vector3 Color(const Ray& _r)
{
	_r.Direction().normalise();
	Vector3 direction = _r.Direction();

	float t = 0.5 * (direction.y + 1.0);
	return Vector3(1, 1, 1) * (1.0f - t) + Vector3(0.5, 0.7, 1.0) * t;
}

bool hitSphere(Vector3& _centre, Vector3& _radius, const Ray& _ray)
{
	Vector3 oc = _ray.Origin() - _centre;
	float a = _ray.Direction().dot(_ray.Direction());
	float b = 2.0 * oc.dot(_ray.Direction());
	float c = oc.dot(oc) - _radius * _radius;
	float discriminant = b * b - 4 * a * c;
	return (discriminant > 0);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	/*Matrix4x4 test = Matrix4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 6, 3, 31, 1);
	test.Print();
	Matrix4x4 test2 = Matrix4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 6, 3, 31, 1);
	test2.Print();
	Matrix4x4 test3 = test + test2;
	test3.Print();*/

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