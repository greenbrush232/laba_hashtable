#pragma once
#include "table.h"
#include <list>
#include <string>
#include <vector>

int ConvolutionFunc(int key, int size){
	return key % size;
}

int ConvolutionFunc(std::string key, int size){
	int res = 0;
	for (int i = 0; i < key.size(); i++)
		res += key[i];
	return res % size;
}

template<class Key>
int OwnConvolutionFunc(Key key, int size) {
	//ввести функцию
	return 0;
}

template<class Key, class Data>
class HashTable {
protected:
	std::vector<std::list<Record<Key, Data> > > dataVector;
	int size;
	int(*convolutionFunc)(Key, int);
public:
	HashTable(int Size = 10, bool _ownConvolutionFunc = 0) : size(Size) {
		dataVector.resize(size);
		if (_ownConvolutionFunc)
			convolutionFunc = OwnConvolutionFunc;
		else convolutionFunc = ConvolutionFunc;
	}

	void Add(Key key, Data data){
		int index = convolutionFunc(key, size);
		dataVector[index].push_back(Record<Key, Data>(key, data));
	}

	Data Find(Key key){
		int index = convolutionFunc(key, size);
		typename std::list<Record<Key, Data> >::iterator it = dataVector[index].begin();
		while (it->key != key)
			it++;
		return it->data;
	}
	int getSize() const { return size; }
};
