def set_operation():
    initial_set = {'c', 'd'} # початкова множина
    # множина голосних літер англійського алфавіту
    vowels_set = {'a', 'e', 'i', 'o', 'u'}
    # виведення множин
    print("Початкова множина літер:", initial_set)
    print("Множина голосних:", vowels_set)

    try: # пробуємо виконати об’єднання множин
        result = initial_set.union(vowels_set)
    except TypeError: # якщо не можна то перетворюємо у списки
        initial_set = list(initial_set)
        vowels_list = list(vowels_set)
        result = set(initial_set + vowels_list)
    # виведення результатів
    print("Результат об’єднання множин:", result)

set_operation()
