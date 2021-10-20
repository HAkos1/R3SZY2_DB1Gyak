import java.io.*;

/*
    r3szy2_3_6.java

    A fajlnev sajnos nem felel meg a feladatban leirtaknak,
    mivel az Auto class-ra fogok meg hivatkozni.
    Akkor lehet kulonbozo egy java filenev es a benne levo class,
    ha a class nem public.

 */

public class Auto implements Serializable
{
    public String rendszam;
    public String tipus;
    public int ar;

    public Auto(String rendszam, String tipus, int ar)
    {
        this.rendszam = rendszam;
        this.tipus = tipus;
        this.ar = ar;
    }

    public static void writeObjectsToBinaryFile(Auto[] autok, String filename)
    {
        try
        {
            ObjectOutputStream stream = new ObjectOutputStream(
                                        new FileOutputStream(filename));

            for (Auto a : autok)
            {
                stream.writeObject(a);
            }
            stream.close();
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public Auto readObjectFromBinaryFileByIndex(String filename, int index)
    {
        Auto returnval = null;
        try
        {
            ObjectInputStream stream = new ObjectInputStream(
                                       new FileInputStream(filename));

            int i = 0;
            while (true)
            {
                Auto a = null;
                try
                {
                    a = (Auto) stream.readObject();
                } catch (EOFException e) {
                    break;
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
                if (index == i)
                    returnval = a;
                i++;
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
        return returnval;
    }

    public static void main(String args[])
    {
        Auto[] autok =
        {
            new Auto("ABC-123", "Toyota", 500000),
            new Auto("EFG-456", "Volkswagen", 600000),
            new Auto("HIJ-789", "Mercedes", 700000)
        };

    }
}
