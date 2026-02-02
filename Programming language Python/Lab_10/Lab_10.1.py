import matplotlib.pyplot as plt # імпортуємо бібліотеку для роботи з графіком
import numpy as np # імпортуємо бібліотеку для роботи з масивом

# створюємо масив х розміром 50 елементів (від 0 до 4)
x = np.linspace(0, 4, 50)
# знаходимо значення функції від х та записуємо значення в масив
y = 5 * np.sin(10 * x) * np.sin(3 * x)

# будуємо графік функції
plt.plot(x, y, label='5·sin(10·x)·sin(3·x)', color = 'red', linewidth = 3)

plt.title('My plot', fontsize = 20, color = 'blue') # підписуємо графік
plt.xlabel('x', fontsize = 15, color = 'green') # підписуємо вісь абсцис
plt.ylabel('y', fontsize = 15, color = 'green') # підписуємо вісь ординат
plt.legend() # додаємо легенду
plt.grid(True) # додаємо лінію сітки

plt.show() # відображаємо графік на екрані
plt.savefig('fig_10.1.png') # збережемо побудований графік
