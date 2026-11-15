const loadBtn = document.getElementById('loadBtn');          // кнопка
const cartIdInput = document.getElementById('cartId');       // поле введення ідентифікатора
const testModeSelect = document.getElementById('testMode');  // випадний список
const messageArea = document.getElementById('messageArea');  // область для повідомлень
const cartSection = document.getElementById('cartSection');  // область для відображення кошика
const cartHeader = document.getElementById('cartHeader');    // заголовок таблиці
const cartBody = document.getElementById('cartBody');        // вміст таблиці
const cartTotal = document.getElementById('cartTotal');      // область для загальної суми

// коли клієнт натискає кнопку, викликаємо завантаження
loadBtn.addEventListener('click', loadCart);

// головна функція для завантаження кошика
async function loadCart() {
    const cartId = cartIdInput.value;      // дістаємо ідентифікатор кошика
    const testMode = testModeSelect.value; // дістаємо обраний режим
    
    // формуємо url
    let url = `https://dummyjson.com/carts/${cartId}?delay=3000`;
    if (testMode === '404') {
        url = 'https://dummyjson.com/http/404/Not_Found';
    } else if (testMode === '503') {
        url = 'https://dummyjson.com/http/503/Service_Unavailable';
    }

    // підготовка інтерфейсу до завантаження
    cartSection.style.display = 'none'; // ховаємо таблицю
    loadBtn.disabled = true;            // блокуємо кнопку
    messageArea.style.color = 'black';  // скидаємо колір тексту

    try {
        // викликаємо функцію з повторними спробами
        const data = await requestWithRetry(url, 2, testMode);
        
        // якщо запит успішний
        renderCartTable(data);                                 // виводимо таблицю
        messageArea.textContent = 'Дані успішно завантажено.'; // повідомляємо про успіх
    } catch (error) {
        // обробка остаточної помилки
        messageArea.style.color = 'red';                       // змінюємо колір на червоний
        messageArea.textContent = `Помилка: ${error.message}`; // виводимо текст помилки
    } finally {
        // видаляємо блокування з кнопки
        loadBtn.disabled = false;
    }
}

// функція запиту з логікою повторних спроб
async function requestWithRetry(url, maxRetries, testMode) {
    // цикл для повторних спроб
    for (let attempt = 1; attempt <= maxRetries; attempt++) {
        try {
            // показуємо користувачу яка поточна спроба
            messageArea.textContent = `Завантаження кошика... Будь ласка, зачекайте. (Спроба ${attempt} із ${maxRetries})`;
            
            // якщо це штучна помилка на 1-й спробі
            if (testMode === 'simError' && attempt === 1) {
                await delay(3000);                                         // робимо паузу 3 секунди
                throw new Error("Штучний збій мережі на стороні клієнта"); // генеруємо помилку
            }

            // виконуємо запит
            const response = await fetch(url);

            // штучно зупиняємо код на 3 секунди для помилок 404 та 503
            if (testMode === '404' || testMode === '503') {
                await delay(3000);
            }

            // перевірка чи такий статус є успішним
            if (!response.ok) {
                throw new Error(`HTTP помилка запиту. Статус: ${response.status}`);
            }

            // перетворюємо JSON-рядок від сервера у словник/об'єкт
            return await response.json(); 

        // якщо виникає помилка
        } catch (error) {
            console.warn(`Спроба ${attempt} завершилася невдачею: ${error.message}`);
            
            // якщо це остання спроба
            if (attempt === maxRetries) {
                throw error;
            }

            // чекаємо 1.5 секунди перед повторною спробою
            messageArea.textContent = `Помилка на спробі ${attempt}. Повторний запит через 1.5 секунди...`;
            await delay(1500);
        }
    }
}

// допоміжна функція для створення паузи
function delay(ms) {
    return new Promise(resolve => setTimeout(resolve, ms));
}

// функція для відображення даних у таблиці
function renderCartTable(cartData) {
    // якщо користувач отримав пусті дані
    if (!cartData || !cartData.products) {
        throw new Error("Некоректні дані кошика");
    }

    cartHeader.textContent = `Ідентифікатор кошика: ${cartData.id}`; // оновлюємо заголовок
    cartBody.innerHTML = '';                                         // очищаємо тіло таблиці

    // проходимося по списку товарів
    cartData.products.forEach(product => {
        const row = document.createElement('tr'); // створюємо новий рядок
        
        // формуємо актуальний рядок з даними
        row.innerHTML = `
            <td>${product.title}</td>
            <td>$${product.price}</td>
            <td>${product.quantity}</td>
            <td>$${product.total}</td>
        `;
        
        cartBody.appendChild(row); // додаємо запис у таблицю
    });

    cartTotal.textContent = `Загальна сума кошика: $${cartData.total}`; // виводимо суму
    cartSection.style.display = 'block';                                // відображаємо таблицю
}