#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(220);
    ofSetCircleResolution(80);
    
    space = 35;
    wLine = 120.0f;
    m_stopSound = true;

    // setup sound
    soundStream.printDeviceList();
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    
    int bufferSize = 256;
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);

}

//--------------------------------------------------------------
void ofApp::update(){
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 0.5, true);
   // cout << ofRandom(scaledVol-1, scaledVol) << endl;
    ofSoundUpdate();
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(0);
    ofNoFill();
    ofSeedRandom(0);
    ofSetLineWidth(2);

    if(!m_stopSound){
        max += (scaledVol * wLine)* ofGetElapsedTimef();
        min += (-scaledVol * wLine)* ofGetElapsedTimef();
    }
       
  
    for (int x = 0; x < 15; x++){
        for (int y = 0; y < 15; y++){
            ofPoint a(ofRandom(-5,max),0);
            ofPoint b(ofRandom(25,50),0);
            ofPoint c(ofRandom(min,50),25);
            ofPoint d(ofRandom(-5, 30),25);
            
            ofPushMatrix();
            ofTranslate(120+x*space, 150+y*space);
            ofDrawLine(a,b);
            ofDrawLine(b,c);
            ofDrawLine(c,d);
            ofDrawLine(d,a);
            ofPopMatrix();
        }
    }
    
    min = 0;
    max = 0;
    
    ofDrawCircle(750, 750, scaledVol * 20.0f);

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 's' ){
        soundStream.start();
        m_stopSound = false;
    }
    
    if( key == 'm' ){
        m_stopSound = true;
        max = 50;
        min = 25;
        soundStream.stop();
    }

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
void ofApp::dragEvent(ofDragInfo info){
   
}

//--------------------------------------------------------------
void ofApp::audioIn(float * input, int bufferSize, int nChannels){
    
    float curVol = 0.0;
    int numCounted = 0;
    
    for (int i = 0; i < bufferSize; i++){
        left[i]        = input[i*2]*0.5;
        right[i]    = input[i*2+1]*0.5;
        
        curVol += left[i] * left[i];
        curVol += right[i] * right[i];
        numCounted+=2;
    }
    
    curVol /= (float)numCounted;
    curVol = sqrt( curVol );
    
    smoothedVol *= 0.93;
    smoothedVol += 0.07 * curVol;
    bufferCounter++;
}










