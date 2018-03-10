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
    ofSeedRandom(0);
    ofSetLineWidth(3);
    ofNoFill();
    
    
    for(int i = 0; i < 20; i++){
        float sinOfTimePlus = sin((ofGetElapsedTimef()+i)*0.5);
        float sinOfTimeRemmapped = ofMap(sinOfTimePlus, -1, 1, 90, (((ofGetElapsedTimef()*i)*i)-300));
        float colorR = ofRandom(50, 255);
        float colorG = ofRandom(50, 255);
        float colorB = ofRandom(50, 255);
        
        ofSetColor(colorR, 255, 255, 100);
        
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, sinOfTimeRemmapped);
        
        
        
        /*ofPushMatrix();
        ofTranslate(ofGetWidth()/2 - sinOfTimeRemmapped/2, ofGetHeight()/2 - sinOfTimeRemmapped/2);
        ofRotateZ(sinOfTimeRotateB);
        ofDrawRectangle(0, 0, sinOfTimeRemmapped, sinOfTimeRemmapped);
        ofPopMatrix();*/
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
