package view;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.FlowLayout;
import java.awt.Font;
import java.awt.Image;
import java.util.ArrayList;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import model.CModificationImage;
import model.CRequeteRasp;
import java.awt.BorderLayout;

public class IHMPieceChoisi extends JFrame {

	/**
	 * 
	 */
	private static final long serialVersionUID = -7351129140236878668L;

	//private JPanel contentPane;

	private CModificationImage modifImg;
	private static CRequeteRasp maRequete;
	private int hauteur,largeur;

	/**
	 * Create the frame.
	 */
	public IHMPieceChoisi(String maPiece,CRequeteRasp req,int hauteur,int largeur) {
		setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		Dimension dimension = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
		int height = (int)dimension.getHeight();
		int width  = (int)dimension.getWidth();
		setBounds(width*5/100, height*20/100, largeur, hauteur);
		//contentPane = new JPanel();
		//contentPane.setBorder(new EmptyBorder(5, 5, 5, 5));
		//contentPane.setLayout(new FlowLayout());
		//setContentPane(contentPane);
		
		this.maRequete = req;
		//maRequete = req;
		this.modifImg = new CModificationImage();
		
		this.hauteur = hauteur;
		this.largeur = largeur;
		
		
		this.pack();
		//JFrame.setDefaultLookAndFeelDecorated(true);
		//setExtendedState(Frame.MAXIMIZED_BOTH);
		
		//Dimension dimension = java.awt.Toolkit.getDefaultToolkit().getScreenSize();
		//int height = (int)dimension.getHeight();
		//int width  = (int)dimension.getWidth();
		
		//setLocation(0,0);
		setSize(largeur,hauteur);
		setLayout(new FlowLayout());
		
/******************************************************************************************************
		
		Partie menu de l'application evc le logo

******************************************************************************************************/
		/*
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
		public void actionPerformed(ActionEvent arg0) {
			
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
		public void actionPerformed(ActionEvent e) {
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
		/*
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
					partie app
		 ************************************************/
	
	
	setJPanelandComponent();
	

	
/***********************************************************************************************************
	 
	 Partie des differant rectangle de couleur de l'application pour separer les differentes partie
	
************************************************************************************************************/
	/*
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
	

		*/
		
	}
	
	/*private void setJPanelandComponent()
	{
		JPanel central = new JPanel ();
		//central.setLayout();
		//central.setBounds(2*width/100,27*height/100,96*width/100,70*height/100);
		central.setLocation(2*width/100,27*height/100);
		central.setPreferredSize(new Dimension(96*width/100,height*4/100+10/2*height*30/100+10*height/100));
		
		ArrayList<JPanel> mesModules = new ArrayList<JPanel>();
		int largeurPanel = 96*width/100;
		int hauteurPanel = 70*height/100;
		
		
		for(int i=0;i<10;i++)
		{
			//JPanel temporairePanel = new JPanel();
			//temporairePanel.setPreferredSize(new Dimension(largeurPanel,hauteurPanel));
			central.add(new JButton("JButton"));
		}
		
		
		/*for (int i=0;i<10;i++){
			JPanel temporairePanel = new JPanel();
			if (i%2==0){
				temporairePanel.setBounds(largeurPanel*4/100, hauteurPanel*4/100+i/2*hauteurPanel*30/100+i*hauteurPanel/100, largeurPanel*44/100, hauteurPanel*30/100);
				
			}
			else{

				temporairePanel.setBounds(largeurPanel*54/100, hauteurPanel*4/100+i/2*hauteurPanel*30/100+i*hauteurPanel/100, largeurPanel*44/100, hauteurPanel*30/100);

			}
			temporairePanel.setBackground(Color.darkGray);

			mesModules.add(temporairePanel);
			central.add(mesModules.get(i));

		}*/
		
/*
		JScrollPane js = new JScrollPane(central,
		JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
		JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
		js.setPreferredSize(new Dimension(96*width/100,70*height/100));
		add(js);
	}*/
	private void setJPanelandComponent()
	{
		
		JPanel jp = new JPanel();
		//jp.setLayout(null);
		//jp.setLocation(p);
		jp.setPreferredSize(new Dimension(this.largeur,this.hauteur*10));
		ArrayList<JPanel> mesModules = new ArrayList<JPanel>();
		for(int i=0;i<10;i++)
		{
			JPanel temporairePanel = new JPanel();
			temporairePanel.setPreferredSize(new Dimension(largeur-largeur/10,2*hauteur/3));
			temporairePanel.setBackground(Color.BLUE);
			
			JLabel lblInfoImgAmp = new JLabel ("");
			lblInfoImgAmp.setBounds(1, 1, 20*this.largeur/100, 2*hauteur/3);
			lblInfoImgAmp.setOpaque(false);
			//lblInfoImgAmp.setBackground(Color.WHITE);
			Image iconAmpoule = new ImageIcon(this.getClass().getResource("/iconAmpoule.jpg")).getImage();
			lblInfoImgAmp.setIcon(new ImageIcon(this.modifImg.scaleImage(iconAmpoule, 20*largeur/100, 2*hauteur/3)));
			temporairePanel.add(lblInfoImgAmp);
			
			JLabel lblText = new JLabel ("Module Lumi�re" );
			lblText.setBounds(21*this.largeur/100, 1, 30*this.largeur/100, 2*hauteur/3);
			lblText.setFont(new Font("Tahoma", Font.PLAIN,100));
			temporairePanel.add(lblText);
			
			JButton bouton = new JButton("Activer");
			bouton.setBounds(55*largeur/100,1,20*largeur/100,hauteur);
			bouton.setFont(new Font("Tahoma", Font.PLAIN, 100));
			temporairePanel.add(bouton);
			
			mesModules.add(temporairePanel);
			
			jp.add(mesModules.get(i));
		}
		//getContentPane().setLayout(new BorderLayout(0, 0));
		JScrollPane js = new JScrollPane(jp,
				JScrollPane.VERTICAL_SCROLLBAR_ALWAYS,
				JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);
				js.setPreferredSize(new Dimension(largeur,hauteur));
				add(js);
	}
	

}
