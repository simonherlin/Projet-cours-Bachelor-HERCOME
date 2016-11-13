#if !defined MONSOC
# define MONSOC

#include "afxsock.h"

class CModbus;

class CMonSocket :public CAsyncSocket
{
public:
	CMonSocket(CModbus* adress);
	~CMonSocket(void);
	void OnReceive( int nErrorCode );
	//void setAdress( CDialog* adresse);
	void OnAccept(int nErrorCode );
	void OnConnect(int nErrorCode);
	void OnClose (int nErrorCode);
	void SetNum (int numero);
	void setAdress(CDialog* adresse);
	bool GetConnect();

private:
	CModbus* pModbus;
	CDialog* fenetre;
	int num;
	bool etatConnect;

};

#endif