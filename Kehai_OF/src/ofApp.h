#pragma once

#include "ofMain.h"
#include "Circle.h"
#include "ofxOsc.h"
#define NUM 10
#define HOST "127.0.0.1"
#define PORT 12000
#define PORT2 10000

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
		int Count;
		int click;
		Circle circles[NUM];

		ofxOscReceiver receiver;
		ofxOscReceiver receiver2;
		float remorteNum;
		float remorteNum2;
		float a, b;
		bool rFlag1 = false;
		bool rFlag2 = false;
		bool swich1,swich2 = false;
};
