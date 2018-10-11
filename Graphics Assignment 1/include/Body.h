#pragma once
#include <SFML/Graphics.hpp>
#include "Blade.h"

constexpr unsigned short towerHeight = 300;
constexpr unsigned short towerWidth = 100;
constexpr unsigned short baseHeight = 75;
constexpr unsigned short baseWidth = 150;


using namespace sf;
class Body {
private:
	RectangleShape base;
	RectangleShape tower;
	CircleShape roundTop;
	Blade blades[4];
	Vector2f position;
	ConvexShape pin;
	int x, y;
	bool activePin;
public:
	Body() = default;
	Body(Vector2f, Texture*);
	void render(RenderWindow*);
	void update(void);
	void initPin(void);
	void enable(void);
	void disable(void);
};