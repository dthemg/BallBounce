#include <Ball.h>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const float S = 5.f; // Window scaling
	const float speedLossFactor = 0.70;
	const int height = 800.f;
	const int width = 800.f;
	const float G = 9.81/S;
	float radius = 30.f;

	float initX = 0.f;
	float initY = 0.f;

	bool ballExist = false;
	bool firstClick = false;

	sf::RenderWindow window(sf::VideoMode(height, width), "Bouncing ball");
	window.setFramerateLimit(60);
	Ball ball(radius, 200.f, 200.f);
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
				
			if (!firstClick && event.type == sf::Event::MouseButtonPressed) {
				firstClick = true;
				sf::Vector2f initPosition = sf::Vector2f(sf::Mouse::getPosition(window));
				initX = initPosition.x;
				initY = initPosition.y;
			} else if (firstClick && event.type == sf::Event::MouseButtonPressed) {
				sf::Vector2f localPosition = sf::Vector2f(sf::Mouse::getPosition(window));
				ball.x = localPosition.x;
				ball.y = localPosition.y;
				ball.vx = (localPosition.x - initX)/S;
				ball.vy = (localPosition.y - initY)/S;

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
				ball.vy = -ball.vy*speedLossFactor;
				ball.y -= 2 * (ball.y - (height - radius));
			}
			// Collision roof
			else if (ball.y < radius) {
				ball.vy = -ball.vy*speedLossFactor;
				ball.y -= 2 * (ball.y - radius);//   -ball.y;
			}
			// Collision left wall
			if (ball.x < radius) {
				ball.vx = -ball.vx*speedLossFactor;
				ball.x -= 2 * (ball.x - radius);
			}
			// Collision right wall
			else if (ball.x > width - radius) {
				ball.vx = -ball.vx*speedLossFactor;
				ball.x -= 2*(ball.x - (width - radius));
			}
			

			ball.draw(window);
		}

		window.display();
	}

	return 0;
}