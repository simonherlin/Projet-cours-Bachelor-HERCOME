package model;

import model.ER433Rasp;

public class CCapteurPresence {
	
	private ER433Rasp com;
	public void activer(){
		
		com.envoyerTrame();
	}
	
	public void desactiver(){
		com.envoyerTrame();
	}

}
