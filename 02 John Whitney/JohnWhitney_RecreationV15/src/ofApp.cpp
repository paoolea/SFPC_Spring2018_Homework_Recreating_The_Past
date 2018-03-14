#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2);
    ofSeedRandom(0);
    
    float t = ofGetElapsedTimef() * .2;
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float totalDots = 90;
    float size = 3;
    
    line.resize(totalDots);
    
    for(int i = 0; i < totalDots; i++){
        float angle = ofMap(t, 0, 1, 0, ofRandom(-TWO_PI, TWO_PI));
        float radius = ofMap( 3 * cos(3 * angle), -1, 1, 0, ofRandom(50, 120));
        
        float x = (radius * sin(angle)) + (centerX + ofRandom(-200, 200));
        float y = (radius * cos(angle)) + (centerY + ofRandom(-200, 200));
        
        float color = 255 - (i * (255/totalDots));
        
        ofSetColor(color);
        ofDrawCircle(x, y, size);
        line[i].addVertex(x, y);
        
        ofDrawCircle( line[i].getPointAtPercent(0).x, line[i].getPointAtPercent(0).y, size);
        
        if(line[i].size() > ((i+1)*3)){
            line[i].getVertices().erase(line[i].getVertices().begin());
        }
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
