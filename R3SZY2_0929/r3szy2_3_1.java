import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;

public class XYFileOlvas
{
    public static void sumOfIntsFromFile(String filename)
    {
        ArrayList<Integer> intList = new ArrayList<Integer>();
        try
        {
            File file = new File(filename);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine())
            {
                int n = scanner.nextInt();
                intList.add(n);
            }
            scanner.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        System.out.println("Adatok száma: " + intList.size());
        int sum = 0;
        for (int i = 0; i < intList.size(); i++)
        {
            System.out.println("" + i + ". adat: " + intList.get(i));
            sum += intList.get(i);
        }
        System.out.println("Összeg: " + sum);
    }
    public static void main(String args[])
    {

    }
}
