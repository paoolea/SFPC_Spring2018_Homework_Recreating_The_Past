#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofSeedRandom(0);
    ofEnableSmoothing();


}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);
	ofSetLineWidth(2);
    ofNoFill();
    
    float time = ofGetElapsedTimef();
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float total = 15;
    float totalDupli = 15;
    float radius = 50;
    float space = 20;

    ofTranslate(centerX, centerY);
    for(int i = 0; i < total; i++){
        for(int a = 1; a < totalDupli; a++){
            float size = 10 + (i * 10);
            float color = (i * (100/total));
            
            float angle = ofMap(a, 0, totalDupli, 0, TWO_PI*2);
            float x = ((radius + (a * space)) * cos(angle));
            float y = ((radius + (a * space)) * sin(angle));
            
            ofSetColor(color);
            ofPushMatrix();
            ofRotateZ((i*3) + (a * 0));
            ofDrawRectangle(x, y, size, size);
            ofPopMatrix();
        }
    }
	
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
