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
    
    ofPushMatrix();
    ofTranslate(stageW/2, stageH/2 - 10);
    ofTranslate(centerCharacter(myString));
    ofSetLineWidth(2);
    
    for(int i = 0; i < characters.size(); i++){
        // Detect every letter of my string
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            // Detect every dots for every letter
            ofPolyline line = lines[j].getResampledBySpacing(5);
            
            // Fill letters
            ofPath path;
            for( int p = 0; p < line.getVertices().size(); p++) {
                if(p == 0) {
                    path.newSubPath();
                    path.moveTo(line.getVertices()[p]);
                } else {
                    path.lineTo(line.getVertices()[p]);
                    
                    ofSetColor(255, 0, 0);
                    ofDrawCircle(line.getVertices()[p], 2);
                }
            }
            
            path.close();
            path.simplify();
            path.draw();
            
            
            for (int k = 0; k < line.size(); k += jumpDots) {
                ofPoint point = line[k];
                
                for (int m = 1; m < coutDot; m++) {
                    float x = point.x ;
                    float y = point.y ;
                    
                    ofPushMatrix();
                    ofSetColor(255);
                    ofTranslate(x, y, 1);
                    ofDrawCircle(0, 0, sizeCir);
                    ofPopMatrix();
                }
            }
        }
    }
    
    
    
    ofPopMatrix();
    
    //ofSetColor(255);
    //ofDrawCircle(100, 100, scaledVol * 190);
    //cout << scaledVol * 30 << endl;
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

