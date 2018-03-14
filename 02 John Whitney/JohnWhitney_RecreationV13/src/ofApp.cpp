#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    
    float total = 100;
    float radius = 100;
    float size = 5;
    float amplitude = 100;
    float frequency = 0.01;
    float phase = 3.0;
    
    
    for(int i = 0; i < total; i++){
        float x = ofMap(i, 0, total, 0, ofGetWidth());
        
        float sinOfTimeA = sin(time * 0.03);
        float newFreq = ofMap(sinOfTimeA, -1, 1, 0.01 , 0.5);
        float input = (newFreq * x) + phase;
        
        float sinOfTime = sin(time * 3);
        float y = centerY + sin(input) * amplitude;
        float y2 = centerY + cos(input) * amplitude;
        float newY = ofMap(sinOfTime, -1, 1, y2 , y);
        
        ofDrawCircle(x, newY, size);
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
