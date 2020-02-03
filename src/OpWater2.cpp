#include "OpWater2.h"

void OpWater2::setup(){
	// Give our source a decent name
    name = "op Water2";
//    rectColor = ofColor(255);
    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(800,295);
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);
    
    this->beginFbo();
    ofClear(ofColor(255));
    ofSetRectMode(OF_RECTMODE_CENTER);
    this->endFbo();
    
    cols=20;
    rows=7;
    rectSize=fbo->getWidth()/cols;  // 800/20=40
    spacing=rectSize+5;
    startingX=rectSize/2;
    startingY=rectSize/2;
    rectH=0;
    
    
    mode1=false;
    mode3=false;
    

    
}

void OpWater2::reset(){
//    reset is called optionally. if you leave it empty nothing is happening

    startTime=ofGetElapsedTimeMillis();
    mode1=false;
    mode3=false;
    
}

void OpWater2::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void OpWater2::update(){
    phase+=2;
    
    if(mode3==true)rectH++;


}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void OpWater2::draw(){
    
    if(startTime==0){
    mode1=false;
    mode3=false;
    }

    ofClear(ofColor(255));
    
    if(ofGetElapsedTimeMillis()-startTime<21000){
            mode1=false;
        
        }else if (ofGetElapsedTimeMillis()-startTime<37000){
            mode1=true;
        }else if (ofGetElapsedTimeMillis()-startTime<40000){
            mode1=false;
        }else if(ofGetElapsedTimeMillis()-startTime<50000){
            mode3=true;
        }
    
        for(int i = 0; i<cols;i++){
            for(int j = 0; j<rows; j++){
                ofSetColor(0);
                
                float locX = startingX+i*spacing;
                float locY = startingY+j*spacing;
        
                float dist = ofDist(locX,0,fbo->getWidth(),0);
//            
                ofPushMatrix();
                ofTranslate(locX, locY);
               
               mode2Phase = phase+dist;
               
            
                float s = sin(ofDegToRad(mode2Phase));
                float modeS1 = ofMap(s,-1,1,rectSize-15,rectSize);
                float modeS2 = rectSize;
                if(mode1==false){
                    rectSizeS=modeS2;
                }else if (mode1==true){
                    rectSizeS=modeS1;
                }
                
                ofDrawRectangle(0,0, rectSizeS, rectSizeS);
                ofPopMatrix();
                
            }
        }
    
    if(mode3==true){
        ofSetColor(0);
        ofDrawRectangle(0,0, fbo->getWidth(), rectH);
    }
  
    
}


