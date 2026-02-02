import matplotlib.pyplot as plt # імпортуємо бібліотеку для роботи з графіком
import numpy as np # імпортуємо бібліотеку для роботи з масивом
import json # імпортуємо бібліотеку для роботи з .json файлами

# функція зчитування даних з .json файлу
def read_json_file(filename="data_1.json"): # приймає назву файла
    try:
        with open(filename, "r", encoding="utf-8") as f: # відкриваємо файл та зчитуємо інформацію
            data = json.load(f)
            return data # повертаємо зчитані дані
    except Exception as e: # якщо виникла помилка при спробі виконати блок коду try
        print("Помилка при зчитуванні файлу:", e)
        return None # нічого не повертаємо

data = read_json_file("data_1.json") # зчитуємо дані з файлу

if data: # якщо дані успішно зчитані
    # рахуємо кількість учнів для кожного дня
    days = {} # створюємо пустий словник
    for student in data: # проходимо по зчитаних даних з .json файлу
        day = student["Day"] # запам'ятовуємо день (значення словника по ключу Day)
        days[day] = days.get(day, 0) + 1 # додаємо до словника days ключ (день) та рахуємо к-сть учнів

    labels = list(days.keys()) # перетворюємо ключі словника на назви секторів
    values = list(days.values()) # перетворюємо значення словника на кількість учнів

    # створюємо фігуру (fig) і координатну вісь (ax)
    fig, ax = plt.subplots(figsize=(6, 4), subplot_kw=dict(aspect="equal"))

    # функція перетворення відсотків на текстовий формат де вказано і відсоток, і кількість учнів
    def func(pct, allvals):
        absolute = int(np.round(pct / 100. * np.sum(allvals)))
        return f"{pct:.1f}%\n({absolute} уч.)" # повертає перетворений текст

    # будуємо кругову діаграму
    wedges, texts, autotexts = ax.pie(
        values, # дані
        autopct=lambda pct: func(pct, values), # формат підписів
        textprops=dict(color="white"), # колір тексту на секторах
        startangle=90 # розвертаємо діаграму на 90 градусів
    )

    # додаємо легенду
    ax.legend(
        wedges, labels, # кольори, назви секторів
        title="День відвідування гуртка", # заголовок легенди
        loc="center left", # місце розташування легенди відносно діаграми
        bbox_to_anchor=(1, 0, 0.5, 1) # розміщує легенду праворуч
    )
    plt.subplots_adjust(right=0.6) # налаштовуємо розташування легенди

    plt.setp(autotexts, size=9, weight="bold") # налаштування підписів на діаграмі
    ax.set_title("Розподіл учнів за днем відвідування гуртка") # додаємо заголовок над діаграмою

    plt.show() # відображаємо графік на екрані

else: # якщо дані не зчитано
    print("Неможливо побудувати діаграму — файл не зчитано")
