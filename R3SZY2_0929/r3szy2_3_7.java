import java.io.*;
import java.util.ArrayList;

public class r3szy2_3_7
{
    public static ArrayList<Auto> readObjectsFromBinaryFile(String filename)
    {
        ArrayList<Auto> returnval = new ArrayList<Auto>();
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
                returnval.add(a);
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

    public static void printCarsMoreExpensiveThan300(ArrayList<Auto> autok)
    {
        for (Auto a : autok)
        {
            if (a.ar>300)
                System.out.println("Auto rendszama: " + a.rendszam);
        }
    }
}
