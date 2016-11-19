#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define BLOCKSIZE 50

int main()
{

	// Komentarz testowy 

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
	sf::RectangleShape basicSquare;

	basicSquare.setSize(sf::Vector2f(BLOCKSIZE, BLOCKSIZE));
	basicSquare.setOutlineColor(sf::Color::Magenta);
	basicSquare.setFillColor(sf::Color::Black);
	basicSquare.setOutlineThickness(3);
	Vector2f halfOfBlock = basicSquare.getSize();

	Vector2i localMousePosition = Mouse::getPosition(window);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();


		basicSquare.setPosition(sf::Vector2f(sf::Mouse::getPosition(window)));


		window.draw(basicSquare);
		window.display();
	}

	return 0;
}