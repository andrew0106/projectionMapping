#include "RandomLine.h"

void RandomLine::setup(){
	// Give our source a decent name
    name = "Random Line";
//    rectColor = ofColor(255);
    ofBackground(0);
	// Allocate our FBO source, decide how big it should be
    allocate(400,850);
//    ofEnableBlendMode(OF_BLENDMODE_ALPHA);

    this->beginFbo();
    ofClear(0);
    this->endFbo();
    
    lineH=fbo->getHeight();
    lineH1=fbo->getHeight();
    lineH2=fbo->getHeight();
    scene2A=1;
    
    
}

void RandomLine::reset(){
//    reset is called optionally. if you leave it empty nothing is happening
//    rectColor = ofColor(ofRandom(255),ofRandom(255),ofRandom(255))
    ofClear(0);
    startTime=ofGetElapsedTimeMillis();
    lineH=fbo->getHeight();
    lineH1=fbo->getHeight();
    lineH2=fbo->getHeight();
    line.clear();
    line1.clear();
    line2.clear();
}

void RandomLine::setName(string _name){
    name = _name;
}


// Don't do any drawing here
void RandomLine::update(){

    lineH-=ofRandom(0.1,2);
    lineH1-=ofRandom(0.1,2);
    lineH2-=ofRandom(0.1,2);

      // the resourse form the ofBook
    for (auto &vert : line.getVertices()){
          
          vert.y += ofRandom(-2,2);
          vert.x += ofRandom(-2,2);
     }
    for (auto &vert : line1.getVertices()){
             
             vert.y += ofRandom(-2,2);
             vert.x += ofRandom(-2,2);
     }
    for (auto &vert : line2.getVertices()){
                
                vert.y += ofRandom(-2,2);
                vert.x += ofRandom(-2,2);
     }
    
    
}

// No need to take care of fbo.begin() and fbo.end() here.
// All within draw() is being rendered into fbo;
void RandomLine::draw(){
//    ofClear(0);
    
    if(ofGetElapsedTimeMillis()<0){
        lineH=fbo->getHeight();
        lineH1=fbo->getHeight();
        lineH2=fbo->getHeight();
    }
    ofFill();
    ofSetColor(0,0,0,20);
    ofDrawRectangle(0, 0, fbo->getWidth(), fbo->getHeight());
    ofSetColor(255);
       
        
    //    scene1
 
    ofSetLineWidth(1);
    crazyLines(100);
    crazyLines1(fbo->getWidth()/2);
    crazyLines2(fbo->getWidth()-100);


}

void RandomLine::crazyLines(float s){
    
    ofPoint pt;
    float s1 =ofMap(s,0,1,50,70);
    pt.set(s,lineH);
    line.addVertex(pt);
    line.draw();
    
}

void RandomLine::crazyLines1(float s){
    
    ofPoint pt;
    float s1 =ofMap(s,0,1,50,70);
    pt.set(s,lineH1);
    line1.addVertex(pt);
    line1.draw();
    
}

void RandomLine::crazyLines2(float s){
    
    ofPoint pt;
    float s1 =ofMap(s,0,1,50,70);
    pt.set(s,lineH2);
    line2.addVertex(pt);
    line2.draw();
    
}

