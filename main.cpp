#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

int main()
{
	const int height = 800;
	const int width = 800;

	bool ballExist = false;

	sf::RenderWindow window(sf::VideoMode(height, width), "Bouncing ball");
	window.setFramerateLimit(60);

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
				// Create the ball
				ballExist = true;
			}
		}

		window.clear();
		
		if (ballExist) 
		{
			cout << "Ball exists" << endl;
		}

		window.display();
	}

	return 0;
}