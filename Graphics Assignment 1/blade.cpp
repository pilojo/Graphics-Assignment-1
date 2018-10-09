#include "Blade.h"

Blade::Blade(void) {
	blade.setFillColor(Color::Red);
	blade.setSize(Vector2f(BLADE_WIDTH, BLADE_HEIGHT));
	blade.setOrigin(Vector2f(BLADE_WIDTH/2, BLADE_HEIGHT+PIN_OFFSET));

	speed = 1.0f;
	direction = 1;
	active = true;
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

}