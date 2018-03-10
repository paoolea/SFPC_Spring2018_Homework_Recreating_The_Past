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
    ofSetColor(255);
    
    
    float time = ofGetElapsedTimef();
    float timeMult = ofGetElapsedTimef()*2;
    float timeScale = ofGetElapsedTimef()*0.5;
    float total = 10;
    float totalX = 300;
    float left = 0;
    float top = 0;
    
    for (int i = 0; i < total; i++){
        for (int posX = 0; posX < totalX; posX++){
            float sinOfTime = sin(((time*10)+i)*0.3);
            float sinOfTimeScaleUp = ofMap(sinOfTime, -1, 1, 20, 100);
            float sinOfTimeScaleDown = ofMap(sinOfTime, -1, 1, 100, 20);
            
            float sinOfTimeColorUp = ofMap(sinOfTime, -1, 1, 50, 200);
            float sinOfTimeColorDown = ofMap(sinOfTime, -1, 1, 200, 50);
            
            float sinOfTimeY = sin(((time*7)+i)*0.3);
            float sinOfTimeX = sin(((time*7)+i)*0.2);
            
            float x = ofMap(sinOfTimeX, -1, 1, 0, 100);
            float x2 = ofMap(sinOfTimeX, -1, 1, 100, 0);
            float y = ofMap(sinOfTimeY, -1, 1, -50, 50);
            
            ofNoFill();
            ofSetColor(sinOfTimeColorDown, 217, 245);
            ofDrawCircle(left+x+posX*mouseX, top+i*100+y , sinOfTimeScaleUp);
            ofSetColor(sinOfTimeColorUp);
            ofDrawCircle(left+x2+posX*mouseX, top+i*100+y , sinOfTimeScaleDown);
        }
    }
    
    /*float sinOfTime = sin(ofGetElapsedTimef());
     float sinOfTimeRemmapped = ofMap(sinOfTime, -1, 1, 0, 20);
     ofDrawCircle( 300 , 400, sinOfTimeRemmapped);*/
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

