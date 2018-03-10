#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(1, 1, 63);
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
    float left = 120;
    float top = 250;
    
    for (int i = 0; i < total; i++){
        for (int posX = 0; posX < 4; posX++){
            float sinOfTime = sin(((time*10)+i)*0.3);
            float sinOfTimeScaleUp = ofMap(sinOfTime, -1, 1, 3, 25);
            float sinOfTimeScaleDown = ofMap(sinOfTime, -1, 1, 25, 3);
            
            float sinOfTimeColorUp = ofMap(sinOfTime, -1, 1, 100, 255);
            float sinOfTimeColorDown = ofMap(sinOfTime, -1, 1, 255, 100);
            
            float sinOfTimeY = sin(((time*7)+i)*0.3);
            float sinOfTimeX = sin(((time*7)+i)*0.2);
            
            float x = ofMap(sinOfTimeX, -1, 1, 0, 100);
            float x2 = ofMap(sinOfTimeX, -1, 1, 100, 0);
            float y = ofMap(sinOfTimeY, -1, 1, -50, 50);

            ofSetColor(0, 0, sinOfTimeColorUp);
            ofDrawCircle(left+x+posX*150, top+i*30+y , sinOfTimeScaleUp);
            ofSetColor(0, 0, sinOfTimeColorDown);
            ofDrawCircle(left+x2+posX*150, top+i*30+y , sinOfTimeScaleDown);
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
