#include <Ball.h>
#include <SFML/Graphics.hpp>
#include <iostream>


using namespace std;

int main()
{
	const float S = 50.f; // Window scaling

	const int height = 800;
	const int width = 800;
	const float G = 9.81/S;
	float radius = 50.f;

	bool ballExist = false;

	sf::RenderWindow window(sf::VideoMode(height, width), "Bouncing ball");
	window.setFramerateLimit(60);
	Ball ball(50, 200, 200);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
				
			if (event.type == sf::Event::MouseButtonPressed)
			{
				sf::Vector2i localPosition = sf::Mouse::getPosition(window);
				ball.x = localPosition.x;
				ball.y = localPosition.y;
				ballExist = true;
			}
		}

		window.clear();
		
		if (ballExist) 
		{
			float Fy = G * ball.M; 
			float Fx = 0;
			ball.moveBall(Fx, Fy);

			// Collision floor, TODO - add mirroring of x, y points
			if (ball.y > height - radius) {
				ball.vy = -ball.vy;
				ball.y -= (ball.y + radius - height);
			}
			else if (ball.y < 0) {
				ball.vy = -ball.vy;
				ball.y = -ball.y;
			}

			ball.draw(window);
		}

		window.display();
	}

	return 0;
}