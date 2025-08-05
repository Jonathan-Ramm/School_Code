

public class CD extends Medium
{
    private String Kuenstler;
    private int Titelanzahl;
    
    public CD(String Titel, int spielzeit, String Kuenstler, int Titelanzahl)
    {
        super(Titel, spielzeit);
        this.Kuenstler=Kuenstler;
        this.Titelanzahl=Titelanzahl;
    }
    
    public String gibKuenstler()
    {
        return Kuenstler;
    }

    public int Titelanzahl()
    {
        return Titelanzahl;
    }
    
}
