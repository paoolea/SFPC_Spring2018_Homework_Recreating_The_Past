#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    img.load("kelly.jpg");
    
    // Scale image
    scl = 10;
    w = img.getWidth()/scl;
    h = img.getHeight()/scl;
    
    small.clone(img);
    small.resize(w, h);
    small.setImageType(OF_IMAGE_COLOR);
    pix = small.getPixels();

    LoadClassmates();
}

//--------------------------------------------------------------
void ofApp::LoadClassmates(){
    ofDirectory dir;
    
    int nFiles = dir.listDir("classmates");
    if(nFiles) {
        for(int i = 0; i < dir.size(); i++) {
            string filePath = dir.getPath(i);

            mates.push_back(ofImage());
            mates.back().load(filePath);
            mates[i].resize(w, h);
            
            // read the all pixel from every iamge
            float bImg = 0;
            for(int j = 0; j < mates[i].getPixels().size(); j++){
                float b = mates[i].getPixels()[j];
                bImg += b;
            }
            
            bImg /= mates[i].getPixels().size();
            brighness.push_back(bImg);
        }
    } else ofLog(OF_LOG_WARNING) << "Could not find folder";
    
    
    // Ask for the brighness for every image
    brighImgs.resize(256);
    
    for(int i = 0; i < brighImgs.size(); i++) {
        float record = 256;
        for(int j = 0; j < brighness.size(); j++){
            float dif = abs(i - brighness[j]);
            
            if(dif < record){
                record = dif;
                brighImgs[i] = mates[j];
            }
        }
    }
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    //img.draw(0, 0);
    
    for(int x = 0; x < w; x++){
        for(int y = 0; y < h; y++){
            float c = pix.getColor(x, y).getBrightness();
            float scale = 1;
            
           ofImage temp;
            temp = brighImgs[c];
            temp.setImageType(OF_IMAGE_GRAYSCALE);
            temp.draw(x * scl*scale, y * scl*scale, scl*scale, scl*scale);
            
            // ofSetColor(c);
           // ofDrawRectangle(x * scl, y * scl, scl, scl);
        }
    }
    
    ofSetColor(255);
    //small.draw(0, 0);
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
