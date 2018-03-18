#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(243, 235, 223);
    total = 3;
    count = 0;
    
    font.load("fonts/HelveticaNeueLTStd-Bd.otf", 190, true, true, 1);
    
    // colors
    colors.resize(3);
    colors[0] = ofPoint(0, 174, 239);
    colors[1] = ofPoint(237, 25, 109);
    colors[2] = ofPoint(255, 242, 0);
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
    float moveY = 50;
    float colorEnd = 240;
    float hightText = 20;
    
    for(float i = 0; i < total; i++){
        //float angle = ofMap(i, 0, total, 0, TWO_PI);
        float y = centerY + 67;
        float x = 60;
        float sinOfTime = sin((time+(i*0.2)) * 3);
        float newX = x + ofMap(sinOfTime, -1, 1, 0 , (i*15));
        float color = colorEnd - (i * (colorEnd/total));
       // float sinOfTime = sin((time+(i*0.2)) * 3);
       // float newY = (centerY - (hightText/2)) + y + ofMap(sinOfTime, -1, 1, 0 , moveY);
        
        ofSetColor(colors[count].x, colors[count].y, colors[count].z, 229);
        
        ofPushMatrix();
            ofTranslate(newX,  y);
            font.drawStringAsShapes("SFPC", 0, 0);
        ofPopMatrix();
        
        // Change color
        if(count == 2){
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
