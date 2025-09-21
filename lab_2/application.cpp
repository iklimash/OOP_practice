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
            cout << "Enter length array:\n" << "> ";
            cin >> len;
            array = new Array(len);
            cout << "Array " << len << " elements has been created \n";
            break;
        case 2:
            cout << "Enter " << array->getLength() << " elements:\n";
            array->insertValue();
            cout << "Array is full\n";
            break;

        case 3:
            cout << "Enter new length: "; cin >> newLen;
            array->resize(newLen);
            break;

        case 4:
            cout << "Array: ";
            array->printArray();
            cout << "\n";
            break;
        case 5:
            cout << "Average value: " << array->avgValue() << "\n";
            break;
        case 6:
            cout << "CKO equally: " << array->CKO() << "\n";
            break;
        case 7:
            array->insertionSortASC();
            cout << "Array is sorted in ascending order\n";
            break;
        case 8:
            array->insertionSortDESC();
            cout << "Array is sorted in descending order\n";
            break;
        case 9:
            cout << "Enter index and value\n>"; cin >> index; cin >> value;
            if (array->changeValue(index, value))
            {
                cout << "Element be changed\n";
            }
            else
            {
                cout << "Error change element\n";
            }
            break;
        case 0:
            delete array;
            return 0;
        default:
            cout << "Error number\n";
            break;
        }
    }

}

void Application::showMenu()
{
    setlocale(0, "");

    cout << "1 - Create array\n";
    cout << "2 - Fill array\n";
    cout << "3 - Change array size\n";
    cout << "4 - Print array elements\n";
    cout << "5 - Calculate average\n";
    cout << "6 - Calculate CKO\n";
    cout << "7 - Sort in ascending order\n";
    cout << "8 - Sort in descending order\n";
    cout << "9 - Change element\n";
    cout << "0 - Exit\n" << "> ";
}
