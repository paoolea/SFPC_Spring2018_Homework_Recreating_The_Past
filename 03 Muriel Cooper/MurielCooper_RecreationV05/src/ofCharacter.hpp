//
//  ofCharacter.hpp
//  MurielCooper_RecreationV05
//
//  Created by pao on 3/17/18.
//

#include "ofMain.h"
#pragma once

class ofCharacter : public ofBaseApp{
    
public:
    void setup(string s);
    void update();
    void draw(int id, float nX, float nY, float depthY, float timeSpace, ofPoint myColor);
    void loadCharacters(string s);
    
    ofTrueTypeFont font;
    string myString;
    
    vector<ofTTFCharacter> characters;
    ofPoint centerCharacter(string s);
    
};

