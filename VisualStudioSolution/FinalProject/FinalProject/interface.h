#include <iostream>
#include <string>
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
	void menu();
	void select_map();
	void list_maps();
	void header(string title);
	void create_map();
private:
	string b_horizontal = "";
};

#endif