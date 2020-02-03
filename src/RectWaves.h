#pragma once

#include "ofMain.h"
#include "FboSource.h"

class RectWaves : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void drawMovingRect(int, int, int, int, float);
        void setName(string _name);
        void setColor(ofColor);
        void drawRect(float locY, float ly);
        ofColor rectColor;
        float time;
    
    
    float rectSize;
    float phase;
    float sp ;
    int rectOfNums;
    float lx;
    
    int startTime;
    
    bool change;
    
};
