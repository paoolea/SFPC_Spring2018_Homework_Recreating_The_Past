#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofBackground(0);
	ofSeedRandom(0);
    ofEnableSmoothing();

	total = 5;
	line.resize(total);
	colors.resize(total);

	colors[0] = ofPoint(185, 29, 159);
	colors[1] = ofPoint(101, 179, 56);
	colors[2] = ofPoint(223, 141, 46);
	colors[3] = ofPoint(244, 210, 232);
	colors[4] = ofPoint(178, 40, 45);
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	ofSetColor(255);
	ofSetLineWidth(3);


	float time = ofGetElapsedTimef();
	float width = 250;
	float sinOfTimeX;
	float centerX;

	for (int i = 0; i < total; i++) {
		float sinOfTimePosX;
		float sinOfTimeY = sin((time * 10)*0.3);
		float y = ofMap(sinOfTimeY, -1, 1, -60, ofGetHeight() + 60);
		float x;

		// Detect when the element touch the Top or Bottom
		if (y >= ofGetHeight() + 50) change = true;
		if (y <= -50) change = false;

		// When is the first element the with change
		if (i > 0) {
			ofSetLineWidth(3);
			if (change) width = -(170 - (i * 40));
			if (!change) width = 170 - (i * 40);
			centerX = width / 2;
			sinOfTimeX = sin((time*((i + 1) * 30))*0.3);
		} else {
			ofSetLineWidth(5);
			width = 350;
			centerX = width / 2;
			sinOfTimeX = sin((time*((i + 1) * 30))*0.3);
		}

		
		sinOfTimePosX = ofMap(sinOfTimeX, -1, 1, 0, width);
		x = ofGetWidth() / 2 + sinOfTimePosX - centerX;
		
		//cout << y << endl;
		ofSetColor(255, 0, 0);
		//ofDrawCircle(x, y, 10);
		ofSetColor(colors[i].x, colors[i].y, colors[i].z);

		// Create points and lines
		ofPoint pt;
		pt.x = x;
		pt.y = y;

		if(line[i].size() > 10*(i+1)) {
			line[i].getVertices().erase(line[i].getVertices().begin());
		}

		line[i].addVertex(pt);
		line[i].draw();
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}
