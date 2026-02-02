# функія для відкриття файлу
def open_file(file_name, mode):
    try: # спробуємо відкрити файл
        file = open(file_name, mode)
    except: # якщо виникла помилка при відкритті
        print("Помилка: файл", file_name, "не відкрито!")
        return None
    else: # якщо файл відкрито
        print("Файл", file_name, "успішно відкрито!")
        return file

# записуємо назви файлів
file1_name = "TF9_1.txt"
file2_name = "TF9_2.txt"

file_1_w = open_file(file1_name, "w") # відкриваємо 1 файл для запису

if (file_1_w != None): # якщо файл відкрито
    # введення кількості рядків
    n = int(input("\nВведіть скільки рядків ви хочете додати до файла TF9_1.txt: "))
    while (n <= 0): # якщо введено не правильно
        n = int(input("Помилка при введенні кількості рядків, спробуйте знову: "))

    for i in range(n): # цикл по рядкам
        line = input("Введіть " + str(i + 1) + " рядок: ") # вводимо рядок
        file_1_w.write(line + "\n") # записуємо до файлу введений рядок

    print("\nВведені рядки було додано до файлу TF9_1.txt!")
    file_1_w.close() # закриваємо 1 файл
    print("Файл TF9_1.txt закрито!")

file_1_r = open_file(file1_name, "r") # відкриття першого файлу для читання
file_2_w = open_file(file2_name, "w") # відкриття 2 файлу для запису

if (file_1_r != None and file_2_w != None): # перевірка чи файли відкрито
    for line in file_1_r: # проходимося по рядкам 1-го файлу
        line = line.rstrip("\n") # видалення \n в кінці рядка

        if len(line) < 20: # якщо к-сть символів у рядку < 20
            line = line.ljust(20, " ") # додаємо пробіли
        else: # якщо к-сть символів у рядку > 20
            line = line[:20] # зрізаємо рядок

        file_2_w.write(line + "\n") # записуємо до 2 файлу оброблені рядки

    print("Рядки із файлу TF9_1.txt були успішно оброблені та записані у файл TF9_2.txt!")
    # закриття файлів
    file_1_r.close()
    file_2_w.close()
    print("Файли було закрито!")

file_2_r = open_file(file2_name, "r") # відкриваємо 2 файл для читання

if (file_2_r != None): # якщо файл відкрито
    print("\nВміст файла TF9_2.txt:")

    for line in file_2_r: # друкуємо вміст файлу
        print(line, end="")

    file_2_r.close() # закриваємо файл
    print("\nФайл TF9_2.txt було закрито!")
