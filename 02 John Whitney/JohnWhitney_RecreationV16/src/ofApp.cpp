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
    ofSetLineWidth(2);
    
    float time = ofGetElapsedTimef();
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    
    float total = 600;
    float totalB = 50;
    float amplitude = 100;
    float frequency = .01;
    float phase = 0.1;
    float vel = 0.3;
    
    // Points movement
    for(int f = 0; f < totalB; f++){
        float sinOfTimePh2 = sin(time * vel);
        float newPhase2 = ofMap(sinOfTimePh2, -1, 1, 0, (ofGetWidth()));
        float phase2 = newPhase2 * 0.1;
            
        float sinOfTimeFq2 = sin(time * vel);
        float newFreq2 = ofMap(sinOfTimeFq2, -1, 1, .01, .03);
        float frequency2 = newFreq2;
            
        float x2 = ofMap(f, 0, totalB, 0, ofGetWidth());
        float y2 = centerY + sin(x2 * frequency2 + phase2) * amplitude;
        float y3 = centerY + cos(x2 * frequency2 + phase2) * amplitude;
            
        ofSetColor(255, 255, 255, 100);
        ofDrawCircle(x2, y2, 2);
        ofSetColor(255, 255, 255, 200);
        ofDrawCircle(x2, y3, 2);
        
    }
    
    // Linea points
    float sinOfTimeFor = sin(time * 0.5);
    float newFor = ofMap(sinOfTimeFor, -1, 1, 0, total/2);
    float newFor2 = ofMap(sinOfTimeFor, -1, 1, 0, newFor+200);
    
    for(int i = newFor; i < newFor2; i++){
        float sinOfTimePh = sin(time * vel);
        float newPhase = ofMap(sinOfTimePh, -1, 1, 0, ofGetWidth());
        phase = newPhase * 0.1;
        
        float sinOfTimeFq = sin(time * vel);
        float newFreq = ofMap(sinOfTimeFq, -1, 1, .01, .03);
        frequency = newFreq;
        
        float x = ofMap(i, 0, total, 0, ofGetWidth());
        float y = centerY + sin(x * frequency + phase) * amplitude;
        
        ofSetColor(255);
        ofDrawCircle(x, y, 2);
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
