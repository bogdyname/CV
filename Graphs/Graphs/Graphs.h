#pragma once

#include <windows.h>
#include <iostream>
#include <cmath>

class Graphs
{
public:
	Graphs(float x = 1.0, float y = 1.0);
	~Graphs();

public:
	bool InitWindowsApi();
	bool DrawGraph();

private:
	float x;
	float y;

	HWND hwnd = NULL;
	HDC hdc = NULL;
};