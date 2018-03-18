#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    //ofBackground(243, 235, 223);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    ofSetLineWidth(2);
        
    vMyString = {"S", "F", "P", "C"};
    vCharacter.resize(vMyString.size());
    
    for(int i = 0; i < vMyString.size(); i++){
        vCharacter[i].setup(vMyString[i]);
    }
    
    // colors
    count = 0;
    colors.resize(4);
    colors[0] = ofPoint(0, 174, 239);
    colors[1] = ofPoint(237, 25, 109);
    colors[2] = ofPoint(255, 242, 0);
    colors[3] = ofPoint(0, 174, 239);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    cam.begin();
    for(int i = 0; i < vMyString.size(); i++){
        float speed = 0.5*(i+2);
        
        if(i == 0) speed = 0.5*(i+2);
        
        vCharacter[i].draw(i, i*70, i*70, 100, speed, colors[i]);
    }
    cam.end();
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
