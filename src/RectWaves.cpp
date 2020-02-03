#include "RectWaves.h"

void RectWaves::setup(){
	// Give our source a decent name
    name = "rect Waves";
    rectColor = ofColor(255);
    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(700,700);
    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    this->beginFbo();
    ofClear(ofColor(0));
    ofSetRectMode(OF_RECTMODE_CENTER);
    this->endFbo();
    
    rectOfNums = 15;
    rectSize = fbo->getWidth()/2/rectOfNums;
    sp=0;
    change=false;
}

void RectWaves::reset(){
//    reset is called optionally. if you leave it empty nothing is happening
    startTime=ofGetElapsedTimeMillis();
}

void RectWaves::setName(string _name){
    name = _name;
}

// Don't do any drawing here
void RectWaves::update(){
//     time = ofGetFrameNum()*2;
    if(change==false){
    phase+=0.5;
    }else if (change==true){
        phase+=2.5;
    }

}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void RectWaves::draw(){
    
    //make after 15sec change the rect
    
    if(ofGetElapsedTimeMillis()-startTime<15000){
        change=false;
    }else if (ofGetElapsedTimeMillis()-startTime<30000){
        change=true;
    }
    
    ofSetColor(0,0,0,90);
    ofFill();
    ofDrawRectangle(0,0,fbo->getWidth(), fbo->getHeight());
    
    for(int i = 0; i< fbo->getHeight();i++){
        float locY = rectSize/2+i*rectSize*2;
        drawRect(locY,fbo->getHeight()/2);
    }
    
    for(int i = 0; i< ofGetHeight();i++){
        float locY = rectSize+rectSize/2+i*rectSize*2;
        drawRect(locY,fbo->getHeight()/2);
    }
    
}

//--------------------------------------------------------------
void RectWaves::drawRect(float locY,float ly){
    for(int i = 0;i<rectOfNums;i++){
        
        float locX = (rectSize/2)+i*rectSize;
        
        float s1 = sin(ofDegToRad(phase));
        float x1 = ofMap(s1,0,1,0,fbo->getWidth());    // mapping the sin wave
        
        float dist = ofDist(locX,locY,fbo->getWidth()/4,fbo->getHeight());

        float s = sin(ofDegToRad(phase+dist));
        float x = ofMap(s,-1,0,rectSize/3*-1,rectSize/3);    // move the position

        ofPushMatrix();
        ofTranslate(locX+x, locY);  // position

        
        float rw = ofMap(s,0,1,rectSize*-1,rectSize);  // make the size change
        float c = ofMap(s,0,1,50,200);
        float r = ofMap(s,0,1,0,360);
        ofSetColor(255);
        if(change==false){
            ofNoFill();
        }else if(change==true){
            ofFill();
            
        }
        ofRotate(r);
        ofDrawRectangle(0,0,rw,rectSize);
        
        ofPopMatrix();
            
    }
    
}
