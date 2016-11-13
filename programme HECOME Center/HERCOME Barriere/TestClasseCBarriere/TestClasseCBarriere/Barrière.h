#if !defined BARR
# define BARR

#include "CIEH12.h"
class CBarrière
{
public:
	CBarrière(CCIEH12 *monCieh12);
	~CBarrière();
	void ouvrir();
	void fermer();

private:
	CCIEH12* pMonCieh12;
};

#endif