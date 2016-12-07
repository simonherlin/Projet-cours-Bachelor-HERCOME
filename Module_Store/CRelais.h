class CRelais
{
public : 
	CRelais(int Pin);
	~CRelais();
	void EcrireSortie(bool Ordre);
private : 
	int _Pin;
};
