#include "OpArt2.h"

void OpArt2::setup(){
	// Give our source a decent name
    name = "op Art2";
//    rectColor = ofColor(255);
    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(800,295);

    this->beginFbo();
    ofClear(ofColor(0));
    ofSetRectMode(OF_RECTMODE_CENTER);
    this->endFbo();
    
    
    cols=10;
    rows=5;
    rectH=30;
    rectW=30;
    startingX;
    startingY=10;
    spacing=rectH*2;
    locX=50;

    
}

void OpArt2::reset(){
//    reset is called optionally. if you leave it empty nothing is happening
    startTime=ofGetElapsedTimeMillis();
}

void OpArt2::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void OpArt2::update(){
    phase++;
    if(locX>800){
        locX=800;
    }else{locX++;}

}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void OpArt2::draw(){
  

    ofClear(0);

    ofSetColor(255);
    ofDrawRectangle(0,0, locX, 295);

    for(int i = 15; i <fbo->getWidth(); i+=60){
        rects(i,0,rectW);
    }
    for(int i = 45; i <fbo->getWidth(); i+=60){
        rects(i,rectW,0);
    }
    
}

void OpArt2::rects(float locX,float sinMin, float sinMax){
    ofSetColor(0);
    
    for(int i=0;i<rows;i++){
        
        int locY1 = spacing*i;
        int locY2 = spacing/2+(spacing*i);
        
        ofPushMatrix();
        ofTranslate(locX,locY1);
        
        float s = sin(ofDegToRad(phase));
        h = ofMap(s,0,1,sinMin,sinMax);
        ofDrawRectangle(0,startingY,h,rectH);
        ofPopMatrix();
        
        float b = sin(ofDegToRad(phase));
        ofPushMatrix();
        ofTranslate(locX,locY2);
        float z = ofMap(b,0,1,sinMax,sinMin);
        ofDrawRectangle(0,startingY,z,rectH);
        ofPopMatrix();
        
    }
}
