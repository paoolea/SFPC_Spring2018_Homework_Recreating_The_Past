#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    m_over.load("over.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    
    float time = ofGetElapsedTimef();
    float timeMult = ofGetElapsedTimef()*0.5;
    float timeScale = ofGetElapsedTimef()*2;
    float total = 20;
    
    for (int i = 0; i < total; i++){
        for (int f = 0; f < total; f++){
            float x = ofMap(sin(timeMult * (i*0.1+1)), -1, 1, 50, 70);
            float scal = ofMap(sin(timeScale * (i*0.1+1)), -1, 1, 10, 30);
            float color = ofMap(sin(timeScale * (i*0.1+1)), -1, 1, 5, 170);
            
            ofSetColor(color, color, color);
            ofDrawCircle(20+x*f, i*40 + 20, scal);
        }
    }
    
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
