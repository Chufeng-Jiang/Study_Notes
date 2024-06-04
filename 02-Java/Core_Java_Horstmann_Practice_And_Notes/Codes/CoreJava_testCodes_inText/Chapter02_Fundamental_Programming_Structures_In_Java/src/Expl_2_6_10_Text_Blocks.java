public class Expl_2_6_10_Text_Blocks {
    public static void main(String[] args) {
        String greeting = """
                Hello
                World
                """; // "Hello\nWorld\n"
        System.out.println(greeting);


        String prompt = """
                Hello, my name is Chufeng.
                Please enter your name:
                """;
        System.out.println(prompt);

        String prompt1 = """
                Hello, my name is Chufeng. \
                Please enter your name:
                """;
        System.out.println(prompt1);

        String html= """
                <div class = "Warning">
                    Beware of those who say "Hello" to the world
                </div>
                """;
        System.out.println(html);


    }
}