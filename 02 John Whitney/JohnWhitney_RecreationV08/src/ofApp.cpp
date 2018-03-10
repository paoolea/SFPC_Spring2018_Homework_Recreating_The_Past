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
        float color = 255 - (i * 55);
        
        ofSetColor(220, 220, 255, color);
        
        ofPoint pt;
        pt.x = xorig + radius * cos(angle);
        pt.y = yorig + radius * sin(angle);
        
        line[i].addVertex(pt);
        
        if (line[i].size() > 150){
            line[i].getVertices().erase(line[i].getVertices().begin());
        }
        
        line[i].draw();
        
        ofSetColor(255);
       // ofDrawCircle(pt, 5);
        
       /* for(int f = 0; f < 10; f++){
            float nX = pt.x - (5 * f);
            float nY = pt.y + (15 * f);
            
            ofDrawCircle(nX, nY, 5);
        }
        */
        
        
        
        
    }
    
    for(int f = 1; f < 3; f++){
        myWidthMax = 300 - (f*30);
        float radiusA = ofMap(sin((time*10) + f), -1, 1, 0, myWidthMax);
        float angleA = ofGetElapsedTimef()*(f*2);
        
        
        ofPoint ptA;
        ptA.x = xorig + radiusA * cos(angleA);
        ptA.y = yorig + radiusA * sin(angleA);
        
        
        ofSetColor(255);
        ofDrawCircle(ptA, 5);
        
        
    }
  
   /*
    for(int i = 1; i < 2; i++){
        float xorig = 400;
        float yorig = 400;
        float myWidthMax = 300;
        
        float sinOfTimeX = sin((time * (10+i))*0.1);
        float x = ofGetHeight() / 2 + ofMap(sinOfTimeX, -1, 1, -200, 200);
        
        float sinOfTimeY = sin((time * (10+i))*0.3);
        //float y = ofGetHeight() / 2 + ofMap(sinOfTimeY, -1, 1, -200, 200);
        float y = ofGetHeight()/2;
        
        float radius = ofMap(sin(time), -1, 1, 0, myWidthMax);
        float angle = ofGetElapsedTimef()*(i*2);
        float color = 255 - (i * 45);
        //float x = ofGetWidth()/2;
        //float y = ofGetHeight() / 2 + ofMap(sin(radius), -1, 1, 0, 200);
        
        ofSetColor(255);
        ofDrawCircle(x, y, 5);
        
        float xA = myWidthMax * cos(theta);
        float yA = myWidthMax * sin(theta);
        

        // Adjust for center of window
        ofDrawCircle(xA + ofGetWidth()/2, yA + ofGetHeight()/2, 16, 16);
        
        // Increment the angle
        theta += 0.01;
    }
    */
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

