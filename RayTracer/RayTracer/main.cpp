#include <SFML/Graphics.hpp>
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"

Vector3 Colour(const Ray& _r, Hitable* _world)
{
	hitRecord rec;

	if (_world->Hit(_r, 0.0, 100000, rec))
	{
		return Vector3(rec.normal.x + 1, rec.normal.y + 1, rec.normal.z + 1) * 0.5;
	}
	else
	{
		Vector3 unitDir = _r.dir.normalised();
		float t = 0.5 * (unitDir.y + 1);
		return  Vector3(1, 1, 1) * (1 - t) + Vector3(0.5, 0.7, 1) * t;
	}
}

int main()
{
	int width = 200;
	int height = 100;

	sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracing works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	window.setFramerateLimit(30);
	sf::VertexArray pointmap(sf::Points, width * height);

	for (register int a = 0; a < width * height; a++) {
		pointmap[a].position = sf::Vector2f(a % width, (a/ width) % width);
		pointmap[a].color = sf::Color::Green;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		Vector3 lowerLeft(-2.0, 1.0, -1.0);
		Vector3 horizontal(4.0, 0.0, 0.0);
		Vector3 vertical(0.0, -2.0, 0.0);
		Vector3 origin(0.0, 0.0, 0.0);

		Hitable* list[2];
		list[0] = new Sphere(Vector3(0, 0, -1), 0.5);
		list[1] = new Sphere(Vector3(0, -100.5, -1), 100);

		Hitable* world = new HitableList(list, 2);

		for (int i = height - 1; i >= 0; i--)
		{
			for (int j = 0; j < width; j++)
			{
				float u = float(j) / width;
				float v = float(i) / height;

				Ray raymond(origin, lowerLeft + (horizontal * u) + (vertical * v));

				Vector3 p = raymond.PointAt(2.0);
				Vector3 col = Colour(raymond, world);

				int ir = int(255.99 * col.x);
				int ig = int(255.99 * col.y);
				int ib = int(255.99 * col.z);
				pointmap[i * width + j].color.r = ir;
				pointmap[i * width + j].color.g = ig;
				pointmap[i * width + j].color.b = ib;
			}
		}

		window.clear();
		window.draw(pointmap);
		//</debug>
		window.display();
	}
	/*Matrix4x4 test = Matrix4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 6, 3, 31, 1);
	test.Print();
	Matrix4x4 test2 = Matrix4x4(1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 3, 5, 6, 3, 31, 1);
	test2.Print();
	Matrix4x4 test3 = test + test2;
	test3.Print();*/

	return 0;
}