//Специализация шаблона класса для string*
template <> class Array_specialization<string*>
{
private:
	string mas;
	size_t size;
public:
	Array_specialization()noexcept : Array_specialization(string(), 0) {};
	Array_specialization(const string mas_S, size_t size_S)noexcept;
	Array_specialization(Array_specialization&& arr)noexcept;
	Array_specialization(const Array_specialization& arr) noexcept : mas{ arr.mas }, size{ arr.size } {}

	string Min() = delete;
	string Max() = delete;

	bool Find(string element)const noexcept;
	void Add(string element)noexcept;
	void Delete()noexcept;
	void Copy(Array_specialization& arr)noexcept;
};

Array_specialization<string*>::Array_specialization(const string mas_S, size_t size_S)noexcept : size{ size_S }
{
	for (size_t i{ 0 }; i < size; i++)
	{
		mas = mas_S;
	}
}
Array_specialization<string*>::Array_specialization(Array_specialization&& arr) noexcept : size{ arr.size }
{
	mas = arr.mas;

	arr.mas = char();
	arr.size = 0;
}

bool Array_specialization<string*>::Find(string element)const noexcept
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
void Array_specialization<string*>::Add(string element)noexcept
{
	mas.append(element);
}
void Array_specialization<string*>::Delete()noexcept
{
	mas.erase();
}
void Array_specialization<string*>::Copy(Array_specialization& arr)noexcept
{
	mas = arr.mas;
}