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
    ofNoFill();
    
    for (int x = 0; x < 30; x++){
        float randomW = ofRandom(30, 500);
        float randomH = ofRandom(randomW-50,randomW+50);
        float randomPosX = ofRandom(-mouseX, mouseX);
        float randomPosY = ofRandom(-50, 50);
        
        ofPushMatrix();
        ofTranslate((ofGetWidth()/2)-(randomW/2)+randomPosX, ofGetHeight()/2-(randomH/2)+randomPosY);
        ofDrawRectangle(0, 0, randomW, randomH);
        ofPopMatrix();
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





