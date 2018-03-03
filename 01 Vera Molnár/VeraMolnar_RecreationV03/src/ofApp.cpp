#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofSeedRandom(0);
    
    for (int x = 0; x < 50; x++){
        for (int y = 0; y < 50; y++){
            
            float randomAngle = ofRandom(-180*ofGetElapsedTimef(),180*ofGetElapsedTimef());

            
            ofPushMatrix();
            ofTranslate(x*16, y*16);
            ofRotateZ(randomAngle);
            
            if (ofNoise(x*0.01,y*0.01, ofGetElapsedTimef()) < 0.7){
                ofSetLineWidth(1);
                ofDrawLine(0-10,0, 0+10, 0);
            } else {
                ofSetLineWidth(2);
                ofDrawLine(0-30,0, 0+30, 0);
            }
            
            ofPopMatrix();
            
        }
    }
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}



