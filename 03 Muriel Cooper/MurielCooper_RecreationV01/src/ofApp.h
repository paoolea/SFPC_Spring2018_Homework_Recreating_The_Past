#pragma once

#include "ofMain.h"
#include "ofxFaceTracker.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    void createChar();
    
     // ------ General ------- //
    float total;
    float count;
    float maxScale;
    float longArray;
    float mouthWidth;
    vector <ofPoint> colors;
    vector <float> m_noise;
    vector <float> m_depth;
    vector <ofVec2f> m_points;
	
    // ------ Tracker ------- //
    ofVideoGrabber cam;
    ofxFaceTracker tracker;
    ExpressionClassifier classifier;
    
    // ------ Others ------- //
    ofTrueTypeFont font;
    ofEasyCam easyCam;
    
    // ------ Microphone ------- //
    void audioIn(float * input, int bufferSize, int nChannels);
    
    vector <float> left;
    vector <float> right;
    vector <float> volHistory;
    
    int bufferCounter;
    int drawCounter;
    float smoothedVol;
    float scaledVol;
    
    ofSoundStream soundStream;
};
