package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Frame;
import java.awt.Image;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.border.EmptyBorder;

import model.CModificationImage;
import model.CRequeteRasp;

public class IHMAlarmeRasp extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = 3935263116957716522L;

	private JPanel contentPane;
	
	private CModificationImage modifImg;
	private static CRequeteRasp maRequete=new CRequeteRasp();
	
	private String temp,temp2="";

	/**
	 * Launch the application.
	 */


	/**
	 * Create the frame.
	 */
	public IHMAlarmeRasp(CRequeteRasp req) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		setBounds(100, 100, 450, 300);
		contentPane = new JPanel();
		contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		contentPane.setLayout(new BorderLayout(0, 0));
		setContentPane(contentPane);
		
		
		maRequete = req;
		modifImg = new CModificationImage();
		
		this.pack();
		JFrame.setDefaultLookAndFeelDecorated(true);
		setExtendedState(Frame.MAXIMIZED_BOTH);
		
		Dimension dimension = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
		int height = (int)dimension.getHeight();
		int width  = (int)dimension.getWidth();
		
		
		
/******************************************************************************************************
  					
  					Partie menu de l'application evc le logo
 
******************************************************************************************************/
		JLabel lblNewLabel = new JLabel("");
		lblNewLabel.setBounds(2*width/100, 8*height/100, 21*width/100, 15*height/100);
		lblNewLabel.setOpaque(true);
		lblNewLabel.setBackground(Color.WHITE);
		Image img = new ImageIcon(this.getClass().getResource("/logoHercome.jpg")).getImage();
		contentPane.setLayout(null);
		lblNewLabel.setIcon(new ImageIcon(this.modifImg.scaleImage(img, 21*width/100, 15*height/100)));
		contentPane.add(lblNewLabel);
		
		
		JButton btnChauffage = new JButton("Chauffage");
		btnChauffage.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				
				IHMChauffageRasp chauffage = new IHMChauffageRasp(maRequete);
				chauffage.setVisible(true);
				dispose();
			}
		});
		btnChauffage.setBounds(27*width/100, 8*height/100, 21*width/100, 15*height/100);
		btnChauffage.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		btnChauffage.setBackground(Color.WHITE);
		contentPane.add(btnChauffage);
		
		JButton btnModules = new JButton("Modules");
		btnModules.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {

			IHMModuleRasp module = new IHMModuleRasp(maRequete);
			module.setVisible(true);
			dispose();
			}
		});
		
		btnModules.setBounds(52*width/100, 8*height/100, 21*width/100, 15*height/100);
		btnModules.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		btnModules.setBackground(Color.WHITE);
		contentPane.add(btnModules);
		
		JButton btnAlarme = new JButton("Alarme");
		btnAlarme.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {

			}
		});
		btnAlarme.setBounds(77*width/100, 8*height/100, 21*width/100, 15*height/100);
		btnAlarme.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		btnAlarme.setBackground(Color.WHITE);
		contentPane.add(btnAlarme);
		
		
/*********************************************************************************************************
		  
			Partie texte information de l'application

********************************************************************************************************/
			/***********************************************
					partie bande noir
		 	************************************************/
		JLabel lblInfoImgAmp = new JLabel ("");
		lblInfoImgAmp.setBounds(1, 1, 4*width/100, 6*height/100);
		lblInfoImgAmp.setOpaque(true);
		lblInfoImgAmp.setBackground(Color.WHITE);
		Image iconAmpoule = new ImageIcon(this.getClass().getResource("/iconAmpoule.jpg")).getImage();
		contentPane.setLayout(null);
		lblInfoImgAmp.setIcon(new ImageIcon(this.modifImg.scaleImage(iconAmpoule, 4*width/100, 6*height/100)));
		contentPane.add(lblInfoImgAmp);
		
		
		this.temp = Integer.toString(maRequete.getNombreDeLum());
		JLabel lblNbLum = new JLabel(this.temp);
		lblNbLum.setBounds(5*width/100, 1, 2*width/100, 6*height/100);
		lblNbLum.setHorizontalAlignment(SwingConstants.CENTER);
		lblNbLum.setFont(new Font("Tahoma", Font.PLAIN, 5*height/100));
		lblNbLum.setForeground(Color.WHITE);
		contentPane.add(lblNbLum);
		
		
		JLabel lblInfoImgTemp = new JLabel ("");
		lblInfoImgTemp.setBounds(11*width/100, 1*height/100, 3*width/100, 6*height/100);
		lblInfoImgTemp.setOpaque(true);
		lblInfoImgTemp.setBackground(Color.BLACK);
		Image iconTemp = new ImageIcon(this.getClass().getResource("/iconTemp.png")).getImage();
		contentPane.setLayout(null);
		lblInfoImgTemp.setIcon(new ImageIcon(this.modifImg.scaleImage(iconTemp, 3*width/100, 6*height/100)));
		contentPane.add(lblInfoImgTemp);
		
		this.temp = " : "+Float.toString(maRequete.getTemperatureIntern())+"�C";
		this.temp += " / "+Float.toString(maRequete.getTemperatureSouhaiter())+"�C";
		JLabel lblTemp = new JLabel(this.temp);
		lblTemp.setBounds(14*width/100, 1, 26*width/100, 6*height/100);
		lblTemp.setHorizontalAlignment(SwingConstants.CENTER);
		lblTemp.setFont(new Font("Tahoma", Font.PLAIN, 5*height/100));
		lblTemp.setForeground(Color.WHITE);
		contentPane.add(lblTemp);
		
		
			/***********************************************
				partie alarme
		 	************************************************/		
		
		JLabel lblTextAlarme = new JLabel("");
		lblTextAlarme.setBounds(20*width/100, 30*height/100, 46*width/100, 10*height/100);

		lblTextAlarme.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(lblTextAlarme);
		
		Image iconValider = new ImageIcon(this.getClass().getResource("/iconValider.png")).getImage();
		JButton btnValider = new JButton(new ImageIcon(this.modifImg.scaleImage(iconValider, 20*width/100, 20*height/100)));
		btnValider.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				if (Integer.parseInt(temp2.toString())==maRequete.getCodeAlarme()){
					if (maRequete.etatAlarme()==true){
						maRequete.SetEtatAlarme(false);
						lblTextAlarme.setText("Alarme desactiver");
						
					}
					else{
						maRequete.SetEtatAlarme(true);
						lblTextAlarme.setText("Alarme activer");
					}
				}
			}
		});
		btnValider.setBounds(70*width/100,30*height/100, 20*width/100, 20*height/100);
		contentPane.add(btnValider);
		

		
		
		JLabel resultat = new JLabel("");
		resultat.setBounds(10*width/100, 70*height/100, 50*width/100, 10*height/100);
		resultat.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(resultat);
		
		
		
		Image iconCorriger = new ImageIcon(this.getClass().getResource("/iconCorriger.png")).getImage();
		JButton btnCorriger = new JButton(new ImageIcon(this.modifImg.scaleImage(iconCorriger, 20*width/100, 20*height/100)));
		btnCorriger.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2="";
				resultat.setText(temp2);
			}
		});
		btnCorriger.setBounds(70*width/100,55*height/100, 20*width/100, 20*height/100);
		contentPane.add(btnCorriger);
		
		
		JButton btnUn = new JButton("1");
		btnUn.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				
				temp2 +="1";
				resultat.setText(temp2);
			}
		});
		btnUn.setBounds(5*width/100, 40*height/100, 10*width/100, 8*height/100);
		btnUn.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnUn);
		
		JButton btnDeux = new JButton("2");
		btnDeux.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="2";
				resultat.setText(temp2);
			}
		});
		btnDeux.setBounds(17*width/100, 40*height/100, 10*width/100, 8*height/100);
		btnDeux.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnDeux);
		
		JButton btnTrois = new JButton("3");
		btnTrois.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="3";
				resultat.setText(temp2);
			}
		});
		btnTrois.setBounds(29*width/100, 40*height/100, 10*width/100, 8*height/100);
		btnTrois.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnTrois);
		
		
		JButton btnQuatre = new JButton("4");
		btnQuatre.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="4";
				resultat.setText(temp2);
			}
		});
		btnQuatre.setBounds(41*width/100, 40*height/100, 10*width/100, 8*height/100);
		btnQuatre.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnQuatre);
		
		JButton btnCinq = new JButton("5");
		btnCinq.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="5";
				resultat.setText(temp2);
			}
		});
		btnCinq.setBounds(53*width/100, 40*height/100, 10*width/100, 8*height/100);
		btnCinq.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnCinq);
		
		JButton btnSix = new JButton("6");
		btnSix.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="6";
				resultat.setText(temp2);
			}
		});
		btnSix.setBounds(5*width/100, 52*height/100, 10*width/100, 8*height/100);
		btnSix.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnSix);
		
		JButton btnSept = new JButton("7");
		btnSept.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="7";
				resultat.setText(temp2);
			}
		});
		btnSept.setBounds(17*width/100, 52*height/100, 10*width/100, 8*height/100);
		btnSept.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnSept);
		
		JButton btnHuit = new JButton("8");
		btnHuit.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="8";
				resultat.setText(temp2);
			}
		});
		btnHuit.setBounds(29*width/100, 52*height/100, 10*width/100, 8*height/100);
		btnHuit.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnHuit);
		
		
		JButton btnNeuf = new JButton("9");
		btnNeuf.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="9";
				resultat.setText(temp2);
			}
		});
		btnNeuf.setBounds(41*width/100, 52*height/100, 10*width/100, 8*height/100);
		btnNeuf.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnNeuf);
		
		JButton btnZero = new JButton("0");
		btnZero.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				temp2 +="0";
				resultat.setText(temp2);
			}
		});
		btnZero.setBounds(53*width/100, 52*height/100, 10*width/100, 8*height/100);
		btnZero.setFont(new Font("Tahoma", Font.PLAIN, 6*height/100));
		contentPane.add(btnZero);
		
		if (maRequete.etatAlarme()==true){
			
			lblTextAlarme.setText("Alarme activer");
		}
		else{
			lblTextAlarme.setText("Alarme d�sactiver");
		}

		
		JButton btnQuitter = new JButton("Retour accueil");
		btnQuitter.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				IHMAccueilRasp accueil = new IHMAccueilRasp(maRequete);
				accueil.setVisible(true);
				dispose();
			}
		});
		btnQuitter.setBounds(10*width/100,80*height/100, 80*width/100, 15*height/100);
		btnQuitter.setFont(new Font("Tahoma", Font.PLAIN, 8*height/100));
		contentPane.add(btnQuitter);
		
		
		
		
/***********************************************************************************************************
		 
		 Partie des differant rectangle de couleur de l'application pour separer les differante partie
		
************************************************************************************************************/
		//bande noir au dessus
		JLabel lblBandeNoir = new JLabel("");
		lblBandeNoir.setBounds(0,0,width,7*height/100);
		lblBandeNoir.setOpaque(true);
		lblBandeNoir.setBackground(Color.BLACK);
		//contentPane.setLayout(null);
		contentPane.add(lblBandeNoir);
		
		// rectangle gris claire sur les bouton menu
		JLabel lblRecGris = new JLabel("");
		lblRecGris.setBounds(0,7*height/100,width,17*height/100);
		lblRecGris.setOpaque(true);
		lblRecGris.setBackground(Color.LIGHT_GRAY);
		//contentPane.setLayout(null);
		contentPane.add(lblRecGris);
		

		
		// rectangle blanc 
		JLabel lblRecChoix = new JLabel("");
		lblRecChoix.setBounds(2*width/100,27*height/100,96*width/100,70*height/100);
		lblRecChoix.setOpaque(true);
		lblRecChoix.setBackground(Color.WHITE);
		//contentPane.setLayout(null);
		contentPane.add(lblRecChoix);
		
		
		//rectangle gris foncer du reste de l'application
		JLabel lblMiddleDarkGray = new JLabel("");
		lblMiddleDarkGray.setBounds(0,25*height/100,width,75*height/100);
		lblMiddleDarkGray.setOpaque(true);
		lblMiddleDarkGray.setBackground(Color.DARK_GRAY);
		//contentPane.setLayout(null);
		contentPane.add(lblMiddleDarkGray);
		
				
		
		
		
	}

}
