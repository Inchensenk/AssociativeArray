#pragma once
#include<iostream>
//Глобальная константа длины словаря
const size_t LEN_DIC = 100;
using namespace std;

template <typename TKey, typename TValue, size_t size>
class Dictionary
{
	//ключь
	TKey key[size];
	//значение
	TValue data[size];
	//индекс текущего элемента
	size_t index = 0;

public:
	//получение текущего индекса
	size_t getIndex()
	{
		return index;
	}

	//проверка на наличие ключа
	bool isExistKey(TKey _key)
	{
		for (size_t i = 0; i < LEN_DIC; i++)
		{
			if (_key == key[i])
			{
				return true;
			}
		}
		return false;
	}

	//поиск значения по ключу
	TValue findKeyData(TKey _key)
	{
		if (isExistKey(_key))
		{
			for (size_t i = 0; i < LEN_DIC; i++)
			{
				if (_key == key[i])
				{
					return data[i];
				}
			}
		}
		else
		{
			cout << "Такого слова нету в словаре!" << endl << endl;
		}
	}

	//перезапись значения по ключу
	bool UpdateDataOnKey(TKey _key)
	{
		if (isExistKey(_key))
		{
			for (size_t i = 0; i < LEN_DIC; i++)
			{
				if (_key == key[i])
				{
					cout << "Введите новое значение слова:" << endl;
					getline(cin, data[index]);
					cout << endl;
					return true;
				}
			}
		}
		else
		{
			cout << "Такого слова нету в словаре!" << endl << endl;
			return false;
		}
	}

	//перезапись значения по ключу
	bool UpdateDataOnKey(TKey _key, TValue _data)
	{
		if (isExistKey(_key))
		{
			for (size_t i = 0; i < LEN_DIC; i++)
			{
				if (_key == key[i])
				{
					data[i] = _data;
					return true;
				}
			}
		}
		else
		{
			cout << "Такого слова нету в словаре!" << endl << endl;
			return false;
		}
	}

	//запись в текущий элемент
	bool pushBack()
	{
		if (index == LEN_DIC)
		{
			cout << "Словарь полностью заполнен!" << endl << endl;
			return false;
		}
		TKey buf;
		cout << "Введите название слова:" << endl;
		getline(cin, buf);
		if (isExistKey(buf))
		{
			cout << "Такое слово уже есть!" << endl;
			return false;
		}
		key[index] = buf;
		cout << "Введите значение слова:" << endl;
		getline(cin, data[index]);
		cout << endl;
		index++;
		return true;
	}

	//запись в текущий элемент
	bool pushBack(TKey _key, TValue _value)
	{
		if (index == LEN_DIC)
		{
			cout << "Словарь полностью заполнен!" << endl << endl;
			return false;
		}
		if (isExistKey(_key))
		{
			cout << "Такое слово уже есть!" << endl;
			return false;
		}
		key[index] = _key;
		data[index] = _value;
		index++;
		return true;
	}

	//вывод словаря
	void showDic()
	{
		for (size_t i = 0; i < LEN_DIC && key[i] != ""; i++)
		{
			cout << key[i] << ":\n" << data[i] << endl;
		}
	}

	//перегрузка оператора индексирования
	TValue& operator [](TKey _key)
	{
		if (isExistKey(_key))
		{
			for (size_t i = 0; i < LEN_DIC; i++)
			{
				if (_key == key[i])
				{
					return data[i];
				}
			}
		}
		else
		{
			cout << "Такого слова нету в словаре!" << endl << endl;
		}
	}

	//очистка словаря
	bool cleanDic()
	{
		if (this->index != 0)
		{
			for (size_t i = this->index; i >= 0; i--)
			{
				this->key[i] = "";
				this->data[i] = "";
			}
			this->index = 0;
		}
		return true;
	}

	//перегрузка оператора присваивания
	Dictionary& operator =(Dictionary& right)
	{
		this->cleanDic();

		for (size_t i = 0; i < right.index; i++)
		{
			this->key[i] = right.key[i];
			this->data[i] = right.data[i];
		}
		this->index = right.index;
		return *this;
	}
};