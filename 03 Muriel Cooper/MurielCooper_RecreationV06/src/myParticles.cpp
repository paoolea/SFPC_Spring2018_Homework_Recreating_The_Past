//
//  myParticles.cpp
//  MurielCooper_RecreationV06
//
//  Created by pao on 3/19/18.
//

#include "myParticles.hpp"


//--------------------------------------------------------------
void myParticles::setup(ofVec3f pos){
    float ranVel = 3;
    
    radius = 1;
    maxSpeed = 10;
    maxForce = 1;
    target = pos;
    position = ofVec3f(ofRandom(-ofGetWidth()/2, ofGetWidth()),
                       ofRandom(-ofGetHeight(), ofGetHeight()/2), 0);
    velocity = ofVec3f(ofRandom(-ranVel, ranVel), ofRandom(-ranVel, ranVel), ofRandom(-ranVel, ranVel));
    
    // mag() - processing
    // ofVec3f es(20.0, 30.0, 40.0);
    // float ca = es.length();
    // cout << ca << endl;
    
    // setMag() - processing
    // scale == serMag processing
    // ofVec3f p(3, 4, 0);
    // cout << 10 * p.normalize() << endl;
    
    // mult
    // ofVec3f m(3, 4, 0);
    // cout << m * 3 << endl;
}

//--------------------------------------------------------------
void myParticles::update(){
    position += velocity;
    velocity += acceleration;
    acceleration.set(0, 0); // acceleration.mult(0);
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
    
    newflee = newflee*5;
    
    applyForce(newArrive);
    applyForce(newflee);
}

//--------------------------------------------------------------
void myParticles::applyForce(ofVec3f f){
    acceleration = acceleration + f;
}

//--------------------------------------------------------------
ofVec3f myParticles::arrive(ofVec3f t){
    ofVec3f desired = t - position;
    float d = desired.length();
    float speed = maxSpeed;
    float dif = 50;
    
    if(d < dif) speed = ofMap(d, 0, dif, 0, maxSpeed);

    desired.scale(speed);
    ofVec3f steer = desired - velocity;
    steer.limit(maxForce);
    return steer;
}

//--------------------------------------------------------------
ofVec3f myParticles::flee(ofVec3f t){
    ofVec3f desired = t - position;
    float d = desired.length();
    
    if(d < 500){
        desired.scale(maxSpeed);
        desired = desired * -1;
        ofVec3f steer = desired - velocity;
        steer.limit(maxForce);
        return steer;
    } else {
        return ofVec3f(0, 0, 0);
    }
}


