#include "Array_specialization.h"
#include "Functions.inl"
#include "Functions.cpp"
#include "char_specialization.inl"
#include "string_specialization.inl"

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

	cout << "1 - ��������\n2 - �������\n3 - �����\n4 - ����������\n5 - MIN\n6 - MAX\n7 - ����� �� �������\n8 - ����� ��������\n";

	do
	{
		try
		{
			cin >> choise;
			switch (choise)
			{
			case ADD:
				cout << "������� �� ��� �� ������ ��������: ";
				cin >> element;
				arr.Add(element);

				/*cout << "������� �� ��� �� ������ ��������(string): ";
				cin >> string;
				str_mas.Add(string);*/
				break;
			case DELETE:
				arr.Delete();
				break;
			case PRINT:
				cout << "������ 1\n" << arr << "������ 2\n" << arr2;
				/*cout << "String\n";
				cout << str_mas;*/
				break;
			case COPY:
				arr2.Copy(arr);
				cout << "����������� �������\n";
				break;
			case MIN:
				cout << "����������� ��������: " << arr.Min() << "\n";
				break;
			case MAX:
				cout << "������������ ��������: " << arr.Max() << "\n";
				break;
			case FIND_INDEX:
				cout << "������� ������ ��� ������: ";
				cin >> index;
				cout << arr[index] ;
				break;
			case FIND:
				cout << "������� ������� ��� ������: ";
				cin >> element;
				if (arr.Find(element) == true)
				{
					cout << "������� ������\n";
				}
				else
				{
					cout << "������� �� ������\n";
				}

				/*cout << "String\n";
				cout << "������� ������� ��� ������(string): ";
				cin >> string;
				if (str_mas.Find(string) == true)
				{
					cout << "������� ������\n";
				}
				else
				{
					cout << "������� �� ������\n";
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