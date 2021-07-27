#include <iostream>
#include "List.h"

int main(){
	std::cout << "Hello, World!" << std::endl;
	
	List<int> list;
	
	try {
		list.printHead();
	}
	catch (std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	list.addHead(2);
	list.printHead();
	std::cout << "List is empty: " << list.isEmpty() << std::endl << std::endl;
	list.addTail(5);
	list.printHead();
	list.printTail();
	list.clear();
	
	try {
		list.printHead();
		list.printTail();
	}
	catch (std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	std::cout << "List is empty: " << list.isEmpty() << std::endl << std::endl;
	
	list.addHead(5);
	list.addHead(10);
	list.addHead(8);
	std::cout << "List size: " << list.size() << std::endl;
	list.printHead();
	list.removeHead();
	list.printHead();
	
	return 0;
}
