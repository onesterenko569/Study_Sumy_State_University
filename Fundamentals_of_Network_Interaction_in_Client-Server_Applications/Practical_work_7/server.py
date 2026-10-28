import asyncio    # асинхронність для спілкування з кількома клієнтами одночасно
import json       # робота з JSON
import websockets # робота з мережею

# словник активів
assets = {
    "BTC": 64000,
    "ETH": 3100
}

# множина для зберігання всіх підключених клієнтів
connected_clients = set()

# функція для спілкування з клієнтами
async def exchange_handler(websocket):

    # коли клієнт підключається, додаємо його до нашого списку
    connected_clients.add(websocket)
    print(f"Новий клієнт підключився! Всього активних трейдерів: {len(connected_clients)}")
    
    try:
        # безкінечний цикл, який слухає повідомлення від конкретного клієнта
        async for message in websocket:
            print(f"Отримано від клієнта: {message}")
            
            data = json.loads(message)   # перетворюємо JSON-рядок від клієнта у словник Python
            action = data.get("action")  # витягуємо дію

            # якщо користувач хоче додати новий актив
            if action == "add_asset":
                name = data.get("name")     # дістаємо назву активу
                price = data.get("price")   # дістаємо ціну активу
                assets[name] = float(price) # додаємо запис у словник активів

            # якщо користувач хоче оновити ціну активу
            elif action == "update_price":
                name = data.get("name")         # дістаємо назву активу
                price = data.get("price")       # дістаємо нову ціну активу
                if name in assets:              # перевірка чи такий актив існує
                    assets[name] = float(price) # оновлюємо ціну
            
            # формуємо актуальний список активів
            response = {
                "event": "update",
                "assets": assets
            }
            
            # розсилаємо оновлений список всім підключеним клієнтам
            websockets.broadcast(connected_clients, json.dumps(response))

    # якщо клієнт відключився
    except websockets.exceptions.ConnectionClosed:
        print("Клієнт відключився")

    # видаляємо клієнта зі списку
    finally:
        connected_clients.remove(websocket)

async def main():
    # запускаємо сервер на локальному комп'ютері на порту 8765
    async with websockets.serve(exchange_handler, "localhost", 8765):
        print("Сервер біржі запущено на ws://localhost:8765")
        await asyncio.Future()  # робить так, щоб сервер працював вічно і не вимикався

if __name__ == "__main__":
    asyncio.run(main())