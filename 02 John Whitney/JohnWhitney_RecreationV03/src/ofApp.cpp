#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSetLineWidth(2);
    
    float total = 50;
    float size = 2;
    float radiusB = 200;
    float radiusM = 150;
    float radiusS = 100;
    float radiusSS = 80;
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    
  
    for(int f = 0; f < total*10; f++){
        float angle = f * (TWO_PI  / (total*10));
        float movSS = ofMap(sin(time*(f*0.1)), -1, 1, radiusSS, radiusB+100);
        float xSS = centerX + cos(angle) * (movSS);
        float ySS = centerY + sin(angle) * (movSS);
        
        ofSetColor(255, 255, 255, 130);
        ofDrawCircle(xSS, ySS, size);
    }
   
    for(int i = 0; i < total; i++){
        float angle = i * (TWO_PI  / total);
        float x = centerX + cos(angle) * (radiusB);
        float y = centerY + sin(angle) * (radiusB);
        
        float xM = centerX + cos(angle) * (radiusM);
        float yM = centerY + sin(angle) * (radiusM);
        
        float mov = ofMap(sin(time*(i*0.37)), -1, 1, radiusS, radiusB-30);
        float xS = centerX + cos(angle) * mov;
        float yS = centerY + sin(angle) * mov;
       

        ofSetColor(255);
        ofDrawLine(x, y, xS, yS);
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
