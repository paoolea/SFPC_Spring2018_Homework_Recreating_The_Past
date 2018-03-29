//
//  Circle.cpp
//  KenKnowlton_RecreationV02
//
//  Created by pao on 3/26/18.
//

#include "Circle.hpp"

//--------------------------------------------------------------
void Circle::setup(float x, float y, ofColor c){
    posX = x;
    posY = y;
    radius = 1;
    col = c;
    growing = true;
}

//--------------------------------------------------------------
void Circle::update(){
    
}

//--------------------------------------------------------------
void Circle::draw(){
    ofSetLineWidth(0);
    ofFill();
    ofSetColor(col);
    ofDrawCircle(posX, posY, radius);
}

//--------------------------------------------------------------
void Circle::grow(){
    if(growing) radius += 0.5;
}

//--------------------------------------------------------------
bool Circle::edges(){
    return(posX + radius > ofGetWidth() || posX - radius < 0
           || posY + radius > ofGetHeight() || posY - radius < 0);
}
