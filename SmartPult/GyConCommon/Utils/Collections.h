/*
 * Collections.h
 *
 *  Created on: 18 ����. 2015 �.
 *      Author: cno
 */

#ifndef GYCONCOMMON_UTILS_COLLECTIONS_H_
#define GYCONCOMMON_UTILS_COLLECTIONS_H_
#include <dataTypes.h>

//������������ List
//1-� ������� �� ������������ � �������������������� ������� � ���������
//2-� �� ����� ������� ��������� ������ � ���������� �� ���� ��������� � ������ � �����
//3-� ����� ����� ����������� ��� ��������� ���������� ������, ��� ��������� ����������� �������� ��� ���������
//4-� �� ����� ���������� ������� ������


template <typename ElementType> class List {
protected:
   volatile UInt32 size;
   volatile UInt32 maxSize;
   ElementType *elements;
   volatile UInt32 interatorId;
public:
   List();
   ElementType get(UInt32 id);
   ElementType* getAll();
   UInt32 getSize();
   UInt32 getMaxSize();
   bool set(UInt32 id, ElementType element);
   bool add(ElementType element);
   bool addAll(List<ElementType> *other);
   void remove();
   void removeAll();
};


template<typename ElementType>
inline List<ElementType>::List() {
	maxSize = 0;
	size = 0;
}

template<typename ElementType>
inline  ElementType* List<ElementType>::getAll() {
	return elements;
}

template<typename ElementType>
inline  ElementType List<ElementType>::get(UInt32 id) {
	if (id>=size) id = size - 1;
	return elements[id];
}


template<typename ElementType>
inline UInt32 List<ElementType>::getSize() {
	return size;
}

template<typename ElementType>
inline UInt32 List<ElementType>::getMaxSize() {
    return maxSize;
}


template<typename ElementType>
inline bool List<ElementType>::add(ElementType element) {
	if (size<maxSize) {
		elements[size++] = element;
		return true;
	} else {
		return false;
	}
}

template<typename ElementType>
inline bool List<ElementType>::set(UInt32 id, ElementType element) {
	if (id>=size) {
		return false;
	} else {
        elements[id] = element;
        return true;
	}
}

template<typename ElementType>
inline void List<ElementType>::remove() {
    if (size>0) {
    	size--;
    	return true;
    } else {
    	return false;
    }
}

template<typename ElementType>
inline void List<ElementType>::removeAll() {
	size = 0;
}

template<typename ElementType>
inline bool List<ElementType>::addAll(List<ElementType> *other) {
	bool res = true;
    UInt32 maxId = size + other->getSize() - 1;
    if (maxId >= maxSize) {maxId = maxSize - 1; res = false;}

    for (int i = size; i<=maxId; i++) {
        this->elements[i] = other->elements[i];
    }
    size+=other->getSize(); //��� �����������
    return res;
}

template <typename ElementType, UInt32 maxSize> class StaticList: public List<ElementType> {
    ElementType staticElements[maxSize];
public:
    StaticList();
};

template<typename ElementType, UInt32 maxSize>
inline StaticList<ElementType, maxSize>::StaticList() {
		this->size = 0;
		this->maxSize = maxSize;
		this->elements = staticElements;
}

//-------------- FIFO -----------------------------------------------------
//todo �� �����������!!!!!!!!!!!!!!!
template <typename ElementType> class MyFifo {
protected:
	volatile UInt32 size;
	volatile UInt32 head;
	volatile UInt32 tail;
	ElementType *elements;
	inline UInt32 nextIndex(UInt32 index)
	{
		if(index>=(size-1))
		{
			return 0;
		}
		return index+1;
	}
public:
	 MyFifo();
	 bool isFill();
	 bool isEmpty();
	 bool push(ElementType elem );
	 ElementType pop();
	 void clear();
};

template<typename ElementType>
inline MyFifo<ElementType>::MyFifo()
{
	size=0;
	head=0;
	tail=0;
}

template<typename ElementType>
inline bool MyFifo<ElementType>::isEmpty()
{
	return (head==tail);
}

template<typename ElementType>
inline bool MyFifo<ElementType>::isFill()
{
	return (nextIndex(head)==tail);
}

template<typename ElementType>
inline bool MyFifo<ElementType>::push(ElementType elem)
{
	if(isFill()){return false;}

	elements[head]=elem;
	head=nextIndex();
	return true;
}

template<typename ElementType>
inline ElementType MyFifo<ElementType>::pop()
{
	if(isEmpty()){elements[0];}
	UInt32 t=tail;
	tail=nextIndex();
	return elements[tail];
}

template <typename ElementType,UInt32 msize> class StaticMyFifo: public  MyFifo<ElementType>
{
	ElementType staticElements[msize];
public:
	 StaticMyFifo();

};

template<typename ElementType, UInt32 msize>
inline StaticMyFifo<ElementType, msize>::StaticMyFifo():StaticFifo()
{


}
//-------------------------------------------------------------------------


#endif /* GYCONCOMMON_UTILS_COLLECTIONS_H_ */
