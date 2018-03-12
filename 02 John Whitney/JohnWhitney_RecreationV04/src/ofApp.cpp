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
    ofSetColor(255);
    ofSetLineWidth(3);
    ofSetColor(150, 223, 255);
    
    float time = ofGetElapsedTimef();
    float total = 6;
    float totalPoints = 2;
    float angle = -50;
    float angleB = 90;
    float width = 80;
    float widthB = 80;
    float longLine = 7;
    float size = 2;
    
    line.resize(total);
    line2.resize(total);
    lineB.resize(total);
    lineB2.resize(total);
    
    for(int i = 0; i < total; i++){
        float centerX = ofGetWidth()/2;
        float sinOfTimeX = sin((time * (3 + i))*0.3);
        float sinOfTimeY = sin((time *  (3 + i))*0.3);
        float x = centerX + ofMap(sinOfTimeX, -1, 1, -width, width);
        float y = (i * 100) + 170 + ofMap(sinOfTimeY, -1, 1, 0, angle);
        
        float sinOfTimeX2 = sin((time * (5 + i))*0.3);
        float sinOfTimeY2 = sin((time *  (5 + i))*0.3);
        float x2 = centerX + ofMap(sinOfTimeX2, -1, 1, -width, width);
        float y2 = (i * 100) + 170 + ofMap(sinOfTimeY2, -1, 1, 0, angle);
        
        ofPoint pt;
        pt.x = x;
        pt.y = y;
        
        if (line[i].size() > longLine)  line[i].getVertices().erase(line[i].getVertices().begin());
        
        line[i].addVertex(pt);
        line[i].draw();
        
        
        ////////////////
        ofPoint pt2;
        pt2.x = x2;
        pt2.y = y2;
        
        if (line2[i].size() > longLine/2) line2[i].getVertices().erase(line2[i].getVertices().begin());
        
        line2[i].addVertex(pt2);
       // line2[i].draw();
    }
    
    for(int but = 0; but < totalPoints; but++){
        for(int butB = 0; butB < total; butB++){
            float centerXBut = ofGetWidth()/2;
            float sinOfTimeXBut = sin((time * (3 + but))*0.3);
            float sinOfTimeYBut = sin((time *  (3 + but))*0.3);
            float xBut = centerXBut + ofMap(sinOfTimeXBut, -1, 1, -width, width);
            float yBut = (butB * 100) + 170 + ofMap(sinOfTimeYBut, -1, 1, 0, angle);
            
            //ofDrawCircle(xBut, yBut, size);
        }
    }
    
    ///////////////////////////////
    //////////////////////////////
    
    for(int iB = 0; iB < total; iB++){
        float centerXB = ofGetWidth()/2;
        float sinOfTimeXB = sin((time * (3 + iB))*0.3);
        float sinOfTimeYB = sin((time *  (3 + iB))*0.3);
        float xB = centerXB + ofMap(sinOfTimeXB, -1, 1, -widthB, widthB);
        float yB = (iB * 100) + 100 + ofMap(sinOfTimeYB, -1, 1, 0, angleB);
        
        float sinOfTimeXB2 = sin((time * (5 + iB))*0.3);
        float sinOfTimeYB2 = sin((time *  (5 + iB))*0.3);
        float xB2 = centerXB + ofMap(sinOfTimeXB2, -1, 1, -widthB, widthB);
        float yB2 = (iB * 100) + 100 + ofMap(sinOfTimeYB2, -1, 1, 0, angleB);
        
        ////////////////
        ofPoint ptB;
        ptB.x = xB;
        ptB.y = yB;
        
        if (lineB[iB].size() > longLine) lineB[iB].getVertices().erase(lineB[iB].getVertices().begin());
        
        lineB[iB].addVertex(ptB);
        lineB[iB].draw();
        
        ////////////////
        ofPoint ptB2;
        ptB2.x = xB2;
        ptB2.y = yB2;
        
        if (lineB2[iB].size() > longLine/2) lineB2[iB].getVertices().erase(lineB2[iB].getVertices().begin());
        
        lineB2[iB].addVertex(ptB2);
       // lineB2[iB].draw();
    }
    
    for(int butC = 0; butC < totalPoints; butC++){
        for(int butD = 0; butD < total; butD++){
            float centerXButC = ofGetWidth()/2;
            float sinOfTimeXButC = sin((time * (3 + butC))*0.3);
            float sinOfTimeYBut = sin((time *  (3 + butC))*0.3);
            float xButC = centerXButC + ofMap(sinOfTimeXButC, -1, 1, -widthB, widthB);
            float yButC = (butD * 100) + 100 + ofMap(sinOfTimeYBut, -1, 1, 0, angleB);
            
          //  ofDrawCircle(xButC, yButC, size);
        }
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
