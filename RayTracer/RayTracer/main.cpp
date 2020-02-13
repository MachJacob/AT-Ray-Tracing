#include <SFML/Graphics.hpp>
#include "Vector3.h"
#include "Matrix4x4.h"
#include "Ray.h"
#include "Sphere.h"
#include "HitableList.h"
#include "Camera.h"
#include "Random.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Dialectic.h"
#include <iostream>
#include <cfloat>

Vector3 Colour(const Ray& _r, Hitable* _world, int depth)
{
	hitRecord rec;

	if (_world->Hit(_r, 0.001, FLT_MAX, rec))
	{
		Ray scattered;
		Vector3 attenuation;
		if (depth < 50 && rec.mat->Scatter(_r, rec, attenuation, scattered))
		{
			Vector3 col = Colour(scattered, _world, depth + 1);
			Vector3 ret = Vector3(col.x * attenuation.x, col.y * attenuation.y, col.z * attenuation.z);
			return ret;
		}
		else
		{
			return Vector3(0, 0, 0);
		}
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
	int samples = 100;

	sf::RenderWindow window(sf::VideoMode(width, height), "Ray Tracing works!");

	window.setFramerateLimit(30);
	sf::Image image;
	image.create(width, height);
	sf::Texture tex;
	tex.loadFromImage(image);
	sf::Sprite sprite;
	Camera cam;

	Hitable* list[5];
	list[0] = new Sphere(Vector3(0, 0, -1), 0.5, new Lambertian(Vector3(0.1, 0.2, 0.5)));
	list[1] = new Sphere(Vector3(0, -100.5, -1), 100, new Lambertian(Vector3(0.8, 0.8, 0.0)));
	list[2] = new Sphere(Vector3(1, 0, -1), 0.5, new Metal(Vector3(0.8, 0.6, 0.2), 0.0));
	list[3] = new Sphere(Vector3(-1, 0, -1), 0.5, new Dialectic(1.5));
	list[3] = new Sphere(Vector3(-1, 0, -1), -0.45, new Dialectic(1.5));

	Hitable* world = new HitableList(list, 4);

	for (int i = height - 1; i >= 0; i--)
	{
		for (int j = 0; j < width; j++)
		{
			Vector3 col(0, 0, 0);
			for (int s = 0; s < samples; s++)
			{
				float u = float(j + RandomDouble()) / float(width);
				float v = float(i + RandomDouble()) / float(height);

				Ray raymond = cam.GetRay(u, v);

				Vector3 p = raymond.PointAt(2.0);
				col += Colour(raymond, world, 0);
			}
			col /= float(samples);
			col = Vector3(std::sqrt(col.x), std::sqrt(col.y), std::sqrt(col.z));

			int ir = int(255.99 * std::sqrt(col.x));
			int ig = int(255.99 * std::sqrt(col.y));
			int ib = int(255.99 * std::sqrt(col.z));
			image.setPixel(j, i, sf::Color(ir, ig, ib));
		}
		//std::cout << i << std::endl;
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event)) 
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		tex.update(image);
		sprite.setTexture(tex);
		window.draw(sprite);
		//window.draw(pointmap);
		//</debug>
		window.display();
	}

	return 0;
}