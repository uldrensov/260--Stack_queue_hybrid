#include "Staque.h"
#include <iostream>
using namespace std;
#include "Staque.h"

int main(){
	//example 1 (in the assignment prompt)
	Staque alpha = Staque();
	cout << "Staque ALPHA generated.\n";

	alpha.push(1);
	alpha.push(3);
	alpha.push(2);
	alpha.push(4);
	alpha.push(6);
	alpha.push(8);
	alpha.push(9);
	cout << "Pushed 1,3,2,4,6,8,9. Displaying staque contents:\n";
	alpha.display(cout);

	alpha.pop();
	alpha.pop();
	alpha.pop();
	cout << "Popped three values, updating staque display:\n";
	alpha.display(cout);

	cout << "End sample 1. Preparing next sample...\n\n\n\n";


	//example 2
	Staque beta = Staque();
	cout << "Staque BETA generated.\n";

	beta.push(0);
	beta.push(9);
	beta.push(8);
	beta.push(3);
	beta.push(2);
	beta.push(6);
	beta.push(5);
	cout << "Pushed 0,9,8,3,2,6,5. Displaying staque contents:\n";
	beta.display(cout);

	Staque gamma = beta;
	cout << "Copy constructor called. Staque GAMMA shall mirror staque BETA.\n";

	cout << "Displaying contents of staque GAMMA:\n";
	gamma.display(cout);

	gamma.pop();
	gamma.pop();
	gamma.pop();
	gamma.pop();
	cout << "Popped four values from GAMMA, updating staque display:\n";
	gamma.display(cout);

	cout << "End sample 2. Preparing final sample...\n\n\n\n";


	//example 3
	Staque delta = Staque();
	Staque epsilon = Staque();
	cout << "Staques DELTA and EPSILON generated.\n";

	delta.push(4);
	delta.push(3);
	delta.push(0);
	delta.push(8);
	delta.push(1);
	cout << "Pushed to DELTA 4,3,0,8,1. Displaying staque contents:\n";
	delta.display(cout);

	epsilon = delta;
	cout << "Overloaded assignment operator called. Staque EPSILON shall mirror staque DELTA.\n";

	cout << "Displaying contents of staque EPSILON:\n";
	epsilon.display(cout);

	epsilon.pop();
	epsilon.pop();
	epsilon.pop();
	cout << "Popped three values from EPSILON, updating staque display:\n";
	epsilon.display(cout);

	cout << "End of simulation.\n";

	return 0;
}
