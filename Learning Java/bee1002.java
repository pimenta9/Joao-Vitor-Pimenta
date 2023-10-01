import java.util.Scanner;

public class bee1002 {

    public static void main (String[] args) {

        Scanner read = new Scanner(System.in);

        double raio = read.nextDouble();

        double area = (raio*raio) * (3.14159);

        // System.out.println("A=" + area);
        System.out.println("A=" + String.format("%.4f", area));
    }
}
