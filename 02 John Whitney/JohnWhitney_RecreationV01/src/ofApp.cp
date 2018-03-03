#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    
    
    for(int i = 0; i < 5; i++){
        float sinOfTime = sin(ofGetElapsedTimef()+i);
        float sinOfTimePlus = sin((ofGetElapsedTimef()+i)*5);
        float sinOfTimeRemmapped = ofMap(sinOfTime, -1, 1, 30, 300);
        float sinOfTimeRotate = ofMap(sinOfTime, -1, 1, 0, 90);
        float sinOfTimeRotateB = ofMap(sinOfTime, -1, 1, 0, -90);
        float sinOfTimeColorR = ofMap(sinOfTimePlus, -1, 1, 0, 255);
        float sinOfTimeStroke = ofMap(sinOfTimePlus, -1, 1, 0, 3);
        
        ofSetColor(sinOfTimeColorR, 255, 60);
        
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, sinOfTimeRemmapped);
        
        ofSetColor(255);
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 - sinOfTimeRemmapped/2, ofGetHeight()/2 - sinOfTimeRemmapped/2);
        ofRotateZ(sinOfTimeRotate);
        ofDrawRectangle(0, 0, sinOfTimeRemmapped, sinOfTimeRemmapped);
        ofPopMatrix();
        
        ofPushMatrix();
        ofTranslate(ofGetWidth()/2 - sinOfTimeRemmapped/2, ofGetHeight()/2 - sinOfTimeRemmapped/2);
        ofRotateZ(sinOfTimeRotateB);
        ofDrawRectangle(0, 0, sinOfTimeRemmapped, sinOfTimeRemmapped);
        ofPopMatrix();
    }
    
    //ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, sinOfTimeRemmapped);
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
