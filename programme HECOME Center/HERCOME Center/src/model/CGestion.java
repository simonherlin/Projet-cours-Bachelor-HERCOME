package model;

public class CGestion {
	private CRequeteRasp maRequete;
	public CGestion(CRequeteRasp req){
		this.maRequete = req;
	}
	
	public CGestion(){
		maRequete = new CRequeteRasp();
	}

	
	public float decryptageTrame(char [] trame){
		
		float retour= (float) 0.0;
		
		switch (trame[4]){
			
			case '1' :
				CCommandStore mesStores = new CCommandStore();
				switch (trame[8]){
				
					case '0' :
						mesStores.monterStore(trame);
						
							
					break;
					
					case '1':
						mesStores.dessendreStore(trame);
					break;
					
					case '2':
						mesStores.stoperStore(trame);
					break;	
				
				}
				
				
				break;
			
			case '2' :
				
				
				retour = maRequete.getTemperatureSouhaiter();
				
				
				break;
				
			case '3' :
				CCommandLumiere mesLumieres = new CCommandLumiere();
				if (trame[8]=='0'){
					mesLumieres.allumerLumiere(trame);
					maRequete.setEtatLamp(trame[1]*100+trame[2]*10+trame[3], true);
					
				}
				else{
					mesLumieres.eteindreLumiere(trame);
					maRequete.setEtatLamp(trame[1]*100+trame[2]*10+trame[3], false);
				}
				
				break;
				
			default :
					
				break;
		
		}
		return retour;
	}
}
