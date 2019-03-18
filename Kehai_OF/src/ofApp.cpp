#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	//Setting background
	ofSetBackgroundAuto(false);
	ofBackground(0);
	ofSetColor(255);//Setting Color
	ofSetFrameRate(30);//Setting Framerate
	ofSetCircleResolution(64);//Setting roundness
	//Initialization "circles"
	for (int i = 0;i < NUM ;i++) {
		circles[i].init();
	}
	//Setting OSC communication
	receiver.setup(PORT);
	receiver2.setup(PORT2);
}

//--------------------------------------------------------------
void ofApp::update(){
	//Update circles
	for (int i = 0;i < NUM;i++) {
		circles[i].update();
	}
	//Reserve OSC
	while (receiver.hasWaitingMessages()) {
		ofxOscMessage m;
		receiver.getNextMessage(m);
			remorteNum = m.getArgAsInt32(0)*10;
			a = m.getArgAsInt32(0);
	}

	while (receiver2.hasWaitingMessages()) {
		ofxOscMessage f;
		receiver2.getNextMessage(f);
		remorteNum2 = f.getArgAsInt32(0) * 10;
	}
	Count++;
	//Setting the timing to generate "circles"
	if (Count == 2 || Count==46) {
		circles[click].updatePos(ofGetWidth() / 2 + remorteNum, ofGetHeight() / 2 - remorteNum2);
		circles[click].updateeSize(1);
		click++;
	}
	if (Count == 90) {
		Count = 0;
	}
	if (click == 9) {
		click = 0;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofSetColor(0, 0, 0, 60); //Set background color
	ofFill();
	ofRect(0,0 , ofGetWidth(), ofGetHeight()); //Draw Rectangle whitch is same to monitor size.
	//Draw "circles"
	for (int i = 0;i < NUM;i++) {
		
		ofSetColor(200,200,200);
		ofNoFill();
		ofSetLineWidth(2);
		circles[i].display();
	}

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	//When click mouse, draw circle.
	circles[click].updatePos(ofGetMouseX(),ofGetMouseY());
	circles[click].updateeSize(1);
	click++;
	//When click is over 19, click set 0
	if (click > 19) {
		click = 0;
	}

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
