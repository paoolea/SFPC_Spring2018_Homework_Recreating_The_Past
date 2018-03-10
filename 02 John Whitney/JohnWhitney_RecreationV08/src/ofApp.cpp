#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    theta = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSetLineWidth(2);
    ofSeedRandom(750);
    
    float total = 7;
    float time = ofGetElapsedTimef();
    float myWidthMax;
    float xorig = 400;
    float yorig = 400;
    
    line.resize(total);
    
    for(int i = 1; i < total; i++){
        myWidthMax = 300 - (i*30);
        float radius = ofMap(sin(time*10), -1, 1, 0, myWidthMax);
        float angle = ofGetElapsedTimef()*(i*2);
        float color = 255 - (i * 45);
        
        ofSetColor(223,255, 255, color);
        
        ofPoint pt;
        pt.x = xorig + radius * cos(angle);
        pt.y = yorig + radius * sin(angle);
        
        line[i].addVertex(pt);
        
        if (line[i].size() > i*30){
            line[i].getVertices().erase(line[i].getVertices().begin());
        }
        
        line[i].draw();
        
        ofSetColor(255);
        ofDrawCircle(pt, 5);
     
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

