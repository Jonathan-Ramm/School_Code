

public class Medium
{
    protected boolean habIch;
    protected int spielzeit;
    protected String Titel;

   
    public Medium(String derTitel, int laenge)
    {
       Titel=derTitel;
       spielzeit=laenge;
    }

    public String Titelausgeben()
    {
        return this.Titel;
    }
    
    public int Spielzeit()
    {
        return spielzeit;
    }
    
    public void setzeVorhanden(boolean vorhanden)
    {
        habIch=vorhanden;
    }
    
    public boolean gibVorhanden()
    {
        return habIch;
    }
}
