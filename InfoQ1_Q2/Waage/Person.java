

public class Person
{
    private double Gewicht;
    private double Groeße;
    
    private double Idealgewicht= (Groeße-100)*0.9;
    private double Differenz=Gewicht-Idealgewicht;
    
    public Person()
        {
      
        }
    
    public void Idealgewicht()
        {
            Idealgewicht= (Groeße-100)*0.9;
        }   
    
    public void setGewicht(double neuesGewicht)
        {
            Gewicht=neuesGewicht;
        }
    
    public void setGroeße(double neueGroeße)
        {
            Groeße=neueGroeße;
        }
    
    public double getGewicht()
        {
            return this.Gewicht;
        }
    
     public double getGroeße()
        {
            return this.Groeße;
        }
    
    public void Differenz()
        {
            Differenz=Gewicht-Idealgewicht;
        }
    
    public void anzeigen()
        {
            double x, y, z, d;
            x=getGewicht();
            y=getGroeße();
            z=Idealgewicht;
            d=Differenz;
            System.out.println("Gewicht:"+x+"kg");
            System.out.println("Groeße:"+y+"cm");
            System.out.println("Ihr Idealgewicht ist:"+z+"kg");
            System.out.println("Die Differenz ist:"+d+"kg");
            
            if (d<0){d*=-1;
            System.out.println("Sie müssen"+d+("zunehmen"));}
            else{System.out.println("Sie müssen"+d+("Kilo abnehemen"));};
          
        }
        
    public double gibDifferenz()
    {
        double Differenz,x;
        x=Idealgewicht;
        Differenz=Gewicht-x;
        return Differenz;
    }
   
}
