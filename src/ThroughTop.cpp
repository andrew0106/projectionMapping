#include "ThroughTop.h"

void ThroughTop::setup(){
	// Give our source a decent name
    name = "Through Top";

    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(800,200);
    
    this->beginFbo();
    ofClear(ofColor(0));
    this->endFbo();
    
    rectW=800;
    rectH=200;
    phase=1;
    lineW=fbo->getHeight();
    
    
}

void ThroughTop::reset(){
//    reset is called optionally. if you leave it empty nothing is happening

    startTime=ofGetElapsedTimeMillis();
}

void ThroughTop::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void ThroughTop::update(){
    phase-=0.01;
    if(phase<0.01)phase=1;
    lineW-=2;
    if(lineW<0.01)lineW=fbo->getHeight();
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void ThroughTop::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    

     ofFill();
     ofSetColor(0,0,0,20);
     ofDrawRectangle(fbo->getWidth()/2, fbo->getHeight()/2, fbo->getWidth(), fbo->getHeight());
      
      ofSetColor(255);
      ofDrawCircle(ofRandom(fbo->getWidth()),ofRandom(fbo->getHeight()),1,1);
      
      drawLine();
    
}

void ThroughTop::drawLine(){

    ofSetRectMode(OF_RECTMODE_CENTER);
    ofPushMatrix();
    ofTranslate(fbo->getWidth()/2, 0);
    ofSetColor(255);
    ofSetLineWidth(1);
    ofScale(phase,1,1);
    ofDrawRectangle(0, lineW, fbo->getWidth(), 2);
    ofPopMatrix();

}

