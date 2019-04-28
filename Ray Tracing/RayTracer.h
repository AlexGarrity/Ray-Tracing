#pragma once

#include <cstdlib>
#include <thread>

#include "Camera.h"
#include "Sphere.h"
#include "ObjectList.h"
#include "Vector3.h"
#include "PPM.h"
#include "Random.h"
#include "Ray.h"
#include "Viewer.h"


#define DRAND Random::get().dbNext()

class RayTracer
{
public:
	void init();
	void trace();

	void setSize(int64_t width, int64_t height);
	void setFileName(const char* filePath);

	uint64_t uGetThreadCount();
	void generateThreads();

	RGB RGBResolveColor(const Ray &r, Object *world);
	Vector3 vec3GetRandomUnitVectorInSphere();
	void resolvePixels(int64_t uXLower, int64_t uXUppery);

	Object * objectList = new ObjectList(
		std::vector<Object*>{
			new Sphere(Vector3(0.0, 0.0, -1.0), 0.5)
			//, new Sphere(Vector3(0.0, -100.5, -1.0), 100.0)
		}
	);

	std::vector<std::thread*> _arrThreadPool;
	uint64_t _uThreadCount = 0;

	Viewer _viewer;
	Camera _cameraMain;
	PPM* _pImage = nullptr;
	const char* _pchFilePath = "";
	int64_t _iWidth = 1280, _iHeight = 720, _iDepth = 200;
};

