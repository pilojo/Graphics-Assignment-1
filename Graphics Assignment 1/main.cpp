#include <SFML/Graphics.hpp>
#include "Blade.h"

using namespace sf;

ConvexShape pin;

void initPin(){
	pin.setPointCount(8);
	pin.setFillColor(Color::White);
	pin.setPoint(0, Vector2f(8,0));
	pin.setPoint(1, Vector2f(13,7));
	pin.setPoint(2, Vector2f(20,8));
	pin.setPoint(3, Vector2f(13, 13));
	pin.setPoint(4, Vector2f(12, 20));
	pin.setPoint(5, Vector2f(7, 13));
	pin.setPoint(6, Vector2f(0, 12));
	pin.setPoint(7, Vector2f(7,7));
	pin.setOrigin(10, 10);
	pin.setPosition(1024/2-50/2, 780/3);
	pin.setRotation(13);
}

int main() {
	RenderWindow window(VideoMode(1024, 780), "Windmills");
	initPin();
	Blade blades[4] = {Blade(0), Blade(90), Blade(180), Blade(270)};
	Event e;
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();
		window.draw(pin);
		for(int i = 0; i < 4; i++){
			blades[i].render(&window);
		}
		window.display();
		for(int i = 0; i < 4; i++){
			blades[i].update();
		}
		pin.rotate(1);
	}
}