import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Клас для виконання першої частини практичної роботи.
 * Реалізує зчитування одного набору даних з файлу, обчислення та запис результату.
 */
public class Part_1 {

    /**
     * Точка входу в програму.
     * Відповідає за читання файлу input.txt та запис у output.txt.
     *
     * @param args аргументи командного рядка
     */
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(new File("input.txt"));
             PrintWriter writer = new PrintWriter(new FileWriter("output.txt"))) {

            if (scanner.hasNextBoolean()) {
                boolean b = scanner.nextBoolean();

                if (scanner.hasNextInt()) {
                    int i = scanner.nextInt();

                    int result = calculation(b, i);

                    String message = "Результат обчислення для b = " + b + ", i = " + i + ": " + result;

                    System.out.println(message);
                    writer.println(message);
                }
                else {
                    System.out.println("Помилка! Друге значення не є цілим числом");
                    writer.println("Помилка! Друге значення не є цілим числом");
                }
            }
            else {
                System.out.println("Помилка! Файл input.txt порожній або перше значення некоректне");
                writer.println("Помилка! Файл input.txt порожній або перше значення некоректне");
            }
        }
        catch (IOException e) {
            System.out.println("Помилка роботи з файлами: " + e.getMessage());
        }
    }

    /**
     * Метод обчислює результат за алгоритмом згідно 4 варіанту.
     *
     * @param b логічне значення для вибору гілки алгоритму
     * @param i ціле число для математичних операцій
     * @return обчислений результат типу int
     */
    public static int calculation(boolean b, int i) {
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

        return result;
    }
}