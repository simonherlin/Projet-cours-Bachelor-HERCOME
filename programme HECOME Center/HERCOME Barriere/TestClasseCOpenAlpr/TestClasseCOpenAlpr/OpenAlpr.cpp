#include "stdafx.h"
#include "OpenAlpr.h"


COpenAlpr::COpenAlpr()
{
}


COpenAlpr::~COpenAlpr()
{
}

vector<CString> COpenAlpr::recupPlaque()
{
	CString temps;
	vector<CString> resultat;

	alpr::Alpr openalpr("eu", "openalpr.conf");

	openalpr.setTopN(20);

	openalpr.setDefaultRegion("md");

	if (openalpr.isLoaded() == false)
	{
		temps = "resultat incorrect";
		resultat.push_back(temps);

		return resultat;
	}

	alpr::AlprResults results = openalpr.recognize("1.jpeg");

	for (int i = 0; i < results.plates.size(); i++)
	{
		alpr::AlprPlateResult plate = results.plates[i];
		//std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

		for (int k = 0; k < plate.topNPlates.size(); k++)
		{
			alpr::AlprPlate candidate = plate.topNPlates[k];

			temps = candidate.characters.c_str();
			resultat.push_back(temps);

			//std::cout << "    - " << candidate.characters << "\t confidence: " << candidate.overall_confidence;
			//std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
		}
	}
	return resultat;
}
