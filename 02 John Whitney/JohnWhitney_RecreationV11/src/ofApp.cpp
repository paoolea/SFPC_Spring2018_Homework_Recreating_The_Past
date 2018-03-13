#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);
    ofSetLineWidth(5);
    
    float time = ofGetElapsedTimef();
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float repet = 55;
    float space = 5;
    float size = 30;
    
    ofTranslate(centerX, centerY);
    ofBeginShape();
    for(float b = 0; b < repet; b++){
        
        float sinOfTime = sin((time + (b*5)) * 0.5);
        float moveLine = ofMap(sinOfTime, -1, 1, 0, TWO_PI);
        float moveLine2 = ofMap(sinOfTime, -1, 1, TWO_PI, 0);
        
        for(float a = moveLine2; a < moveLine; a += 0.01){
            float radius = size + (b * space);
            float x = radius * cos(a);
            float y = radius * sin(a);
            float color = 255 - (b * (255/repet));
            
            ofFill();
            ofSetColor(color);
            ofDrawCircle(x, y, 2);
            ofNoFill();
            //ofVertex(x, y);
        }
    }
    ofEndShape();

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
