import java.io.*;
import java.util.ArrayList;

public class Szemely
{
    public int id;
    public String nev;

    public Szemely(int id, String nev)
    {
        this.id = id;
        this.nev = nev;
    }

    public void create(String filename)
    {
        try
        {
            ObjectOutputStream stream = new ObjectOutputStream(
                    new FileOutputStream(filename));

            stream.writeObject(this);

            stream.close();
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }
    }

    public static void delete(int id, String nev, String filename)
    {
        ArrayList<Szemely> szemelyList = new ArrayList<Szemely>();
        try
        {
            ObjectInputStream stream = new ObjectInputStream(
                    new FileInputStream(filename));

            int i = 0;
            while (true)
            {
                Szemely sz = null;
                try
                {
                    sz = (Szemely) stream.readObject();
                } catch (EOFException e) {
                    break;
                } catch (ClassNotFoundException e) {
                    e.printStackTrace();
                }
                szemelyList.add(sz);
            }
        }
        catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        catch (IOException e) {
            e.printStackTrace();
        }

    }

}
