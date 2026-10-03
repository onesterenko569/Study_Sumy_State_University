import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.io.IOException;
import java.util.Scanner;

/**
 * Клас для виконання другої частини практичної роботи.
 * Обробляє декілька наборів даних з файлу config.txt та записує результати.
 */
public class Part_2 {

    /**
     * Точка входу в програму для другої частини.
     * Відповідає за зчитування файлу, перевірку коректності
     * кожного набору даних та виведення результатів обчислень.
     *
     * @param args аргументи командного рядка
     */
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(new File("config.txt"));
             PrintWriter writer = new PrintWriter(new FileWriter("output.txt"))) {

            if (scanner.hasNextInt()) {
                int count = scanner.nextInt();

                String initMessage = "Кількість наборів для обробки: " + count;

                System.out.println(initMessage);
                writer.println(initMessage);

                for (int k = 1; k <= count; k++) {

                    if (scanner.hasNextBoolean()) {
                        boolean b = scanner.nextBoolean();

                        if (scanner.hasNextInt()) {
                            int i = scanner.nextInt();

                            int result = Part_1.calculation(b, i);

                            String message = "Результат набору " + k + " (b = " + b + ", i = " + i + "): " + result;

                            System.out.println(message);
                            writer.println(message);
                        }
                        else {
                            String errorMessage = "Помилка! У наборі " + k + " друге значення не є цілим числом";

                            System.out.println(errorMessage);
                            writer.println(errorMessage);

                            break;
                        }
                    }
                    else {
                        String errorMessage = "Помилка! У наборі " + k + " перше значення некоректне або відсутнє";

                        System.out.println(errorMessage);
                        writer.println(errorMessage);

                        break;
                    }
                }
            }
            else {
                String errorMessage = "Помилка! Файл config.txt порожній або не містить кількості наборів на початку";

                System.out.println(errorMessage);
                writer.println(errorMessage);
            }

        } catch (IOException e) {
            System.out.println("Помилка роботи з файлами: " + e.getMessage());
        }
    }
}