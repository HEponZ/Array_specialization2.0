#include "Array_specialization.h"
#include "Functions.inl"
#include "Functions.cpp"

int main()
{
	setlocale(LC_ALL, "rus");

	Array_specialization<int> arr, arr2;
	Array_specialization<string> str_mas;
	string string;
	int choise, element, index;
	enum MENU {
		EXIT = 0,
		ADD,
		DELETE,
		PRINT,
		COPY,
		MIN,
		MAX,
		FIND_INDEX,
		FIND
	};

	cout << "1 - Добавить\n2 - Удалить\n3 - Вывод\n4 - Копировать\n5 - MIN\n6 - MAX\n7 - Поиск по индексу\n8 - Поиск элемента\n";

	do
	{
		try
		{
			cin >> choise;
			switch (choise)
			{
			case ADD:
				cout << "Введите то что вы хотите добавить: ";
				cin >> element;
				arr.Add(element);

				/*cout << "Введите то что вы хотите добавить(string): ";
				cin >> string;
				str_mas.Add(string);*/
				break;
			case DELETE:
				arr.Delete();
				break;
			case PRINT:
				cout << "Массив 1\n" << arr << "Массив 2\n" << arr2;
				/*cout << "String\n";
				cout << str_mas;*/
				break;
			case COPY:
				arr2.Copy(arr);
				cout << "Копирование успешно\n";
				break;
			case MIN:
				arr.Min();
				break;
			case MAX:
				arr.Max();
				break;
			case FIND_INDEX:
				cout << "Введите индекс для поиска: ";
				cin >> index;
				cout << arr[index] ;
				break;
			case FIND:
				cout << "Введите элемент для поиска: ";
				cin >> element;
				if (arr.Find(element) == true)
				{
					cout << "Элемент найден\n";
				}
				else
				{
					cout << "Элемент не найден\n";
				}

				/*cout << "String\n";
				cout << "Введите элемент для поиска(string): ";
				cin >> string;
				if (str_mas.Find(string) == true)
				{
					cout << "Элемент найден\n";
				}
				else
				{
					cout << "Элемент не найден\n";
				}*/
				break;
			case EXIT:
				break;
			}
		}
		catch (const char* exc)
		{
			puts(exc);
		}
	} while (choise != 0);

	return 0;
}