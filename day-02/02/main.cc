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

// function to compare how different 2 strings are 
// (by how many chars in the same position they differ)
int how_different(const string& word1, const string& word2) {
	int diff_letters = 0;
	for (auto i = 0; i < word1.size(); ++i) {
		if (word1[i] != word2[i]) ++diff_letters;
		if (diff_letters > 1) return -1;
	}
	return diff_letters;
}

string remove_difference(const string& word1, const string& word2) {
	string result;
	for (auto i = 0; i < word1.size(); ++i) {
		if (word1[i] == word2[i]) result+= word1[i];
	}
	return result;
}

int main(int argc, char const *argv[])
{
	ifstream myfile;
	myfile.open("input.txt");
	string s;
	V<string> words;
	while (myfile.is_open() && myfile >> s) {
		words.push_back(s);
	}
	myfile.close();
	auto w_size = words.size();
	for (auto i = 0; i < w_size; ++i) {
		for (auto j = i; j < w_size; ++j) {
			if (i < w_size - 1) {
				string w1 = words[i];
				string w2 = words[j];
				if (how_different(w1, w2) == 1) {
					string solution = remove_difference(w1, w2);
					cout << solution;
					break;
				}
			}
		}
	}

	return 0;
}
