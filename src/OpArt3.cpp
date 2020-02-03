#include "OpArt3.h"

void OpArt3::setup(){
	// Give our source a decent name
    name = "op Art3";

    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(600,800);

    this->beginFbo();
    ofClear(ofColor(0));
    ofSetRectMode(OF_RECTMODE_CENTER);
    this->endFbo();
    
    cols=10;
    rows=5;
    rectH=fbo->getHeight();
    rectW=15;
    startingX;
    startingY=10;
    spacing=rectH*2;
    
    locY=fbo->getHeight();


}

void OpArt3::reset(){
//    reset is called optionally. if you leave it empty nothing is happening
    startTime=ofGetElapsedTimeMillis();
}

void OpArt3::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void OpArt3::update(){
    phase++;
    if(locY<0){
        locY=0;}else{locY--;}


}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void OpArt3::draw(){
  

    ofClear(0);

    ofSetColor(255);
    ofDrawRectangle(0,locY,600,800);
    

    for(int i = 5; i <fbo->getWidth(); i+=20){
        rects(i,0,rectW);
    }

    for(int i = 15; i <fbo->getWidth(); i+=20){
        rects(i,rectW,0);
    }
    
}

void OpArt3::rects(float locX,float sinMin, float sinMax){
    ofSetColor(0);
    
    for(int i=0;i<rows;i++){
        
        int locY1 = spacing*i;
        int locY2 = spacing/2+(spacing*i);
        
        ofPushMatrix();
        ofTranslate(locX,locY1);
        
        float s = sin(ofDegToRad(phase));
        h = ofMap(s,0,1,sinMin,sinMax);
        ofDrawRectangle(0,0,h,rectH);
        ofPopMatrix();
        
    }
}
