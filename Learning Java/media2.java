import java.util.Scanner;

public class bee1006 {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        double A = sc.nextDouble();
        double B = sc.nextDouble();
        double C = sc.nextDouble();

        double media = (2*A + 3*B + 5*C) / 10;

        System.out.println("MEDIA = " + String.format("%.1f", media));
    }
}
