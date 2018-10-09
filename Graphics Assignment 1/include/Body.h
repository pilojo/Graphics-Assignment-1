#pragma once
#include <SFML/Graphics.hpp>
#include "Blade.h"

constexpr unsigned short numBlades = 4;

using namespace sf;
class Body {
private:
    RectangleShape body;
    Blade blades[numBlades];
public:
    Body();

};