#pragma once

#include "ofMain.h"
#include "FboSource.h"

class OpArt3 : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void drawMovingRect(int, int, int, int, float);
        void setName(string _name);
        void setColor(ofColor);
        float time;
        void rects(float locX,float sinMin,float sinMax);

    
    int startTime;
     
     float phase;
     float w,h;
     float startingX,startingY;
     float gapSize;
     int cols,rows;
     float spacing;
     float rectH;
     float rectW;
     
     float locY;
     bool start;
};
