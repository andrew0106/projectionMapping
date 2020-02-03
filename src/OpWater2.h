#pragma once

#include "ofMain.h"
#include "FboSource.h"

class OpWater2 : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void drawMovingRect(int, int, int, int, float);
        void setName(string _name);
        void setColor(ofColor);
        float time;
        

    
     int startTime;
     
     int rows,cols;
     float phase;
     float rectSize;
     float spacing;
     float startingX,startingY;
     float rectSizeS;
     float rectH;
    
     float mode2Phase;
     bool mode1,mode3;
};
