#if !defined CCIE
# define CCIE

#include "Modbus.h"
#define WORLD_COUNT 0x01
#define BYTE_COUNT 0x02
#define ON 0x01
#define OFF 0x00
#define FC_LIRE 0x03
#define FC_ECIRE 0x10
#define ECRIREUN true
#define ECRIREZERO false

class CCapteurPresence;
class CCIEH12
{
public:
	CCIEH12(CDialog* adress);
	~CCIEH12();
	void ecrireSortie(bool choix);
	void lectureSortie();
	bool retourDonne();
	void setAdress(CCapteurPresence* adress);

private :
	CCapteurPresence*	pMonCapteur;
	CModbus*			pMonModbus;
	CString				monAdresseIp;
};

#endif