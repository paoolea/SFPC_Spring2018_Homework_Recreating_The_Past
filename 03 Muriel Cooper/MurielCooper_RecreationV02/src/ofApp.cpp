#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(255, 244, 235);
    total = 12;
    
    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 100, true, true, 1);

    count = 0;
    
    colors.resize(4);
    
    colors[0] = ofPoint(241, 111, 44);
    colors[1] = ofPoint(106, 173, 196);
    colors[2] = ofPoint(251, 211, 48);
    colors[3] = ofPoint(255, 255, 255);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    float time = ofGetElapsedTimef();
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    float radius = 200;
    float colorEnd = 240;
    
    for(float i = 0; i < total; i++){
        float angle = ofMap(i, 0, total, 0, TWO_PI);
        float y = (radius * sin(angle));
        float color = colorEnd - (i * (colorEnd/total));
        
        float sinOfTime = sin((time+(i*0.2)) * 3);
        float newY = -100 + y + ofMap(sinOfTime, -1, 1, 0 , radius);
        
        
        ofSetColor(colors[count].x, colors[count].y, colors[count].z);
        
        //ofEnableDepthTest();
        cam.begin();
            ofPushMatrix();
                ofTranslate(-(680/2),  newY, -(200 * i));
                //ofNoFill();
                font.drawStringAsShapes("BAUHAUS", 0, 0);
                //ofDrawRectangle(0, 0, 680, 100);
            ofPopMatrix();
        cam.end();
        
        if(count == 3){
            count = 0;
        } else {
            count++;
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
