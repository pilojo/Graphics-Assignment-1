#include "Body.h"
#include <iostream>
Body::Body(Vector2f position) {
	this->position = position;
	for (int i = 0; i < 360; i += 90) {
		blades[i/90] = Blade(i, position);
	}
	
	roundTop.setRadius(50.0f);
	roundTop.setOrigin(Vector2f(50, 50));
	roundTop.setPosition(position);
	roundTop.setFillColor(Color::Blue);

	tower.setSize(Vector2f(towerWidth, towerHeight));
	tower.setOrigin(towerWidth / 2, 0);
	tower.setPosition(position);
	tower.setFillColor(Color::Blue);

	base.setSize(Vector2f(baseWidth, baseHeight));
	base.setOrigin(baseWidth / 2, 0);
	base.setPosition(Vector2f(position.x, position.y+towerHeight));
	base.setFillColor(Color::Blue);
}

void Body::render(RenderWindow *window) {
	window->draw(base);
	window->draw(roundTop);
	window->draw(tower);
	for (int i = 0; i < 4; i++) {
		blades[i].render(window);
	}
}

void Body::update() {
	for (int i = 0; i < 4; i++) {
		blades[i].update();
	}
}