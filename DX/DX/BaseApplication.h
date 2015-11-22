// BaseApplication.h
// Contains base application functionality. For inheritance purposes.
#ifndef _BASEAPPLICATION_H_
#define _BASEAPPLICATION_H_

// Globals
const bool FULL_SCREEN = false;
const bool VSYNC_ENABLED = true;
const float SCREEN_DEPTH = 200.0f;	// 1000.0f
const float SCREEN_NEAR = 0.1f;		//0.1f
#define MOUSE_DEADZONE 10

enum DisplayState{
	START,
	MOUNTAINS,
	LIGHTING
};

enum ColourFilter{
	NONE,
	GREYSCALE,
	NO_RED,
	NO_BLUE,
	NO_GREEN
};

// Includes
#include "input.h"
#include "d3d.h"
#include "camera.h"
#include "timer.h"

class BaseApplication
{
public:

	BaseApplication(HINSTANCE hinstance, HWND hwnd, int screenWidth, int screenHeight, Input*);
	~BaseApplication();

	virtual bool Frame();

protected:
	virtual void HandleInput(float);
	virtual bool Render() = 0;
	void setCamera(DisplayState newState);

protected:
	Input* m_Input;
	D3D* m_Direct3D;
	Camera* m_Camera;
	Timer* m_Timer;
	RECT windowRect;
	RECT screenRect;
	float tesselationFactor;
	DisplayState currentState;
	ColourFilter currentFilter;
	bool showOptions;
	bool shouldBlur;
	bool isHighBlur;
	bool blurUpdated;
};

#endif