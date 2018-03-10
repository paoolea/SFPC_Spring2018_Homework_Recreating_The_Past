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
    ofSetLineWidth(1);
    ofSeedRandom(750);
    
    float total = 10;
    float myWidthMax = 300;
    float myWidthMin = 100;
    float time = ofGetElapsedTimef();
    
    line.resize(total);
    
    for(int i = 3; i < total; i++){
        float xorig = 400;
        float yorig = 400;
        float radius = ofMap(sin(time*5*i), -1, 1, myWidthMin, myWidthMax);
        float angle = ofGetElapsedTimef()*3;
        float colorR = ofRandom(0, 255);
        float colorG = ofRandom(0, 255);
        float colorB = ofRandom(0, 255);
        //float strokeW = ofMap(sin(time*5*i), -1, 1, 1, 5);

        // Setup
        //ofSetLineWidth(strokeW);
        ofSetColor(colorR, colorG, colorB);
        
        ofPoint pt;
        pt.x = xorig + radius * cos(angle);
        pt.y = yorig + radius * sin(angle);
        
        line[i].addVertex(pt);
        
        if (line[i].size() > 5000){
            line[i].getVertices().erase(line[i].getVertices().begin());
        }
        
        line[i].draw();
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
