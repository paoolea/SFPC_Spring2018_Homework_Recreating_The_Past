#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(245, 192, 2);
    //ofEnableSmoothing();
    
    maxX = 4;
    maxY = 4;
    midX = 3;
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofNoFill();
    ofSetColor(0);
    ofSetLineWidth(2);
    
    float radius = 100;

    cam.begin();
    ofTranslate(-200, 100);
    
    
    for (int x = 0; x < maxX; x++){
        for (int y = 0; y < maxY; y++){
            
            
            if(y <= midX){
                if(y == 0){
                    ofPushMatrix();
                    ofTranslate(x*radius, -y*radius);
                    ofRotateY(73);
                    ofSetColor(255);
                    ofDrawLine(0, 100, 105, 152);
                    ofPopMatrix();
                }
                
                
                
                ofSetColor(0);
                ofDrawBitmapString(y, x*radius, -y*radius);
                ofDrawRectangle(x*radius, -y*radius, radius, radius);
                
                ofPushMatrix();
                ofTranslate(x*radius, -y*radius);
                ofRotateY(73);
                ofSetColor(255);
                ofDrawLine(0, 0, 105, 52);
                ofPopMatrix();
                
                
                ofPushMatrix();
                ofSetColor(0);
                ofTranslate(0, 0, -100);
                ofDrawRectangle(x*radius+30, -y*radius+50, radius, radius);
                ofPopMatrix();
                
             
            }
        
        }
        
        if(midX <= 3 && midX > 0){
            midX--;
        } else{
            midX = 3;
        }
        
    
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
