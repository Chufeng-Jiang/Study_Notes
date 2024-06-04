import java.io.IOException;
import java.io.PrintWriter;
import java.nio.charset.StandardCharsets;
import java.nio.file.Path;
import java.util.Scanner;

public class Expl_2_8_5_Yield_Statement {
    public static void main(String[] args) {
        var seasonName = "Spring";
         int numLetters = switch(seasonName){
             case "Spring" -> {
                 System.out.println("Spring Time");
                 yield 6;
             }
             case "Summer", "Winter" -> 6;
             case "Fall" -> 4;
             default -> -1;
         }; // be careful here, a \; is required
        System.out.println(numLetters);
    }
}
