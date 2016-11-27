package model;

import java.util.ArrayList;

import model.CBdd;

public class CRequeteRasp {

	CBdd maBdd;
	float testTempSouhaiter=20;
	float testTempintern=18;
	float testTempExtern = (float) 15.6;
	int codeAlarme=123456789;
	boolean etatAlarme = false;
	int nbLumAllumer = 0;
	int nbPiece;
	ArrayList<String> nomPiece = new ArrayList<String>();
	ArrayList<Boolean> etatLampePiece = new ArrayList<Boolean>();
	ArrayList<ArrayList<Boolean>> pieceMaisonLum =new ArrayList<ArrayList<Boolean>>();
	
	
	public CRequeteRasp (){
		maBdd = new CBdd ();
		
		this.nomPiece.add("salon");
		this.nomPiece.add("chambre parent");
		this.nomPiece.add("cuisine");
		this.nomPiece.add("salle de jeu");
		this.nomPiece.add("Chambre fille");
		this.nomPiece.add("Chambre garcon");
		this.nomPiece.add("salle � manger");

		this.etatLampePiece.add(false);
		this.etatLampePiece.add(false);
		
		this.pieceMaisonLum.add(this.etatLampePiece);
		
		this.etatLampePiece.clear();
		
		this.etatLampePiece.add(false);
		this.pieceMaisonLum.add(this.etatLampePiece);
		
		this.etatLampePiece.clear();
		
		this.etatLampePiece.add(false);
		this.pieceMaisonLum.add(this.etatLampePiece);
		
		this.etatLampePiece.clear();
		
		this.etatLampePiece.add(false);
		this.etatLampePiece.add(false);
		this.pieceMaisonLum.add(this.etatLampePiece);

		
		this.etatLampePiece.clear();
		
		this.etatLampePiece.add(false);
		this.pieceMaisonLum.add(this.etatLampePiece);
		
		this.etatLampePiece.clear();
		
		this.etatLampePiece.add(false);
		this.pieceMaisonLum.add(this.etatLampePiece);
		
		this.etatLampePiece.clear();
		
		this.etatLampePiece.add(false);
		this.etatLampePiece.add(false);
		this.etatLampePiece.add(false);
		this.pieceMaisonLum.add(this.etatLampePiece);
		
		this.nbPiece = nomPiece.size();
		
		for (int i=0;i<nbPiece;i++){
			this.etatLampePiece.add(false);
		}
	}
	
	
	// a prog les differente requete pour la base de donn�e
	public int recupNumeroArduino (){
		
		this.maBdd.connection();
		String query = "SELECT ARD_Num FROM ARDUINO";
		return maBdd.retourDonneInt(query,"ARD_Num");
	}
	
	public void activerAlarme(){
		
		this.maBdd.connection();
		String query = "";
	}
	
	public boolean etatAlarme(){
		this.maBdd.connection();
		
		return this.etatAlarme;
	}
	
	public void SetEtatAlarme(boolean etat){
		this.etatAlarme = etat;
	}
	
	public int getNombreDeLum(){
		this.maBdd.connection();
		
		return this.nbLumAllumer;
	}
	
	public void setNombreDeLumPlus(){
		this.nbLumAllumer++;
	}
	
	public void setNombreDeLumMoin(){
		this.nbLumAllumer--;
	}
	
	public int getVitesseVent(){
		this.maBdd.connection();
		
		
		return 55;
	}
	
	public String getDirectionVent(){
		this.maBdd.connection();
		
		return "N-O";
	}
	
	public int getPluie(){
		this.maBdd.connection();
		
		return 20;
	}
	
	public int getHumidite(){
		this.maBdd.connection();
		
		return 20;
	}
	
	public float getTemperatureExtern(){
		this.maBdd.connection();
		
		return this.testTempExtern;
	}

	public float getTemperatureIntern(){
		this.maBdd.connection();
		
		return testTempintern;
	}
	
	public float getTemperatureSouhaiter(){
		this.maBdd.connection();
		
		return testTempSouhaiter;
	}
	
	public void setTemperatureSouhaiterPlus(){
		this.maBdd.connection();
		
		testTempSouhaiter+=0.5;
	}
	
	public void setTemperatureSouhaiterMoin(){
		this.maBdd.connection();
		
		testTempSouhaiter-=0.5;
	}
	
	public int getCodeAlarme(){
		return this.codeAlarme;
	}
	
	public void setCodeAlarme(int code){
		this.codeAlarme=code;
	}
	
	public int getNbPiece(){
		return this.nbPiece;	
	}
	
	public String nomPieceIndexer(int id){
		return this.nomPiece.get(id);
	}
	
	public boolean getEtatLampe(int id){
		return this.etatLampePiece.get(id);
	}
	
	public void setEtatLamp(int id, boolean etat){
		this.etatLampePiece.set(id, etat);
	}
	
	public ArrayList<Boolean> getEtatStoreParPiece(int id){
		return this.pieceMaisonLum.get(id);
	}
	
	public void setEtatStoreParPiece(int id,ArrayList<Boolean> piece){
		this.pieceMaisonLum.set(id, piece);
	}
	
	public ArrayList<Boolean> getEtatLumParPiece(int id){
		return this.pieceMaisonLum.get(id);
	}
	
	public void setEtatLumParPiece(int id,ArrayList<Boolean> piece){
		this.pieceMaisonLum.set(id, piece);
	}
}

