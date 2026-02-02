import sympy as sp

# обчислює значення функції за формулою трапецій
def trapezoids(a, b, n, f):
    h = (b - a) / n          # обчислення кроку
    s = 0                    # змінна для зберігання суми функцій

    for i in range(1, n):    # внутрішні вузли
        x = a + i * h        # обраховуємо наступний х
        s += f(x)            # обраховуємо суму значень функції

    result = h/2 * (f(a) + f(b) + 2 * s) # формула трапецій

    return result # повертаємо результат обчислень

def main(): # головна функція програми
    # створюємо математичні змінні для x та y
    x_symbol = sp.symbols('x')
    allowed_symbols = {x_symbol}

    while True: # введення підінтегральної функції користувачем
        try:
            function_str = input("Введіть підінтегральну функцію f(x): ") # вводимо функцію (рядок)

            if not function_str.strip(): # перевірка на порожній рядок
                print("Помилка! Введено пустий рядок")
                continue

            function = sp.sympify(function_str, locals={'e': sp.exp(1)}) # створюємо функцію щоб програма знала число e

            if not function.free_symbols:
                print("Помилка! Ви ввели константу, а не функцію (відсутня змінна x)")
                continue

            # перевірка чи є зайві змінні
            error_vars = function.free_symbols - allowed_symbols # з введених змінних прибираємо х
            if error_vars: # якщо ще є символьні змінні окрім х
                print(f"Помилка! Знайдено невідомі змінні: {error_vars}")
                print("Дозволено використовувати лише 'x'")
                continue

            f = sp.lambdify(x_symbol, function, 'numpy') # створюємо функцію для обчислень

            print("Функцію успішно прийнято!")
            break

        except Exception as e: # якщо виникла помилка
            print(f"Помилка при введенні функції: {e}")

    while True: # введення нижньої межі інтегрування
        try: # спробуємо виконати наступний блок коду
            a = float(input("Введіть нижню межу інтегрування a: "))
            break
        except ValueError: # якщо виникла помилка
            print("Помилка! Введіть число")

    while True: # введення верхньої межі інтегрування
        try: # спробуємо виконати наступний блок коду
            b = float(input("Введіть верхню межу інтегрування b: "))

            if a >= b:
                print("Помилка! b повинно бути більше за a")
            else:
                break
        except ValueError: # якщо виникла помилка
            print("Помилка! Введіть число")

    while True: # введення точності обчислень е
        try: # спробуємо виконати наступний блок коду
            epsilon = float(input("Введіть точність обчислень e: "))

            if epsilon <= 0 or epsilon >= 1:
                print("Помилка! Значення e введено не правильно")
            else:
                break
        except ValueError: # якщо виникла помилка
            print("Помилка! Введіть число")

    n = 2 # початкова кількість відрізків (на скільки частин поділено відрізок ab)
    s_previous = None # попереднє значення формули прямокутників

    while True: # цикл триватиме поки не спрацює break
        h = (b - a) / n

        try: # спробуємо обчислити за формулою прямокутників
            s_current = trapezoids(a, b, n, f)

        except Exception as err: # якщо виникла помилка
            print(f"Помилка при обчисленні значень функції: {err}")
            return

        if s_previous is not None: # якщо попередньо обчислене значення існує
            print(f"\nПеревіримо отримане значення інтеграла ({s_previous:.4f}) на точність розрахунків:")
            print(f"    Застосуємо правило Рунге")

            R = abs(s_current - s_previous) / 3 # оцінюємо похибку

            print(f"    Значення інтеграла при n = {n} дорівнює {s_current:.4f} ")
            print(f"    Похибка = |{s_current:.4f} - {s_previous:.4f}| / 3 = {R:.8f}")

            if R <= epsilon: # якщо шукану точність знайдено
                print(f"\nДосягнуто заданої точності e = {epsilon:.8f}!")
                print(f"Кінцевий результат: {s_previous:.4f}\nПохибка = {R:.8f}\nn = {n/2}\nh = {h*2}")
                break
            else:
                print(f"\nЗаданої точності e = {epsilon:.8f} не досягнуто")
                print(f"Перейдемо до значення інтеграла при n = {n}")
        else:
            print(f"\nЗначення інтеграла при n = {n} дорівнює {s_current:.4f}")

        # готуємось до наступної ітерації
        s_previous = s_current
        n *= 2

main() # виклик головної функції програми
