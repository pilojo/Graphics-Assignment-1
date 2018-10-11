#include "Blade.h"
Blade::Blade(int rotation, Vector2f position, Texture *texture){
	
	blade.setOrigin(Vector2f(0, BLADE_HEIGHT+PIN_OFFSET));
	blade.setPosition(position);
	blade.setScale(Vector2f(0.5, 0.5));
	speed = 1.0f;
	direction = 1;
	active = true;
	blade.setRotation(rotation);
	blade.setTexture(*texture);
	blade.setTextureRect(IntRect(0, 0, BLADE_WIDTH, BLADE_HEIGHT));
}

void Blade::render(RenderWindow *window) {
	window->draw(blade);
}

void Blade::update(void) {
	if (active) {
		blade.rotate(speed*direction);
	}
}

void Blade::disable(void) {
	active = false;
}

void Blade::enable(void) {
	active = true;
}

void Blade::changeDirection(void) {
	direction = -direction;
}

void Blade::changeSpeed(Vector2f mousePos) {
	speed = 3*(mousePos.x/SCREEN_WIDTH);
}