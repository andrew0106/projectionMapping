#include "LinesVideo.h"

void LinesVideo::setup(){
	// Give our source a decent name
    name = "Lines Video";
//    rectColor = ofColor(255);
    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(720,480);
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    this->beginFbo();
//    ofClear(0);
    this->endFbo();
    
    video.load("movieTest2_2.mov");

    spacing=5;
    startPos=spacing/2;
    
    
}

void LinesVideo::reset(){
//    reset is called optionally. if you leave it empty nothing is happening

    startTime=ofGetElapsedTimeMillis();
}

void LinesVideo::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void LinesVideo::update(){

    video.update();
    pixels = video.getPixels();
    
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void LinesVideo::draw(){
    ofClear(0);
    video.play();

    for (int j=0; j<fbo->getHeight(); j+=spacing){
        ofPolyline poly;
        for(int i=0; i<fbo->getWidth(); i++){

            ofColor c = pixels.getColor(i,j);
            int brightness = c.getBrightness();
            poly.addVertex(i, j+ofMap(brightness,0,255,0,-64));
        }
       poly = poly.getSmoothed(10);
       poly.draw();

     }

}


