#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

//--------------------------------------------------------------
void ofApp::setup() {
    ofBackground(66);
    //ofBackground(255, 244, 235);
    
    ofSetVerticalSync(true);
    cam.initGrabber(1280, 720);

    tracker.setup();
    tracker.setRescale(.5);
    
    font.load("fonts/HelveticaNeueLTStd-Bd.otf", 100, true, true, 1);
    
    maxScale = 30;
    total = 0;
    longArray = 3;
    mouthWidth = 160;
    
    // --------- MICROPHONE --------- //
    soundStream.printDeviceList();
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter = 0;
    drawCounter = 0;
    smoothedVol = 0.0;
    scaledVol = 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
    
    // --------- COLORS --------- //
    count = 0;
    colors.resize(6);
    colors[0] = ofPoint(255, 111, 44);
    colors[1] = ofPoint(255, 111, 44);
    colors[2] = ofPoint(106, 173, 20);
    colors[3] = ofPoint(106, 173, 20);
    colors[4] = ofPoint(251, 211, 48);
    colors[5] = ofPoint(251, 211, 48);

}

//--------------------------------------------------------------
void ofApp::update() {
    cam.update();
    if(cam.isFrameNew()) {
        if(tracker.update(toCv(cam))) {
            classifier.classify(tracker);
        }
    }
    
    scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
}

//--------------------------------------------------------------
void ofApp::draw() {
    float centerX = ofGetWidth()/2;
    float centerY = ofGetHeight()/2;
    
    // --------- CAMERA --------- //
    ofDisableBlendMode();
    ofEnableBlendMode(OF_BLENDMODE_DISABLED);
    ofSetColor(255, 111, 44);
    ofPushMatrix();
    cam.draw(cam.getWidth(),0,-cam.getWidth(),cam.getHeight());
    ofPopMatrix();
    
    // --------- TRACKER --------- //
    //tracker.draw();
    ofVec2f mouth = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH).getCentroid2D();
    ofDrawCircle(ofGetWidth() - mouth.x, mouth.y, 10);
    
    
    // --------- STRING --------- //
    ofEnableAlphaBlending();
    ofEnableBlendMode(OF_BLENDMODE_MULTIPLY);
    
    easyCam.begin();
    for(int i = 0; i < total; i++){
        float scale = m_noise[i]/10;
        float x = m_points[i].x - (200 * scale) - centerX;
        float y = (centerY - (50 * scale)) - (m_points[i].y);
       // float mathDepth = (100 * m_depth[i]) / mouthWidth;
        float depth =  ofMap(m_depth[i], 0, 200, 1, 100);
  
        cout << m_depth[i] << endl;
        
        //ofSetColor(colors[count].x, colors[count].y, colors[count].z), 50;
        ofSetColor(255, 100, 100, 50);
        ofPushMatrix();
        ofTranslate(x, y, -depth);
        ofScale(scale, scale);
        font.drawStringAsShapes("sfpc", 0, 0);
        ofPopMatrix();
        
        if (m_points.size() > 100) {
            total--;
            m_points.erase(m_points.begin());
            m_noise.erase(m_noise.begin());
            m_depth.erase(m_depth.begin());
        }
        
        if(count == 5){
            count = 0;
        } else {
            count++;
        }
    }
    easyCam.end();

    // --------- MICROPHONE --------- //
    float volume = scaledVol * 190;
    if(volume > longArray){
        createChar();
    }
}

//--------------------------------------------------------------
void ofApp::createChar() {
    m_points.resize(total);
    
    ofVec2f mouthNew = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH).getCentroid2D();
    float mouthWidth = tracker.getImageFeature(ofxFaceTracker::INNER_MOUTH).getPerimeter();
    
    m_points.push_back(ofPoint(ofGetWidth() - mouthNew.x, mouthNew.y));
    m_depth.push_back(mouthWidth);
    m_noise.push_back(scaledVol * maxScale);
    
    total++;
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
    
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if (key == 'c'){
        createChar();
    }
    
    if (key == 'd'){
        total = 0;
        m_points.clear();
        m_noise.clear();
    }
    
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
        left[i] = input[i*2]*0.5;
        right[i] = input[i*2+1]*0.5;
        
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
