#pragma once

#include "ofMain.h"
#include "FboSource.h"

class RandomLine : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void drawMovingRect(int, int, int, int, float);
        void setName(string _name);
        void setColor(ofColor);
     int startTime;
    
    void crazyLines(float s);
    void crazyLines1(float s);
    void crazyLines2(float s);
    
    float lineH;
    float lineH1;
    float lineH2;
    
    float scene2A,scene2B;
    float phase;
    
    float rectH1;
    
    ofPolyline line;
    ofPolyline line1;
    ofPolyline line2;
    ofPolyline line3;
    
    
     
     
};
