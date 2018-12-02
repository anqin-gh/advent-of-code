#include <fstream>
#include <iostream>
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

int main(int argc, char const *argv[])
{
	ifstream myfile;
	myfile.open("input.txt");
	int a;
	V<int> v;
	while (myfile.is_open() && myfile >> a) {
		v.push_back(a);
	}
	myfile.close();

	USet<int> s;
	int frecuency = 0;
	int result;
	auto it = v.begin();
	bool found = false;
	while (!found) {
		frecuency += *it;
		found = s.find(frecuency) != s.end();
		if (!found) s.insert(frecuency);
		else result = frecuency;
		++it;
		if (it == v.end()) it = v.begin();
	}
	cout << result;

	return 0;
}