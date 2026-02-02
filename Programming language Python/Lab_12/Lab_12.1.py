import tkinter as tk                 # для створення програми з графічним інтерфейсом
from tkinter import messagebox       # для виведення вікна з помилкою
import json                          # для роботи з .json файлом (зчитування даних)
import random                        # для перемішування зчитаних з .json файлу запитань
import datetime                      # для роботи з датою та часом (щоб записати час проходження тесту)

# функція для зчитування даних з .json файлу
def read_json_file(filename="Road_traffic_issue.json"):
    try:                                                          # спробуємо виконати наступний блок коду
        with open(filename, 'r', encoding='utf-8') as json_file:  # відкриваємо файл та зчитуємо запитання, після роботи з файлом закриваємо його
            data = json.load(json_file)                           # зберігаємо зчитані питання в змінну data
            random.shuffle(data)                                  # "тосуємо" питання (елементи списку (словники))
            return data[:10]                                      # повертаємо 10 випадкових питань

    except Exception as e:                                       # якщо виникла помилка при спробі виконати блок коду try
        print("\nВиникла помилка: ", e)                          # виведення відповідного повідомлення в консоль
        return []                                                # повертаємо пустий список, бо сталася помилка

# функція для збереження результатів у текстовий файл
def save_result_to_file(program_status):
    questions = program_status['questions']  # дістаємо список питань зі стану програми
    score = calculate_score(program_status)  # рахуємо кількість балів за допомогою функції підрахунку
    total = len(questions)                   # дізнаємося загальну кількість питань
    username = program_status['username']    # дістаємо ім'я користувача, яке він ввів

    try:                                                                                           # спробуємо відкрити файл для запису
        with open("results.txt", "a", encoding="utf-8") as f:                                      # відкриваємо файл "results.txt" у режимі додавання
            timestamp = datetime.datetime.now().strftime("%Y-%m-%d %H:%M:%S")                      # отримуємо поточну дату і час у зручному форматі
            f.write(f"Дата: {timestamp} | Користувач: {username} | Результат: {score}/{total}\n")  # записуємо рядок з результатом у файл
        return True                                                                                # повертаємо True, якщо запис пройшов успішно
    except Exception as e:                                                                         # якщо виникла помилка при записі
        messagebox.showerror("Помилка збереження", str(e))                                    # показуємо вікно з помилкою
        return False                                                                               # повертаємо False, бо запис не вдався

# функція для підрахунку кількості правильних відповідей
def calculate_score(program_status):
    score = 0                                     # створюємо змінну для підрахунку балів, спочатку вона дорівнює 0
    questions = program_status['questions']       # беремо список всіх питань
    user_answers = program_status['user_answers'] # беремо словник відповідей користувача

    for idx, question in enumerate(questions):    # проходимося по кожному питанню (отримуємо його номер idx і саме питання question)
        user_choice = user_answers.get(idx)       # дістаємо відповідь користувача на це питання (за номером idx)
        if user_choice is not None and user_choice == question['correct_index']: # перевіряємо чи є відповідь і чи вона збігається з правильною
            score += 1                            # якщо відповідь правильна, додаємо 1 бал
    return score                                  # повертаємо загальну кількість балів

# функція для очищення вікна від старих елементів
def clear_window(root):
    for widget in root.winfo_children():  # перебираємо всі елементи (кнопки, написи), які є у вікні
        widget.destroy()                  # видаляємо кожен елемент по черзі

# функція для створення початкового екрану
def create_start_screen(program_status):
    root = program_status['root']  # отримуємо доступ до головного вікна програми
    clear_window(root)             # видаляємо всі кнопки та написи, що були на екрані раніше

    tk.Label(root, text="Тест з Правил дорожнього руху", font=("Arial", 20, "bold"), bg="white").pack(pady=20)                  # додавання першої мітки
    tk.Label(root, text="Вам буде запропоновано 10 випадкових питань", font=("Arial", 10), fg="gray", bg="white").pack(pady=10) # додавання другої мітки
    tk.Label(root, text="Введіть ваше ім'я:", font=("Arial", 12), bg="white").pack()                                            # додавання третьої мітки

    ent_name = tk.Entry(root, font=("Arial", 12), bd=2, relief="solid") # створюємо поле для введення тексту (імені користувача)
    ent_name.pack(pady=10)                                              # розміщуємо поле на екрані з відступами в 10 пікселів зверху та знизу

    # створюємо кнопку для початку тесту
    tk.Button(root, text="Розпочати тест", font=("Arial", 14),                     # налаштовуємо текст та шрифт кнопки
              bg="#4CAF50", fg="white", width=20, height=2,                        # налаштовуємо колір та розмір кнопки
              command=lambda: start_test(program_status, ent_name)).pack(pady=30)  # при натисканні на кнопку запускаємо функцію start_test

# функція підготовки програми до старту (перевірка імені)
def start_test(program_status, ent_name):
    name = ent_name.get()                                                           # отримуємо введений користувачем текст з поля
    if not name.strip():                                                            # перевіряємо, чи ім'я не пусте (strip видаляє зайві пробіли)
        messagebox.showwarning("Увага", "Будь ласка, введіть ім'я!")   # показує спливаюче вікно з повідомленням про помилку
        return                                                                      # зупиняє функцію, не дає пройти далі

    # оновлюємо стан програми перед початком
    program_status['username'] = name    # зберігаємо ім'я користувача у словник
    program_status['current_index'] = 0  # ініціалізуємо лічильник питань (починаємо з першого питання - 0)
    program_status['user_answers'] = {}  # очищуємо словник відповідей, щоб він був пустим

    create_question_screen(program_status) # запускаємо функцію, яка покаже екран з питанням

# функція для відображення екрану з поточним питанням
def create_question_screen(program_status):
    root = program_status['root']              # отримуємо доступ до вікна програми
    questions = program_status['questions']    # отримуємо доступ до збережених 10 запитань
    idx = program_status['current_index']      # отримуємо доступ до номера поточного запитання

    clear_window(root)                         # очищуємо вікно від попереднього вмісту (старого питання)

    question_data = questions[idx]             # отримуємо дані конкретного питання зі списку за індексом

    tk.Label(root, text=f"Питання {idx + 1} з {len(questions)}", fg="gray", bg="white").pack(pady=5)                        # додаємо мітку яка відображає номер поточного питання
    tk.Label(root, text=f"Тема: {question_data['category']}", font=("Arial", 10, "italic"), bg="white").pack(pady=(0, 10))  # додаємо мітку з темою питання

    tk.Label(                             # створюємо синій блок з текстом питання
        root,                             # в якому вікні створюємо
        text=question_data['question'],   # беремо текст питання зі словника
        font=("Arial", 14, "bold"),       # робимо шрифт жирним
        wraplength=600,                   # якщо текст довший за 600 пікселів, переносимо його на новий рядок
        justify="center",                 # вирівнюємо текст по центру
        bg="#1565C0",                     # задаємо синій колір фону
        fg="white"                        # задаємо білий колір тексту
    ).pack(                               # додамо створений блок на екран
        fill="x",                         # розтягуємо блок на всю ширину вікна
        padx=30,                          # робимо відступ з боків
        ipady=20,                         # робимо внутрішній відступ (щоб текст не прилипав до країв)
        pady=10)                          # робимо відступ зверху та знизу

    image_filename = question_data['image']  # дістаємо назву файлу картинки

    if image_filename:                       # перевіряємо чи існує запис про картинку для цього питання
        try: # пробуємо виконати блок коду для завантаження картинки
            tk_image = tk.PhotoImage(file=image_filename)              # завантажуємо зображення з файлу
            img_label = tk.Label(root, image=tk_image, bg="white")     # створюємо мітку куди помістимо це зображення
            img_label.image = tk_image                                 # щоб не видаляло картинку
            img_label.pack(pady=5)                                     # розміщуємо картинку на екрані з відступом
        except Exception as e:                                         # якщо виникла помилка
            # виводимо червоний текст з помилкою прямо у вікні
            tk.Label(root, text=f"Помилка при завантаженні фото ({e})!", font=("Arial", 14, "bold"), fg="red", bg="white").pack(pady=30)

    options_frame = tk.Frame(root, bg="white")  # створюємо контейнер для кнопок відповідей
    options_frame.pack(fill="both", pady=10)    # розміщуємо цей контейнер у вікні

    options = question_data['options']          # дістаємо список варіантів відповідей для цього питання

    # цикл для створення кнопок відповідей
    for i, option_text in enumerate(options):   # проходимося по кожному варіанту (i - порядковий номер відповіді, option_text - текст відповіді)
        # створюємо кнопку відповіді
        btn = tk.Button(options_frame, text=option_text, font=("Arial", 11), wraplength=500, bg="#4CAF50")

        # налаштовуємо дію кнопки: при натисканні викликаємо handle_answer_click і передаємо номер обраної відповіді
        btn.configure(command=lambda opt_idx=i: handle_answer_click(program_status, opt_idx))
        btn.pack(fill="x", padx=50, pady=5) # показуємо кнопку на екрані, розтягуючи її по ширині


# функція, що обробляє клік по відповіді
def handle_answer_click(program_status, selected_index):
    current_idx = program_status['current_index']                # дізнаємося номер поточного питання

    # зберігаємо відповідь користувача у словник
    program_status['user_answers'][current_idx] = selected_index # записуємо обраний варіант (selected_index) під номером питання

    # логіка переходу далі
    if current_idx < len(program_status['questions']) - 1:  # перевіряємо, чи це не останнє питання
        program_status['current_index'] += 1                # збільшуємо номер поточного питання на 1 (переходимо до наступного питання)
        create_question_screen(program_status)              # створюємо екран з наступним питанням
    else:                                                   # якщо це було останнє питання
        show_final_results(program_status)                  # завершуємо тест і показуємо результат

# функція відображення екрану з результатами
def show_final_results(program_status):
    root = program_status['root']                    # отримуємо доступ до вікна
    clear_window(root)                               # очищуємо вікно від питань

    score = calculate_score(program_status)          # рахуємо фінальний бал
    total = len(program_status['questions'])         # дізнаємося загальну кількість питань
    questions = program_status['questions']          # отримуємо список питань для аналізу помилок
    user_answers = program_status['user_answers']    # отримуємо відповіді користувача

    # показуємо заголовок з результатом
    tk.Label(root, text=f"Ваш результат: {score} з {total}", font=("Arial", 16, "bold"), bg="white").pack(pady=10)

    # створюємо текстове поле для виведення списку помилок
    report_box = tk.Text(root, height=30, width=100, font=("Arial", 10)) # створюємо текстове поле для виведення списку помилок
    report_box.pack(pady=10, padx=10)                                    # розміщуємо його на екрані

    report_box.images = []                                         # створюємо список для збереження картинок щоб вони не видалялися
    report_box.insert(tk.END, "--- СПИСОК ПОМИЛОК ---\n\n")  # пишемо заголовок всередину текстового поля

    has_errors = False  # створюємо прапорець, щоб знати чи були помилки

    # проходимося по всіх питаннях циклом, щоб знайти помилки
    for i, question in enumerate(questions):       # i - номер питання, question - текст питання
        user_idx = user_answers.get(i)             # дістаємо номер відповіді, яку обрав користувач
        correct_idx = question['correct_index']    # дістаємо номер правильної відповіді

        if user_idx != correct_idx:                           # якщо відповідь користувача не збігається з правильною
            has_errors = True                                 # ставимо прапорець, що помилка знайдена

            if user_idx is not None:                          # перевіряємо, чи користувач обрав якусь відповідь
                user_text = question['options'][user_idx]     # якщо відповідь є то беремо текст цієї відповіді
            else:                                             # якщо користувач пропустив питання
                user_text = "Немає відповіді"                 # зберігаємо що відповіді немає

            correct_text = question['options'][correct_idx]   # дістаємо текст правильної відповіді

            # формуємо текст помилки
            report_box.insert(tk.END, f"Питання {i + 1}: {question['question']}\n")

            # додаємо фото
            image_filename = question['image']  # дістаємо назву файлу із зображенням
            if image_filename:                  # перевіряємо чи є картинка у цьому питанні
                try:                            # спробуємо виконати наступний блок коду
                    photo = tk.PhotoImage(file=image_filename)              # завантажуємо зображення
                    report_box.insert(tk.END, "   Зображення:\n   ")  # додаємо підпис перед картинкою
                    report_box.image_create(tk.END, image=photo)            # вставляємо картинку в текстове поле
                    report_box.insert(tk.END, "\n")                   # додаємо перенос рядка після картинки
                    report_box.images.append(photo)                         # щоб не видаляло картинку

                except Exception as e:                                                # якщо виникла помилка при завантаженні картинки
                    report_box.insert(tk.END, f"   [Фото не знайдено: {e}]\n")  # виводимо повідомлення про помилку

            report_box.insert(tk.END, f"   Ваша відповідь: {user_text}\n")  # пишемо, що обрав користувач
            report_box.insert(tk.END, f"   Правильно: {correct_text}\n")    # пишемо, як було правильно

            report_box.insert(tk.END, "-" * 60 + "\n") # додаємо лінію розділювача після фото

    if not has_errors: # якщо після циклу прапорець залишився False (помилок не було)
        report_box.insert(tk.END, "Вітаємо! У вас немає жодної помилки") # пишемо вітання

    # забороняємо редагування поля, щоб користувач не міг стирати текст
    report_box.configure(state="disabled")                                  # змінюємо стан на тільки читання

    # додаємо кнопку для збереження результату і виходу
    tk.Button(root, text="Зберегти та вийти", font=("Arial", 12),           # текст кнопки
              bg="#2196F3", fg="white",                                     # синя заливка, білий текст
              command=lambda: save_and_exit(program_status)).pack(pady=10)  # при натисканні виконуємо save_and_exit

# функція збереження і закриття програми
def save_and_exit(program_status):
    if save_result_to_file(program_status):                                                   # викликаємо функцію збереження і перевіряємо чи все ок
        messagebox.showinfo("Успіх", "Результат збережено у файл results.txt")   # показуємо вікно успіху
        program_status['root'].destroy()                                                      # закриваємо вікно програми повністю


# головна функція програми
def main():
    root = tk.Tk()                 # створюємо головне вікно програми
    root.title("Тестування ПДР")   # встановлюємо заголовок вікна (напис зверху)
    root.geometry("700x650")       # встановлюємо розмір вікна застосунку (ширина x висота)
    root.configure(bg="white")     # змінюємо налаштування вікна (робимо колір фону білим)

    filename = "Road_traffic_issue.json"  # записуємо назву файлу, звідки зчитуватимуться питання

    questions = read_json_file(filename)  # викликаємо функцію зчитування питань і зберігаємо їх у змінну

    if not questions: # якщо список питань пустий (файл не знайдено або помилка)
        messagebox.showerror("Помилка", "Не вдалося знайти файл з питаннями або він порожній!")  # показуємо помилку
        root.destroy()  # знищуємо вікно (закриваємо програму)
        return          # виходимо з функції main

    # створюємо головний словник, який зберігатиме всі змінні програми в одному місці
    program_status = \
        {
            "root": root,            # саме вікно програми
            "questions": questions,  # список усіх зчитаних питань
            "current_index": 0,      # номер поточного питання (починаємо з 0)
            "user_answers": {},      # словник для збереження відповідей користувача {індекс_питання: індекс_відповіді}
            "username": ""           # тут буде зберігатися ім'я користувача
        }

    create_start_screen(program_status) # запускаємо функцію що створює початковий екран

    root.mainloop()                     # запускаємо саму програму

main() # запускаємо головну функцію
