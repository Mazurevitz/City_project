#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

#define BLOCKSIZE 50



class BasicSquare
{
public:
	sf::RectangleShape basicSquare;

	BasicSquare() {
		basicSquare.setSize(sf::Vector2f(BLOCKSIZE, BLOCKSIZE));
		basicSquare.setOutlineColor(sf::Color::Magenta);
		basicSquare.setFillColor(sf::Color::Black);
		basicSquare.setOutlineThickness(3);
	}

	void setIt()
	{
		basicSquare.setPosition(sf::Vector2f(sf::Mouse::getPosition()));
	}

};

int main()
{
	BasicSquare square;
	//Komentarz
	//pa jak zmieniam

	sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");

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




		window.draw(square.basicSquare);
		window.display();
	}

	return 0;
}