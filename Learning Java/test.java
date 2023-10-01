import java.util.Scanner;

public class teste {
    public static void main(String[] args) {
        
        int x = 1;
        String nome = "joao";

        System.out.println(nome);
        System.out.println(x);
        System.out.println("Olá Mundo!");

        Scanner ler = new Scanner(System.in);

        System.out.println("Seu nome: ");
        nome = ler.nextLine();

        System.out.println("Olá, "+ nome+ "!");

        x = ler.nextInt();
        int dobro = x*2;

        for (int i = 0; i < 5; i++) {
            System.out.println("1");
        }

        if (x >= 5)
            System.out.println("Dobro de "+ x + " é "+ dobro);
        else
            System.out.println("Metade de "+ x + " é "+ x/2);
    }
}
