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

template<typename T>
ostream& operator<<(ostream& os, USet<T> s) {
	if (!s.empty()) {
		for (auto it = s.begin(); it != s.end() ; ++it)
			os << *it << " ";
	}
	return os;
}

int main(int argc, char const *argv[])
{
	ifstream myfile;
	myfile.open("parsed_input.txt");

	auto size = 1000;
	auto ids			= V<V<int>> (size, V<int> (size, 0)); // matrix with ids (later claims overlap earlier)
	auto times_visited	= V<V<int>> (size, V<int> (size, 0)); // matrix with count of overlaps per square
	auto exclude = USet<int>(); // set with ids that have been overlapped, and thus, to be excluded 

	int id, x, y, w, h;
	while (myfile.is_open() && myfile >> id >> x >> y >> w >> h) {
		for (auto i = x; i < x + w; ++i) {
			for (auto j = y; j < y + h; ++j) {
				if (ids[i][j] != 0) {
					exclude.insert(id);
					exclude.insert(ids[i][j]);
				}
				ids[i][j] = id;
				++times_visited[i][j];
			}
		}
	}
	myfile.close();

	USet<int> seen;
	for (auto i = 0; i < size; ++i) {
		for (auto j = 0; j < size; ++j) {
			if (times_visited[i][j] == 1 && (exclude.find(ids[i][j]) == exclude.end()))  
				seen.insert(ids[i][j]);
		}
	}
	cout << seen;

	return 0;
}
