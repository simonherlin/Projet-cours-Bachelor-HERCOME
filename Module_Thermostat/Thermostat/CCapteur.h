class CCapteur
{
public :
	~CCapteur();
	virtual void Open() = 0;
	virtual void Close() = 0;
	virtual float GetValeur() = 0;

};
