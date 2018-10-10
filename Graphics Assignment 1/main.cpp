#include <SFML/Graphics.hpp>
#include "Body.h"

using namespace sf;





int main() {
	RenderWindow window(VideoMode(1024, 780), "Windmills");
	Event e;
	Body body(Vector2f(1024 / 2, 780 / 3));
	Body body2(Vector2f(1024 - 200, 780 / 3));
	Body body3(Vector2f(200, 780 / 3));
	window.setFramerateLimit(60);
	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
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