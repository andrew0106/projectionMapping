#pragma once

#include "ofMain.h"
#include "Settings.h"
#include "ofxPiMapper.h"
#include "RunCorner.h"
#include "RectWaves.h"
#include "OpArt1.h"
#include "OpArt2.h"
#include "OpArt3.h"
#include "OpWater.h"
#include "OpWater2.h"
#include "ThroughFront.h"
#include "ThroughTop.h"
#include "LinesVideo.h"
#include "LinesVideo2.h"
#include "RandomLine.h"
#include "VideoSource.h"
#include "SceneManager.h"

class ofApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
	
		void keyPressed(int key);
		void keyReleased(int key);
	
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseDragged(int x, int y, int button);

		ofxPiMapper piMapper;

		// By using a custom source that is derived from FboSource
		// you will be able to see the source listed in sources editor
        RunCorner * runCorner;
        RectWaves * rectWaves;
        OpArt1 * opArt1;
        OpArt2 * opArt2;
        OpArt3 * opArt3;
        OpWater * opWater;
        OpWater2 * opWater2;
        ThroughFront * throughFront;
        ThroughTop * throughTop;
        LinesVideo * linesVideo;
        LinesVideo2 * linesVideo2;
        RandomLine * randomLine;
        ofImage dummyObjects;

        SceneManager sceneManager;
};
