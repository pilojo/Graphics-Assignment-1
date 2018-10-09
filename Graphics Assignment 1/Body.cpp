#include "Body.h"

Body::Body(){
    {   //Don't keep memory I don't need.
        int rotation = 360/numBlades;
        for(int i = rotation; i <= 360; i+=rotation){
            blades[i/rotation] = Blade(i);
        }
    }

    body.setFillColor(Color(32, 128, 255));
    body.setSize(Vector2f(500,20));
}