import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class r3szy2_3_5
{
    public static void copyFileAndChangeNumbersToWords(String fromFileName, String toFileName)
    {
        String[] numbers = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"};
        String[] words = {"nulla", "egy", "kettő", "három", "négy", "öt", "hat", "hét", "nyolc", "kilenc"};

        ArrayList<String> lines = new ArrayList<String>();
        try
        {
            File file = new File(fromFileName);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine())
            {
                lines.add(scanner.nextLine());
            }
            scanner.close();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        ArrayList<String> replacedLines = new ArrayList<String>();
        for (String l : lines)
        {
            for (int i = 0; i < numbers.length; i++)
            {
                replacedLines.add(l.replace(numbers[i], words[i]));
            }
        }

        File file = new File(toFileName);
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

            for (String s : replacedLines)
            {
                writer.write(s);
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
