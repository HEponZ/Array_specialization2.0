#pragma once
#include <iostream>
#include <string>

using namespace std;

//Шаблонный класс
template <class T>
class Array_specialization
{
private:
	T* mas;
	size_t size; //Размер массива
public:
	//Конструкторы
	Array_specialization()noexcept : Array_specialization{nullptr, 0} {};
	Array_specialization(const T* mas_S, size_t size_S) noexcept;
	//Конструкторы перемещения и копирования
	Array_specialization(Array_specialization&& arr) noexcept;
	Array_specialization(const Array_specialization& arr) noexcept;

	T Min() const noexcept;
	T Max() const noexcept;

	bool Find(T element) const noexcept;
	void Add(T element)noexcept;
	void Delete()noexcept;
	void Copy(Array_specialization<T>& arr)noexcept;

	//Перегрузки копирующего и перемещающего присваивания
	Array_specialization<T>&& operator=(Array_specialization<T>&& arr) noexcept;
	Array_specialization<T>& operator=(const Array_specialization<T>& arr) noexcept;
	//Перегрузка []
	T operator[] (int index) const;
	T operator[] (int index);

	//Перегрузка ввода и вывода
	template<typename T> friend ostream& operator<< (ostream& my_cout, const Array_specialization<T>& arr) noexcept;
	template<typename T> friend istream& operator>> (istream& my_cin, Array_specialization<T>& arr) noexcept;
};