#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h"

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;
	
	int h(string key){
    	    int suma = 0;
    	    for(int i = 0; i < key.length(); i++)
		suma += int(key.at(i));

    	    return suma % max;
  	}
	


    public:
        /*MÉTODOS DE HASHTABLE.H*/
	
    	HashTable(int size){
    	    table = new ListLinked<TableEntry<V>>[size]; 
    	    n = 0;
    	    max = size;
  	} 
	
	~HashTable(){
	    delete[] table;
	}

	int capacity(){return max}

	friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
		out << "HashTable [entries: " << th.entries() << ", capacity: " << th.capacity() << "]" << endl;
		out << "======================" << endl << endl;
		for(int i = 0; i < th.capacity; i++){
		    out << "== Cubeta " << i << " ==" << endl << endl;
		    out << "List => [ " << endl;
		    for(j = 0; j < th.table[i].size(); j++){
		    	out << "    " << th.table[i].get(j) << endl;
		    }
		out << "]" << endl;
		}
	return out;
	}

	V operator[](std::string key){
	    int pos = h(key);
	    return search(key);
	}
	
  	/*MÉTODOS DE DICT.H*/

	V search(string key) override{ //Busca el valor correspondiente a key
    	    int pos = h(key);
    	    for(int i = 0; i < table[pos].size(); i++){
      	        if(table[pos].get(i).key == key){
        	return table[pos].get(i).value;
      		}
       	    }
    	throw runtime_error("Key not found!\n");
  	}
 
	void insert(std::string key, V value) override{
		if(){}
	}
        
};

#endif
