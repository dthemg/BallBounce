#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Ball {
public:
	float x = 0.f;
	float y = 0.f;
	float vx = 0.f;
	float vy = 0.f;
	float radius = 30.f;
	float M = 1.f; // 100 kg

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
