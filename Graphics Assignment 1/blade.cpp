#include "Blade.h"

Blade::Blade(){
	blade.setOrigin(Vector2f(0, BLADE_HEIGHT+PIN_OFFSET));
	blade.setScale(Vector2f(0.5, 0.5));
}

Blade::Blade(int rotation, Vector2f position, Texture *texture) : Blade(){

	//blade.setPosition(position);
	blade.setRotation(rotation);
	blade.setTexture(*texture);
	blade.setTextureRect(IntRect(0, 0, BLADE_WIDTH, BLADE_HEIGHT));
}

void Blade::render(RenderWindow *window, Transform transform) {
	transform.translate(10,10);
	window->draw(blade, transform);
}