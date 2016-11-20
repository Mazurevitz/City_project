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
	RectangleShape house_1used;
	GeneratePanel() {}
	void getLeftMenu();
	void getHouse_1();
	void useHouse_1();

private:
	
};
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

void GeneratePanel::useHouse_1() {

		

		house_1used.setFillColor(Color::Black);
		house_1used.setOutlineColor(Color::Magenta);
		house_1used.setOutlineThickness(3);
		house_1used.setSize(Vector2f(50, 50));

		

}
class MyMouse {

public:
	MyMouse(const Window& _window, float mouse_width, float mouse_height) :
		window(_window)
	{
		//initialize box
		mouse_box.width = mouse_width;
		mouse_box.height = mouse_height;
	}

	Vector2i getPosition(const Window &relativeTo) {
		return Mouse::getPosition(relativeTo);
	}

	//WRAP THE REST OF sf::Mouse FUNCTIONS

	bool intersects(FloatRect& other_box) {

		//update before comparing
		mouse_box.left = Mouse::getPosition(window).x;
		mouse_box.top = Mouse::getPosition(window).y;

		return mouse_box.intersects(other_box);
	}

private:
	const Window& window;
	FloatRect mouse_box;
};


int main()
{
	
	RenderWindow window(sf::VideoMode(1320, 600), "SFML works!");
	GeneratePanel menu;
	MyMouse mouse(window, 16, 16);
	menu.getLeftMenu();
	menu.getHouse_1();

	

	
	
	while (window.isOpen()) {
		
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed) {
				window.close();
			}
		}
		//set values for LeftPanel and House_1
		
		window.draw(menu.rectangle);
		window.draw(menu.house_1);
		
		Vector2i mousePosition = Mouse::getPosition(window);


		if(mouse.intersects(menu.house_1.getGlobalBounds())) {
			menu.house_1.setFillColor(Color::White);
			
			if (event.type == Event::MouseButtonPressed && event.mouseButton.button == Mouse::Left)
			{
				
				menu.house_1used.setPosition(Vector2f(Mouse::getPosition(window)));
				Vector2f highlightPostion = menu.house_1used.getPosition();
				
			}
		}
		else {
			menu.house_1.setFillColor(Color::Red);
		}
		
		
		
		
		//cout << "Koordynaty" << mousePosition.x<<mousePosition.y;
		//int temp;
		
		window.display();
		
		//cin >> temp;
		window.clear();
		
	}

	

	return 0;
}



