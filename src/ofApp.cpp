#include "ofApp.h"

void ofApp::setup(){
	ofBackground(0);
    ofSetFrameRate(60);

	// Enable or disable audio for video sources globally
	// Set this to false to save resources on the Raspberry Pi
	ofx::piMapper::VideoSource::enableAudio = true;
	ofx::piMapper::VideoSource::useHDMIForAudio = false;

    // Add our BouncingBallsSource to list of fbo sources of the piMapper
	// FBO sources should be added before piMapper.setup() so the
	// piMapper is able to load the source if it is assigned to
	// a surface in XML settings.

    runCorner = new RunCorner();
    runCorner->setup();
    piMapper.registerFboSource(runCorner);
    
    rectWaves = new RectWaves();
    rectWaves->setup();
    piMapper.registerFboSource(rectWaves);
    
    opArt1 = new OpArt1();
    opArt1->setup();
    piMapper.registerFboSource(opArt1);

    opArt2 = new OpArt2();
    opArt2->setup();
    piMapper.registerFboSource(opArt2);
    
    opArt3 = new OpArt3();
    opArt3->setup();
    piMapper.registerFboSource(opArt3);
    
    opWater = new OpWater();
    opWater->setup();
    piMapper.registerFboSource(opWater);
    
    
    opWater2 = new OpWater2();
    opWater2->setup();
    piMapper.registerFboSource(opWater2);
    
    throughFront = new ThroughFront();
    throughFront->setup();
    piMapper.registerFboSource(throughFront);
    
    throughTop = new ThroughTop();
    throughTop->setup();
    piMapper.registerFboSource(throughTop);
    
    linesVideo = new LinesVideo();
    linesVideo->setup();
    piMapper.registerFboSource(linesVideo);
    
    linesVideo2 = new LinesVideo2();
    linesVideo2->setup();
    piMapper.registerFboSource(linesVideo2);
    
    randomLine = new RandomLine();
    randomLine->setup();
    piMapper.registerFboSource(randomLine);
    
    //
	piMapper.setup();

	// The info layer is hidden by default, press <i> to toggle
	// piMapper.showInfo();
	
	ofSetFullscreen(Settings::instance()->getFullscreen());
	ofSetEscapeQuitsApp(false);

    dummyObjects.load("test1.png");

    //setup sceneManager to handle scene/present changes automatically
    sceneManager.setup("scenes.json", &piMapper);
}
//-----------------------------------------------------------
void ofApp::update(){
	piMapper.update();
    sceneManager.update();
}
//-----------------------------------------------------------
void ofApp::draw(){
//    dummyObjects.draw(400,20);
    piMapper.draw();
}
//-----------------------------------------------------------
void ofApp::keyPressed(int key){
    //press 5 to go to previous preset (scene)
    if (key=='5') {
        if (piMapper.getNumPresets()>1){
            int targetScene = piMapper.getActivePresetIndex() - 1;
            if (targetScene<0) targetScene = piMapper.getNumPresets()-1;
            piMapper.setPreset(targetScene);
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    //press 6 to go to next preset (scene)
    else if (key=='6') {
        if (piMapper.getNumPresets()>1){
            piMapper.setNextPreset();
            cout << "Switched to preset: " << piMapper.getActivePresetIndex() << endl;
        } else cout << "only one preset available" << endl;
    }
    else if (key == '7'){
        piMapper.cloneActivePreset();
        piMapper.setPreset(piMapper.getNumPresets()-1);
        cout << "Cloned and switched to preset: " << piMapper.getActivePresetIndex() << endl;
    }

	piMapper.keyPressed(key);
}
//-----------------------------------------------------------
void ofApp::keyReleased(int key){
	piMapper.keyReleased(key);
}
//-----------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	piMapper.mousePressed(x, y, button);
}
//-----------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	piMapper.mouseReleased(x, y, button);
}
//-----------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	piMapper.mouseDragged(x, y, button);
}
