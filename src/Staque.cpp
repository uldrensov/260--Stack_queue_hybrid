#include <new>
using namespace std;
#include "Staque.h"

//default constructor
Staque::Staque()
:stackptr(0), tailptr(0) //no elements in the default staque; null pointers
{}


//copy constructor
Staque::Staque(const Staque& original){
	stackptr = 0;
	tailptr = 0;

	if (!original.emptyflag()){
		stackptr = new Staque::Node(original.gettop(), original.getorder()); //first node gets data from the existing staque's top-node
		tailptr = stackptr; //with only 1 node, the top pointer is the same as the bottom pointer by default
		Staque::nodeptr walkingstick = stackptr, seeingdog = original.stackptr->next, footprint = stackptr; //three pointers for nav purposes

		while (seeingdog != 0){ //while more nodes exist in the original staque
			walkingstick->next = new Staque::Node(seeingdog->data, seeingdog->order); //construct the next node with data from the original staque's next node
			footprint = walkingstick; //save the current walking stick before moving it forward
			walkingstick = walkingstick->next; //move the walking stick to the address of the newly constructed node
			walkingstick->prev = footprint; //the previously saved address becomes the "prev" pointer (not technically needed on the even/top half of the staque, but whatever)
			tailptr = walkingstick; //move the bottom pointer to the newest copied node
			seeingdog = seeingdog->next; //scout out the next node in the original staque
		}
	}
}


//destructor
Staque::~Staque(){
	Staque::nodeptr currentp = stackptr, nextp;

	while (currentp != 0){
		nextp = currentp->next; //save the address of the next node
		delete currentp; //kill the current node
		currentp = nextp; //move the pointer up to the saved address
	}
}


//assignment operator overload
const Staque& Staque::operator=(const Staque& rightside){
	if (this != &rightside){ //if a staque isn't using this function on itself
		this-> ~Staque(); //call the destructor to force a wipe before doing anything

		if (rightside.emptyflag()){ //if rightside is an empty staque, the solution is simple
			stackptr = 0;
			tailptr = 0;
		}
		else{
			stackptr = new Staque::Node(rightside.gettop(), rightside.getorder()); //same procedure as the copy constructor
			tailptr = stackptr;
			Staque::nodeptr walkingstick = stackptr, seeingdog = rightside.stackptr->next, footprint = stackptr;

			while (seeingdog != 0){
				walkingstick->next = new Staque::Node(seeingdog->data, seeingdog->order);
				footprint = walkingstick;
				walkingstick = walkingstick->next;
				walkingstick->prev = footprint;
				tailptr = walkingstick;
				seeingdog = seeingdog->next;
			}
		}
	}
	return *this; //return the copied staque
}


//empty checker
bool Staque::emptyflag() const{
	return (stackptr == 0); //if a top node does not exist (AKA is null), return true
}


//"top" element accessor
	//retrieves the highest order element, either from the top or the bottom
element Staque::top() const{
	if (!emptyflag()){
		if ((stackptr->order) > (tailptr->order)) //determine whether to take from the top or the bottom based on node order
			return (stackptr->data);
		else return (tailptr->data);
	}
	else{ //generate and return random garbage if this is attempted on an empty staque
		cerr << "**Empty stack; returning garbage**\n";
		element* temp = new(element); //new dynamically generated element
		element garbage = *temp; //copy it to a volatile variable
		delete temp; //kill the original garbage
		return garbage; //return the copy
	}
}


//true top element accessor
	//retrieves an element from the actual top of the staque
element Staque::gettop() const{
	return (stackptr->data);
}


//order accessor
int Staque::getorder() const{
	return (stackptr->order);
}


//stack push
void Staque::push(const element& value){
	if (emptyflag()){ //special treatment for the very first node push
		stackptr = new Staque::Node(value, 1); //initial order number is 1
		tailptr = stackptr;
	}
	else{
		int oldorder;
		if ((stackptr->order) > (tailptr->order)) //seek the current highest order node
			oldorder = (stackptr->order);
		else oldorder = (tailptr->order);
		int neworder = oldorder + 1; //the newly pushed node should have a higher order than all existing nodes

		if (value % 2 == 0) //if pushing an even number, send it to the top
			stackptr = new Staque::Node(value, neworder, stackptr, 0); //pointed by the new stack pointer, and points where the old one did
		else{ //if pushing an odd number, send it to the bottom
			Staque::nodeptr ptr = tailptr; //save the old tail pointer
			tailptr = new Staque::Node(value, neworder, 0, tailptr); //pointed by the old tail pointer, and points where the old one did
			ptr->next = tailptr; //ensure that the new node is doubly linked (only required for the odd/bottom half of the staque)
		}
	}
}


//stack pop
void Staque::pop(){
	if (!emptyflag()){
		if ((stackptr->order) > (tailptr->order)){ //if the highest order node is at the top
			Staque::nodeptr ptr = stackptr; //save the top node's address for imminent deletion
			stackptr = stackptr->next; //advance the stack pointer
			delete ptr; //push the saved top node
		}
		else{ //if the highest order node is at the bottom
			Staque::nodeptr ptr = tailptr;
			tailptr = tailptr->prev; //de-advance the tail pointer
			delete ptr;
			tailptr->next = 0; //ensure that the new bottom node does not point anywhere "next"
		}
	}
	else
		cerr << "**Empty stack; nothing to pop**\n";
}


//display function
void Staque::display(ostream& out) const{
	Staque::nodeptr ptr;
	for (ptr = stackptr; ptr != 0; ptr = ptr->next) //output all elements in top-down order
		out << ptr->data << endl;
}
