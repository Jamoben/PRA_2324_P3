#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTree<TableEntry<V>>* tree;

    public:
        
	/*MÉTODOS DE BSTREEDICT.H*/
        
	BSTreeDict(){
	    tree = new BSTree<TableEntry<V>>;
	}

	~BSTreeDict(){
	    delete tree;
	}

	friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
	    return out << *bs.tree;
	}

	V operator[](std::string key){
	    return tree->search(TableEntry<V>(key)).value;
	}

	/*MÉTODOS DE DICT.H*/

	void insert(std::string key, V value) override{
	    tree->insert(TableEntry<V>(key,value));
	}
	
	V search(std::string key) override{
	    return tree->search(TableEntry<V>(key)).value;
	}
	
	V remove(std::string key) override{
	    V val = tree->search(TableEntry<V>(key)).value;
	    tree->remove(TableEntry<V>(key));
	    return val;
	}
	
	int entries() const override{
	    return tree->size();
	}
};

#endif
