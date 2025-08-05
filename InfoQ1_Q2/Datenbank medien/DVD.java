

public class DVD extends Medium
{
    private String regisseur;
    
    public DVD(String Titel, int spielzeit, String derRegisseur)
    {
        super(Titel, spielzeit);
        this.regisseur=derRegisseur;
    }
    
    public String gibRegisseur()
    {
        return regisseur;
    }


}
