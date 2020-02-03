#pragma once

#include "ofMain.h"
#include "FboSource.h"

class ThroughTop : public ofx::piMapper::FboSource {
	public:
        void setup();
		void update();
		void draw();
        void reset();
        void drawMovingRect(int, int, int, int, float);
        void setName(string _name);
        void setColor(ofColor);
     int startTime;
     
     void drawLine();
     
     float rectW,rectH;
     float phase;
     float lineW;
};
