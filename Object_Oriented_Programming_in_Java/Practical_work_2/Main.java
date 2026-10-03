import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);

        System.out.print("Введіть логічне значення b (true або false): ");
        boolean b = scanner.nextBoolean();

        System.out.print("Введіть ціле число i: ");
        int i = scanner.nextInt();

        int result = 0;

        if (b) {
            if (i <= -6) {
                result = i - 10;
            }

            else {
                result = i + 1;
            }
        }

        else {
            if (i < 8) {
                result = i - 1;
            }

            else {
                result = i + 10;
            }
        }

        System.out.println("Результат обчислення: " + result);

        scanner.close();
    }
}
