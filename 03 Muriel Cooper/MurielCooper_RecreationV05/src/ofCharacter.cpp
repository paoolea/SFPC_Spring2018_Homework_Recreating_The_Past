//
//  ofCharacter.cpp
//  MurielCooper_RecreationV05
//
//  Created by pao on 3/17/18.
//

#include "ofCharacter.hpp"

//--------------------------------------------------------------
void ofCharacter::setup(string s){
    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 230, true, true, true);
    myString = s;
    loadCharacters(myString);
    
    
}

void ofCharacter::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
}

//--------------------------------------------------------------
void ofCharacter::update(){
    
}

//--------------------------------------------------------------
void ofCharacter::draw(int id, float nX, float nY, float depthY, float timeSpace, ofPoint myColor){
    ofSeedRandom(0);
    float depthZ = 1400;
  //  float depthY = 100;
    float sizeCir = 2;
    float jumpDots = 1;
    float coutDot = 10;
    
    float time = ofGetElapsedTimef() * 1.5;
    float moveZ = ofMap(sin(time*timeSpace), -1, 2, 70 - (id*30), ofRandom(depthZ/2, depthZ));
    float moveY = ofMap(sin(time*timeSpace), -1, 1, 5, -depthY);
    float manyDots = ofMap(sin(time*timeSpace), -1, 1, 0, coutDot);
    float alpha = ofMap(sin(time*timeSpace), -1, 2, 0, 255);
    float stageW = ofGetWidth();
    float stageH = ofGetHeight();
    
    ofPushMatrix();
    ofTranslate(-220 + nX, -90);
    ofTranslate(centerCharacter(myString));
    ofSetColor(myColor.x, myColor.y, myColor.z, 150);
    ofRotateX(180);
    
    ofSetLineWidth(2);
   
    
    for(int i = 0; i < characters.size(); i++){
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(5);
            
            for (int i = 0; i < line.size(); i += jumpDots) {
                ofPoint point = line[i];
                ofPushMatrix();
                ofTranslate(point.x, point.y);
                ofRotateY(90);
                ofDrawLine(0, 0, moveZ, moveY);
                ofPopMatrix();
                
//                for (int m = 0; m < coutDot; m++) {
//                    float alphaDot = (m * (255/coutDot));
//                    
//                    ofPoint point = line[i];
//                    ofPushMatrix();
//                    //ofSetColor(255, 255, 255, alpha);
//                    //ofSetColor(255, 255, 255,  255);
//                    ofTranslate(point.x, -point.y, -m*(moveZ/coutDot));
//                    ofRotateY(90);
//                    ofSetLineWidth(2);
//                    ofDrawCircle(j*30, m*(moveY/coutDot), 2);
//                    ofPopMatrix();
//                }
            }
            
        }
        
    }
    ofPopMatrix();
}

//--------------------------------------------------------------
ofPoint ofCharacter::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}

