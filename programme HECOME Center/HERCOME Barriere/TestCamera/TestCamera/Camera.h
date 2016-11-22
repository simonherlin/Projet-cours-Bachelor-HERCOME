#pragma once
#include "axismediacontrol1.h"

class CCamera
{
public:
	CCamera(CAxismediacontrol1* Camera);
	~CCamera();
	void demarerCamera();
	void prendrePhoto();

private :
	CAxismediacontrol1* pMaCamera;
};

