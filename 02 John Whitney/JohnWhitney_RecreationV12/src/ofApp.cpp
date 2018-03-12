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
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(3);
    
    float time = ofGetElapsedTimef();
    float total = 15;
    
    line.resize(total);
    
    for (int i = 1; i < total; i++) {
        float sinOfTimeX = sin((time * (2 + (i*0.1)))*0.2);
        float x = ofMap(sinOfTimeX, -1, 1, 200, ofGetWidth() - 200);
        float sinOfTimeY = sin((time * (9 + (i*0.1)))*0.2);
        float y = ofGetHeight() / 2 + ofMap(sinOfTimeY, -1, 1, 0, 300) - 150;
        float scale = 20 + (i * 20);
        float color = 80 + (i * 10);
        
        ofSetColor(255);
        ofPushMatrix();
        ofTranslate(x-scale/2, y-scale/3);
        ofDrawTriangle(0, 0, scale, 0, scale/2, scale/1.2);
        ofPopMatrix();
        
        float sinOfTimeXA = sin((time * (2 + (i*0.1)))*0.2);
        float xA = ofMap(sinOfTimeXA, -1, 1, ofGetWidth() - 200, 200);
        float sinOfTimeYA = sin((time * (9 + (i*0.1)))*0.2);
        float yA = ofGetHeight() / 2 + ofMap(sinOfTimeYA, -1, 1, 300, 0) - 150;
        float scaleA = 20 + (i * 20);
        float colorA = 10 + (i * 15);
        
        ofSetColor(colorA, colorA, colorA, 70);
        ofPushMatrix();
        ofTranslate(xA-scaleA/2, yA-scaleA/3);
        ofDrawTriangle(0, 0, scaleA, 0, scaleA/2, scaleA/1.2);
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

