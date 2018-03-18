#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    m_font.load("HelveticaNeueLTStd-Bd.otf", 150, true, true, 100);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    /*ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    
    ofSetColor(255, 255, 0, 100);
    m_font.drawString("wolas", 200, 300);
    
    ofRectangle bounds = m_font.getStringBoundingBox("WOLAS", 200, 300);
    ofNoFill();
    ofDrawRectangle(bounds);
    bounds.scaleFromCenter(1, 1);
    
    ofFill();
    ofSetColor(255, 0, 0, 100);
    ofDrawCircle(200, 100, 200);*/
    
    // Rotate camera with face
    // With sound create text
    // BAUHAUS, MURIEL, COOPER, SFPC, RECREATING THE PAST
    
    // ------------- 3D ------------- //
    ofEnableDepthTest();
    //cam.enableOrtho();
    cam.begin();
        ofSetColor(255);
        m_font.drawStringAsShapes("WOLAS", 0, 0);
       // m_font.drawString("wolas", 0, 0);
       // ofDrawRectangle(0, 0, 100, 100);
        ofPushMatrix();
            ofRotateY(90);
            ofSetColor(255, 0, 0);
            m_font.drawStringAsShapes("WOLAS", 0, 0);
            //m_font.drawString("wolas", 0, 0);

            //ofDrawRectangle(0, 0, 100, 100);
        ofPopMatrix();
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
