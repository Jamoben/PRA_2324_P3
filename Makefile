bin/testTableEntry: 	testTableEntry.cpp 	TableEntry.h
	mkdir 	-p 	bin
	g++ 	-o 	bin/testTableEntry testTableEntry.cpp

bin/testHashTable:	HashTable.h	testHashTable.cpp	Dict.h	TableEntry.h
	mkdir	-p	bin
	g++	-o	bin/testHashTable testHashTable.cpp
bin/testBSTree:		BSTree.h	testBSTree.cpp
	mkdir	-p	bin
	g++	-o	bin/testBSTree	testBSTree.cpp
bin/testBSTreeDict:	BSTreeDict.h	testBSTreeDict.cpp	BSNode.h
	mkdir	-p	bin
	g++	-o	bin/testBSTreeDict	testBSTreeDict.cpp
clean:
	rm 	-rf 	*.o 	*.gch 	bin
