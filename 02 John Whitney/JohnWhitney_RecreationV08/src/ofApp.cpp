#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    
    m_over.load("over.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSetLineWidth(2);
    ofSeedRandom(0);
    
    float time = ofGetElapsedTimef();
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float totalX = 10;
    float totalY = 19;
    float size = 100;
    float spaceX = size;
    float spaceY = size-50;
    
    
    for(int i = 0; i < totalY; i++){ // Y
        for(int f = totalX; f >= 0; f--){ // X
            float color = ofRandom(50, 250);
            
            float sinOfTimeX = sin((time+(f*50)) * 0.5);
            float moveX = ofMap(sinOfTimeX, -1, 1, -50, 50);
            float x = size - (f * spaceX) + moveX;
            
            float sinOfTimeY = sin((time+(i*50)) * 2);
            float moveY = ofMap(sinOfTimeY, -1, 1, 0, 50);
            float y = (ofGetHeight() - (i * spaceY) - 70) + moveY;
            
            int result = 2 * (i / 2);
            if(i == result){
                x = (((f * spaceX) - 50) + moveX) - size;
            } else {
                x = ((f * spaceX) + moveX) - size;
            }
            
            ofPushMatrix();
                ofSetColor(color, color, color);
                ofDrawRectRounded(x, y, size, size+50, 50);
            
                ofSetColor(0, 0, 0, 30);
                ofDrawRectRounded(x, y, size+1, size+51, 50);
            ofPopMatrix();
        }
    }
   
    ofSetColor(255, 255, 255, 150);
    m_over.draw(0, 0);
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

