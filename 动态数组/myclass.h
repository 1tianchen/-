//#pragma once
//#include <assert.h>
//template <typename T>
//class MyClass//��̬���Ӽ���
//{
//public:
//	MyClass()
//	{
//		data = new T[10];
//		capacity = 10;
//		size = 0;
//	}
//	~MyClass()
//	{
//		delete[]data;
//	}
//	void push_back(T e)
//	{
//		if (size == capacity)
//		{
//			resize(2 * capacity);
//		}
//		//assert(size < capacity);
//		data[size++] = e;
//	}
//	T pop_back()
//	{
//		assert(size > 0);
//		size--;
//		T ret = data[size - 1];
//		if (size == capacity / 4)
//		{
//			resize(capacity / 4);//��ֹ���鶯̬ ���� ����
//		}
//		return ret;
//	}
//private:
//	T* data;
//	int capacity;
//	int size;
//	void resize(int newCapcity)
//	{
//		T* newData = new T[newCapcity];
//		for (int i = 0; i < size; i++)
//		{
//			newData[i] = data[i];
//		}
//		delete[] data;
//		data = newData;
//		capacity = newCapcity;
//	}
//};
//
