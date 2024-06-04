import java.io.Console;
import java.util.Scanner;

public class Expl_2_7_1_ConsoleClass_Passwords {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        // get first input
        System.out.print("What is your name?");
        String name = in.nextLine();

        // get second input
        System.out.print("How old are you?");
        int age = in.nextInt();

        // display output to console
        System.out.println("Hello, " + name + ". New year you will be " + (age + 1));

        Console  cons = System.console();
        if(cons != null)
        {
            System.out.print("User Name：");
            String username = cons.readLine();

            System.out.print("Password: ");
            char[] passwd = cons.readPassword();
        }
        else
        {
            System.out.println("Console object is null");
        }
    }
}