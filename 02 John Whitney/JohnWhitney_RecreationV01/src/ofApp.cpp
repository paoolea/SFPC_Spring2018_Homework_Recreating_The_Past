#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    
    m_oveR.load("over.png");
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    ofSetLineWidth(2);
    ofNoFill();
    
    float time = ofGetElapsedTimef();
    //float sinOfTime = sin(time);
    float total = 20;
    float totalDupli = 35;
    float num = 1;
    float centerX = ofGetWidth()/2;
    float centerY = ofGetWidth()/2;
    float space;
    float multi = 1.5;
    
    for(int i = 0; i < total; i++){
        float color;
        color = (i * (255/total));

        for(int f = 1; f < totalDupli; f++){ // Copy
            if(f == 1) space = 0.5;
            if(f == 2) space = 0.3;
            if(f > 2) space = 0.2;
            
            float sinOfTime = sin(((time/((f+1)*2)) * 0.5)); // Time for every copy
            float rotationZ = ofMap(sinOfTime, -1, 1, 0, 360);

            ofPushMatrix();
                ofSetColor(255, 255, 255, color);
                ofTranslate(centerX, centerY);
                ofRotateZ(rotationZ);
                ofSetCircleResolution(5);
                ofDrawCircle(0, 0, 30*f + ((i * multi)));
            ofPopMatrix();
        }
    }
    
    ofSetColor(255);
    m_oveR.draw(0, 0);
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

