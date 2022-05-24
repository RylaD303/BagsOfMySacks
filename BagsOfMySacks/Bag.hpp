#pragma once
template<typename T>
class Bag
{
protected:
	unsigned int capacity;
	unsigned int size;
	T* data;
	void Free()
	{
		delete[] this->data;
	}
	void Copy(Bag& other)
	{
		capacity = other.capacity;
		size = other.size;
		data = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = other.data[i];
		}
	}
	void Expand()
	{
		Bag copy(this);
		Free();
		capacity *= 2;
		data = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			this->data[i] = copy.data[i];
		}
	}
public:
	Bag()
	{
		capacity = 8;
		size = 0;
		data = new T[8];
	}
	~Bag()
	{
		Free();
	}
	Bag(Bag& other)
	{
		Copy(other);
	}
	Bag& operator=(Bag& other)
	{
		if (this != &other)
		{
			Free();
			Copy(Bag & other);
		}
		return *this;
	}

	void Add(T data)
	{
		if (size + 1 == capacity) Expand();
		data[size] = data;
		size++;
	}
	T Get()
	{
		if (size > 0)
		{
			size--;
			return data[size];
		}
	}

	Bag operator+(Bag& other)
	{
		Bag copy(this);
		Free();
		data = new T[capacity];
		for (int i = other.size - 1; i >= 0; i--)
		{
			copy.Add(other.Get());
		}
		return copy;
	}
	bool operator==(Bag& other)
	{
		if (size == other.size)
		{
			for (int i = 0; i < size; i++)
			{
				if (data[i] != other.data[i])
				{
					return false;
				}
			}
			return true;
		}
		return false;
	}
};

