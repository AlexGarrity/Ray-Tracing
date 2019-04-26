
#include "ppm.h"


#ifndef _DEBUG
	#define WIDTH 1280
	#define HEIGHT 720
#else
	#define WIDTH 20
	#define HEIGHT 10
#endif

int main() {
	C_ppm testImage();
	
	return 0;
}