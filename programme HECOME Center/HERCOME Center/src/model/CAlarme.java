package model;

import model.CCapteurPresence;
import model.CRequeteRasp;

public class CAlarme {
	
	private CCapteurPresence monCapteur;
	private CRequeteRasp maRequete;
	private boolean etat=false;
	
	public CAlarme(){
		
	}
	
	
	public void activer(){
		
		this.etat = true;
		this.maRequete.activerAlarme();
		this.monCapteur.activer();
		
	}
	public void desactiver(){
		
		this.etat = false;
		this.monCapteur.desactiver();
		
	}

}
