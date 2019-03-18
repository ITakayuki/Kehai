#include "Circle.h"



void Circle::init() {
	//Initial setting of 'rapple'
	rapple_x = ofGetWidth()/2;
	rapple_y = ofGetHeight()/2;
}

void Circle::update() {
	//Update eSize.
	eSize += 1;
}

void Circle::updatePos(float _rapple_x, float _rapple_y) {
	//Assign to rapple.
	rapple_x = _rapple_x;
	rapple_y = _rapple_y;
}

void Circle::updateeSize(int _eSize) {
	//Assign to eSize.
	eSize = _eSize;
}

void Circle::display() {
	//Drow rapple.
	ofPushMatrix();
	ofTranslate(rapple_x, rapple_y);
	ofCircle(0,0,eSize);
	ofPopMatrix();
}