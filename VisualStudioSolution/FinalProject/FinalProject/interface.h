#include <iostream>
#include <cstdlib>
#include <conio.h>
#include <string>
#include "AllMaps.h"
using namespace std;
#ifndef INTERFACE_H
#define INTERFACE_H

#define B_V		(char)186
#define B_H		(char)205
#define B_TL	(char)201
#define B_TR	(char)187
#define B_ML	(char)204
#define B_MR	(char)185
#define B_BL	(char)200
#define B_BR	(char)188

class interface {
public:
	interface();
	void menu(AllMaps all);
	void select_map(AllMaps all);
	void list_maps(AllMaps all);
	void header(string title);
	void create_map(AllMaps all);
private:
	string b_horizontal = "";
};

#endif