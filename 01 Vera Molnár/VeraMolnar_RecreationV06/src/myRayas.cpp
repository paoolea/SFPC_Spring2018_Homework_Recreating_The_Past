#include "myRayas.hpp"

//--------------------------------------------------------------
void myRayas::setup(float width){

    m_total = 10;
    m_pointsX.resize(m_total);
    m_widthSquare = width;
    
}

//--------------------------------------------------------------
void myRayas::update(){
    
}

//--------------------------------------------------------------
void myRayas::draw(float x, float y){

     cout << x << endl;
    
        for(int i = 0; i < m_total; i++){
            m_pointsX[i] = ofPoint(ofRandom(x, x+m_widthSquare), ofRandom(y, y+m_widthSquare));

            ofPushMatrix();
            
            if(i+1 >= m_total){
                //ofDrawLine(m_pointsX[i], m_pointsX[i]);
            } else {
                ofDrawLine(m_pointsX[i], m_pointsX[i+1]);
            }
            
            ofPopMatrix();
        }
   
}

//--------------------------------------------------------------
void myRayas::keyPressed(int key){
    
}

//--------------------------------------------------------------
void myRayas::keyReleased(int key){
    
}

//--------------------------------------------------------------
void myRayas::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void myRayas::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void myRayas::mousePressed(int x, int y, int button){
    
}

//--------------------------------------------------------------
void myRayas::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void myRayas::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void myRayas::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void myRayas::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void myRayas::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void myRayas::dragEvent(ofDragInfo dragInfo){
    
}

