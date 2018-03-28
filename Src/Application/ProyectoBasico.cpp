#include <stdio.h>

#include "Escenas.h"

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

	Escenas* escena = new Escenas();
	escena->run();

	return 0;
}