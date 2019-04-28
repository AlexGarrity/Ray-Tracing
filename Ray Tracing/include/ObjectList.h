#pragma once

#include <vector>
#include "Object.h"

class ObjectList : public Object
{
public:
	ObjectList() {};
	ObjectList(const std::vector<Object*> &arrObjectList) { _arrObjectList = arrObjectList; };
	virtual bool bCheckHit(const Ray& r, double_t dbTMin, double_t dbTMax, Hit& hit) const {
		Hit tempRecord;
		bool bHasHit = false;
		double_t dbClosestObject = dbTMax;
		for (Object* obj : _arrObjectList) {
			if (obj->bCheckHit(r, dbTMin, dbClosestObject, tempRecord)) {
				bHasHit = true;
				dbClosestObject = tempRecord.dbT;
				hit = tempRecord;
			}
		}
		return bHasHit;
	}
	std::vector<Object*> _arrObjectList;
};
