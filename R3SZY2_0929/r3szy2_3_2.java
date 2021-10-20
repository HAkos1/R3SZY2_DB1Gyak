import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

class HAFileIr {

    static ArrayList<Integer> getUserInput()
    {
        ArrayList<Integer> intList = new ArrayList<Integer>();

        System.out.println("Hány számot szeretne kiírni a fájlba?");
        Scanner scanner = new Scanner(System.in);

        int numOfInts = 0;
        boolean successfulInput = true;
        do
        {
            try
            {
                numOfInts = scanner.nextInt();
                successfulInput = true;
            }
            catch (Exception e)
            {
                System.out.println("Kérem egy számot írjon be!");
                e.printStackTrace();
                successfulInput = false;
            }
        } while(!successfulInput);
        scanner.close();

        for (int i = 0; i < numOfInts; i++)
        {
            System.out.println("Kérem írja be a " + i + ". számot!");
            Scanner scanner1 = new Scanner(System.in);
            int n = 0;
            boolean successful = true;
            do
            {
                try
                {
                    n = scanner.nextInt();
                    successful = true;
                }
                catch (Exception e)
                {
                    System.out.println("Kérem egy számot írjon be!");
                    e.printStackTrace();
                    successful = false;
                }
            } while(!successful);
            intList.add(n);
        }

        return intList;
    }

    static void writeIntegersToFile(ArrayList<Integer> intList)
    {
        File file = new File("horvath.txt");
        try
        {
            file.createNewFile();
        }
        catch (IOException e)
        {
            System.out.println("Hiba történt fájl létrehozásakor.");
            e.printStackTrace();
        }

        try
        {
            FileWriter writer = new FileWriter(file.getName());
            System.out.println("Adatok kiírása: " + file.getName() + " állományba.");

            for (int i = 0; i < intList.size(); i++)
            {
                System.out.println(intList.get(i));
                writer.write(intList.get(i));
            }
            writer.close();
        }
        catch (IOException e)
        {
            System.out.println("Hiba történt fájlba íráskor.");
            e.printStackTrace();
        }
    }
}
