//
//  myParticles.hpp
//  MurielCooper_RecreationV06
//
//  Created by pao on 3/19/18.
//

#include "ofMain.h"


class myParticles : public ofBaseApp{
    
public:
    void setup(ofVec3f pos);
    void update();
    void draw();
    void keyPressed(int key);
    
    void behaviors(float x, float y);
    void applyForce(ofVec3f f);
    
    ofVec3f target;
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f acceleration;
    ofVec3f flee(ofVec3f t);
    ofVec3f arrive(ofVec3f t);
    
    float radius;
    float maxSpeed;
    float maxSpeedR;
    float maxForce;
    float areaDectect;
    bool reset;
};
