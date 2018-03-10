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
    
    
    float time = ofGetElapsedTimef();
    float timeMult = ofGetElapsedTimef()*0.5;
    float timeScale = ofGetElapsedTimef()*2;
    float total = 20;
    
    //    float offset = ofMap(sin(time), -1, 1, 0, 3.7);
    //    for (int i = 0; i < 40; i++){
    //        float x = ofMap(sin(time + i*offset), -1, 1, 200,600);
    //        ofDrawCircle(x, i*20 + 10, 10);
    //    }
    
    
    for (int i = 0; i < total; i++){
        for (int f = 0; f < total; f++){
            float x = ofMap(sin(timeMult * (i*0.1+1)), -1, 1, 50, 70);
            float scal = ofMap(sin(timeScale * (i*0.1+1)), -1, 1, 10, 30);
            ofDrawCircle(20+x*f, i*40 + 20, scal);
           // ofDrawCircle(10+x, i*40 + 20, scal);
           // ofDrawRectangle(20+x*f, i*40 + 20, scal, scal);
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
