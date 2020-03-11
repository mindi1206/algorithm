#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
using namespace std;

struct cmp {
	bool operator()(string first, string second) {
		// 길이 작은 
		int n = 0, m = 0;

		if (first.length() != second.length()) {
			return first.length() < second.length();
		}

		for (string::size_type i = 0; i < first.length(); i++) {
			char c = first[i];
			if (c - '0' < 10) {
				n += c - '0';
			}
			c = second[i];
			if (c - '0' < 10) {
				m += c - '0';
			}
		}

		if (n != m) {
			return n < m;
		}
		else {
			return first < second;
		}

		return false;
	}
};
int main() {
	deque<string> dq;
	int num;
	scanf("%d", &num);
	for (int i = 0; i < num; i++) {
		string str;
		cin >> str;
		dq.push_back(str);
	}
	sort(dq.begin(), dq.end(), cmp());
	for (int i = 0; i < num; i++) {
		cout << dq[i] << endl;
	}
}
