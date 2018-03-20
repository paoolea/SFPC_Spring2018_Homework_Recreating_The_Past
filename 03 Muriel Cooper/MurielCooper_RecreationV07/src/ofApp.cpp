#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofEnableSmoothing();
    ofSetCircleResolution(80);
    ofSetLineWidth(2);
    coutPar = 0;
    
    total = 543;
    mParticles.resize(total);
    
    font.load("fonts/HelveticaNeueLTStd-Blk.otf", 150, true, true, true);
    myString = "SFPC";
    loadCharacters(myString);
    
    gui.setup(); // most of the time you don't need a name
    gui.add(guiSpeed.setup("speed", 10, 0, 15));
    gui.add(guiForce.setup("force", 1.0, 1.0, 10.0));
    
}

//--------------------------------------------------------------
void ofApp::loadCharacters(string s) {
    characters = font.getStringAsPoints(s);
   
    for(int i = 0; i < characters.size(); i++){
        vector<ofPolyline> lines = characters[i].getOutline();
        
        for(int j = 0; j < lines.size(); j++){
            ofPolyline line = lines[j].getResampledBySpacing(5);
            
            for (int k = 0; k < line.size(); k++) {
                ofPoint point = line[k];
                float x = point.x + 120;
                float y = point.y + ofGetHeight()/2 + 50;
                
                mParticles[coutPar].setup(ofVec3f(x, y, 0));
                coutPar++;
            }
        }
    }

}

//--------------------------------------------------------------
ofPoint ofApp::centerCharacter(string s) {
    auto bounds = font.getStringBoundingBox(s, 0, 0);
    return ofPoint(-bounds.width/2, bounds.height/2);
}

//--------------------------------------------------------------
void ofApp::update(){
    for (int i = 0; i < total; i++) {
        mParticles[i].maxSpeed = guiSpeed;
        mParticles[i].maxForce = guiForce;
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSeedRandom(0);
    
    float time = ofGetElapsedTimef() * 1.5;
    float stageW = ofGetWidth();
    float stageH = ofGetHeight();
    
   // cam.begin();
    ofPushMatrix();
    ofTranslate(0, 0);

    for(int i = 0; i < total; i++){
        mParticles[i].behaviors();
        mParticles[i].update();
        mParticles[i].draw();
    }

    ofPopMatrix();
   // cam.end();
    
    gui.draw();
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

