#pragma once
// Linked list
namespace MYLIST {
	// Used for list
	class Node {
	public:
		double value;
		Node* next;
	};
	
	// List
	class MyList {
	private:
		Node* head;
		Node* current;
		static const int MAXCOUNT = 100;
		int count;
	public:
		MyList();
		MyList(double value);
		void Add(double value);
		bool IsEmpty();
		bool IsFull();
		void WalkThrow(void (*foo)(Node* el)); // Use function with all nodes
		~MyList();
	};
	

}