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
    Array* array = new Array(0);
    while (true)
    {
        showMenu();
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "������� ������ �������:\n" << "> ";
            cin >> len;
            array = new Array(len);
            cout << "������ �� " << len << " ��������� ������� ������\n";
            break;
        case 2:
            cout << "������� " << array->getLength() << " ���������:\n";
            array->insertValue();
            cout << "������ ��������\n";
            break;

        case 3:
            cout << "������� ����� ������: "; cin >> newLen;
            array->resize(newLen);
            break;

        case 4:
            cout << "������: ";
            array->printArray();
            cout << "\n";
            break;
        case 5:
            cout << "������� ��������: " << array->avgValue() << "\n";
            break;
        case 6:
            cout << "CKO �����: " << array->CKO() << "\n";
            break;
        case 7:
            array->insertionSortASC();
            cout << "������ ������������ �� �����������\n";
            break;
        case 8:
            array->insertionSortDESC();
            cout << "������ ������������ �� ��������\n";
            break;
        case 9:
            cout << "������� index � value\n>"; cin >> index; cin >> value;
            if (array->changeValue(index, value))
            {
                cout << "������� ������� �������\n";
            }
            else
            {
                cout << "������ ��������� ��������\n";
            }
            break;
        case 0:
            delete array;
            return 0;
        default:
            cout << "�������� �����\n";
            break;
        }
    }

}

void Application::showMenu()
{
    setlocale(0, "");

    cout << "1 - ������� ������\n"; /*���������*/
    cout << "2 - ��������� ������\n"; /*���������*/
    cout << "3 - �������� ����������� �������\n"; /*���������*/
    cout << "4 - ������� �������� �������\n"; /*���������*/
    cout << "5 - ��������� �������\n"; /*���������*/
    cout << "6 - ��������� ���\n"; /*���������*/
    cout << "7 - ������������� �� �����������\n";/*���������*/
    cout << "8 - ������������� �� ��������\n";/*���������*/
    cout << "9 - �������� �������\n";/*���������*/
    cout << "0 - exit\n" << "> ";/*���������*/
}
