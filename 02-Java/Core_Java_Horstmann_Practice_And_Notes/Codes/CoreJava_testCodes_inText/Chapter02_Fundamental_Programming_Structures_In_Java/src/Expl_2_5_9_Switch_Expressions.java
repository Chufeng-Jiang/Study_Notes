import java.util.Scanner;

public class Expl_2_5_9_Switch_Expressions {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Please input a number from 0-3:");
        int seasonCode = scanner.nextInt();

        String seasonName = switch (seasonCode){
            case 0 -> "Spring";
            case 1 -> "Summer";
            case 2 -> "Fall";
            case 3 -> "Winter";
            default -> "???";
        };

        System.out.println("The season is: " + seasonName);
        scanner.close();
    }
}
