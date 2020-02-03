#include "LinesVideo2.h"

void LinesVideo2::setup(){
	// Give our source a decent name
    name = "Lines Video2";

    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(720,480);
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    this->beginFbo();

    this->endFbo();
    
    video.load("movieTest2_2.mov");

    spacing=5;
    startPos=spacing/2;
    
    
}

void LinesVideo2::reset(){
//    reset is called optionally. if you leave it empty nothing is happening

    startTime=ofGetElapsedTimeMillis();
}

void LinesVideo2::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void LinesVideo2::update(){

    video.update();
    pixels = video.getPixels();
    
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void LinesVideo2::draw(){
    ofClear(255);
    video.play();

    for (int j=0; j<fbo->getHeight(); j+=spacing){
        ofPolyline poly;
        for(int i=0; i<fbo->getWidth(); i++){

            ofColor c = pixels.getColor(i,j);
            int brightness = c.getBrightness();
            poly.addVertex(i, j+ofMap(brightness,0,255,0,-64));
        }
       poly = poly.getSmoothed(10);
       ofSetColor(0);
       poly.draw();

     }

}


