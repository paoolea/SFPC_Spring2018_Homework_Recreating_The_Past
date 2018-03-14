#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    ofSetLineWidth(0);
    ofSetColor(255);
    
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float time = ofGetElapsedTimef();
    float totalDots = 100;
    float totalDupli = 20;
    float totalScale = 3;
    float size = 1;
    float space = 3;
    float amplitude = 10;
    float frequency = 10;
    float phase = 3.0;
    float radius = 100;
    float spaceScale = 70;
    
    ofTranslate(centerX, centerY);
    
    for(int i = 0; i < totalDots; i++){
        for(int f = 0; f < totalDupli; f++){
             for(int g = 0; g < totalScale; g++){
                float angle = ofMap(i, 0, totalDots, 0, TWO_PI);
                float sinOfTime = sin((time) * 2);
                float newY = ofMap(sinOfTime, -1, 1, 1 , 5);
                float input = (newY * angle) + phase;
                 // radius * pointsIwant + howManyObjectsIwant + 2 * amplitude * Noise
                float radiusB = ((radius - (f * space)) + (g * spaceScale)) + 2 * amplitude * ofNoise(newY * cos(angle*100), newY * sin(angle));
             
                float x = (radiusB * cos(angle));
                float y = (radiusB * sin(angle));
                float color = 255 - (f * (255/totalDupli));
                float colorAlpha = 255 - (g * (255/totalScale)) + 50;
             
                ofSetColor(color, color, color, colorAlpha);
                ofDrawCircle(x, y, size);
             }
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
