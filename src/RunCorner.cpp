#include "RunCorner.h"

void RunCorner::setup(){
	// Give our source a decent name
    name = "Running Corner";
    rectColor = ofColor(255);
    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(800,200);
     ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    this->beginFbo();
    ofClear(ofColor(0));
    this->endFbo();

    rectSize=20;
    locX=0;
    locY=0;
}

void RunCorner::reset(){


}

void RunCorner::setName(string _name){
    name = _name;
}

void RunCorner::setColor(ofColor c){
    rectColor = c;
}

// Don't do any drawing here
void RunCorner::update(){
    // make the rect run around the fbo
    if(locX==0){
          locY+=10;
      }if(locY==180){
          locY=180;
          locX+=10;
      }if(locX==780){
          locX=780;
          locY-=10;
      }if(locY==0){
          locX-=10;
          locY=0;
      }
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void RunCorner::draw(){
   
     ofSetColor(0,0,0,20);
     ofDrawRectangle(0, 0,800,200);
    
     
     ofSetColor(255,255,255);
     ofDrawRectangle(locX,locY,rectSize,rectSize);
    
   
   
     // create the corner rect
     ofSetColor(255,255,255);
     if(locX==0 && locY<50)ofDrawRectangle(0,0,800,200);
     if(locY==180 && locX<50)ofDrawRectangle(0,0,800,200);
     if(locX==780 && locY>130)ofDrawRectangle(0,0,800,200);
     if(locY==0 && locX>730)ofDrawRectangle(0,0,800,200);


}
