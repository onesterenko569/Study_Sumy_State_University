import matplotlib.pyplot as plt # імпортуємо бібліотеку для роботи з графіком
import numpy as np # імпортуємо бібліотеку для роботи з масивом
import csv # імпортуємо бібліотеку для роботи з .csv файлами

filename = "Data_10.2.csv" # записуємо назву необхідного файлу

# створюємо пусті списки, які далі зберігатимуть зчитані дані
years = []
ukr_values = []
usa_values = []

try: # спробуємо виконати наступний блок коду
    with open(filename, "r", encoding="utf-8") as csvfile: # відкриваємо файл, після роботи закриваємо його
        reader = csv.reader(csvfile) # зчитуємо дані з відкритого файлу
        header = next(reader) # запам'ятовуємо заголовок

        years = [col.split()[0] for col in header[4:]] # зчитуємо роки
        years = [int(y) for y in years] # перетворюємо на цілий тип даних

        for row in reader: # цикл по рядкам
            country = row[0].strip() # зчитуємо назви країн

            # збираємо дані для України
            if country == "Ukraine": # якщо країна Україна
                for value in row[4:]: # зчитуємо дані з 5 стовпчика
                    if value.strip() in ("..", ""): # якщо елемент відсутній
                        ukr_values.append(np.nan) # додаємо нічого
                    else: # якщо елемент є
                        ukr_values.append(float(value)) # додаємо даний елемент

            # збираємо дані для США
            elif country == "United States": # якщо країна США
                for value in row[4:]: # зчитуємо дані з 5 стовпчика
                    if value.strip() in ("..", ""): # якщо елемент відсутній
                        usa_values.append(np.nan) # додаємо нічого
                    else: # якщо елемент є
                        usa_values.append(float(value)) # додаємо даний елемент

except Exception as e: # якщо виникла помилка
    print("Помилка при зчитуванні файлу:", e)
    exit() # вихід з програми

# перетворення списків у масиви
years = np.array(years)
UKR = np.array(ukr_values)
USA = np.array(usa_values)

plt.figure(figsize=(10, 5)) # визначаємо розмір фігури
# будуємо графік для України
plt.plot(years, UKR, label='Ukraine', linewidth=2, color="blue")
# будуємо графік для США
plt.plot(years, USA, label='United States', linewidth=2, color="red")

plt.title('Children out of school, primary (2005 - 2024)', fontsize=16) # назва графіка
plt.xlabel('Year', fontsize=12, color='green') # позначення вісі абсцис
plt.ylabel('Number of children', fontsize=12, color='green') # позначення вісі ординат
plt.xticks(years) # щоб на вісі абсцис було відображено всі роки

plt.legend() # додаємо легенду
plt.grid(True) # додаємо сітку
plt.show() # відображаємо графік на екрані

# вивід тексту
print("\nОберіть країну для якої буде побудовано стовпчасту діаграму")
print("1 - Україна")
print("2 - США\n")

choice = input("Введіть Ваш вибір: ") # користувач вводить свій вибір

# перевірка введеного користувачем вибору
while not choice.isdigit() or int(choice) not in range(1, 3):
    choice = input("Помилка при введенні, спробуйте знову: ")

choice = int(choice) # перетворюємо на int

if choice == 1: # якщо введено 1
    country = "Ukraine"
    values = UKR
    color = 'blue'

else: # якщо введено 2
    country = "United States"
    values = USA
    color = 'red'

plt.figure(figsize=(10, 5)) # налаштовуємо розмір фігури
plt.bar(years, values, color=color) # будуємо стовпчасту діаграму
plt.title(f'Children out of school, primary (2005 - 2024): {country}', fontsize=16) # назва графіка
plt.xlabel('Year', fontsize=12, color='green') # позначення вісі абсцис
plt.ylabel('Number of children', fontsize=12, color='green') # позначення вісі ординат
plt.xticks(years) # щоб на вісі абсцис було відображено всі роки

plt.grid(axis='y', linestyle='--',) # додаємо сітку
plt.show() # відображаємо графік на екрані
