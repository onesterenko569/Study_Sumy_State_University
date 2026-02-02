import numpy as np
import math

def average_arr(arr): # обрахування середнього арифметичного
    return np.mean(arr)

def geometric_mean(arr): # обрахування середнього геометричного
    return np.prod(arr) ** (1 / len(arr))

def harmonic_mean(arr): # обрахування середнього гармонійного
    denominator = sum(1/x for x in arr)
    return len(arr) / denominator

def regression_equation(N, x, y):
    x_arithmetic = average_arr(x)
    x_geometric = geometric_mean(x)
    x_harmonic = harmonic_mean(x)

    y_arithmetic= average_arr(y)
    y_geometric = geometric_mean(y)
    y_harmonic = harmonic_mean(y)

    x_average = []
    y_average = []

    for i in range (0, N): # створюємо стовпець х середнє
        if i % 3 == 0:
            x_average.append(x_arithmetic)
        if i % 3 == 1:
            x_average.append(x_geometric)
        if i % 3 == 2:
            x_average.append(x_harmonic)

    while len(y_average) < N: # створюємо стовпець y середнє
        for i in range(0, 3):
            y_average.append(y_arithmetic)
        for i in range(0, 3):
            y_average.append(y_geometric)
        for i in range(0, 3):
            y_average.append(y_harmonic)

    # списки які зберігатимуть значення хі, хі+1, уі, уі+1
    x_i = []
    y_i = []
    x_i_plus_1 = []
    y_i_plus_1 = []

    for k in range (0, 3): # цикл знаходження хі, хі+1, уі, уі+1
        for i in range (0, N-1):
            if x_average[k] >= x[i] and x_average[k] <= x[i+1]:
                x_i.append(x[i])
                x_i_plus_1.append(x[i+1])
                y_i.append(y[i])
                y_i_plus_1.append(y[i+1])
                break

    y_regressive = [] # зберігатиме обраховане значення у регресивного

    for i in range (0, 3): # обрахування перших трьох значень у регресивного
        y_r = y_i[i] + ((y_i_plus_1[i] - y_i[i]) / (x_i_plus_1[i] - x_i[i])) * (x_average[i] - x_i[i])
        y_regressive.append(y_r)

    for i in range (0, N-3): # заповнюємо решту масиву який зберігає значення y регресивного
        if i % 3 == 0:
            y_regressive.append(y_regressive[0])
        if i % 3 == 1:
            y_regressive.append(y_regressive[1])
        if i % 3 == 2:
            y_regressive.append(y_regressive[2])

    y_module = [] # список який зберігатиме обчислений модуль

    for i in range (0, N): # створюємо стовпець модуля
        y_m = np.abs((y_average[i] - y_regressive[i]) / y_regressive[i])
        y_module.append(y_m)

    smallest_value = min(y_module) # знаходимо найменший елемент списку
    smallest_index = y_module.index(smallest_value) # знаходимо індекс найменшого елемента списку
    smallest_index += 1 # збільшуємо на 1

    # виведення таблиці
    print("\nТаблиця для встановлення вигляду рівняння регресії:")
    print("\n|  №  |  Xav  |  Yav  |   Y^  |  |(Yav - Y^) / Y^|  |")
    print("----------------------------------------------------")
    for i in range(0, N):
        print(f"|  {i+1}  | {x_average[i]:.3f} | {y_average[i]:.3f} | {y_regressive[i]:.3f} |        {y_module[i]:.3f}        |")

    return smallest_index

def calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2): # обрахунок коефіцієнтів а0 та а1
    a1 = (sum_x_y - (1.0 / N) * sum_x * sum_y) / (sum_x_2 - (1.0 / N) * sum_x_then_2)
    a0 = (1.0 / N) * sum_y - (a1 / N) * sum_x
    return a0, a1 # повернення обрахованих коефіцієнтів

def first_function_calculation(N, x, y): # розрахунок коефіцієнтів для лінійної функції та її виведення
    # оголошуємо списки
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        x_2.append(x[i] ** 2)
        y_2.append(y[i] ** 2)
        x_y.append(x[i] * y[i])

    # обчислення сум
    sum_x = sum(x)
    sum_y = sum(y)
    sum_x_y = sum(x_y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_then_2 = sum_x ** 2

    a0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2)  # обчислення коефіцієнтів
    print(f"y = {a0:.4f} + {a1:.4f} * x")  # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def second_function_calculation(N, x, y): # розрахунок коефіцієнтів для логарифмічної функції та її виведення
    # оголошуємо списки
    X = []
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        xl = math.log(x[i])
        X.append(xl)
        x_2.append(xl ** 2)
        y_2.append(y[i] ** 2)
        x_y.append(xl * y[i])

    # обчислення сум
    sum_x = sum(X)
    sum_y = sum(y)
    sum_x_y = sum(x_y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_then_2 = sum_x ** 2

    a0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2)  # обчислення коефіцієнтів
    print(f"y = {a0:.4f} + {a1:.4f} * ln(x)")  # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def third_function_calculation(N, x, y): # розрахунок коефіцієнтів для гіперболічної функції та її виведення
    # оголошуємо списки
    X = []
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        t = 1.0 / x[i]
        X.append(t)
        x_2.append(t ** 2)
        y_2.append(y[i] ** 2)
        x_y.append(t * y[i])

    # обчислення сум
    sum_x = sum(X)
    sum_y = sum(y)
    sum_x_y = sum(x_y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_then_2 = sum_x ** 2

    a0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2)  # обчислення коефіцієнтів
    print(f"y = {a0:.4f} + {a1:.4f} / x")  # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def fourth_function_calculation(N, x, y): # розрахунок коефіцієнтів для показникової функції та її виведення
    # оголошуємо списки
    Y = []
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        yl = math.log(y[i])
        Y.append(yl)
        x_2.append(x[i] ** 2)
        y_2.append(yl ** 2)
        x_y.append(x[i] * yl)

    # обчислення сум
    sum_x = sum(x)
    sum_y = sum(Y)
    sum_x_y = sum(x_y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_then_2 = sum_x ** 2

    A0, A1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2)  # обчислення коефіцієнтів

    # обраховуємо а0 та а1
    a0 = math.exp(A0)
    a1 = math.exp(A1)

    print(f"y = {a0:.4f} * {a1:.4f}^(x)")  # виведення функції

    return A1, sum_x, sum_y, sum_x_y, sum_y_2

def fifth_function_calculation(N, x, y): # розрахунок коефіцієнтів для степеневої функції та її виведення
    # оголошуємо списки
    Y = []
    X = []
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        xl = math.log(x[i])
        yl = math.log(y[i])
        X.append(xl)
        Y.append(yl)
        x_2.append(xl ** 2)
        y_2.append(yl ** 2)
        x_y.append(xl * yl)

    # обчислення сум
    sum_x = sum(X)
    sum_y = sum(Y)
    sum_x_y = sum(x_y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_then_2 = sum_x ** 2

    A0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2)  # обчислення коефіцієнтів

    # обраховуємо а0 та а1
    a0 = math.exp(A0)

    print(f"y = {a0:.4f} * x^({a1:.4f})")  # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def sixth_function_calculation(N, x, y): # розрахунок коефіцієнтів для експоненційної функції та її виведення
    # оголошуємо списки
    Y = []
    X = []
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        xt = 1.0 / x[i]
        yl = math.log(y[i])
        X.append(xt)
        Y.append(yl)
        x_2.append(xt ** 2)
        y_2.append(yl ** 2)
        x_y.append(xt * yl)

    # обчислення сум
    sum_x = sum(X)
    sum_y = sum(Y)
    sum_x_y = sum(x_y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_then_2 = sum_x ** 2

    a0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2)  # обчислення коефіцієнтів

    print(f"y = e^({a0:.4f} + {a1:.4f} / x)")  # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def seven_function_calculation(N, x, y): # розрахунок коефіцієнтів для дробово-лінійної функції та її виведення
    # оголошуємо списки
    Y = []
    x_2 = []
    y_2 = []
    x_y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        yl = 1.0 / y[i]
        Y.append(yl)
        x_2.append(x[i] ** 2)
        y_2.append(yl ** 2)
        x_y.append(x[i] * yl)

    # обчислення сум
    sum_x = sum(x)
    sum_y = sum(Y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_y = sum(x_y)
    sum_x_then_2 = sum_x ** 2

    a0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2) # обчислення коефіцієнтів
    print(f"y = 1 / ({a0:.4f} + {a1:.4f} * x)") # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def eight_function_calculation(N, x, y): # розрахунок коефіцієнтів для дробово-логарифмічної функції та її виведення
    # оголошуємо списки
    X = []
    Y = []
    x_2 = []
    y_2 = []
    x_Y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        xl = math.log(x[i])
        yt = 1.0 / y[i]
        X.append(xl)
        Y.append(yt)
        x_2.append(xl ** 2)
        y_2.append(yt ** 2)
        x_Y.append(xl * yt)

    # обчислення сум
    sum_x = sum(X)
    sum_y = sum(Y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_y = sum(x_Y)
    sum_x_then_2 = sum_x ** 2

    a0, a1 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2) # обчислення коефіцієнтів
    print(f"y = 1 / ({a0:.4f} + {a1:.4f} * ln(x))") # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def ninth_function_calculation(N, x, y): # розрахунок коефіцієнтів для дробово-лінійної функції 2-го роду та її виведення
    # оголошуємо списки
    X = []
    Y = []
    x_2 = []
    y_2 = []
    x_Y = []

    # обчислення необхідних компонентів
    for i in range(0, N):
        xt = 1.0 / x[i]
        yt = 1.0 / y[i]
        X.append(xt)
        Y.append(yt)
        x_2.append(xt ** 2)
        y_2.append(yt ** 2)
        x_Y.append(xt * yt)

    # обчислення сум
    sum_x = sum(X)
    sum_y = sum(Y)
    sum_x_2 = sum(x_2)
    sum_y_2 = sum(y_2)
    sum_x_y = sum(x_Y)
    sum_x_then_2 = sum_x ** 2

    a1, a0 = calculation_a0_a1(N, sum_x, sum_y, sum_x_y, sum_x_2, sum_x_then_2) # обчислення коефіцієнтів
    print(f"y = x / ({a0:.4f} + {a1:.4f} * x)") # виведення функції

    return a1, sum_x, sum_y, sum_x_y, sum_y_2

def coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2): # функція обрахування коефіцієнта детермінації
    R = (a1 * (N * sum_x_y - sum_x * sum_y)) / (N * sum_y_2 - sum_y ** 2)
    print(f"\nR^(2) = {R:.4f}")
    return R

def criterion_Fisher(R, N, M):
    F = (R / (1 - R)) * (N - M - 1) / M
    print(f"F = {F:.4f}")

def main():
    while True: # введення кількості точок
        try:
            N = int(input("Введіть кількість точок: "))
            if N < 2:
                print("\nКількість точок має бути не менше 2\n")
            elif N > 50:
                print("\nКількість точок має бути не більше 50\n")
            else:
                break  # коректне значення, вихід із циклу
        except ValueError:
            print("\nПомилка: введіть ціле число!\n")

    x = [] # список для координат по х
    y = [] # список для координат по y

    for i in range (0, N): # цикл для введення координат точок (x; y)
        print(f"\nВведіть координати {i+1} точки:")
        while True: # цикл для введення х
            try:
                x_ = float(input(f"   x[{i + 1}] = "))
                if x_ in x:
                    print("   Помилка: введено значення х яке вже існує!")
                elif x_ == 0:
                    print("   Введіть інше значення, виникне помилка при знаходженні середнього геометричного")
                else:
                    x.append(x_)
                    break
            except ValueError:
                print("   Помилка: введіть число!")

        while True: # цикл для введення y
            try:
                y_ = float(input(f"   y[{i + 1}] = "))
                if y_ == 0:
                    print("   Введіть інше значення, виникне помилка при знаходженні середнього геометричного")
                else:
                    y.append(y_)
                    break
            except ValueError:
                print("   Помилка: введіть число!")

    # зшиваємо і сортуємо по x
    data = sorted(zip(x, y))
    x = [p[0] for p in data]
    y = [p[1] for p in data]

    smallest_idx = regression_equation(N, x, y)
    M = 1

    if smallest_idx == 1: # якщо лінійна функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = first_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 2: # якщо логарифмічна функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = second_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 3: # якщо гіперболічна функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = third_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 4: # якщо показникова функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = fourth_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 5: # якщо степенева функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = fifth_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 6: # якщо експоненційна функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = sixth_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 7: # якщо дробово-лінійна функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = seven_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    elif smallest_idx == 8: # якщо дробово-логарифмічна функція
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = eight_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

    else: # якщо дробово-лінійна функція 2-го роду
        print(f"\nДля Ваших даних оптимальним є {smallest_idx} рівняння регресії:")
        a1, sum_x, sum_y, sum_x_y, sum_y_2 = ninth_function_calculation(N, x, y)
        R = coefficient_determination(N, a1, sum_x, sum_y, sum_x_y, sum_y_2)
        criterion_Fisher(R, N, M)

main()
