#pragma once
#include <iostream>
#include <string>

using namespace std;

template <class T>
class Array_specialization
{
private:
	T* mas;
	size_t size;
public:
	Array_specialization()noexcept : Array_specialization{nullptr, 0} {};
	Array_specialization(const T* mas_S, size_t size_S) noexcept;
	Array_specialization(const initializer_list<T> list);
	Array_specialization(Array_specialization&& arr) noexcept;
	Array_specialization(const Array_specialization& arr) noexcept : mas{ arr.mas }, size{ arr.size } {}

	T Min();
	T Max();

	bool Find(T element);
	void Add(T element);
	void Delete();
	void Copy(Array_specialization<T>& arr);

	Array_specialization<T>&& operator=(Array_specialization<T>&& arr);
	const Array_specialization<T>& operator=(const Array_specialization<T>& arr);
	T operator[] (int index) const;

	template<typename T> friend ostream& operator<< (ostream& my_cout, const Array_specialization<T>& arr) noexcept;
	template<typename T> friend istream& operator>> (istream& my_cin, Array_specialization<T>& arr) noexcept;
};

template <> class Array_specialization<char*>
{
private:
	char** mas;
	size_t size;
public:
	Array_specialization(const char** mas_S, size_t size_S) noexcept : size{ size_S }
	{
		mas = new char* [size];
		if (mas_S)
		{
			for (size_t i{ 0 }; i < size; i++)
			{
				mas[i] = new char[strlen(mas_S[i]) + 1];
				strcpy_s(mas[i], strlen(mas_S[i]) + 1, mas_S[i]);
			}
		}
	}
	Array_specialization(Array_specialization&& arr) noexcept : size{ arr.size }
	{
		mas = new char* [size];

		mas = arr.mas;

		arr.mas = nullptr;
		arr.size = 0;
	}
	Array_specialization(const Array_specialization& arr) noexcept : size{ arr.size }
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			mas[i] = new char[strlen(arr.mas[i]) + 1];
			strcpy_s(mas[i], strlen(arr.mas[i]) + 1, arr.mas[i]);
		}
	}

	char** Min() = delete;
	char** Max() = delete;

	bool Find(char* element)
	{
		for (int i{ 0 }; i < size; i++)
		{
			if (strcmp(mas[i], element) != 0)
			{
				return true;
			}
		}
		return false;
	}
	void Add(char* element)
	{
		char** new_mas = new char* [++size];

		for (int i{ 0 }; i < size - 1; i++)
		{
			new_mas[i] = new char[strlen(mas[i]) + 1];
			strcpy_s(new_mas[i], strlen(mas[i]) + 1, mas[i]);
		}
		new_mas[size - 1] = new char[strlen(element) + 1];
		strcpy_s(new_mas[size - 1], strlen(element) + 1, element);

		for (size_t i{ 0 }; i < size; i++)
		{
			delete[] mas[i];
		}
		delete[] mas;

		mas = new_mas;
	}
	void Delete()
	{
		char** new_mas = new char* [++size];

		for (int i{ 0 }; i < size - 1; i++)
		{
			new_mas[i] = new char[strlen(mas[i]) + 1];
			strcpy_s(new_mas[i], strlen(mas[i]) + 1, mas[i]);
		}

		for (size_t i{ 0 }; i < size; i++)
		{
			delete[] mas[i];
		}
		delete[] mas;

		mas = new_mas;
	}
	void Copy(char** element)
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			mas[i] = new char[strlen(element[i]) + 1];
			strcpy_s(mas[i], strlen(element[i]) + 1, element[i]);
		}
	}
};

template <> class Array_specialization<string>
{
private:
	string mas;
	size_t size;
public:
	Array_specialization()noexcept : Array_specialization(string(), 0) {};
	Array_specialization(const string mas_S, size_t size_S)noexcept : size{ size_S }
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			mas = mas_S;
		}
	}
	Array_specialization(Array_specialization&& arr) noexcept : size{ arr.size }
	{
		mas = arr.mas;

		arr.mas = nullptr;
		arr.size = 0;
	}
	Array_specialization(const Array_specialization& arr) noexcept : mas{ arr.mas }, size { arr.size } {}

	string Min() = delete;
	string Max() = delete;

	bool Find(string element)
	{
		for (int i{ 0 }; i < size; i++)
		{
			if (mas.find(element) != string::npos)
			{
				return true;
			}
		}
		return false;
	}
	void Add(string element)
	{
		mas.append(element);
	}
	void Delete()
	{
		mas.erase();
	}
	void Copy(string element)
	{
		mas = element;
	}
};