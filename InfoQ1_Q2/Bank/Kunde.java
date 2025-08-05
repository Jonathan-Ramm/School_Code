
/**
 * Beschreiben Sie hier die Klasse Kunde.
 * 
 * @author (Ihr Name) 
 * @version (eine Versionsnummer oder ein Datum)
 */
public class Kunde
{
    // Instanzvariablen - ersetzen Sie das folgende Beispiel mit Ihren Variablen
    private int x;
    private int kdnr;
    private String name;
    private Konto meinKonto;
    
    
    /**
     * Konstruktor für Objekte der Klasse Kunde
     */
    public Kunde(int kdnr, String name)
    {
        // Instanzvariable initialisieren
        this.kdnr = kdnr;
        this.name = name;
    }

    /**
     * Ein Beispiel einer Methode - ersetzen Sie diesen Kommentar mit Ihrem eigenen
     * 
     * @param  y    ein Beispielparameter für eine Methode
     * @return        die Summe aus x und y
     */
  
    
    public int getkdnr ()
    {
        return kdnr;
    }
    
    public void setkdnr (int neuekdnr)
    {
        kdnr = neuekdnr;
    }
    
    public String getname ()
    {
        return this.name;
    }
    
    public void setname (String neuename)
    {
        name = neuename;
    }
     
    public void setmeinKonto (Konto meinKonto)
    {
        this.meinKonto=meinKonto;
    }
    
    public Konto getmeinKonto()
    {
        return meinKonto;
    }

    
}
