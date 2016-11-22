package controler;

import java.text.ParseException;
import java.util.Date;
import java.util.InputMismatchException;
import java.util.Scanner;
import java.text.DateFormat;
import java.text.SimpleDateFormat;


public class saisie {

	/********************************************************************
	************************Saisir un entier*****************************
	********************************************************************/
		public int saisieEntier()
		{
			boolean verification=false;
			int X=0;
			do
			{
				Scanner s = new Scanner(System.in);
				try
				{
					X = s.nextInt();
					verification = true;
				}
			 	catch (InputMismatchException e) 
			  	{
				 verification = false;
			  	}	
			}while(verification!=true);
			return X;
		}


	/********************************************************************
	************************Saisir un String*****************************
	********************************************************************/

		public String saisieString()
		{
			boolean verification=false;
			String X="";
			do
			{
				Scanner s = new Scanner(System.in);
				try
				{
					X = s.nextLine();
					verification = true;
				}
			 	catch (InputMismatchException e) 
			  	{
				 verification = false;
			  	}	
			}while(verification!=true);
			return X;
		}
		
		
		
		
		/********************************************************************
		************************Saisir une date *****************************
		********************************************************************/
		public Date saisieDate()
		{
			
		
			DateFormat format =new SimpleDateFormat("dd/mm/yyyy");
			Scanner scan=new Scanner(System.in);
		    
			Date date=null;
			
		    while (date==null) 
		    {
		        System.out.print("date (dd/mm/yyyy): ");
		        String entree=scan.next();
		
		        try 
		        {
		            date=format.parse(entree);
		        } 
		        catch (ParseException e) 
		        {
		            
		        }
		    }
		    return date;
		}
	
}
