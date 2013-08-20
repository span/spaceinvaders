#include "stdafx.h"

// Game loop constants
const int TICKS_PER_SECOND = 50;
const int SKIP_TICKS = 1000 / TICKS_PER_SECOND;
const int MAX_FRAMESKIP = 10;

// New game id for menu
const int ID_NEW_GAME = 1;

// Loops to keep track of game loop
int loops;

// Controls
bool left = false;
bool right = false;
bool space = false;

// Intro, Level and time counter
Intro* introScreen;
Level* level;
DWORD nextTick = GetTickCount();

State state = State::intro;

// Dispatches draw calls to the available state
void Draw() {
	BeginGraphics();
	if(state == State::intro) {
		introScreen->draw();
	} else if(state == State::game) {
		level->draw();
	}
	EndGraphics();
}

// Loads the intro and level and makes sure everything was initiated correctly
bool InitializeGame() {
	introScreen = new Intro(); // TODO Could make sure this is also initiated properly...
	level = new Level();
	return level->init();
}

// Dispatches update calls to the available state
void Update() {
	if(state == State::intro) {
		introScreen->update(space, &state);
	} else if(state == State::game) {
		level->update(left, right, space);
	}
}

// Cleans up the memory for the states
void ShutdownGame() {
	delete introScreen;
	delete level;
}

// Windows message processing function
// Checks if any control keys are pressed or released and saves the state
// of these keys in flags that are then passed into the update functions.
LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
	switch(msg) {
		case WM_ERASEBKGND:
			return 1;

		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;

		case WM_KEYDOWN:
			switch (wParam) {
				case VK_LEFT:
					left = true;
					break;

				case VK_RIGHT:
					right = true;
					break;

				case VK_SPACE:
					space = true;
					break;
			}
			break;

		case WM_KEYUP:
			switch (wParam) {
				case VK_LEFT:
					left = false;
					break;

				case VK_RIGHT:
					right = false;
					break;

				case VK_SPACE:
					space = false;
			}
			break;

		case WM_COMMAND:
			switch(wParam) {
				case ID_NEW_GAME:
					level->reset();
			}
	}

	return DefWindowProc(hwnd, msg, wParam, lParam);
}

// Creates a menu with new game option
HMENU CreateMainMenu()
{
	HMENU file = CreateMenu();
	AppendMenu(file, MF_STRING, ID_NEW_GAME, "&New game");

	HMENU main = CreateMenu();
	AppendMenu(main, MF_POPUP, (UINT_PTR)file, "&File");

	return main;
}


// Initial main function that sets up the window clsas and styles. Calls the initiators
// in that are needed to launch the game and then goes into a game loop to dispatch messages
// and update/draw calls to the active screen state.
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASS wc = { 0 };
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = hInstance;
	wc.lpszClassName = "MyWindowClass";
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	
	RegisterClass(&wc);

	DWORD windowStyle = (WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN) & ~(WS_SIZEBOX | WS_MAXIMIZEBOX);
	RECT windowSize = { 0, 0, WindowWidth, WindowHeight };
	AdjustWindowRect(&windowSize, windowStyle, FALSE);

	HWND hwnd = CreateWindow(
		"MyWindowClass",
		"SpaceInvaders",
		windowStyle,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		windowSize.right - windowSize.left,
		windowSize.bottom - windowSize.top,
		0,
		CreateMainMenu(),
		hInstance,
		0);

	srand((unsigned int)time(0));

	InitializeGraphics(hwnd);

	if(!InitializeGame()) {
		ShutdownGraphics();
		return -1;
	}
	
	UpdateWindow(hwnd);
	ShowWindow(hwnd, nCmdShow);

	// Game loop
	while(true) {
		MSG msg = {0};
		// Handle messages first
		if(PeekMessage(&msg, hwnd, 0, 0, PM_REMOVE)) {
			if(msg.message == WM_QUIT) {
				break;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		} else {
			// No message, lets see if we can keep a steady updating pace by not drawing until
			// we have to. 
			// Game loop based on: http://www.koonsolo.com/news/dewitters-gameloop/
			loops = 0;
			while(GetTickCount64() > nextTick && loops < MAX_FRAMESKIP) {
				Update();
				nextTick += SKIP_TICKS;
				loops++;
			}
			Draw();
		}
	}

	ShutdownGame();
	ShutdownGraphics();
	_CrtDumpMemoryLeaks();
	return 0;
}
