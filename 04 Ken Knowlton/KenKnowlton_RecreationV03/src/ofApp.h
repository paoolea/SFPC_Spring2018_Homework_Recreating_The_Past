#pragma once

#include "ofMain.h"
#include "Circle.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		
    Circle newCircle();
    
    vector <Circle> circles;
    vector <ofPoint> spots;
    vector <ofImage> images;
    
    ofImage img;
    int curr;
};
