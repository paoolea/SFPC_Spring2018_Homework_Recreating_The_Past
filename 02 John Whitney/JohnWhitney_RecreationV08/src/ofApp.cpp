#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    
    total = 5;
    line.resize(total);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSetLineWidth(2);

    
    float time = ofGetElapsedTimef();
    float width = 250;
    float sinOfTimeX;
    float centerX;
    
    for(int i = 0; i < total; i++){
        if(i > 0){
            width = 110 - (i*10);
            centerX = width/2;
            sinOfTimeX = sin((time*((i+1)*30))*0.3);
        } else {
            width = 250;
            centerX = 125;
            sinOfTimeX = sin((time*((i+1)*30))*0.3);
        }
        
        
        float sinOfTimePosX = ofMap(sinOfTimeX, -1, 1, 0, width);
        float sinOfTimeY = sin((time*10)*0.3);
        float y = ofMap(sinOfTimeY, -1, 1, -60, ofGetHeight()+60);
        float x = ofGetWidth()/2 + sinOfTimePosX - centerX;
        
        ofDrawCircle(x, y , 2);
        
        ofPoint pt;
        pt.x = x;
        pt.y = y;
        
        if (line[i].size() > 100){
            line[i].getVertices().erase(line[i].getVertices().begin());
        }
        
        line[i].addVertex(pt);
        line[i].draw();
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
