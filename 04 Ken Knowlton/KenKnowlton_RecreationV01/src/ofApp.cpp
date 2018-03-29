#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0);
    ofSetCircleResolution(80);
    
    // ------ Gui ------- //
    gui.setup(); // most of the time you don't need a name
    gui.add(guiMin.setup("min", 1, 1, 10));
    gui.add(guiMax.setup("max", 3, 1, 10));
    
    camW = 640;
    camH = 480;
    
    camera.setup(camW, camH);
    img.setImageType(OF_IMAGE_GRAYSCALE);
    
    mesh.setMode(OF_PRIMITIVE_POINTS);
    mesh.enableColors();
}

//--------------------------------------------------------------
void ofApp::update(){
    camera.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    camera.draw(camW, 0, -camW, camH);
    // unsigned char * pix = camera.getPixels();
    //    ofPushMatrix();
    //    ofTranslate(camW*2, 0);
    //    for(int x = 0; x < camera.getWidth(); x += 10){
    //        for(int y = 0; y < camera.getHeight(); y += 10){
    //            ofPixels color = camera.getPixels();
    //            float brightness = color.getColor(x, y).getBrightness();
    //            float mapB = ofMap(brightness, 0, 255, guiMin, guiMax);
    //
    //            ofDrawCircle(-x, y, mapB);
    //
    //        }
    //    }
    //    ofPopMatrix();
    
    ofPushMatrix();
    ofTranslate(camW, 0);
    for(int x = 0; x < camW; x += 10){
        for(int y = 0; y < camH; y += 10){
            ofPixels pix = camera.getPixels();
            ofColor color = pix.getColor(x, y);
            float intensity = color.getLightness();
            
            if (intensity >= 150) {
                ofVec3f pos(x, y, 0.0);
                mesh.addVertex(pos);
                mesh.addColor(color);
            }
        }
    }
    mesh.draw();
    ofPopMatrix();
    
    
    
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

