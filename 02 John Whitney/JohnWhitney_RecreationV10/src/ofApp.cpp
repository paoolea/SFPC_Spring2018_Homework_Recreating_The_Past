#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofBackground(0);
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0);
    ofSetLineWidth(3);

	float time = ofGetElapsedTimef();
	float total = 20;

	line.resize(total);

	for (int i = 1; i < total; i++) {
		float width = 250;
		float centerY = 125;
		float sinOfTimeX = sin((time * (2 + i))*0.3);
		float x = ofMap(sinOfTimeX, -1, 1, 100, ofGetWidth() - 100);
		float sinOfTimeY = sin((time*((i + 1) * 2)) *0.1);
		float y = ofGetHeight() / 2 + ofMap(sinOfTimeY, -1, 1, 0, 300) - 150;
        float color = 10 + (i * 10);

		//cout << y << endl;
		ofSetColor(223,255, 255, 255);
		//ofDrawCircle(x, y, 5);
        //ofSetColor(223,141, 46, color);

		ofPoint pt;
		pt.x = x;
		pt.y = y;

		if (line[i].size() > ((i + 1)/3)) {
			line[i].getVertices().erase(line[i].getVertices().begin());
		}

		line[i].addVertex(pt);
		line[i].draw();
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
