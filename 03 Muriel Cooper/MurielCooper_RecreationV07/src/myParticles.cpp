//
//  myParticles.cpp
//  MurielCooper_RecreationV06
//
//  Created by pao on 3/19/18.
//

#include "myParticles.hpp"


//--------------------------------------------------------------
void myParticles::setup(ofVec3f pos){
    ofSetVerticalSync(true);
    
    float ranVel = 1;
    radius = 1;
    maxSpeed = 10;
    maxForce = 1;
    target = pos;
   // position = pos;
    position = ofVec3f(ofRandomWidth(), ofRandomHeight(), 1);
    velocity = ofVec3f(ofRandom(-ranVel, ranVel), ofRandom(-ranVel, ranVel), ofRandom(-ranVel, ranVel));
    
    // mag()  == length()
    // setMag() == scale() or 10 * p.normalize()
    // mult() == v * 3
    
   
}

//--------------------------------------------------------------
void myParticles::update(){
    position += velocity;
    velocity += acceleration;
    acceleration *= 0; // reset acc
}

//--------------------------------------------------------------
void myParticles::draw(){
    ofPushMatrix();
        ofTranslate(position.x, position.y);
        ofDrawCircle(0, 0, radius);
    ofPopMatrix();
    
    
}

//--------------------------------------------------------------
void myParticles::behaviors(){
    ofVec3f newArrive = arrive(target); // return to real position
    ofVec3f mouse = ofVec3f(ofGetMouseX(), ofGetMouseY(), 0); // move mouse
    ofVec3f newflee = flee(mouse);
    
    newArrive *= 1;
    newflee *= 5;
    
    applyForce(newArrive);
    applyForce(newflee);
}

//--------------------------------------------------------------
void myParticles::applyForce(ofVec3f f){
    acceleration += f;
}

//--------------------------------------------------------------
ofVec3f myParticles::arrive(ofVec3f t){ // return to position
    ofVec3f desired = t - position;
    float d = desired.length(); // mag()
    float speed = maxSpeed;
    float dif = 100;

    if(d < dif) speed = ofMap(d, 0, dif, 0, maxSpeed);

    desired.scale(speed);
    ofVec3f steer = desired - velocity;
    steer.limit(maxForce);
    return steer;
}

//--------------------------------------------------------------
ofVec3f myParticles::flee(ofVec3f t){ // repele 
    ofVec3f desired = t - position;
    float d = desired.length();
    
    if(d < 50){
        desired.scale(maxSpeed);
        desired *= -1; // change force
        ofVec3f steer = desired - velocity;
        steer.limit(maxForce);
        return steer;
    } else {
        return ofVec3f(0, 0, 0);
        
    }
}


