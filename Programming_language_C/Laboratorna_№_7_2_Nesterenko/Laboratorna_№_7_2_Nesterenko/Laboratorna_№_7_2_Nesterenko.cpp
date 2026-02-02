#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    char str[] = "Learning programming is no better than wasting time", psubstr[] = "no", * p = 0, * p1 = 0;
    int size = strlen(psubstr);

    while (p = strstr(str, psubstr)) {
        // р - адреса початка підрядка, що видаляють у рядку str,
        p1 = p + size;  // p1 адреса кінця підрядка +1
        for (; *p1 != '\0'; p1++, p++)   //поки не досягнено кінця рядка
            *p = *p1;   // переміщуємо текст 
        *p = '\0';     // новий кінець рядка
    }
    cout << str << endl;
    system("pause");
    return 0;
}


