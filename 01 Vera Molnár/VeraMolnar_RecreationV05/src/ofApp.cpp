#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255);
    mySize = 10;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofNoFill();
    ofSetLineWidth(5);
    ofSeedRandom(0);
    
    for(int x = 0; x < 48; x++){
       for(int y = 0; y < 49; y++){
           
           ofPushMatrix();
           ofTranslate(23+x*16, 18+y*16);
           
           if (ofNoise(x*0.1,y*0.1) < 0.9){
               ofRotateZ(0);
               ofDrawLine(0-mySize,0, 0+mySize, 0);
           } else {
               float myRandom = ofRandom(-45, 45);
               ofRotateZ(myRandom);
               ofDrawLine(0-mySize,0, 0+mySize, 0);
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







