#ifndef Circle_hpp
#define Circle_hpp

#include <stdio.h>
#include "ofMain.h"

class Circle {

public:

	void init();  //Initialization method
	void update();  //update
	void updatePos(float _rapple_y, float _rapple_x);//Setting updatePos
	void updateeSize(int _eSize);//Setting updateeSize
	void display(); //Drow

	float eSize;
	float rapple_x, rapple_y;
	bool Max = false;

private:

};

#endif
