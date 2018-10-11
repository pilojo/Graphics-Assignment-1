#include <iostream>
#include "Blade.h"
#include "Body.h"

Body::Body(Vector2f position, Texture *texture) {
	this->position = position;
	for (int i = 0; i < 360; i += 90) {
		blades[i/90] = Blade(i, position, texture);
	}
	
	roundTop.setRadius(50.0f);
	roundTop.setOrigin(Vector2f(50, 50));
	roundTop.setPosition(position);
	roundTop.setFillColor(Color(180, 0, 0));

	tower.setSize(Vector2f(towerWidth, towerHeight));
	tower.setOrigin(towerWidth / 2, 0);
	tower.setPosition(position);
	tower.setFillColor(Color(180, 0, 0));

	base.setSize(Vector2f(baseWidth, baseHeight));
	base.setOrigin(baseWidth / 2, 0);
	base.setPosition(Vector2f(position.x, position.y+towerHeight));
	base.setFillColor(Color(180, 0, 0));
	initPin();
	activePin = true;
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

void Body::update(void) {
	for (int i = 0; i < 4; i++) {
		blades[i].update();
	}
	if (activePin) {
		pin.rotate(1);
	}
}

void Body::initPin(void) {
	pin.setPointCount(8);
	pin.setFillColor(Color::Black);
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

void Body::enable(void) {
	for (int i = 0; i < 4; i++) {
		blades[i].enable();
	}
	activePin = true;
}

void Body::disable(void) {
	for (int i = 0; i < 4; i++) {
		blades[i].disable();
	}
	activePin = false;
}