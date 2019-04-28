#include "RayTracer.h"

void RayTracer::setSize(int64_t width, int64_t height)
{
	_iWidth = width;
	_iHeight = height;
}

void RayTracer::setFileName(std::string strFilePath)
{
	_strFilePath = strFilePath;
}

uint64_t RayTracer::uGetThreadCount()
{
	uint64_t uThreadCount = std::thread::hardware_concurrency();
	if (uThreadCount == 0) {
		uThreadCount = 1;
	}
	return uThreadCount;
}

void RayTracer::generateThreads()
{

}

RGB RayTracer::RGBResolveColor(const Ray& r, Object *world, Random &random)
{
	Hit hitRecord;
	if (world->bCheckHit(r, 0.0001, 200.0, hitRecord)) {
		Vector3 vec3TargetPixel = hitRecord.vec3P + hitRecord.vec3Normal + vec3GetRandomUnitVectorInSphere(random);
		return RGB(RGBResolveColor(Ray(hitRecord.vec3P, vec3TargetPixel - hitRecord.vec3P), world, random)) * 0.5;
	}
	else {
		Vector3 vec3UnitDirection = vec3UnitVector(r.vec3Direction());
		double_t dbT = (vec3UnitDirection.dbY() + 1.0) * 0.5;
		return RGB(1.0, 1.0, 1.0) * (1.0 - dbT) + RGB(0.5, 0.7, 1) * dbT;
	}
}

Vector3 RayTracer::vec3GetRandomUnitVectorInSphere(Random &r)
{
	Vector3 vec3Point;
	do {
		vec3Point = Vector3(r.dbNext(), r.dbNext(), r.dbNext()) * 2.0 - Vector3(1, 1, 1) ;
	} while (vec3Point.dbSquareLength() >= 1.0);
	return vec3Point;
}

void RayTracer::resolvePixels(int64_t uXLower, int64_t uXUpper)
{
	Random random;
	random.setNoiseSize(10000);
	random.generateDoubleValues();
	random.generateIntValues();
	for (int64_t y = uXUpper - 1; y >= uXLower; y--) {
		for (int64_t x = 0; x < _iWidth; x++) {
			RGB color(0.0, 0.0, 0.0);
			for (int64_t z = 0; z < _iDepth; z++) {
				double_t dbU = double_t(x + random.dbNext()) / double_t(_iWidth);
				double_t dbV = double_t(y + random.dbNext()) / double_t(_iHeight);
				Ray ray = _cameraMain.rayGenerateRay(dbU, dbV);
				Vector3 p = ray.vec3GetPositionOnLine(2.0);
				color += RGBResolveColor(ray, objectList, random);
			}
			color /= double_t(_iDepth);
			color = RGB(sqrt(color._dbR), sqrt(color._dbG), sqrt(color._dbB));
			_pImage->addPixel(color, x, y);
		}
	}
}

void RayTracer::init() {
	_pImage = new PPM(_iWidth, _iHeight);
	_uThreadCount = uGetThreadCount();
	srand(time(NULL));
}

void RayTracer::trace() {
	if (_pImage) {
		_timer.startTimer();
		printf("Creating %i threads\n", (int)_uThreadCount);
		for (auto i = 0; i < _uThreadCount; i++) {
			int64_t uLocalLower = (i * (_iHeight / _uThreadCount));
			int64_t uLocalUpper = ((_iHeight / _uThreadCount) * (i + int64_t(1)));
			_arrThreadPool.push_back(new std::thread(&RayTracer::resolvePixels, this, uLocalLower, uLocalUpper));
			printf("Thread %u's address is: %p.  Range is %i to %i.\n", i, _arrThreadPool[i]->get_id(), uLocalLower, uLocalUpper);
		}
		for (auto t : _arrThreadPool) {
			printf("Joining thread %p\n", t->get_id());
			t->join();
		}
		uint64_t executionTime = _timer.stopTimer();
		printf("Render took %u milliseconds, which is %u milliseconds per pixel\n", executionTime, (_iWidth * _iHeight) / executionTime);
		printf("Clearing the thread pool\n");
		_arrThreadPool.clear();
		printf("Opening the viewer\n");
		_pImage->writeToFile((_strFilePath + ".ppm").data());
		_viewer.setImage(*(_pImage));
		_viewer.saveImage((_strFilePath + ".png").data());
		_viewer.displayImage();
	}
}