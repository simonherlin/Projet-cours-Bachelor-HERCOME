package view;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Dimension;
import java.awt.EventQueue;
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

public class IHMChauffageRasp extends JFrame {

	private JPanel contentPane;
	
	private CModificationImage modifImg;
	private CRequeteRasp maRequete;
	
	private String temp;

	/**
	 * Launch the application.
	 */


	/**
	 * Create the frame.
	 */
	public IHMChauffageRasp(CRequeteRasp req) {
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
		
		//IHMChauffageRasp chauffage = new IHMChauffageRasp();
		//chauffage.setVisible(true);
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
		IHMAlarmeRasp alarme = new IHMAlarmeRasp(maRequete);
		alarme.setVisible(true);
		dispose();
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
		
		/**********************************************************************
		 				Partie centrale 	
		**********************************************************************/
		
		JLabel lblTextTemp = new JLabel("Temp�rature actuelle de la maison :");
		lblTextTemp.setBounds(4*width/100, 30*height/100, 46*width/100, 10*height/100);
		//lblTextTemp.setHorizontalAlignment(SwingConstants.CENTER);
		lblTextTemp.setFont(new Font("Tahoma", Font.PLAIN, 5*height/100));
		contentPane.add(lblTextTemp);
		
		
		JLabel lblResultatTemp = new JLabel (Float.toString(maRequete.getTemperatureIntern())+"�C");
		lblResultatTemp.setBounds(52*width/100, 30*height/100, 10*width/100, 10*height/100);
		lblResultatTemp.setFont(new Font("Tahoma", Font.PLAIN, 5*height/100));
		contentPane.add(lblResultatTemp);
		
		
		JLabel lblTextTempSouhait = new JLabel("Temp�rature souhaiter de la maison :");
		lblTextTempSouhait.setBounds(4*width/100, 51*height/100, 50*width/100, 10*height/100);
		//lblTextTemp.setHorizontalAlignment(SwingConstants.CENTER);
		lblTextTempSouhait.setFont(new Font("Tahoma", Font.PLAIN, 5*height/100));
		contentPane.add(lblTextTempSouhait);
		
		
		JLabel lblResultatTempSouhait = new JLabel(Float.toString(maRequete.getTemperatureSouhaiter())+"�C");
		lblResultatTempSouhait.setBounds(73*width/100, 50*height/100, 15*width/100, 15*height/100);
		lblResultatTempSouhait.setFont(new Font("Tahoma", Font.PLAIN, 7*height/100));
		contentPane.add(lblResultatTempSouhait);
		
		
		Image imgUp = new ImageIcon(this.getClass().getResource("/iconUp.png")).getImage();
		JButton btnTempUp = new JButton(new ImageIcon(this.modifImg.scaleImage(imgUp, 15*width/100, 10*height/100)));
		btnTempUp.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				maRequete.setTemperatureSouhaiterPlus();
				lblResultatTempSouhait.setText(Float.toString(maRequete.getTemperatureSouhaiter())+"�C");
				lblTemp.setText(": "+Float.toString(maRequete.getTemperatureIntern())+"�C / "+Float.toString(maRequete.getTemperatureSouhaiter())+"�C");
				//contentPane.add(lblResultatTempSouhait);
			}
		});
		btnTempUp.setBounds(70*width/100,42*height/100, 15*width/100, 10*height/100);
		btnTempUp.setFont(new Font("Tahoma", Font.PLAIN, 8*height/100));
		contentPane.add(btnTempUp);
		
		
		Image imgDown = new ImageIcon(this.getClass().getResource("/iconDown.png")).getImage();
		JButton btnTempDown = new JButton(new ImageIcon(this.modifImg.scaleImage(imgDown, 15*width/100, 10*height/100)));
		btnTempDown.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent arg0) {
				maRequete.setTemperatureSouhaiterMoin();
				lblResultatTempSouhait.setText(Float.toString(maRequete.getTemperatureSouhaiter())+"�C");
				lblTemp.setText(": "+Float.toString(maRequete.getTemperatureIntern())+"�C / "+Float.toString(maRequete.getTemperatureSouhaiter())+"�C");
				//contentPane.add(lblResultatTempSouhait);
			}
		});
		btnTempDown.setBounds(70*width/100,64*height/100, 15*width/100, 10*height/100);
		btnTempDown.setFont(new Font("Tahoma", Font.PLAIN, 8*height/100));
		contentPane.add(btnTempDown);
		
		
		
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
		

		
		// rectangle blanc des differente parti permettant le recap de la maison
		JLabel lblRecTemp = new JLabel("");
		lblRecTemp.setBounds(2*width/100,27*height/100,96*width/100,70*height/100);
		lblRecTemp.setOpaque(true);
		lblRecTemp.setBackground(Color.WHITE);
		//contentPane.setLayout(null);
		contentPane.add(lblRecTemp);
		

		
		
		//rectangle gris foncer du reste de l'application
		JLabel lblMiddleDarkGray = new JLabel("");
		lblMiddleDarkGray.setBounds(0,25*height/100,width,75*height/100);
		lblMiddleDarkGray.setOpaque(true);
		lblMiddleDarkGray.setBackground(Color.DARK_GRAY);
		//contentPane.setLayout(null);
		contentPane.add(lblMiddleDarkGray);
				
	}

}
