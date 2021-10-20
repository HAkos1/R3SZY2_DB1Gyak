import java.io.File;
import java.util.Scanner;

public class r3szy2_3_4
{
    public static void printLinesFromFile(String filename)
    {
        try
        {
            File file = new File(filename);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine())
            {
                System.out.println(scanner.nextLine().toUpperCase());
            }
            scanner.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
    }
}
