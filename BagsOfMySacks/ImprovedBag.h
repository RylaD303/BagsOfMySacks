#pragma once
#include "Bag.hpp"
template <typename T>
class ImprovedBag : public Bag<T>
{
private:
	char* name;
public:
	void insert(T x, unsigned int _i)
	{
		if (_i >= this->size)
		{
			this->Add(x);
		}
		else
		{
			T copy = this->Get();
			this->Add(copy);
			this->Add(copy);
			for (int i = this->size - 2; i > _i; i--)
			{
				this->data[i] = this->data[i - 1];
			}
			this->data[_i] = x;
		}
	}
};

