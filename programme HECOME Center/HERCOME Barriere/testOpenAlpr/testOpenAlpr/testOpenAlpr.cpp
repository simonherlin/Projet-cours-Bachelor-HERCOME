// testOpenAlpr.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "alpr.h"
#include "testOpenAlpr.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Seul et unique objet application

CWinApp theApp;


//using namespace std;

int main()
{
    int nRetCode = 0;

    HMODULE hModule = ::GetModuleHandle(nullptr);

    if (hModule != nullptr)
    {
        // Initialise MFC et affiche un message d'erreur en cas d'échec
        if (!AfxWinInit(hModule, nullptr, ::GetCommandLine(), 0))
        {
            // TODO: modifiez le code d'erreur selon les besoins
            wprintf(L"Erreur irrécupérable : l'initialisation MFC a échoué\n");
            nRetCode = 1;
        }
        else
        {
          

			alpr::Alpr openalpr("us", "openalpr.conf");

			// Optionally specify the top N possible plates to return (with confidences).  Default is 10
			openalpr.setTopN(20);

			// Optionally, provide the library with a region for pattern matching.  This improves accuracy by
			// comparing the plate text with the regional pattern.
			openalpr.setDefaultRegion("md");

			// Make sure the library loaded before continuing.
			// For example, it could fail if the config/runtime_data is not found
			if (openalpr.isLoaded() == false)
			{
				std::cerr << "Error loading OpenALPR" << std::endl;
				return 1;
			}

			// Recognize an image file.  You could alternatively provide the image bytes in-memory.
			alpr::AlprResults results = openalpr.recognize("1.png");

			// Iterate through the results.  There may be multiple plates in an image,
			// and each plate return sthe top N candidates.
			for (int i = 0; i < results.plates.size(); i++)
			{
				alpr::AlprPlateResult plate = results.plates[i];
				std::cout << "plate" << i << ": " << plate.topNPlates.size() << " results" << std::endl;

				for (int k = 0; k < plate.topNPlates.size(); k++)
				{
					alpr::AlprPlate candidate = plate.topNPlates[k];
					std::cout << "    - ";// << candidate.characters << "\t confidence: " << candidate.overall_confidence;
					std::cout << "\t pattern_match: " << candidate.matches_template << std::endl;
				}
			}











        }
    }
    else
    {
        // TODO: modifiez le code d'erreur selon les besoins
        wprintf(L"Erreur irrécupérable : échec de GetModuleHandle\n");
        nRetCode = 1;
    }

    return nRetCode;
}
