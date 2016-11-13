#pragma once
#include <vector>

#include "alpr.h"
using namespace std;
class COpenAlpr
{
public:
	COpenAlpr();
	~COpenAlpr();

	vector<CString> recupPlaque();

};

