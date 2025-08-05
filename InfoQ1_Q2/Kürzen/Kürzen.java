
import java.io.*;

public class Kürzen
{
    
    private int a;
    private int b;
    private int rest;
    public Kürzen()
    {
        
    }
    
    public void kuerzen() throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        System.out.println("Zaehler eingeben");
        int Zaehler= Integer.parseInt(in.readLine());
        System.out.println("Nenner eingeben");
        int Nenner= Integer.parseInt(in.readLine());
        a=Nenner;
        b=Zaehler; 
        
        while (b!=0){
              rest=a%b;a=b;b=rest;
           }
        int erg=a;
        System.out.println("Der größte gemeinsame teiler ist " + erg + ".");
    }
    //public void vergleichen()
    //{
    //       a=Nenner;
    //       b=Zaehler;
    //       while (y!=0){
    //           rest=a%b;a=b;b=rest;
    //       }
    //}
}
