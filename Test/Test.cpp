// HashLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class KeyValue
{
public:
	char* key;
	int value;
	KeyValue* next;

	KeyValue()
	{
		key = NULL;
		value = -1;
	}


	KeyValue(char* pkey, int pvalue, KeyValue* pnext)
	{
		key = pkey;
		value = pvalue;
		next = pnext;
	}
};

int hashStrings(char* key)
{
	char a = key[0];
	int hashresult = 0;
	int i = 1;
	while (a != '\0')
	{
		hashresult += (int)a - 48;
		a = key[i++];
	}
	return hashresult;
}


class HashTable
{
	KeyValue* table;
	int N;

public:
	HashTable(int pN)
	{
		table = new KeyValue[pN];
		N = pN;
	}
	void Add(char* key, int value)
	{
		int hashkey = hashStrings(key);
		if (table[hashkey].key == NULL)
		{
			table[hashkey] = KeyValue(key, value, NULL);
		}
		else
		{
			KeyValue newKeyValue = KeyValue(key, value, &table[hashkey]);
			table[hashkey] = newKeyValue;
		}
	}

	int Find(char* key)
	{
		int hashkey = hashStrings(key);

		while (table[hashkey].key == key)
		{
			table[hashkey].next;
			return table[hashkey].value;
		}

	}
};


int main()
{
	HashTable* ht = new HashTable(1000);
	ht->Add("cba", 150000);
	ht->Add("abd", 175000);

	cout << "cba" << " " << ht->Find("cba") << endl;
	cout << "abd" << " " << ht->Find("abd") << endl;
	return 0;
}