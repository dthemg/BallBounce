#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Ball {
public:
	float x = 0;
	float y = 0;
	float vx = 0;
	float vy = 0;
	float radius = 100;
	float M = 1; // 100 kg

	Ball() {
		// Default constructor
	}

	Ball(float radius, float startX, float startY) {
		radius = radius;
		x = startX;
		y = startY;
		
	}

	void draw(sf::RenderWindow& window) {
		sf::CircleShape ball(radius, 100);
		ball.setOrigin(radius, radius);
		ball.setFillColor(sf::Color(100, 100, 250));
		ball.setPosition(x, y);
		window.draw(ball);
	}

	void moveBall(float Fx, float Fy) {
		vx += Fx / M;
		vy += Fy / M;
		x += vx;
		y += vy;
	}

//private:
};
