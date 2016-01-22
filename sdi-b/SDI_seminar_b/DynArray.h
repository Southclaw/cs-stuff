#ifndef DYNARRAY_INCLUDED
#define DYNARRAY_INCLUDED

/*
Dynamic array header:

Implements a basic dynamic array template class. Expands at 1.5x size on a
full-push.

All code and comments
- Barnaby Keene, 2015
*/

#include "stdafx.h"


template <typename T>
class DynArray
{
public:
	/*
	Constructors:
	Default constructor size is 1.
	Copy constructor does as expected - copys original contents into new.
	Most commonly used - constructor with size preallocates capacity size.
	Constructor with preset size fills array with preset default data.
	*/
	DynArray();
	DynArray(DynArray<T>&);
	DynArray(unsigned int);
	DynArray(unsigned int, T);
	DynArray(T*, size_t);
	~DynArray();

	/*
	Simple attribute getters:
	size: gets the amount of used cells in the array, the size of the data.
	capacity: gets the current total capacity, the actual size of the array.
	empty: simply returns true if empty; size == 0, regardless of capacity.
	*/
	int size() const;
	int capacity() const;
	bool empty() const;

	/*
	General modifiers:
	push_back: appends data to the end of the array.
	resize: resizes internal array, mostly just for internal abstraction.
	pop_back: removes the data element at the end of the array.
	*/
	void push_back(T const&);
	void resize(unsigned int);
	void pop_back();

	/*
	General data getters:
	back: gets the element at index 0, the first element added.
	front: gets the latest element added, at position size-1.
	get: gets the data at the specified index (if valid).
	*/
	T back() const;
	T front() const;
	T get(unsigned int) const;

	/*
	Special use-case functions:
	set: changes a data value at the specified index.
	insert: creates a gap by shifting data, inserts new data into that gap.
	erase: shifts all elements at specified index down to overwrite a cell.
	zap: sets the internal size to 0 so pushes start from cell 0 again.
	*/
	void set(T, unsigned int);
	void insert(T data, unsigned int idx);
	void erase(unsigned int);
	void clear();

	/*
	Operators:
	== checks equality first by size then element by element
	!= merely calls the above operator and inverts the output
	= is a simple copy assignment, no reallocation
	+= appends one array onto another or pushes a value onto the array
	[] for reading a specific index
	[] for assignment
	<< for ostream output
	*/
	bool operator==(const DynArray<T>& operand) const
	{
		if (this->dataSize_ != operand.dataSize_)
			return false;

		for (unsigned int i = 0; i < this->dataSize_; ++i)
		{
			if (this->heapData_[i] != operand.heapData_[i])
				return false;
		}

		return true;
	}

	bool operator!=(const DynArray<T>& operand) const
	{
		return !(*this == operand);
	}

	void operator=(DynArray<T>& operand)
	{
		if (*this == operand)
			throw;

		for (unsigned int i = 0; i < operand.dataSize_; ++i)
			heapData_[i] = operand.heapData_[i];

		dataSize_ = operand.dataSize_;
		dataCapacity_ = operand.dataCapacity_;
	}

	DynArray<T>& operator+=(const DynArray<T>& operand)
	{
		int newSize = this->capacity() + operand.capacity();

		this->resize(newSize);

		for (int i = 0, j = operand.size(); i < j; ++i)
		{
			this->push_back(operand.get(i));
		}

		return *this;
	}

	DynArray<T>& operator+=(const T& operand)
	{
		this->push_back(operand);
		return *this;
	}

	T const operator[](int idx) const
	{
		return this->get(idx);
	}

	T& operator[](int idx)
	{
		return heapData_[idx];
	}

	friend std::ostream& operator<<(std::ostream& os, DynArray<T>& obj)
	{
		os << "[";

		for (int i = 0, j = obj.size(); i < j; ++i)
		{
			os << (obj.get(i));

			if (i < j - 1)
				os << ", ";
		}

		os << "]";

		return os;
	}

private:
	T* heapData_;
	unsigned int dataSize_;
	unsigned int dataCapacity_;
};


/*
Template member function definitions

Why in the header file, you ask?
These function definitions are actually template definitions and thus are
technically not code (and do not compile directly to code). This whole class
is a class template rather than a regular class so it compiles differently.

When a compilation unit is preprocessed, the required types are gathered.
As the source is compiled, the required classes are generated for whatever
types are found in that unit; this is why the template functions can't be
stored inside a source code file, as they would be compiled independently
and once rather than for each required type. The workaround for this was to
declare explicitly for which types the class must be compiled for which, in
my opinion, defeats the object of flexibility and maintainability for
template classes.
*/
template<typename T> inline
DynArray<T>::DynArray()
{
	DynArray(1);
}

template<typename T> inline
DynArray<T>::DynArray(DynArray& original)
{
	dataCapacity_ = original.capacity();
	dataSize_ = original.size();
	heapData_ = new T[dataCapacity_];

	for (int i = 0, j = original.size(); i < j; ++i)
		heapData_[i] = original.get(i);
}

template<typename T> inline
DynArray<T>::DynArray(unsigned int capacity)
{
	dataCapacity_ = capacity;
	heapData_ = new T[capacity];
}

template<typename T> inline
DynArray<T>::DynArray(unsigned int capacity, T defval)
{
	dataCapacity_ = (int)(capacity * 1.5);
	dataSize_ = capacity;
	heapData_ = new T[capacity];

	for (unsigned int i = 0; i < capacity; ++i)
	{
		heapData_[i] = defval;
	}
}

template<typename T>
inline DynArray<T>::DynArray(T* arr, size_t arr_len)
{
	dataCapacity_ = (unsigned int)(arr_len * 1.5);
	dataSize_ = arr_len;
	heapData_ = new T[arr_len];

	for (unsigned int i = 0; i < arr_len; ++i)
	{
		heapData_[i] = arr[i];
	}
}

template<typename T> inline
DynArray<T>::~DynArray()
{
	delete [] heapData_;
}

/*
Core readers
*/
template<typename T> inline
int DynArray<T>::size() const
{
	return dataSize_;
}
template<typename T> inline
int DynArray<T>::capacity() const
{
	return dataCapacity_;
}
template<typename T> inline
bool DynArray<T>::empty() const
{
	return (dataSize_ == 0);
}

/*
Core modifiers
*/
template<typename T> inline
void DynArray<T>::push_back(T const& val)
{
	if (dataSize_ == dataCapacity_)
	{
		// resize freshly to 1 if capacity 0, else resize to capacity * 1.5
		if (dataCapacity_ == 0)
			resize(1);

		else
			resize((int)((dataCapacity_ * 1.5) + 0.5));
	}

	heapData_[dataSize_] = val;
	dataSize_ += 1;
}

template<typename T> inline
void DynArray<T>::resize(unsigned int size)
{
	T* temp = new T[size];

	if (temp == nullptr)
		throw;

	for (unsigned int i = 0; i < dataSize_; i++)
	{
		temp[i] = heapData_[i];
	}

	if (heapData_ != nullptr)
		delete[] heapData_;

	heapData_ = temp;
	dataCapacity_ = size;
}

template<typename T> inline
void DynArray<T>::pop_back()
{
	dataSize_ -= 1;
}

/*
Utility and misc
*/

template<typename T> inline
T DynArray<T>::back() const
{
	return heapData_[0];
}

template<typename T> inline
T DynArray<T>::front() const
{
	return heapData_[dataSize_ - 1];
}

template<typename T> inline
T DynArray<T>::get(unsigned int idx) const
{
	if (idx >= dataCapacity_ || idx >= dataSize_)
	{
		// out-of-bounds error
		throw;
	}

	return heapData_[idx];
}

template<typename T> inline
void DynArray<T>::set(T data, unsigned int idx)
{
	if (idx >= dataCapacity_ || idx >= dataSize_)
	{
		// out-of-bounds error
		throw;
	}

	heapData_[idx] = data;
}

template<typename T> inline
void DynArray<T>::insert(T data, unsigned int idx)
{
	if (idx >= dataCapacity_ || idx >= dataSize_)
	{
		// out-of-bounds error
		throw;
	}

	if (idx == dataSize_)
	{
		push_back(data);
		return;
	}

	if (dataSize_ + 1 > dataCapacity_)
	{
		resize(dataSize_ + 1);
	}

	for (unsigned int i = dataSize_; i > idx; --i)
	{
		heapData_[i] = heapData_[i - 1];
	}

	heapData_[idx] = data;
	dataSize_++;
}

template<typename T> inline
void DynArray<T>::erase(unsigned int idx)
{
	if (idx >= dataCapacity_ || idx >= dataSize_)
	{
		// out-of-bounds error
		throw;
	}

	if (idx == dataSize_ - 1)
	{
		pop_back();
		return;
	}

	for (unsigned int i = idx; i < dataSize_; ++i)
	{
		heapData_[i] = heapData_[i + 1];
	}

	dataSize_--;
}

template<typename T> inline
void DynArray<T>::clear()
{
	dataSize_ = 0;
}

#endif
