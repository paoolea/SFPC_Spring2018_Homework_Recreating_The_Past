#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    
    m_over.load("over.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2);
    ofNoFill();
    ofSetColor(255);
    ofSetRectMode(OF_RECTMODE_CENTER);
    
    float time = ofGetElapsedTimef();
    float total = 110;
    float centerX = ofGetWidth()/2;
    float centerY = ofGetWidth()/2;
    float space = 15;
    float degree = 2.3;
    
    
    for(int i = 0; i < total; i++){
        float color = 255 - (i * (255/total));
        float size = 10 + (i*space);
        float rotate = i * degree;
        float sinOfTime = sin((time * 0.75) * 0.5);
        float rotationZ = ofMap(sinOfTime, -1, 1, -rotate, rotate);
        
        ofSetColor(255, 255, 255, color);
        ofPushMatrix();
            ofTranslate(centerX, centerY);
            ofRotateZ(rotationZ);
            ofDrawRectangle(0, 0, size, size);
        ofPopMatrix();
    }
    
    //m_over.draw(centerX, centerY);
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
