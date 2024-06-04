import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.util.Scanner;

public class Expl_2_7_3_File_Input_and_Output {
    public static void main(String[] args){
        //Scanner in = new Scanner(System.in);
        StringBuilder content = new StringBuilder();

        try
        {
            Scanner in = new Scanner(Path.of("fileInTest.txt"), StandardCharsets.UTF_8);
            while (in.hasNextLine()){
                content.append(in.nextLine());
                content.append("+aaaaaaa\n");
                System.out.println(content);
            }

            PrintWriter out =  new PrintWriter("new_FileOutTest.txt", StandardCharsets.UTF_8);
            out.println(content);

            out.close();
            in.close();
        }
        catch(IOException e)
        {
            System.out.println("file not found!");
        }
    }
}
