#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

template<typename T> using V = vector<T>;

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
	myfile.open("parsed_input.txt");

	auto size = 1000;
	auto times_visited	= V<V<int>> (size, V<int> (size, 0));		// matrix with count of overlaps per square

	int overlapping_sqares = 0;
	int id, x, y, w, h;
	while (myfile.is_open() && myfile >> id >> x >> y >> w >> h) {
		for (auto i = x; i < x + w; ++i) {
			for (auto j = y; j < y + h; ++j) {
				++times_visited[i][j];
			}
		}
	}
	for (auto i = 0; i < size; ++i) {
		for (auto j = 0; j < size; ++j) {
			if (times_visited[i][j] > 1) ++overlapping_sqares;
		}
	}
	myfile.close();
	cout << overlapping_sqares;

	return 0;
}
