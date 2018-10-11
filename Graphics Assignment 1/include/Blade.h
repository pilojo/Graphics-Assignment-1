#pragma once
#include <SFML/Graphics.hpp>

constexpr unsigned short BLADE_WIDTH = 50;
constexpr unsigned short BLADE_HEIGHT = 250;
constexpr unsigned short PIN_OFFSET = 20;
constexpr unsigned short SCREEN_WIDTH = 1024;

using namespace sf;
class Blade {
private:
	Sprite blade;
	float speed;
	int direction;
	bool active;
public:
	Blade() = default;
	Blade(int, Vector2f, Texture*);
	void render(RenderWindow*);
	void update(void);
	void disable(void);
	void changeDirection(void);
	void changeSpeed(Vector2f);
	void enable(void);
};