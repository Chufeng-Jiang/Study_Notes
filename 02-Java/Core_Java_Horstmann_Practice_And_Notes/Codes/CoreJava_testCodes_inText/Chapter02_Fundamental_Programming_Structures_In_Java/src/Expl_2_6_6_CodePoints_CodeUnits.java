public class Expl_2_6_6_CodePoints_CodeUnits {
    // Method to convert the string "U+XXXXX" to the corresponding character
    public static String codePointToString(String codePoint) {
        int cp = Integer.parseInt(codePoint.substring(2), 16);
        return new String(Character.toChars(cp));
    }

    public static void main(String[] args) {
        String greeting = "\uD835\uDD46 is the set of octonions";
        System.out.println(greeting);

        int n = greeting.length(); //26
        int cpCount = greeting.codePointCount(0,greeting.length()); //25

        char first =  greeting.charAt(4); //s
        char last = greeting.charAt(25); //s

        int index = greeting.offsetByCodePoints(0,24); //1
        int cp = greeting.codePointAt(index); //32

        String cpchar= codePointToString("U+1D546");

        System.out.println("greeting.length->n: " + n);
        System.out.println("greeting.codePointCount->cpCount: " + cpCount);
        System.out.println("first: " + first);
        System.out.println("last: " + last);
        System.out.println("index: " + index);
        System.out.println("cp: " + cp);
        System.out.println("cpchar: " + cpchar); //𝕆

        //////////////////////////////////////////////////////

        System.out.println("--------------------------------");
        String sentence = "\u03C0 \uD835\uDD6B";    // the index 1 is a space

        System.out.println(sentence);
        int lengthU = sentence.length();
        System.out.println("lengthU: " + lengthU);        // 4 code units
        int lengthP = sentence.codePointCount(0, lengthU);
        System.out.println("lengthP: " + lengthP);        // 3 code points
        int n2 = sentence.length(); //
        System.out.println("sentence.length->n: " + n2);
        int cpCount2 = sentence.codePointCount(0,sentence.length()); //
        System.out.println("sentence.codePointCount->cpCount: " + cpCount2);

        char first2 =  sentence.charAt(0); // change the number to see different results
        char last2 = sentence.charAt(2); //s
        System.out.println("first2: " + first2);
        System.out.println("last2: " + last2);


        int index2 = sentence.offsetByCodePoints(0,2); //2
        int cp2 = sentence.codePointAt(index2); //dec:120171 -> hex utf32: 1D56B = utf-16 0xD835 0xDD6B
        System.out.println("index2: " + index2);
        System.out.println("cp2: " + cp2); // U+1D56B


    }
}