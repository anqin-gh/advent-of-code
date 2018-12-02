#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

template<typename T> using V = vector<T>;
template<typename T> using USet = unordered_set<T>;

template<typename T>
ostream& operator<<(ostream& os, V<T> v) {
	os << '{';
	if (v.size() > 0) {
		os << v[0];
		for (auto i = 1; i < v.size(); ++i)
			os << ", " << v[i];
	}
	os << '}';
	return os;
}

void count_letters(const string& word, int& count_2, int&count_3) {
	USet<char> seen;
	bool found_2 = false;
	bool found_3 = false;
	for (const char& c : word) {
		if (seen.find(c) == seen.end()) {
			int count = std::count(word.begin(), word.end(), c);
			if (count == 2) found_2 = true;
			else if (count == 3) found_3 = true;
			seen.insert(c);
		}
	}
	if (found_2) ++count_2;
	if (found_3) ++count_3;
}

int main(int argc, char const *argv[])
{
	ifstream myfile;
	myfile.open("input.txt");
	string s;
	int count_2 = 0;
	int count_3 = 0;
	while (myfile.is_open() && myfile >> s) {
		count_letters(s, count_2, count_3);
	}
	myfile.close();

	cout << count_2 * count_3;

	return 0;
}