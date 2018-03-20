#pragma once

#include "ofMain.h"
#include "myParticles.hpp"

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
    
    vector <myParticles> mParticles;
    float total;
    
    void loadCharacters(string s);
    
    ofEasyCam cam;
    vector<ofTTFCharacter> characters;
    ofPoint centerCharacter(string s);
    vector <string> vMyString;
    ofTrueTypeFont font;
    string myString;
    float coutPar;
};

