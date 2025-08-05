
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
    private double Zinssatz;
    


    /**
     * Konstruktor für Objekte der Klasse Konto
     */
    
        
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
    
    public void bucheZinsen ()
    {
        this.kontostand = kontostand * (1+ Zinssatz);
    }
    
    public void setZinssatz (double neuerZinssatz)
    {
        Zinssatz = neuerZinssatz;
    }
    
    public void ueberweisen (Konto empfaenger, int betrag)
    {
        auszahlen(betrag);
        empfaenger.einzahlen(betrag);
    }
}

    

