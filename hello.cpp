#include<iostream>
using namespace std;

typedef int Rank;
#define DEFAULT_CAPACITY   3

template<typename T> class Vector
{
protected:
	Rank _size;
	int _capacity;
	T* _elem;
	void copyFrom(T const* A, Rank lo, Rank hi);
	void expand();
	void shrink();

public:
	Vector(int c = DEFAULT_CAPACITY, int s = 0, T v = 0)
	{
		_elem = new T[_capacity = c];
		for (_size = 0; _size < s; _elem[_size++] = v);
	}
	Rank insert(Rank r, T const&e);
	Rank insert(T const&e)
	{
		return insert(_size, e);
	}
	T remove(Rank r);
	int remove(Rank o, Rank hi);
	int uniquify();
	Rank size()
	{
		return _size;
	}
	T& operator[] (Rank r) const;
};

template <typename T>
T&Vector<T>::operator[](Rank r)const
{
	return _elem[r];
}

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi)
{
	if (lo == hi)return 0;
	while (hi < _size)
		_elem[lo++] = _elem[hi++];
	_size = lo;
	shrink();
	return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r)
{
	T e = _elem[r];
	remove(r, r + 1);
	return e;
}

template<typename T>
int Vector<T>::uniquify()
{
	int oldSize = _size;
	int i = 1;
	while (i < _size)
		_elem[i - 1] == _elem[i] ? remove(i) : i++;
	return oldSize - _size;
}

template<typename T>
void Vector<T>::copyFrom(T const* A, Rank lo, Rank hi)
{
	_elem = new T[_capacity = 2 * (hi - lo)];
	_size = 0;
	while (lo < hi)
	{
		_elem[_size++] = A[lo++];
	}
}

template<typename T>
void Vector<T>::expand()
{
	if (_size < _capacity)
		return;
	if (_capacity < DEFAULT_CAPACITY)
		_capacity = DEFAULT_CAPACITY;

	T* oldElem = _elem;
	_elem = new T[_capacity <<= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];

	delete[] oldElem;
}


template<typename T>
void Vector<T>::shrink()
{
	if (_capacity < DEFAULT_CAPACITY)
		return;
	if (_size << 2>_capacity)
		return;
	T* oldElem = _elem;
	_elem = new T[_capacity >>= 1];
	for (int i = 0; i < _size; i++)
		_elem[i] = oldElem[i];

	delete[] oldElem;
}

template<typename T> 
Rank Vector<T>::insert(Rank r, T const&e)
{
	expand();
	for (int i = _size; i > r; i--)
		_elem[i] = _elem[i - 1];
	_elem[r] = e;
	_size++;
	return r;
}


int main()
{
	int n, num;
	Vector<int> array;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> num;
		array.insert(num);
	}
	array.uniquify();
	for (int i = 0; i < array.size(); i++)
		cout << array[i] << " ";
	cout << endl;
	cout << array.size() << endl;
}