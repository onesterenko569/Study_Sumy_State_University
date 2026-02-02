import json # для роботи з .json файлами

# функція для зчитування та перетворення інформації з .json файлу
def read_json_file(filename = "data_1.json"): # приймає файл
    try:
        with open(filename, "r", encoding="utf-8") as json_file: # відкриваємо файл та зчитуємо інформацію
            data = json.load(json_file)
            return data # повертаємо зчитані дані

    except Exception as e: # якщо виникла помилка при спробі виконати блок коду try
        print("\nВиникла помилка: ", e)
        return None # нічого не повертаємо

# функція для запису інформації в .json файл
def write_json_file(data, filename = "data_1.json"): # приймає файл та інформацію що потрібно записати
    try:
        with open(filename, "w", encoding="utf-8") as json_file: # відкриваємо файл та записуємо інформацію
            json.dump(data, json_file, ensure_ascii=False, indent=4)
            return True # повертаємо позначку, якщо інформацію успішно записано

    except Exception as e: # якщо виникла помилка при спробі виконати блок коду try
        print("\nВиникла помилка: ", e)
        return False # повертаємо позначку, що інформацію не записано

# функція для додавання запису в .json файл
def add_student(filename = "data_1.json"): # приймає файл
    data = read_json_file(filename) # викликаємо функцію для зчитування
    if data is None: # перевіряємо чи успішно зчитано
        return

    # введення нового запису
    print("\nВведіть дані нового учня")
    surname = str(input("Прізвище: "))
    name = str(input("Ім'я: "))
    patronymic = str(input("По батькові: "))
    adres = str(input("Адреса: "))
    school = int(input("Номер школи: "))
    clas = int(input("Клас: "))
    day = str(input("День відвідування гуртка: "))

    # у кінець списку додаємо новий запис
    data.append({"Name": name, "Surname": surname, "Patronymic": patronymic,
         "Adress": adres, "School": school, "Day": day, "Class": clas})

    # перезаписуємо .json файл та перевіряємо чи успішно записано
    if not write_json_file(data, filename):
        return
    else:
        print("\nДані про нового студента успішно записано!")

# функція видалення запису із .json файлу
def delete_student(filename = "data_1.json"): # приймає файл
    data = read_json_file(filename) # викликаємо функцію для зчитування
    if data is None: # перевіряємо чи успішно зчитано
        return

    # вводимо ПІБ шуканого учня
    print("\nВведіть ПІБ учня, якого бажаєте видалити із json. файла:")
    surname = str(input("Прізвище: "))
    name = str(input("Ім'я: "))
    patronymic = str(input("По батькові: "))

    found = False # створюємо флажок

    for student in data: # цикл по елементам списку (по словникам)
        # якщо шуканого учня знайдено, видаляємо
        if (student["Surname"].lower() == surname.lower() and
            student["Name"].lower() == name.lower() and
            student["Patronymic"].lower() == patronymic.lower()):

            data.remove(student)
            found = True # позначаємо що видалено
            break

    if not found: # якщо не видалено
        print("\nСтудента не знайдено, спробуйте ще раз!")
        return

    # перезаписуємо .json файл та перевіряємо чи успішно записано
    if not write_json_file(data, filename):
        return
    else:
        print("\nСтудента успішно видалено!")

# функція виведення вмісту .json файлу
def output_students(filename = "data_1.json"): # приймає файл
    data = read_json_file(filename) # викликаємо функцію для зчитування
    if data is None: # перевіряємо чи успішно зчитано
        return

    # виведення на екран вмісту .json файлу
    print("\nВиведення на екран вмісту JSON файлу:")
    for student in data:
        print("")
        print(student["Surname"], student["Name"], student["Patronymic"])
        print("Адреса:", student["Adress"], "\nНомер школи:", student["School"])
        print("Клас:", student["Class"], "\nДень відвідування гуртка:", student["Day"])

# функція пошуку учня за ПІБ
def search_student(filename = "data_1.json"): # приймає файл
    data = read_json_file(filename) # викликаємо функцію для зчитування
    if data is None: # перевіряємо чи успішно зчитано
        return

    # вводимо ПІБ шуканого учня
    print("\nВведіть ПІБ шуканого студента:")
    surname = str(input("Прізвище: "))
    name = str(input("Ім'я: "))
    patronymic = str(input("По батькові: "))

    found = False # створюємо флажок

    # цикл по елементам списку (по словникам)
    for student in data:
        # якщо шуканого учня знайдено
        if (student["Surname"].lower() == surname.lower() and
                student["Name"].lower() == name.lower() and
                student["Patronymic"].lower() == patronymic.lower()):

            # виведення на екран інформації про знайденого учня
            print("\nСтудента успішно знайдено!")
            print(student["Surname"], student["Name"], student["Patronymic"])
            print("Адреса:", student["Adress"], "\nНомер школи:", student["School"])
            print("Клас:", student["Class"], "\nДень відвідування гуртка:", student["Day"])
            found = True # позначаємо що знайдено
            break # завершуємо цикл

    if not found: # якщо шуканого учня не знайдено
        print("\nУчня не знайдено, спробуйте ще раз!")
        return

# функція пошуку за завданням
def search_by_day(filename = "data_1.json"): # приймає файл
    data = read_json_file(filename) # викликаємо функцію для зчитування
    if data is None: # перевіряємо чи успішно зчитано
        return

    result = [] # створюємо пустий список

    # цикл по елементам списку (по словникам)
    for student in data:
        # якщо потрібного учня знайдено
        if (student["Day"].lower() == "Субота".lower() and
            student["Class"] in range(7, 9)):

            # додаємо запис до списку
            result.append({"Surname": student["Surname"], "Name": student["Name"],
                "Patronymic": student["Patronymic"], "Adress": student["Adress"]})

    if not result: # якщо учня(ів) не знайдено
        print("\nТаких студентів немає!")

    else: # якщо учня(ів) знайдено
        # виводимо інформацію
        print("\nСтудент(и) що навчаються у молодших (7-8) класах та відвідує(ють) гурток по суботах:")
        for student in result:
            print("")
            print(student["Surname"], student["Name"], student["Patronymic"])
            print("Адреса:", student["Adress"])

        # записуємо шукану інформацію до нового файлу
        if not write_json_file(result, "data_result.json"):
            print("\nПомилка при записі результату у файл!")
        else:
            print("\nРезультат записано у файл data_result.json!")

# головна функція програми
def main():
    # створення словника із 10 записів
    students = [
        {"Name": "Олександр", "Surname": "Нестеренко", "Patronymic": "Олександрович",
         "Adress": "вул. Шевченка, 10", "School": 3, "Day": "Субота", "Class": 6},

        {"Name": "Вадим", "Surname": "Остапенко", "Patronymic": "Миколайович",
         "Adress": "вул. Миру, 8", "School": 5, "Day": "Субота", "Class": 7},

        {"Name": "Іван", "Surname": "Орехов", "Patronymic": "Васильович",
         "Adress": "вул. Центральна, 13", "School": 4, "Day": "Неділя", "Class": 11},

        {"Name": "Богдан", "Surname": "Ганжара", "Patronymic": "Сергійович",
         "Adress": "вул. Грушевського, 58", "School": 5, "Day": "Субота", "Class": 9},

        {"Name": "Юлія", "Surname": "Пушкар", "Patronymic": "Сергіївна",
         "Adress": "вул. Перемоги, 31", "School": 3, "Day": "Субота", "Class": 8},

        {"Name": "Назар", "Surname": "Тахтай", "Patronymic": "Володимирович",
         "Adress": "вул. Квіткова, 4", "School": 4, "Day": "Неділя", "Class": 8},

        {"Name": "Ольга", "Surname": "Писала", "Patronymic": "Володимирівна",
         "Adress": "вул. Лесі Українки, 19", "School": 4, "Day": "Субота", "Class": 7},

        {"Name": "Дар'я", "Surname": "Снаговська", "Patronymic": "Сергіївна",
         "Adress": "вул. Степана Бандери, 21", "School": 3, "Day": "Субота", "Class": 9},

        {"Name": "Яків", "Surname": "Левадний", "Patronymic": "Валентинович",
         "Adress": "вул. Шевченка, 44", "School": 5, "Day": "Неділя", "Class": 10},

        {"Name": "Володимир", "Surname": "Горбась", "Patronymic": "Володимирович",
         "Adress": "вул. Грушевського, 13", "School": 4, "Day": "Субота", "Class": 7},
        ]

    # створюємо та записуємо інформацію до файлу
    if not write_json_file(students, "data_1.json"):
        pass
    else:
        print("\nJson файл успішно створено та записано початкові дані!")

    print("\nІнструкція по використанню програми:")

    # цикл, який виконуватиметься доти, доки користувач не вибере завершення програми
    while True:
        # інструкція по програмі
        print("\n0 - вихід з програми")
        print("1 - додавання нового запису у JSON файл")
        print("2 - видалення запису у JSON файлі")
        print("3 - виведення на екран вмісту JSON файлу")
        print("4 - пошук даних у JSON файлі за ПІБ учня")
        print("5 - визначити ПІБ та адресу учнів, що навчаються у молодших (7-8) класах та відвідують гурток по суботах\n")

        choice = input("Введіть Ваш вибір: ") # користувач вводить свій вибір

        # перевірка введеного користувачем вибору
        while not choice.isdigit() or int(choice) not in range(0, 6):
            choice = input("Помилка при введенні, спробуйте знову: ")

        choice = int(choice)  # перетворюємо на int

        if choice == 0:  # якщо ввів 0
            print("\nПрограму завершено")
            break

        elif choice == 1:  # якщо ввів 1
            add_student("data_1.json")

        elif choice == 2:  # якщо ввів 2
            delete_student("data_1.json")

        elif choice == 3:  # якщо ввів 3
            output_students("data_1.json")

        elif choice == 4:  # якщо ввів 4
            search_student("data_1.json")

        elif choice == 5:  # якщо ввів 5
            search_by_day("data_1.json")

main() # викликаємо головну функцію програми
