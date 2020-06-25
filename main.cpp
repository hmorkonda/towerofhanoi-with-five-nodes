#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class hanoi {
public:
	hanoi();
	void startToDest(string s, string a1, string a2, string a3, string d, int n);
	void startToA3(string s, string a1, string a2, string a3, int n);
	void twohops(string a1, string a2, string a3, int n);
	void onehop(string a1, string a2, string a3, int n);
	void A1ToDest(string a1, string a2, string a3, string d, int n);
	int count;
	void move(string from, string to);
};
int main() {
	int disks = 0;
	cout << "enter number of disks: ";
	cin >> disks;
	hanoi obj;
	obj.startToDest("Start", "A1", "A2", "A3", "Dest", disks);
	cin.ignore();
	cin.get();
	return 0;
}

hanoi::hanoi() { count = 0; }

void hanoi::startToDest(string s, string a1, string a2, string a3, string d, int n) {
	if (n == 1) {
		move(s, a1);
		move(a1, a2);
		move(a2, a3);
		move(a3, d);
	}
	else if (n >= 2) {
		startToA3(s, a1, a2, a3, n - 1);
		move(s, a1);
		move(a1, a2);
		onehop(a3, a1, a2, n - 1);
		move(a2, a3);
		move(a3, d);
		A1ToDest(a1, a2, a3, d, n - 1);
	}
}

void hanoi::startToA3(string s, string a1, string a2, string a3, int n) {
	if (n == 1) {
		move(s, a1);
		move(a1, a2);
		move(a2, a3);
	}
	else if (n >= 2) {
		startToA3(s, a1, a2, a3, n - 1);
		move(s, a1);
		move(a1, a2);
		onehop(a3, a1, a2, n - 1);
		move(a2, a3);
		twohops(a1, a2, a3, n - 1);
	}
}
void hanoi::twohops(string a1, string a2, string a3, int n) {
	if (n == 1) {
		move(a1, a2);
		move(a2, a3);
	}
	else if (n >= 2) {
		twohops(a1, a2, a3, n - 1);
		move(a1, a2);
		onehop(a3, a1, a2, n - 1);
		move(a2, a3);
		twohops(a1, a2, a3, n - 1);
	}

}
void hanoi::A1ToDest(string a1, string a2, string a3, string d, int n) {

	if (n == 1) {
		move(a1, a2);
		move(a2, a3);
		move(a3, d);
	}
	else if (n >= 2) {
		twohops(a1, a2, a3, n - 1);
		move(a1, a2);
		onehop(a3, a1, a2, n - 1);
		move(a2, a3);
		move(a3, d);
		A1ToDest(a1, a2, a3, d, n - 1);
	}
}
void hanoi::onehop(string a1, string a2, string a3, int n) {
	if (n == 1) {
		move(a1, a2);
	}
	else if (n >= 2) {
		twohops(a1, a2, a3, n - 1);
		move(a1, a2);
		twohops(a3, a1, a2, n - 1);
	}
}

void hanoi::move(string from, string to) {
	count++;	
	cout << count << ": " << "Move disk from " << from << " to " << to << endl;
}
