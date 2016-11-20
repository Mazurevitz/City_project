#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

using namespace std;
using namespace sf;





class GeneratePanel
{
public:
	RectangleShape rectangle;
	RectangleShape house_1;
	GeneratePanel() {}
	void getLeftMenu();
	void getHouse_1();


private:

};

int main()
{

	RenderWindow window(sf::VideoMode(1320, 600), "SFML works!");
	GeneratePanel menu;

	RectangleShape highlightSquare;

	highlightSquare.setFillColor(Color::Transparent);
	highlightSquare.setOutlineColor(Color::Magenta);
	highlightSquare.setOutlineThickness(3);
	highlightSquare.setSize(Vector2f(50,50));

	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		//set values for LeftPanel and House_1
		menu.getLeftMenu();
		menu.getHouse_1();

		highlightSquare.setPosition(Vector2f(Mouse::getPosition(window)));
		Vector2f highlightPostion = highlightSquare.getPosition();

		cout << "Highlight X: " << highlightPostion.x << "| Y: " << highlightPostion.y << endl;

		window.draw(menu.rectangle);
		window.draw(menu.house_1);
		window.draw(highlightSquare);

		window.display();
		window.clear();
	}



	return 0;
}

void GeneratePanel::getLeftMenu()
{
	rectangle.setSize(Vector2f(250, 600));
	rectangle.setPosition(Vector2f(0, 0));
	rectangle.setFillColor(Color::Green);
}
void GeneratePanel::getHouse_1()
{
	house_1.setSize(Vector2f(50, 50));
	house_1.setPosition(Vector2f(15, 15));
	house_1.setFillColor(Color::Red);
}

