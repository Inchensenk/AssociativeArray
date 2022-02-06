#pragma once
#include<iostream>
//���������� ��������� ����� �������
const size_t LEN_DIC = 100;
using namespace std;

template <typename TKey, typename TValue, size_t size>
class Dictionary
{
	//�����
	TKey key[size];
	//��������
	TValue data[size];
	//������ �������� ��������
	size_t index = 0;

public:
	//��������� �������� �������
	size_t getIndex()
	{
		return index;
	}

	//�������� �� ������� �����
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

	//����� �������� �� �����
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
			cout << "������ ����� ���� � �������!" << endl << endl;
		}
	}

	//���������� �������� �� �����
	bool UpdateDataOnKey(TKey _key)
	{
		if (isExistKey(_key))
		{
			for (size_t i = 0; i < LEN_DIC; i++)
			{
				if (_key == key[i])
				{
					cout << "������� ����� �������� �����:" << endl;
					getline(cin, data[index]);
					cout << endl;
					return true;
				}
			}
		}
		else
		{
			cout << "������ ����� ���� � �������!" << endl << endl;
			return false;
		}
	}

	//���������� �������� �� �����
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
			cout << "������ ����� ���� � �������!" << endl << endl;
			return false;
		}
	}

	//������ � ������� �������
	bool pushBack()
	{
		if (index == LEN_DIC)
		{
			cout << "������� ��������� ��������!" << endl << endl;
			return false;
		}
		TKey buf;
		cout << "������� �������� �����:" << endl;
		getline(cin, buf);
		if (isExistKey(buf))
		{
			cout << "����� ����� ��� ����!" << endl;
			return false;
		}
		key[index] = buf;
		cout << "������� �������� �����:" << endl;
		getline(cin, data[index]);
		cout << endl;
		index++;
		return true;
	}

	//������ � ������� �������
	bool pushBack(TKey _key, TValue _value)
	{
		if (index == LEN_DIC)
		{
			cout << "������� ��������� ��������!" << endl << endl;
			return false;
		}
		if (isExistKey(_key))
		{
			cout << "����� ����� ��� ����!" << endl;
			return false;
		}
		key[index] = _key;
		data[index] = _value;
		index++;
		return true;
	}

	//����� �������
	void showDic()
	{
		for (size_t i = 0; i < LEN_DIC && key[i] != ""; i++)
		{
			cout << key[i] << ":\n" << data[i] << endl;
		}
	}

	//���������� ��������� ��������������
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
			cout << "������ ����� ���� � �������!" << endl << endl;
		}
	}

	//������� �������
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

	//���������� ��������� ������������
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