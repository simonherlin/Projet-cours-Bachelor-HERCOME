#include "stdafx.h"
#include "Camera.h"


CCamera::CCamera(CAxismediacontrol1* Camera)
{
	pMaCamera = Camera;
}


CCamera::~CCamera()
{
}

void CCamera::demarerCamera()
{
	pMaCamera->put_MediaPassword(L"doowap");
	pMaCamera->put_MediaUsername(L"root");
	pMaCamera->put_MediaURL(L"http://192.168.10.43/axis-cgi/mjpg/video.cgi");
	pMaCamera->put_MediaType(L"mjpeg");
	pMaCamera->put_StretchToFit(TRUE);
	pMaCamera->Play();
}

void CCamera::prendrePhoto()
{
	pMaCamera->SaveCurrentImage(1, L"C:\\Users\\Herlin\\Documents\\Visual Studio 2015\\Projects\\TestCamera\\TestCamera\\1.jpeg");
}
