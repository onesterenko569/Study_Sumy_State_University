import math # математична бібліотека

INF = math.inf # отримуємо значення нескінченності

# функція друку матриці D
def print_D(D, k):
    n = len(D)
    print(f"\nМатриця D{k}:")
    print("     ", end="")
    for j in range(n):
        print(f"{j+1:>5}", end="")
    print()
    for i in range(n):
        print(f"{i+1:>3} |", end="")
        for j in range(n):
            if D[i][j] == INF:
                print(f"{'∞':>5}", end="")
            else:
                print(f"{D[i][j]:>5}", end="")
        print()

# функція друку матриці S
def print_S(S, k):
    n = len(S)
    print(f"\nМатриця S{k}:")
    print("     ", end="")
    for j in range(n):
        print(f"{j+1:>5}", end="")
    print()
    for i in range(n):
        print(f"{i+1:>3} |", end="")
        for j in range(n):
            if S[i][j] is None:
                print(f"{'-':>5}", end="")
            else:
                print(f"{S[i][j] + 1:>5}", end="")
        print()

# функція реалізації алгоритму Флойда-Уоршелла
def floyd_warshall_algorithm(D):
    n = len(D)                           # отримуємо розмір графа (кількість вершин)
    S = [[None] * n for _ in range(n)]   # створюємо порожню матрицю S розмірності n на n

    # заповнюємо S0
    for i in range(n):     # зовнішній цикл
        for j in range(n): # внутрішній цикл
            if D[i][j] != INF and i != j: # перевірка чи є прямий хід
                S[i][j] = j               # щоб потрапити з i в j, необхідно одразу піти в j

    print_D(D, 0) # друкуємо початкову матрицю D0
    print_S(S, 0) # друкуємо початкову матрицю S0

    for k in range(n):         # цикл по дозволеному проміжному вузлі (через який йтимемо)
        for i in range(n):     # цикл по стартовій вершині (з якої починаємо)
            for j in range(n): # цикл по кінцевій вершині (в яку йдемо)
                if D[i][k] != INF and D[k][j] != INF and D[i][k] + D[k][j] < D[i][j]: # якщо через вершину k шлях коротший ніж старий шлях
                    D[i][j] = D[i][k] + D[k][j] # оновлюємо відстань
                    S[i][j] = S[i][k]           # оновлюємо маршрут

        print_D(D, k + 1) # друкуємо матрицю D
        print_S(S, k + 1) # друкуємо матрицю S

    return D, S # повертаємо фінальні матриці D та S

# функція, яка повертає список вершин маршруту від start до end
def get_way(S, start, end):
    if S[start][end] is None: # якщо шляху не існує
        return None           # повертаємо None

    way = [start]             # створюємо список маршруту
    while start != end:       # поки не дійшли до кінцевої вершини
        start = S[start][end] # зберігаємо наступну вершину, в яку ідемо
        way.append(start)     # додаємо в список наступну вершину, в яку ідемо

    return way                # повертаємо маршрут

# головна функція програми
def main():
    # задаємо початкову матрицю
    D = [
        [0, 15, 13, INF, INF, INF, INF],
        [15, 0, 3, 10, 18, INF, INF],
        [13, 3, 0, 18, INF, 1, INF],
        [INF, 10, 18, 0, INF, 18, 3],
        [INF, 18, INF, INF, 0, INF, 14],
        [INF, INF, 1, 18, INF, 0, 6],
        [INF, INF, INF, 3, 14, 6, 0],
    ]

    # знаходимо матриці найкоротшого шляху за алгоритмом Флойда-Уоршелла
    D, S = floyd_warshall_algorithm(D)

    # дістаємо найкоротшу відстань з 3 вершини у 5
    start, end = 2, 4              # зберігаємо вершини, маршрут між якими необхідно знайти (3 та 5)
    way = get_way(S, start, end)   # викликаємо функцію, яка повертає список вершин маршруту від start до end

    # виведення результатів
    if way is None: # якщо шляху немає
        print("Шлях не існує")
    else:           # якщо шлях є
        print("\nРезультат:")
        print("Найкоротша відстань з 3 у 5:", D[start][end])
        print("Оптимальний маршрут:", " --> ".join(str(v + 1) for v in way))

main() # виклик головної функції програми
