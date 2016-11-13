#if !defined MOD
# define MOD

#include "MonSocket.h"


#define T_ID 0x00
#define P_ID 0x00
#define ESCLAVE 0x01


class CCIEH12;
class CModbus
{
public:
	CModbus(CString adresseIp,CDialog* adress);
	~CModbus();
	void envoyerTrame(byte* message, int longueur);
	bool recevoirTrame();

private:
	CMonSocket*	pMonSocket;
	CDialog*	adressDialog;
	char		data[256];
	bool		connecter;
	
};

#endif
