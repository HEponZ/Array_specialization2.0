#pragma once
#include <iostream>
#include <string>

using namespace std;

//��������� �����
template <class T>
class Array_specialization
{
private:
	T* mas;
	size_t size; //������ �������
public:
	//������������
	Array_specialization()noexcept : Array_specialization{nullptr, 0} {};
	Array_specialization(const T* mas_S, size_t size_S) noexcept;
	//������������ ����������� � �����������
	Array_specialization(Array_specialization&& arr) noexcept;
	Array_specialization(const Array_specialization& arr) noexcept;

	T Min() const noexcept;
	T Max() const noexcept;

	bool Find(T element) const noexcept;
	void Add(T element)noexcept;
	void Delete()noexcept;
	void Copy(Array_specialization<T>& arr)noexcept;

	//���������� ����������� � ������������� ������������
	Array_specialization<T>&& operator=(Array_specialization<T>&& arr) noexcept;
	Array_specialization<T>& operator=(const Array_specialization<T>& arr) noexcept;
	//���������� []
	T operator[] (int index) const;
	T operator[] (int index);

	//���������� ����� � ������
	template<typename T> friend ostream& operator<< (ostream& my_cout, const Array_specialization<T>& arr) noexcept;
	template<typename T> friend istream& operator>> (istream& my_cin, Array_specialization<T>& arr) noexcept;
};