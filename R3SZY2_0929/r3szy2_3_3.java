import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class r3szy2_3_3
{
    private static String filename;

    static boolean checkLineForEnd(String line)
    {
        if (line.contains("end"))
            return true;
        else
            return false;
    }

    static String getStringBeforeEnd(String line) //visszaadja a sor "end" előtti részét
    {
        String[] splitline = line.split("end");
        return splitline[0];
    }

    public static ArrayList<String> inputLines()
    {
        System.out.println();
        ArrayList<String> lines = new ArrayList<String>();
        Scanner scanner = null;

        try
        {
            scanner = new Scanner(System.in);
            filename = scanner.nextLine();
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        scanner.close();

        try
        {
            scanner = new Scanner(System.in);

            while (true)
            {
                String line = scanner.nextLine();
                if (checkLineForEnd(line))
                {
                    lines.add(getStringBeforeEnd(line));
                    break;
                }
                else
                {
                    lines.add(line);
                }
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }
        scanner.close();

        return lines;
    }

    public static void writeLinesToFile(ArrayList<String> lines)
    {
        File file = new File(filename);
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

            for (String s : lines)
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


    public static void convertLinesToUpperCase()
    {
        ArrayList<String> lines = new ArrayList<String>();

        try
        {
            File file = new File(filename);
            Scanner scanner = new Scanner(file);
            while (scanner.hasNextLine())
            {
                lines.add(scanner.nextLine());
            }
        }
        catch (Exception e)
        {
            e.printStackTrace();
        }

        ArrayList<String> upperCaseLines = new ArrayList<String>();
        for(String s : lines)
        {
            upperCaseLines.add(s.toUpperCase());
        }

        writeLinesToFile(upperCaseLines);
    }
}
