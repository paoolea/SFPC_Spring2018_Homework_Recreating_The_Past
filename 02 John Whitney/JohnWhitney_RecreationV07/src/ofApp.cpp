#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    
    m_over.load("over.png");
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    
    
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    float k = 0.6;
    float sinOfTime = sin(time * 0.5);
    float cNum = ofMap(sinOfTime, -1, 1, 9, 4.496);
    
    ofTranslate(centerX, centerY);
    ofBeginShape();
    for(float a = 0; a < TWO_PI*cNum; a += 0.05){
        for(float b = 0; b < 10; b++){
            float rotationZ2 = ofMap(sinOfTime, -1, 1, 0.222, 0.111);
            float radius2 = (300 - (b*10)) * cos(rotationZ2 * a);
            float x2 = radius2 * cos(a);
            float y2 = radius2 * sin(a);
            float color = 255 - (b * 30);
            
            ofSetLineWidth(2);
            ofFill();
            ofSetColor(255, 255, 255, color);
            ofDrawCircle(x2, y2, 2);
            ofNoFill();
            ofVertex(x2, y2);
        }
    }
    ofEndShape();
    
    ofSetColor(255);
    ofTranslate(-centerX, -centerY);
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
