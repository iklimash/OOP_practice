#include "application.h"

#include <iostream>

using namespace std;

Application::Application() 
{
}

int Application::exec() {

    int choice;
    int len, newLen, index;
    number value;
    Array *array = new Array(0);
    while (true)
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Введите длинну массива:\n" << "> ";
            cin >> len;
            array = new Array(len);
            cout << "Массив из " << len << " элементов успешно создан\n";
            break;
        case 2:
            cout << "Введите " << array->getLength() << " элементов:\n";
            array->insertValue();
            cout << "Массив заполнен\n";
            break;
         
        case 3:
            cout << "Введите новую длинну: "; cin >> newLen;
            array->resize(newLen);
            break;

        case 4:
            cout << "Массив: ";
            array->printArray();
            cout << "\n";
            break;
        case 5:
			cout << "Среднее значение: " << array->avgValue() << "\n";
			break;
        case 6:
            cout <<"CKO равно: " << array->CKO() << "\n";
			break;
        case 7:
			array->insertionSortASC();
            cout << "Массив отсортирован по возрастанию\n";
			break;
        case 8:
            array->insertionSortDESC();
            cout << "Массив отсортирован по убыванию\n"; 
			break;
        case 9:
			cout << "Введите index и value\n>"; cin >> index; cin >> value;
			if (array->changeValue(index, value))
			{
				cout << "Элемент успешно изменен\n";
			}
			else
			{
				cout << "Ошибка изменения элемента\n";
			}
        case 0:
			return 0;   
        default:
            cout << "Неверный номер\n";
			break;
        }
    }

}

void Application::showMenu()
{
    setlocale(0, "");

    cout << "1 - Создать массив\n"; /*выполнено*/
    cout << "2 - Заполнить массив\n"; /*выполнено*/
    cout << "3 - Изменить размерность массива\n"; /*выполнено*/
    cout << "4 - Вывести элементы массива\n"; /*выполнено*/
    cout << "5 - Посчитать среднее\n"; /*выполнено*/
    cout << "6 - Посчитать СКО\n"; /*выполнено*/
    cout << "7 - Отсортировать по возрастанию\n";/*выполнено*/
    cout << "8 - Отсортировать по убыванию\n";/*выполнено*/
    cout << "9 - Изменить элемент\n";/*выполнено*/
    cout << "0 - exit\n" << "> ";/*выполнено*/
}
