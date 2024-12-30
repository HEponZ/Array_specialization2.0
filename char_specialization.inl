//Специализация шаблона класса для char*
template <> class Array_specialization<char*>
{
private:
	char** mas;
	size_t size;
public:
	//Методы noexcept - те в которых нет исключений
	Array_specialization()noexcept : Array_specialization{ nullptr, 0 } {};
	Array_specialization(const char** mas_S, size_t size_S)noexcept;
	Array_specialization(Array_specialization&& arr)noexcept;
	Array_specialization(const Array_specialization& arr)noexcept;

	char** Min() = delete;
	char** Max() = delete;

	//Методы const - те которые не исзменяют значения
	bool Find(const char* element)const noexcept;
	void Add(char* element)noexcept;
	void Delete()noexcept;
	void Copy(Array_specialization& arr)noexcept;

	friend ostream& operator<< (ostream& my_cout, const Array_specialization& arr) noexcept
	{
		for (int i{ 0 }; i < arr.size; i++)
		{
			my_cout << arr.mas[i] << " ";
		}
		my_cout << "\n";

		return my_cout;
	}
	friend istream& operator>> (istream& my_cin, Array_specialization& arr) noexcept
	{
		for (size_t i{ 0 }; i < arr.size; i++)
		{
			my_cin >> arr.mas[i];
		}

		return my_cin;
	}

	Array_specialization& operator=(Array_specialization& arr);

	char* operator[] (int index) const;
	char* operator[] (int index);
};

Array_specialization<char*>::Array_specialization(const char** mas_S, size_t size_S) noexcept : size{ size_S }
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
Array_specialization<char*>::Array_specialization(Array_specialization&& arr) noexcept : mas{ new char* [arr.size] }, size{ arr.size }
{
	for (size_t i{ 0 }; i < size; i++)
	{
		delete[] mas[i];
	}
	delete[] mas;

	mas = arr.mas;

	arr.mas = nullptr;
	arr.size = 0;
}
Array_specialization<char*>::Array_specialization(const Array_specialization& arr) noexcept : mas{ new char* [arr.size] }, size{ arr.size }
{
	delete[] mas;

	for (size_t i{ 0 }; i < size; i++)
	{
		mas[i] = new char[strlen(arr.mas[i]) + 1];
		strcpy_s(mas[i], strlen(arr.mas[i]) + 1, arr.mas[i]);
	}
}

bool Array_specialization<char*>::Find(const char* element)const noexcept
{
	for (int i{ 0 }; i < size; i++)
	{
		if (strcmp(mas[i], element) == 0)
		{
			return true;
		}
	}
	return false;
}
void Array_specialization<char*>::Add(char* element) noexcept
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
void Array_specialization<char*>::Delete() noexcept
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
void Array_specialization<char*>::Copy(Array_specialization& arr)noexcept
{
	delete[] mas;

	for (size_t i{ 0 }; i < size; i++)
	{
		mas[i] = new char[strlen(arr.mas[i]) + 1];
		strcpy_s(mas[i], strlen(arr.mas[i]) + 1, arr.mas[i]);
	}
}

Array_specialization<char*>& Array_specialization<char*>::operator=(Array_specialization& arr)
{
	if (&arr != this)
	{
		delete[] mas;

		mas = new char* [size];

		for (size_t i = 0; i < size; i++)
		{
			mas[i] = arr.mas[i];
		}
	}
	return *this;
}

char* Array_specialization<char*>::operator[] (int index) const
{
	if (index < 0 || index > size)
	{
		throw "\nОшибка.Такого индекса не существует!\n";
	}
	return mas[index];
}
char* Array_specialization<char*>::operator[] (int index)
{
	if (index < 0 || index > size)
	{
		throw "\nОшибка.Такого индекса не существует!\n";
	}
	return mas[index];
}