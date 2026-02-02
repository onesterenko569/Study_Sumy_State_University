import math

# задана функція згідно 9-го варіанту
def f(x, y):
    return 4*(x - y) - x*x - y*y  # повертає розраховане значення функції в заданій точці

# функція розрахунку частинних похідних
def grad(x, y):
    return (4 - 2*x, -4 - 2*y) # повертаємо df/dx та df/dy

# функція обрахунку довжини вектора
def vector_length(vx, vy):
    return math.sqrt(vx*vx + vy*vy) # повертаємо обраховану довжину вектора

# функція обрахунку значення функції з lam*dx
def theta(x, y, dx, dy, lam):
    return f(x + lam*dx, y + lam*dy)

# функція реалізації методу квадратичної інтерполяції
def quadratic_interpolation(phi, a, b, c):
    fa, fb, fc = phi(a), phi(b), phi(c) # розраховуємо значення функції в точках a, b, c

    num = (b*b - c*c)*fa + (c*c - a*a)*fb + (a*a - b*b)*fc # обраховуємо чисельник формули
    den = (b - c)*fa + (c - a)*fb + (a - b)*fc             # обраховуємо знаменник формули

    if abs(den) < 1e-15:     # перевірка чи знаменник не 0
        return b, fa, fb, fc # нічого не можемо зробити, повертаємо дані

    delta = 0.5 * (num / den) # рахуємо дельта за формулою
    return delta, fa, fb, fc  # повертаємо розраховані дані

# функція, яка підбирає оптимальний крок лямда, щоб значення функції стало максимальним
def search_max_quad_interp(x, y, dx, dy, lam, inner_iters=3):
    def phi(t): # внутрішня функція, яка змінює знак на протилежний
        return -theta(x, y, dx, dy, t) # повертає theta з протилежним знаком

    a = 0.0       # крок = 0
    b = lam / 2.0 # крок = 2
    c = lam       # крок = 4

    # виведення проміжних результатів
    print(f"При кроці a = {a:.2f}, phi(a) = {theta(x,y,dx,dy,a):.4f}")
    print(f"При кроці b = {b:.2f}, phi(b) = {theta(x,y,dx,dy,b):.4f}")
    print(f"При кроці c = {c:.2f}, phi(c) = {theta(x,y,dx,dy,c):.4f}")

    # pнайдемо мінімум функції, скориставшись методом квадратичної інтерполяції
    for k in range(1, inner_iters + 1): # цикл з рівно 3 ітераціями
        delta, fa, fb, fc = quadratic_interpolation(phi, a, b, c) # розраховуємо за допомогою квадратичної інтерполяції дельту

        lo, hi = min(a, c), max(a, c) # обмежимо дульту в межах [min(a,c), max(a,c)], щоб не вилітала за межі

        if delta < lo: # якщо дельта вилетіла за нижню межу
            delta = lo # перезаписуємо дельту

        if delta > hi: # якщо дельта вилетіла за верхню межу
            delta = hi # перезаписуємо дельту

        fd = phi(delta) # обраховуємо значення функції в дельті
        td = -fd        # беремо з протилежним знаком

        print(f"Внутр. ітерація {k}: delta = {delta:.2f}, phi(delta)={td:.4f}")

        # беремо 4 точки і залишаємо 3 з найменшим phi
        pts = [(a, phi(a)), (b, phi(b)), (c, phi(c)), (delta, fd)]
        pts.sort(key=lambda p: p[1])  # сортуємо за зростанням phi

        best3 = pts[:3] # залишаємо перших три
        best3.sort(key=lambda p: p[0]) # упорядкуємо по координатах

        # зберігаємо нові три значення a, b, c, з якими будемо працювати
        a, b, c = best3[0][0], best3[1][0], best3[2][0]

    # беремо найкращий крок лямда серед a,b,c
    candidates = [(a, theta(x, y, dx, dy, a)),
                  (b, theta(x, y, dx, dy, b)),
                  (c, theta(x, y, dx, dy, c))]
    lam_best, th_best = max(candidates, key=lambda p: p[1])

    print(f"Результат пошуку: lambda = {lam_best:.2f}, phi(lambda)={th_best:.4f}")
    return lam_best # повертаємо результат обчислень

# функція методу градієнтного спуску
def gradient_descent_method(eps, lam0, x0, y0, max_iters=50):
    x, y = x0, y0 # зберігаємо копії змінних
    lam = lam0    # зберігаємо копії змінних

    for it in range(1, max_iters + 1):    # цикл з максимальною кількістю ітерацій 50
        gx, gy = grad(x, y)               # знаходимо частинні похідні функції
        grad_norm = vector_length(gx, gy) # обчислюємо довжину вектора (норму градієнта)
        fx = f(x, y)                      # обчислюємо значення функції в точці (х; y)

        # виведення проміжних результатів
        print(f"\n               Ітерація {it}")
        print(f"Поточна точка: x = {x:.2f}, y = {y:.2f}")
        print(f"f(x,y) = {fx:.4f}")
        print(f"grad = ({gx:.4f}, {gy:.4f})\n|grad| = {grad_norm:.4f}")

        if grad_norm <= eps: # якщо заданої точності досягнуто
            print("\nЗадану точність досягнуто!") # виведення відповідного повідомлення
            break                                 # зупиняємо цикл

        # зберігаємо копії змінних
        dx, dy = gx, gy

        # розраховуємо лямду
        lam_best = search_max_quad_interp(x, y, dx, dy, lam, inner_iters=3)

        # оновлення точок
        x_new = x + lam_best * dx
        y_new = y + lam_best * dy

        print(f"Оновлення: x1 = {x_new:.2f}, y1 = {y_new:.2f}")
        print(f"f(x1,y1) = {f(x_new, y_new):.4f}")

        x, y = x_new, y_new # оновлюємо x, y

        # зменшуємо початковий крок удвічі на наступну ітерацію
        lam = lam / 2.0

    # виведення результатів
    print(f"Відповідь:\n   x = {x:.2f}\n   y = {y:.2f}\n   f_max = {f(x,y):.4f}")

# функція для введення необхідних даних
def input_data(text): # приймає текст
    while True: # цикл, який триватиме до моменту правильного вводу користувачем
        try:    # спробуємо виконати наступний блок коду
            num = float(input(text)) # введення числа
            break                    # якщо все добре, завершуємо цикл
        except ValueError: # якщо виникла помилка при введенні
            print("   Помилка! Введіть число") # відповідне повідомлення про помилку

    return num # повертаємо введений коефіцієнт

# головна функція програми
def main():
    # введення точності обчислень е
    print("Введіть точність обчислень:")
    while True:  # цикл
        try:     # спробуємо виконати наступний блок коду
            eps = float(input("   e = "))

            if eps <= 0 or eps >= 1:  # якщо введено не правильно
                print("   Помилка! Значення e введено не правильно")

            else:  # якщо введено правильно
                break  # зупиняємо цикл

        except ValueError:  # якщо виникла помилка
            print("   Помилка! Введіть число")

    # введення початкового кроку
    print("\nВведіть початковий крок:")
    lam0 = input_data("   lambda = ")

    # введення початкового значення x0
    print("\nВведіть початкове значення x0:")
    x0 = input_data("   x0 = ")

    # введення початкового значення y0
    print("\nВведіть початкове значення y0:")
    y0 = input_data("   y0 = ")

    gradient_descent_method(eps, lam0, x0, y0)

main() # виклик головної функції програми
