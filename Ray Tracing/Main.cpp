
#ifdef _DEBUG
#define WIDTH 200
#define HEIGHT 100
#define FILEPATH "output/image_small"
#else
#define WIDTH 1280
#define HEIGHT 720
#define FILEPATH "output/image"
#endif

#ifdef SUPER
#define WIDTH 3840
#define HEIGHT 2160
#define FILEPATH "output/image_big"
#endif

#include "RayTracer.h"

int main() {


	RayTracer tracer;
	tracer.setSize(WIDTH, HEIGHT);
	tracer.init();
	tracer.setFileName(FILEPATH);
	tracer.trace();
	
	return 0;
}