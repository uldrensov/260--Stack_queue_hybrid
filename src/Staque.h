#include <iostream>
using namespace std;

#ifndef STAQUE
#define STAQUE

typedef int element;

class Staque{
	public:
		//constructors
		Staque();
		Staque(const Staque& original);
		
		//destructor
		~Staque();
		
		//assignment operator overload
		const Staque& operator=(const Staque& rightside);
		
		//empty checker
		bool emptyflag() const;
		
		//"top" element accessor
		element top() const;
		
		//true top element accessor
		element gettop() const;
		
		//order accessor
		int getorder() const;
		
		//stack push
		void push(const element& value);
		
		//stack pop
		void pop();
		
		//display function
		void display(ostream& out) const; 
		
	private:
		//node class
		class Node{
			public:
				//data members
				element data;
				int order;
				Node* next;
				Node* prev;
				
				//all-in-one constructor
				Node(element value, int ord, Node* to = 0, Node* fro = 0)
				:data(value), order(ord), next(to), prev(fro)
				{}
		};
		
		//node pointer definition
		typedef Node* nodeptr;
		
		//data members
		nodeptr stackptr, tailptr;
};

#endif
