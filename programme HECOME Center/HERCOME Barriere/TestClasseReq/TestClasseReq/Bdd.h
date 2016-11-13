#pragma once

//#include "stdafx.h"
#include <stdio.h>
#include <Windows.h>
#include "Mysql\mysql.h"
//#include <iostream>
//#include <afx.h>
#include <vector>
using namespace std;

class CBdd
{
public:
	CBdd(void);
	~CBdd(void);
	bool Connect(char* login, char* password, char* bddname, char* IPAddress, int NumPort);
	bool WriteRequest(char* request);
	//vector<vector<CString>> ReadRequest(char* request);
	vector<vector<CString>> ReadRequest(char* request);
	void Close();

private:
	MYSQL *pMabase;
};

