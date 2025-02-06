#include<stdio.h>
#include<stdbool.h>
#include <iostream>
#include <cctype>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <ctime>
#include "enum.h"
using namespace std;

enum enColors {
	BLACK = 0,
	RED,
	YELLOW,
	PURPLE,
	GREEN,
	BROWN,
	BLUE,
	WHITE,
	COLOR_COUNT,
};


void direction() {
	enum direction { NORTH, SOUTH, EAST, WEST };
	enum direction dir;
	int x = 0;
	int y = 0;
	char input{};

	printf("Enter direction (N, S, E, W): ");
	//scanf(" %c", &input);

	switch (input) {
	case 'N':
	case 'n':
		dir = NORTH;
		y--;
		break;
	case 'S':
	case 's':
		dir = SOUTH;
		y++;
		break;
	case 'E':
	case 'e':
		dir = EAST;
		x++;
		break;
	case 'W':
	case 'w':
		dir = WEST;
		x--;
		break;
	default:
		printf("Invalid direction\n");

	}

	printf("New position: x = %d, y = %d\n", x, y);


}

void chess() {

	enum chess_pieces { KING, QUEEN, ROOK, BISHOP, KNIGHT, PAWN };

	const int piece_value[] = { 200, 9, 5, 3, 3, 1 };

	for (int i = KING; i <= PAWN; ++i) {
		printf("Value of ");
		switch (i) {
		case KING:
			printf("KING: ");
			break;
		case QUEEN:
			printf("QUEEN: ");
			break;
		case ROOK:
			printf("ROOK: ");
			break;
		case BISHOP:
			printf("BISHOP: ");
			break;
		case KNIGHT:
			printf("KNIGHT: ");
			break;
		case PAWN:
			printf("PAWN: ");
			break;
		}
		printf("%d\n", piece_value[i]);
	}



}

void planets() {

	enum planets { Me = 1, Ve, Ea, Ma, Ju, Sa, Ur, Ne };
	int plan;
	double mass[8] = { 3.303e+23, 4.869e+24,5.976e+24,6.421e+23,1.9e+27,5.688e+26,8.686e+25,1.024e+26 };
	double radius[8] = { 2.4397e6,6.0518e6, 6.37814e6,3.3972e6,7.1492e7,6.0268e7,2.5559e7,2.4746e7 };
	printf("Enter a planet(1, 2, 3, 4, 5, 6, 7, 8): ");
	plan = getnum2();
	switch (plan) {
	case 1:
		printf("%f, %f", mass[0], radius[0]);
		break;
	case 2:
		printf("%f, %f", mass[1], radius[1]);
		break;
	case 3:
		printf("%f, %f", mass[2], radius[2]);
		break;
	case 4:
		printf("%f, %f", mass[3], radius[3]);
		break;
	case 5:
		printf("%f, %f", mass[4], radius[4]);
		break;
	case 6:
		printf("%f, %f", mass[5], radius[5]);
		break;
	case 7:
		printf("%f, %f", mass[6], radius[6]);
		break;
	case 8:
		printf("%f, %f", mass[7], radius[7]);
		break;
	}
}

void months() {


	enum { jan, feb, mar, apr, may, jun, jul, aug, sept, oct, nov, dec } mon;
	char smon[dec + 2][10] = { " ","January", "February", "March", "April", "May","June", "July","August","September","October","November","December" };
	int days[dec + 2] = { 0,31,29,31,30,31,30,31,31,30,31,30,31 };

	printf("Enter a number 1-12: ");
	int month = getnum2();
	for (int i = 0; i < 10; i++) {
		printf("%c", smon[month][i]);
	}
	printf(" has %d days", days[month]);
}

void degreesDirection() {
	enum Direction {
		North,
		NorthEast,
		East,
		SouthEast,
		South,
		SouthWest,
		West,
		NorthWest,
		NumDirections
	};

	const char* DirectionNames[] = {
		"North",
		"NorthEast",
		"East",
		"SouthEast",
		"South",
		"SouthWest",
		"West",
		"NorthWest"
	};


	const int DirectionDegrees[] = {
		0,
		45,
		90,
		135,
		180,
		225,
		270,
		315
	};

	for (int i = North; i < NumDirections; ++i) {
		printf("%s", DirectionNames[i]);
		printf(" == %d degrees\n", DirectionDegrees[i]);

	}


}

void wrtColor(enColors color) {

	const char sColors[][8] = {
		"BLACK", "RED", "YELLOW", "PURPLE", "GREEN", "BROWN", "BLUE", "WHITE"
	};


	color colors[] = {
		{0, 0, 0},     // BLACK
		{1, 0, 0},     // RED
		{1, 1, 0},     // YELLOW
		{1, 0, 1},     // PURPLE
		{0, 1, 0},     // GREEN
		{1, 1, 0},     // BROWN
		{0, 0, 1},	   // BLUE
		{1, 1, 1}      // WHITE
	};

	if (color >= 0 && color < COLOR_COUNT) {
		printf("Set Color to %s\n", sColors[color]);
	}
	else {
		printf("Invalid color index\n");
	}
}

void testColor() {

	for (int i = BLACK; i < COLOR_COUNT; ++i) {
		enColors color = static_cast<enColors>(i);
		wrtColor(color);
	}
}


int getnum2() {
	int num = 0;
	int  d = 10;
	char ch;

	while (isdigit(ch = getchar())) {
		num = num * 10 + ch - '0';
	}
	ungetc(ch, stdin);
	return num;
}

