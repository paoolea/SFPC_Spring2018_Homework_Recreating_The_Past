#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSetLineWidth(0);
    ofSetColor(255);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    float size = 400;
    float space = 5;
    
    ofTranslate(centerX, centerY);
    
    for(float i = 0; i < TWO_PI; i += 0.04){
        for(float b = 0; b < 10; b++){
            float radius = (size * cos(i)) - (b * space);
            float sinOfTime = sin((time+(i*3)) * 3);
            float newY = ofMap(sinOfTime, -1, 1, 0 , radius);
            float color = 255 - (i * (255/TWO_PI));
            
            float x = (radius * cos(i)) - (size/2);
            float y = (newY * sin(i));
            
            ofSetColor(color);
            ofDrawCircle(x, y, 2);
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
