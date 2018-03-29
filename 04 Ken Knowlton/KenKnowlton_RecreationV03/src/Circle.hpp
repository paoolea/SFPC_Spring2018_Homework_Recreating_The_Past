//
//  Circle.hpp
//  KenKnowlton_RecreationV02
//
//  Created by pao on 3/26/18.
//

#include "ofMain.h"

class Circle : public ofBaseApp{
    
public:
    void setup(float x, float y, ofColor c);
    void update();
    void draw();
    
    void grow();
    bool edges();
    
    float posX, posY, radius;
    bool growing;
    ofColor col;
    
};

