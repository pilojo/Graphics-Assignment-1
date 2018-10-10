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
	initPin();
}

void Body::render(RenderWindow *window) {
	window->draw(base);
	window->draw(roundTop);
	window->draw(tower);
	for (int i = 0; i < 4; i++) {
		blades[i].render(window);
	}
	window->draw(pin);
}

void Body::update() {
	for (int i = 0; i < 4; i++) {
		blades[i].update();
	}
	pin.rotate(1);
}

void Body::initPin() {
	pin.setPointCount(8);
	pin.setFillColor(Color::White);
	pin.setPoint(0, Vector2f(8, 0));
	pin.setPoint(1, Vector2f(13, 7));
	pin.setPoint(2, Vector2f(20, 8));
	pin.setPoint(3, Vector2f(13, 13));
	pin.setPoint(4, Vector2f(12, 20));
	pin.setPoint(5, Vector2f(7, 13));
	pin.setPoint(6, Vector2f(0, 12));
	pin.setPoint(7, Vector2f(7, 7));
	pin.setOrigin(10, 10);
	pin.setPosition(position);
	pin.setRotation(13);
}