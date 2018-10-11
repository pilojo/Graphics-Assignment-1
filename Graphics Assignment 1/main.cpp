#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

#include "Body.h"

using namespace sf;





int main() {
	RenderWindow window(VideoMode(1024, 780), "Windmills");
	Event e;

	Texture texture;
	if (!texture.loadFromFile("Resources/windmill.png")) {
		std::cerr << "Could not load texture!" << std::endl;
		exit(-1);
	}
	Body body(Vector2f(1024 / 2, 780 / 3),&texture);
	Body body2(Vector2f(1024 - 200, 780 / 3), &texture);
	Body body3(Vector2f(200, 780 / 3), &texture);
	
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			switch (e.type) {
			case Event::Closed:
				window.close();
				break;
			case Event::KeyPressed:
				switch (e.key.code) {
				case Keyboard::Num1:
					body.disable();
					body2.disable();
					body3.enable();
					break;
				case Keyboard::Num2:
					body2.disable();
					body.enable();
					body3.disable();
					break;
				case Keyboard::Num3:
					body2.enable();
					body.disable();
					body3.disable();
					break;
				case Keyboard::Num4:
					body.enable();
					body2.enable();
					body3.enable();
					break;
				}
			case Event::MouseMoved:
				break;
			}
		}
		window.clear();
		body.render(&window);
		body2.render(&window);
		body3.render(&window);
		window.display();
		body.update();
		body2.update();
		body3.update();
	}
}