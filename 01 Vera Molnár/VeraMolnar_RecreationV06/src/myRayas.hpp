#pragma once

#include "ofMain.h"

class myRayas : public ofBaseApp{
    
public:
    void setup(float width);
    void update();
    void draw(float x, float y);
    
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
    
    
    vector <ofPoint> m_pointsX;
    float m_widthSquare;
    float m_total;
};

