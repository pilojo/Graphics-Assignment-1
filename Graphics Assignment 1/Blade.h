#pragma once
#include <SFML/Graphics.hpp>

constexpr unsigned short BLADE_WIDTH = 50;
constexpr unsigned short BLADE_HEIGHT = 250;
constexpr unsigned short PIN_OFFSET = 20;


using namespace sf;
class Blade {
private:
	RectangleShape blade;
	float speed;
	int direction;
	bool active;
public:
	Blade();
	void render(RenderWindow*);
	void update(void);
	void disable(void);
	void changeDirection(void);
	void changeSpeed(Vector2f);
	void enable(void);
};