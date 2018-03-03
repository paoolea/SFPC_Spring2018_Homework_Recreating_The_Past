#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    line.resize(3);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    
    float time = ofGetElapsedTimef();
    float sinOfTime = sin(time);
    float total = 2;
    float num = 1;
    
    for(int i = 0; i < total; i++){
        
        float x = ofMap(sin(time*(3+num)), -1, 1, 200,600-(100*i));
        float y = ofMap(sin(time), -1, 1, 0,800);
        float colR = ofRandom(100, 255);
        float colG = ofRandom(100, 255);
        float hatf = 50*i;
        
        ofSetColor(colR, colG, 0);
        ofDrawCircle(x, y, 3);
        
        ofPoint pt;
        pt.x = x;
        pt.y = y;

        line[i].addVertex(pt);
        line[i].draw();
        num++;
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
