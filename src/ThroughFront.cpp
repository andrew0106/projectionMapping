#include "ThroughFront.h"

void ThroughFront::setup(){
	// Give our source a decent name
    name = "Through Front";

    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(800,200);

    
    this->beginFbo();
    ofClear(ofColor(0));
    this->endFbo();
    
    rectW=800;
    rectH=200;
    phase=1;
    
    
}

void ThroughFront::reset(){
//    reset is called optionally. if you leave it empty nothing is happening

    startTime=ofGetElapsedTimeMillis();
}

void ThroughFront::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void ThroughFront::update(){
    phase-=0.01;
    if(phase<0.01)phase=1;
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void ThroughFront::draw(){
    ofSetRectMode(OF_RECTMODE_CENTER);
    
//    ofClear(ofColor(0));
    ofFill();
    ofSetColor(0,0,0,20);
    ofDrawRectangle(fbo->getWidth()/2, fbo->getHeight()/2, fbo->getWidth(), fbo->getHeight());
     
     ofSetColor(255);
     ofDrawCircle(ofRandom(fbo->getWidth()),ofRandom(fbo->getHeight()),1,1);
     
     rectDraw();
    
}

void ThroughFront::rectDraw(){

    ofPushMatrix();
    ofTranslate(fbo->getWidth()/2,fbo->getHeight()/2);
    ofNoFill();
    ofSetColor(255);
    ofSetLineWidth(1);
    ofScale(phase);
    ofDrawRectangle(0, 0, rectW, rectH);
    ofPopMatrix();

}

