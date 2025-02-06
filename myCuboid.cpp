#include <stdio.h>
#include <stdbool.h>
#include <iostream>
#include <cctype>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include <math.h>
#include "myCuboid.h"
using namespace std;




void Cuboid::update(const POINT pt1, const POINT pb1) {

	tl.x = pt1.x;
	tl.y = pt1.y;
	tl.z = pt1.z;
	br.x = pb1.x;
	br.y = pb1.y;
	br.z = pb1.z;
	l = fabs(pt1.x - pb1.x);
	w = fabs(pt1.y - pb1.y);
	h = fabs(pt1.z - pb1.z);
}
Cuboid::Cuboid(POINT tl, POINT br) {


	vertices[0] = tl;// Top-left-front
	vertices[1] = { tl.x, tl.y, br.z }; // Top-left-back
	vertices[2] = { br.x, tl.y, tl.z }; // Top-right-front
	vertices[3] = { br.x, tl.y, br.z }; // Top-right-back
	vertices[4] = { tl.x, br.y, tl.z }; // Bottom-left-front
	vertices[5] = { tl.x, br.y, br.z }; // Bottom-left-back
	vertices[6] = { br.x, br.y, tl.z }; // Bottom-right-front
	vertices[7] = br;// Bottom-right-back
}
double Cuboid::getSurfaceArea() {

	double surfaceArea = 2 * (l * w + l * h + w * h);
	return surfaceArea;
}
double Cuboid::getVol() {

	double volume = l*w*h;
	return volume;
}
void Cuboid::showVertices() {
	POINT vertices[8];


	vertices[0] = tl;// Top-left-front
	vertices[1] = { tl.x, tl.y, br.z }; // Top-left-back
	vertices[2] = { br.x, tl.y, tl.z }; // Top-right-front
	vertices[3] = { br.x, tl.y, br.z }; // Top-right-back
	vertices[4] = { tl.x, br.y, tl.z }; // Bottom-left-front
	vertices[5] = { tl.x, br.y, br.z }; // Bottom-left-back
	vertices[6] = { br.x, br.y, tl.z }; // Bottom-right-front
	vertices[7] = br;// Bottom-right-back


	printf("Vertices of the cube:\n");
	for (int i = 0; i < 8; i++) {
		printf("Vertex %d: (%.2f, %.2f, %.2f)\n", i, vertices[i].x, vertices[i].y, vertices[i].z);
	}



}

int Cuboid::getOrder() {
	return order;
}

int Cuboid::getMax() {
	return max;
}