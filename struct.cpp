#include<stdio.h>
#include<stdbool.h>
#include <iostream>
#include <cctype>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include "struct.h"
using namespace std;

double dist(POINT p1, POINT p2) {
	double x_dist = fabs(p1.x - p2.x);
	double y_dist = fabs(p1.y - p2.y);
	return sqrt((x_dist * x_dist) + (y_dist * y_dist));
}

bool equalPoints(POINT p1, POINT p2) {
	return (p1.x == p2.x && p1.y == p2.y);
}

double areaRect(RECT rect) {
	double width = fabs(rect.br.x - rect.tl.x);
	double height = fabs(rect.tl.y - rect.br.y);
	return width * height;
}

bool insideRect(RECT rect, POINT p) {
	if (rect.tl.x <= p.x && p.x <= rect.br.x &&
	        rect.br.y <= p.y && p.y <= rect.tl.y) {
		return true;
	}
	return false;
}

bool insideRectComplete(RECT rect, RECT other) {
	if (insideRect(rect, other.tl) && insideRect(rect, other.br)) {
		return true;
	}
	return false;
}

bool RectOverlap(RECT rect1, RECT rect2) {
	if (insideRect(rect1, rect2.tl) || insideRect(rect1, rect2.br) ||
	        insideRect(rect2, rect1.tl) || insideRect(rect2, rect1.br)) {
		return true;
	}
	return false;
}

float calculateDistance(POINT p1, POINT p2) {
	return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

Pair findFarthestPair(POINT pts[5]) {
	Pair farthestPair;
	farthestPair.dist = 0;

	for (int i = 0; i < 5; ++i) {
		for (int j = i + 1; j < 5; ++j) {
			float distance = calculateDistance(pts[i], pts[j]);
			if (distance > farthestPair.dist) {
				farthestPair.pts[0] = pts[i];
				farthestPair.pts[1] = pts[j];
				farthestPair.dist = distance;
			}
		}
	}
	return farthestPair;
}

double overlappingArea(RECT rect1, RECT rect2) {
	//gets the left side
	double overlapLeft = max(rect1.tl.x, rect2.tl.x);
	//gets the right side
	double overlapRight = min(rect1.br.x, rect2.br.x);
	//gets the top side
	double overlapTop = min(rect1.tl.y, rect2.tl.y);
	//gets the bottom side
	double overlapBottom = max(rect1.br.y, rect2.br.y);


	double overlapWidth = overlapRight - overlapLeft;
	double overlapHeight = overlapTop - overlapBottom;


	if (overlapWidth > 0 && overlapHeight > 0) {
		return overlapWidth * overlapHeight;
	}

	return 0.0;
}

void structTest() {
	RECT rect1 = { {2,5}, {6,1} };
	RECT rect2 = { {4,4}, {8,2} };

	printf("%lf", overlappingArea(rect1, rect2));



}