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
    ofSeedRandom(0);
    ofSetLineWidth(2);
    ofNoFill();
    
    float time = ofGetElapsedTimef();
    float sinOfTime = sin(time);
    float total = 20;
    float totalDupli = 4;
    float num = 1;
    float centerX = ofGetWidth()/2;
    float centerY = ofGetWidth()/2;
    float space = 1;
    float multi = 1;
    
    for(int i = 0; i < total; i++){
        float color = 255 - (i * 15);
        
        for(int f = 0; f < totalDupli; f++){
            float sinOfTime = sin((time * ((i+1)*0.5))*0.3);
            float rotationZ = ofMap(sinOfTime, -1, 1, 0, 360);
            
            
            ofPoint p1 = ofPoint(0, -75 + (i*space));
            ofPoint p2 = ofPoint(70 - (i*space), -25 + (i*(space/3)));
            ofPoint p3 = ofPoint(40 - (i*(space/2)), 55 - (i*(space/2)));
            ofPoint p4 = ofPoint(-40 + (i*(space/2)), 55 - (i*(space/2)));
            ofPoint p5 = ofPoint(-70 + (i*space), -25 + (i*(space/3)));
            
            ofPushMatrix();
                ofSetColor(255, 255, 255, color);
                ofTranslate(centerX, centerY - (((f*multi)+1)));
                ofScale(1 + (f*multi), 1 + (f*multi));
                ofRotateZ(rotationZ);
                ofBeginShape();
                    ofVertex(p1);
                    ofVertex(p2);
                    ofVertex(p3);
                    ofVertex(p4);
                    ofVertex(p5);
                ofEndShape(true);
            
                ofSetColor(255);
            
                //ofDrawCircle(0, 0, 20);
            ofPopMatrix();
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
