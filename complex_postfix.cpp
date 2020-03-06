#include <iostream>
#include <utility>
#include <stack>
using namespace std;

// main function executes as soon as program is executed
int main() {
	// mode is the type of operation that is being performed
	char mode = 'Z';
	long long r1, r2;
	char op;
	stack < pair<long long, long long> > numbers;

	while (mode != 'S') {
		cin >> mode;
		// this mode to store complex number in stack
		if (mode == 'V') {
			cin >> r1 >> r2;
			pair <long long, long long> pair1;
			pair1.first = r1;
			pair1.second = r2;
			numbers.push(pair1);
		}

		// B represents when 2 number operations are executed
		else if (mode == 'B') {
			cin >> op;
			// 2 numbers addition case
			if (op == '+') {
				pair <long long, long long> topnum1 = numbers.top();
				numbers.pop();
				pair <long long, long long> topnum2 = numbers.top();
				numbers.pop();
				long long r1 = topnum1.first; 
				long long c1 = topnum1.second;
				long long r2 = topnum2.first; 
				long long c2 = topnum2.second; 

				pair <long long, long long> newtopnum;
				newtopnum.first = r1 + r2;
				newtopnum.second = c1 + c2;
				numbers.push(newtopnum);
			}

			// 2 numbers subtraction case
			else if (op == '-') {
				pair <long long, long long> topnum1 = numbers.top();
				numbers.pop();
				pair <long long, long long> topnum2 = numbers.top();
				numbers.pop();
			 	long long r1 = topnum1.first; 
			 	long long c1 = topnum1.second;
				long long r2 = topnum2.first;
				long long c2 = topnum2.second; 

				pair <long long, long long> newtopnum;
				newtopnum.first = r1 - r2;
				newtopnum.second = c1 - c2;
				numbers.push(newtopnum);		
			}

			// 2 numbers multiplication case
			else if (op == '*') {
				pair <long long, long long> topnum1 = numbers.top();
				numbers.pop();
				pair <long long, long long> topnum2 = numbers.top();
				numbers.pop();
				long long r1 = topnum1.first; 
				long long c1 = topnum1.second;
				long long r2 = topnum2.first; 
				long long c2 = topnum2.second; 

				pair <long long, long long> newtopnum;
				newtopnum.first = ((r1*r2)-(c1*c2));
				newtopnum.second = ((r1*c2)+(c1*r2));
				numbers.push(newtopnum);
			}
		}

		// U represents when 1 number operations are executed
		else if (mode == 'U') {
			cin >> op;
			// To find negative of a number
			if (op == '-') {
				pair <long long, long long> topnum = numbers.top();
				numbers.pop();
				long long p1 = -topnum.first;
				long long p2 = -topnum.second;
				pair <long long, long long> newtopnum;
				newtopnum.first = p1;
				newtopnum.second = p2;

				numbers.push(newtopnum);
			}

			// case to find conjugate of a complex number
			else if (op == 'c') {
				pair <long long, long long> topnum = numbers.top();
				numbers.pop();
				long long p1 = topnum.first;
				long long p2 = -topnum.second;
				pair <long long, long long> newtopnum;
				newtopnum.first = p1;
				newtopnum.second = p2;

				numbers.push(newtopnum);
			}
		}	
	}

	cout << (numbers.top()).first << " " << (numbers.top()).second << endl;

	return 0;
}