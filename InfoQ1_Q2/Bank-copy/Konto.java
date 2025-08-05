
/**
 * Beschreiben Sie hier die Klasse Konto.
 * 
 * @author (Ihr Name) 
 * @version (eine Versionsnummer oder ein Datum)
 */
public class Konto
{
    private String besitzerName;
    private double kontostand;
    private String Telefonnummer;
    private double kreditlimit;
    


    /**
     * Konstruktor für Objekte der Klasse Konto
     */
    public Konto(String besitzerName)
    {
        // Instanzvariable initialisieren
         this.besitzerName = besitzerName;
         this.kontostand = 0.0;
         this.kreditlimit = 0.0;
         this.Telefonnummer = "0";
        }
        
    public void setbesitzerName (String neuerName)
    {
        besitzerName = neuerName; //this.besitzerName =neuerName
    }
    
    public String getbesitzerName ()
    {
    return this.besitzerName;
    }
    
    public void einzahlen (double Betrag)
    {
    this.kontostand = this.kontostand + Betrag;
    }
    
    public void auszahlen (double Betrag)
    {
    this.kontostand = this.kontostand - Betrag;
    }
    
      public void setkontostand (double Menge)
    {
        kontostand = Menge; //this.besitzerName =neuerName
    }
    
    public double getkontostand ()
    {
    return this.kontostand;
    }
    
    public void abräumen ()
    {
        kontostand = 0;
    }
    
    public void bucheZinsen (double Zinssatz)
    {
        this.kontostand = kontostand * (1+ Zinssatz);
    }
}

    

