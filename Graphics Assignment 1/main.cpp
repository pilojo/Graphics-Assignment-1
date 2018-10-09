#include <SFML/Graphics.hpp>

using namespace sf;

int main() {
	RenderWindow window(VideoMode(1024, 780), "Windmills");


	Event e;
	while (window.isOpen()) {
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				window.close();
				break;
			}
		}
		window.clear();

		window.display();
	}
}