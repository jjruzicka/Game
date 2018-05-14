#include <stdio.h>
#include "EscenasManager.h"

#ifdef _DEBUG || !_WIN32
int main() {
#else
#include<Windows.h>
int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
	) {
#endif

	EscenasManager* manager = new EscenasManager();
	manager->run();

	return 0;
}