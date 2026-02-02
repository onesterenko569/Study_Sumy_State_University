import pandas as pd # підключення модуля pandas
import matplotlib.pyplot as plt # підключення модуля для побудови графіка

# зчитуємо інформацію з .csv файлу та перетворюємо її в DataFrame
try: # спробуємо виконати наступний блок коду
    df = pd.read_csv("comptagevelo2017.csv") # зчитуємо та заносимо інформацію у DataFrame

except Exception as e: # якщо виникла помилка при спробі виконати блок коду try
    print("Виникла помилка: ", e) # виведення повідомлення про помилку

df[df.select_dtypes(include='number').columns] = df[df.select_dtypes(include='number').columns].fillna(0).astype(int) # замінює NaN на 0 та float на int

pd.set_option("display.max_columns", None) # для того щоб показувало всі колонки DataFrame при виведенні
pd.set_option("display.width", None) # щоб розтягнути таблицю по всій ширині терміналу
pd.set_option('display.float_format', '{:.0f}'.format) # щоб число типу float у DataFrame буде відображалося без десяткової частини

# перевіримо основні характеристики датафрейму
# виведемо перші 5 рядків сформованого DataFrame
print("Перші 5 рядків:")
print(df.head()) # друкуємо перші 5 рядків

# виведення інформації про DataFrame
print("\nІнформація про DataFrame:")
print(df.info()) # виведення інформації про DataFrame

# отримаємо описову статистику
print("\nСтатистичний опис:")
print(df.describe()) # виведення описової статистики

# визначимо загальну кількість велосипедистів за рік на усіх велодоріжках
number_columns = df.select_dtypes(include='number').columns # зберігаємо список назв велодоріжок
number_cyclists_year = df[number_columns].sum().sum() # обчислюємо загальну кількість велосипедистів, спочатку сума по стовпцях, потім сума стовпців
print("\nЗагальна кількість велосипедистів за рік:", int(number_cyclists_year))

# визначимо загальну кількість велосипедистів за рік на кожній велодоріжці
number_cyclists_separately = df[number_columns].sum() # обчислюємо суму значень для кожного стовпця окремо
print("\nКількість велосипедистів за рік на кожній велодоріжці:")
print(number_cyclists_separately.astype(int)) # перетворення числових значень на int та друк

# визначимо, який місяць найбільш популярний у велосипедистів, на трьох велодоріжках введених користувачем
df["Date"] = pd.to_datetime(df["Date"], dayfirst=True) # перетворюємо рядки на дати у форматі день/місяць/рік
df["Month"] = df["Date"].dt.month_name() # створюємо стовпець Month, який міститиме англійські назви місяців

# виводимо доступні велодоріжки
print("\nДоступні велодоріжки:")
for column in number_columns:
    print(column)

selected_bike_paths = [] # оголошуємо список, який міститиме вибрані користувачем велодоріжки

# цикл для введення користувачем трьох шуканих велодоріжок
for i in range(3):
    while True: # цикл триватиме, поки користувач не введе правильну назву велодоріжки
        bike_path = input(f"\nВведіть назву {i+1} велодоріжки: ").strip()

        if bike_path in number_columns: # якщо введена велодоріжка є в списку всіх велодоріжок
            selected_bike_paths.append(bike_path) # додаємо до списку шуканих велодоріжок
            print(f"Велодоріжку з назвою '{bike_path}' додано") # повідомляємо користувача про успішне введення
            break # завершуємо цикл
        else: # якщо користувач не правильно ввів назву велодоріжки
            print("Такої велодоріжки не існує! Спробуйте ще раз")

print("\nОбрані велодоріжки:")
for bike_path in selected_bike_paths: # виведення введених користувачем велодоріжок
    print(bike_path)
print() # відступ

# визначимо найпопулярніший місяць для кожної обраної велодоріжки
for bike_path in selected_bike_paths: # цикл по введених велодоріжках
    month_sum = df.groupby("Month")[bike_path].sum() # обчислюємо загальну кількість велосипедистів за кожен місяць
    popular_month = month_sum.idxmax() # знаходимо індекс (номер місяця), що відповідає максимальному значенню
    print(f"Найпопулярніший місяць для '{bike_path}': {popular_month}")

# побудова графіка завантаженості для однієї введеної користувачем велодоріжки по місяцях
while True: # цикл триватиме поки користувач не введе правильну назву велодоріжки
    bike_path = input("\nВведіть назву велодоріжки для побудови графіка: ").strip() # введення назви велодоріжки

    if bike_path in number_columns: # якщо велодоріжка введена правильно
        break # завершуємо цикл
    else: # якщо велодоріжка введена неправильно
        print("Такої велодоріжки не існує! Спробуйте ще раз")

month_data = df.groupby("Month")[bike_path].sum() # обчислюємо загальну кількість велосипедистів для введеної доріжки за кожен місяць

# список (зразок) за яким будемо сортувати
months_order = \
    [
    'January', 'February', 'March', 'April', 'May', 'June',
    'July', 'August', 'September', 'October', 'November', 'December'
    ]

month_data = month_data.reindex(months_order) # пересортовуємо по індексу дані згідно зі списком

# будуємо графік
plt.figure(figsize=(12, 5)) # задаємо розмір графіка
plt.plot(month_data.index, month_data.values, marker="o") # створюємо сам графік по х місяці по у к-сть велосипедистів
plt.title(f"Завантаженість велодоріжки '{bike_path}' по місяцях (2017)") # встановлюємо заголовок графіка
plt.xlabel("Місяць") # підписуємо вісь х
plt.ylabel("Кількість велосипедистів") # підписуємо вісь у
plt.grid(True) # додаємо на графік сітку
plt.show() # показує створений графік
