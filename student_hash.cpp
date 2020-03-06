#include <iostream>
#include <unordered_set>
using namespace std;

// Declaration of the student struct
struct StudentRecord {
	string name;
	int id, grade;

	// Operator overload of == to check if the hash is same
	bool operator ==(const StudentRecord & obj) const {
		if (id == obj.id) {
			return true;
		}
		else {
			return false;
		}			
	}
};

// Defining new hash function to store structs in unordered_set
namespace std {
	template<>
	struct hash<StudentRecord> {
		size_t operator()(const StudentRecord& obj) const {
			return hash<int>()(obj.id);
		}
	};
}


int main() {
	unordered_set <StudentRecord> table;
	
	// Declaration of all input variables required
	char mode = 'B';
	std::string name;
	int ID;
	int grade;
	char qmode;

	// Mode defines the kind of operation that is performed
	while (mode !='S') {		
		cin >> mode;
		int flag=0;		
		if (mode == 'I') {
			cin >> name >> ID >> grade;
			auto res = table.insert({name, ID, grade});

			if (res.second == false) {
				cout << "Error: Cannot insert duplicate ID" << endl;
			}		
		}

		else if (mode == 'R') {
			cin >> ID;
			for (StudentRecord i:table) {
				if (i.id == ID) {
					table.erase(i);
					flag = 1;
				}

			}

			if (flag == 0) {
				cout << "Error: Cannot remove non-existent ID" << endl;
			}

		}

		else if (mode == 'Q') {
			cin >> qmode;
			
			if (qmode == 'n') {
				cin >> name;
				for (StudentRecord i:table) {
					if (i.name == name) {
						cout << "Name: " << i.name << ", ID: " << i.id << ", " << "Grade: " << i.grade << endl;
						flag = 1; 
					}
				}
			}

			else if (qmode == 'g') {
				cin >> grade;
				for (StudentRecord i:table) {
					if (i.grade == grade) {
						cout << "Name: " << i.name << ", ID: " << i.id << ", " << "Grade: " << i.grade << endl;
						flag = 1;
					}
				}
			}

			else if (qmode == 'i') {
				cin >> ID;
				for (StudentRecord i:table) {
					if (i.id == ID) {
						cout << "Name: " << i.name << ", ID: " << i.id << ", " << "Grade: " << i.grade << endl;
						flag = 1;
					}
				}
			}

			if (flag == 0) {
				cout << "Error: No matches found" << endl;
			}

		}
	}
	return 0;
}