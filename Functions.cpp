#include "Array_specialization.h"

template<typename T> ostream& operator<< (ostream& my_cout, const Array_specialization<T>& arr) noexcept 
{
	for (int i{ 0 }; i < arr.size; i++)
	{
		my_cout << arr.mas[i] << " ";
	}
	my_cout << "\n";

	return my_cout;
}
template<typename T> istream& operator>> (istream& my_cin, Array_specialization<T>& arr) noexcept 
{
	for(size_t i{0};i<size;i++)
	{
		my_cin >> arr.mas[i];
	}

	return my_cin;
}