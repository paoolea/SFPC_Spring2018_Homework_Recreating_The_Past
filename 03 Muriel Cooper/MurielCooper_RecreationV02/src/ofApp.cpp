#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    ofSetLineWidth(2);

    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 150, true, true, true);
    myString = "SFPC";
    loadCharacters(myString);

    //////////////
    soundStream.printDeviceList();
    int bufferSize = 256;
    
    left.assign(bufferSize, 0.0);
    right.assign(bufferSize, 0.0);
    volHistory.assign(400, 0.0);
    
    bufferCounter    = 0;
    drawCounter        = 0;
    smoothedVol     = 0.0;
    scaledVol        = 0.0;
    
    soundStream.setup(this, 0, 2, 44100, bufferSize, 4);
}

//--------------------------------------------------------------
void ofApp::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
}

//--------------------------------------------------------------
ofPoint ofApp::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}

//--------------------------------------------------------------
void ofApp::update(){
     scaledVol = ofMap(smoothedVol, 0.0, 0.17, 0.0, 1.0, true);
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    float sizeCir = 1;
    float jumpDots = 2;
    float coutDot = 50;
    float spaceZdots = 3;
    float maxColor = 255;
    
    float time = ofGetElapsedTimef() * 1.5;
    float stageW = ofGetWidth();
    float stageH = ofGetHeight();

    cam.begin();
    ofPushMatrix();
    //ofTranslate(stageW/2, stageH/2 - 10);
     ofTranslate(0, -120);
    ofTranslate(centerCharacter(myString));
    ofSetLineWidth(2);
    
    
    for(int i = 0; i < characters.size(); i++){
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(5);
            
            for (int i = 0; i < line.size(); i += jumpDots) {
                ofPoint point = line[i];
                
                for (int m = 1; m < coutDot; m++) {
                    float depthZ = (m * spaceZdots);
                    float noiseZ = ofNoise(2 * cos(depthZ), 2 * sin(depthZ)) * depthZ;
                    float sinOfTimeX = sin((time) * 0.5);
                    float sinOfTimeY = sin((time) * 0.5);
                    float sinOfTimeZ = sin((time) * 2);
                    float moveMicro = 1;
//                    float newX = ofMap(sinOfTimeX, -1, 1, 0, ofRandom(-moveMicro, moveMicro));
//                    float newY = ofMap(sinOfTimeY, -1, 1, 0, ofRandom(-moveMicro, moveMicro));
                    float newX = ofRandom(-moveMicro, moveMicro);
                    float newY = ofRandom(-moveMicro, moveMicro);
                    float newZ = ofRandom(-(moveMicro + depthZ), (moveMicro + depthZ)) ;
                    
                    float newRotX = ofMap(sinOfTimeX, -1, 1, -50, 50);
                    float newRotY = ofMap(sinOfTimeY, -1, 1, -50, 50);
                    
                    float rotateY = ofRandom(0, newRotY);
                    float rotateX = ofRandom(0, newRotX);
                    float x = point.x + 0;
                    float y = point.y + 0;
                    
                    
                    ofPushMatrix();
                    ofSetColor(maxColor - (m * (maxColor/coutDot)));
                    ofRotateY(rotateY);
                    ofRotateX(rotateX);
                    ofTranslate(x, -y + newY, newZ);
                    
                    ofDrawCircle(0, 0, sizeCir);
                    ofPopMatrix();
                }
            }
        }
    }
    ofPopMatrix();
    cam.end();
    
    //ofSetColor(255);
    //ofDrawCircle(100, 100, scaledVol * 190);
    //cout << scaledVol * 30 << endl;
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
    cout << "drag" << endl;
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
