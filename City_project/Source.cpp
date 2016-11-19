#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;


class GeneratePanel
{
public:
	RectangleShape rectangle;
	GeneratePanel() {
		
		RectangleShape rectangle(Vector2f(0, 0));
		rectangle.setSize(Vector2f(250, 600));
		rectangle.setPosition(Vector2f(0, 0));
		rectangle.setFillColor(Color::Green);

	}
private:
	
};

int main()
{
	
	RenderWindow window(sf::VideoMode(1320, 600), "SFML works!");
	
	GeneratePanel panel;
	
	while (window.isOpen()) {

		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}

		window.clear();

		window.draw(panel.rectangle);
		window.display();
	}

	

	return 0;
}