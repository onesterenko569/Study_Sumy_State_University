# Функція Тахтай Н.В
# Виведення словника
def Print(students):
    print("\nДані про успішність студентів:")
    for pib, data in students.items():
        print(f"{pib} ({data['група']}, {data['курс']} курс) — {data['оцінки']}")


# Функція Левадного Якова
# Функція додавання нового студента до словника
def add(students, pib, group, course, grades):
    students[pib] = {
        "група": group,
        "курс": course,
        "оцінки": grades
    }
    print(f"Додано дані про студента: {pib}")

# Функція Орехова Івана
# Функція видалення студента зі словника (видалення значення зі словника за його ключем)
def delete(students):
    pib=str(input("Введіть прізвище, ім'я, по батькові студента, інформацію про якого бажаєте видалити: "))
    if pib in students:
        del students[pib]
        print(f"Студента {pib} успішно видалено!")
    else:
        print(f"Дані про {pib} відсутні")

# Функція Орехова Івана
# Функція визначення студента(-ів), що має(-ють) найбільшу суму оцінок
def max_sum(students):
    max_sum = 0
    max_students = []
    for pib, data in students.items():
        total = sum(data['оцінки'].values())

        if max_sum is None or total > max_sum:
            max_sum = total
            max_students = [pib]
        elif total == max_sum:
            max_students.append(pib)
    print(f"\nСтудент(и) з найбільшою кількістю оцінок ({max_sum}):")
    for s in max_students:
        print(f" - {s}")

# Функція Нестеренка О.О.
# Функція визначення студента(-ів), що має(-ють) найменшу суму оцінок
def min_sum(students):
    min_sum = None
    min_student = []

    for pib, data in students.items():
        total = sum(data['оцінки'].values())

        if min_sum is None or total < min_sum:
            min_sum = total
            min_student = [pib]

        elif total == min_sum:
            min_student.append(pib)

    print(f"\nСтудент(и) з найменшою сумою оцінок ({min_sum}):")
    for s in min_student:
        print(f" - {s}")

# Функція Нестеренка О.О.
# Функція сортування словника по прізвищу за алфавітним порядком
def sort_students(students):
    sorted_items = sorted(students.items(), key=lambda item: item[0].split()[0])
    students.clear()
    students.update(sorted_items)
    print("\nСловник відсортовано по прізвищу за алфавітним порядком")

def main():
# Словник Левадного Я.В
    students = {
        "Левадний Яків Валентинович": {
            "група": "КН-42/1",
            "курс": 2,
            "оцінки": {"Вища Математика": 90, "Програмування": 95, "Пайтон": 88}
        },
        "Нестеренко Олександр Олександрович": {
            "група": "КН-42/1",
            "курс": 2,
            "оцінки": {"Вища Математика": 85, "Програмування": 80, "Пайтон": 92}
        },
        "Тахтай Назарій Володимирович": {
            "група": "КН-42/1",
            "курс": 2,
            "оцінки": {"Вища Математика": 78, "Програмування": 82, "Пайтон": 85}
        },
        "Орехов Іван Васильович": {
            "група": "КН-42/1",
            "курс": 2,
            "оцінки": {"Вища Математика": 88, "Програмування": 91, "Пайтон": 86}
        }
    }

    while True:
        print("\n0 - Вихід")
        print("1 - Вивести всіх студентів")
        print("2 - Ввести нового студента")
        print("3 - Видалити студента")
        print("4 - Сортувати оригінальний словник по прізвищу за алфавітним порядком")
        print("5 - Знайти та вивести ПІБ студента(-ів), що має(-ють) найбільшу суму оцінок")
        print("6 - Знайти та вивести ПІБ студента(-ів), що має(-ють) найменшу суму оцінок")

        choice = input("Ведіть число: ")

        if choice == "1":
            Print(students)

        elif choice == "2":
            pib = input("ПІБ: ")
            group = input("Група: ")
            course = int(input("Курс: "))
            grades = {}
            grades["Вища Математика"] = int(input("Оцінка з Вищої Математики: "))
            grades["Програмування"] = int(input("Оцінка з Програмування: "))
            grades["Пайтон"] = int(input("Оцінка з Пайтону: "))

            add(students, pib, group, course, grades)

        elif choice == "3":
            delete(students)

        elif choice == "4":
            sort_students(students)

        elif choice == "5":
            max_sum(students)

        elif choice == "6":
            min_sum(students)

        elif choice == "0":
            print("Програму завершено.")
            break
main()