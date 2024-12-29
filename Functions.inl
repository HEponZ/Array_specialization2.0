template<class T> Array_specialization<T>::Array_specialization(const initializer_list<T> list)
	:Array_specialization(list.size())
{
	int i = 0;
	for (auto& element : list)
	{
		mas[i] = element;
		i++;
	}
}

template<class T> Array_specialization<T>::Array_specialization(const T* mas_S, size_t size_S)noexcept  : mas{ new T[size_S] }, size{ size_S }
{
	if (mas_S)
	{
		for (size_t i{ 0 }; i < size; i++)
		{
			mas[i] = mas_S[i];
		}
	}
}
template<class T> Array_specialization<T>::Array_specialization(Array_specialization&& arr) noexcept  : mas{ arr.mas }, size{ arr.size }
{
	arr.mas = nullptr;
	arr.size = 0;
}


template<class T> T Array_specialization<T>::Min()
{
	T min = INT_MAX;

	for (size_t i{ 0 }; i < size; i++)
	{
		if (mas[i] < min)
		{
			min = mas[i];
		}
	}
	return min;
}
template<class T> T Array_specialization<T>::Max()
{
	T max = INT_MIN;

	for (size_t i{ 0 }; i < size; i++)
	{
		if (mas[i] > max)
		{
			max = mas[i];
		}
	}
	return max;
}


template<class T> bool Array_specialization<T>::Find(T element)
{
	for (int i{ 0 }; i < size; i++)
	{
		if (mas[i] == element)
		{
			return true;
		}
	}
	return false;
}
template<class T> void Array_specialization<T>::Add(T element)
{
	T* new_mas = new T[++size];

	for (int i{ 0 }; i < size - 1; i++)
	{
		new_mas[i] = mas[i];
	}
	new_mas[size-1] = element;

	delete[] mas;
	mas = new_mas;
}
template<class T> void Array_specialization<T>::Delete()
{
	T* new_mas = new T[size--];

	for (int i{ 0 }; i < size; i++)
	{
		new_mas[i] = mas[i];
	}

	delete[] mas;
	mas = new_mas;
}
template<class T> void Array_specialization<T>::Copy(Array_specialization<T>& arr)
{
	mas = arr.mas;
	size = arr.size;
}


template<class T> const Array_specialization<T>& Array_specialization<T>:: operator=(const Array_specialization<T>& arr)
{
	if (&arr != this)
	{
		delete[] mas;

		mas = new T * [size];

		for (size_t i = 0; i < size; i++)
		{
			mas[i] = arr.mas[i];
		}
	}
	return *this;
}
template<class T> Array_specialization<T>&& Array_specialization<T>:: operator=(Array_specialization<T>&& arr)
{
	if (this != arr)
	{
		delete[] mas;

		size = arr.size;

		mas = new T[size];

		mas = arr.mas;

		mas = arr.mas;

		arr.mas = nullptr;

		arr.size = 0;
	}
	return *this;
}
template<class T> T Array_specialization<T>::operator[] (int index) const
{
	if (index < 0 || index > size)
	{
		throw "\nОшибка.Такого индекса не существует!\n";
	}
	return mas[index];
}