#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    ofSetFrameRate(60);
    
    //img.load("zach.jpg");
    curr = 0;
    
    ofPixels pix = img.getPixels();
    
    for(int i = 0; i < 15; i++){
        ofImage im;
        im.load("classmates/" + ofToString(i) + ".jpg");
        images.push_back(im);
    }
    
//
//    for(int x = 0; x < img.getWidth(); x++){
//        for(int y = 0; y < img.getHeight(); y++){
//            float index = x + y * img.getWidth();
//            ofColor col = img.getColor(x, y);
//            float b = col.getBrightness();
//
//            if(b > 250) {
//                ofPoint temp = ofPoint(x, y);
//                spots.push_back(temp);
//            }
//        }
//    }
    
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetLineWidth(2);
    
    //img.draw(0, 0);
   
    
    float total = 100;
    float count = 0;
    
    if(circles.size() < 3500){
        while (count < total){
            Circle newC = newCircle();
            
            if(newC.posX != -1) {
                circles.push_back(newC);
                count++;
            }
        }
    } else {
        //  Reset and go to next image
        if(curr < images.size() -1){
            curr++;
        } else {
            curr = 0;
        }
        
        circles.clear();
    }
    
    
    for(int i = 0; i < circles.size(); i++){
        Circle c = circles[i];
        if(c.growing){
            if(c.edges()) {
                circles[i].growing = false;
            } else {
                for(int j = 0; j < circles.size(); j++){
                    Circle other = circles[j];
                    if(i != j){
                        float d = ofDist(c.posX, c.posY, other.posX, other.posY);
                        
                        if(d - 2 < c.radius + other.radius){
                            circles[i].growing = false;
                            break;
                        }
                    }
                }
            }
        }
        
        c.draw();
        circles[i].grow();
    }
}

//--------------------------------------------------------------

Circle ofApp::newCircle(){
//    int r = int(ofRandom(0, spots.size()));
//    ofPoint spot = spots[r];
//    float x = spot.x;
//    float y = spot.y;
    float x = ofRandomWidth();
    float y = ofRandomHeight();
    bool valid = true;
    
    for(Circle c : circles){
        float d = ofDist(x, y, c.posX, c.posY);
        
        if(d < c.radius + 5){
            valid = false;
            break;
        }
    }
    
    if(valid) {
        int index = int(x + y * images[curr].getWidth());
        
        Circle temp;
        temp.setup(x, y, images[curr].getPixels().getColor(x, y));
        
        return temp;
    } else {
        Circle temp2;
        temp2.setup(-1, -1, ofColor(255, 255, 255));
        
        return temp2;
    }
}

