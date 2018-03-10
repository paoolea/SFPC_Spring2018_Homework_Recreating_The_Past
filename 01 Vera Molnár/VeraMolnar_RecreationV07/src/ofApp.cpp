#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
     ofBackground(46, 46, 134);
    
    m_total = 70;
    m_ampl = 100;
    m_points.resize(m_total);
    m_points[0] = ofPoint(0, m_ampl);
    
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
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(6, 186, 237);
    ofNoFill();
    ofSetLineWidth(1);
    ofSeedRandom(675);
    
   // cout << mouseX << endl;
    
    ofPushMatrix();
    ofTranslate(0, ofGetHeight()/2 - m_ampl/2);
    
    for(int i = 1; i < m_total; i++){
        if(i+1 >= m_total){
            
        } else {
            m_points[i] = ofPoint(m_points[i-1].x + ofRandom(-30, 60), ofRandom(0, m_ampl));
            ofDrawLine(m_points[i-1], m_points[i]);
        }
        
    }
    
    ofPopMatrix();
    ofDrawCircle(30, 30, scaledVol * 30.0f);
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if( key == 's' ){
        soundStream.start();
        m_stopSound = false;
    }
    
    if( key == 'm' ){
        m_stopSound = true;
        //max = 50;
        //min = 25;
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
void ofApp::dragEvent(ofDragInfo dragInfo){ 

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
