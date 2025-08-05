
public class Person
{
    // Instanzvariablen - ersetzen Sie das folgende Beispiel mit Ihren Variablen
  
    protected String Name;
    protected String Vorname;
    protected String GDatum;
     
      
    public Person(String Name, String Vorname, String GDatum)
    {
        // Instanzvariable initialisieren
        this.Name=Name;
        this.Vorname=Vorname;
        this.GDatum=GDatum;
        }
        
    public void setName(String neuerName)
    {
        Name=neuerName;
    }
    
    public void setVorname(String neuerVorname)
    {
        Vorname=neuerVorname;
    }
    
    public String Vorname()
    {
        return this.Vorname;
    }
    
    public String Name()
    {
        return this.Name;
    }
    
    public String GDatum()
    {
        return this.GDatum;
    }

}
