#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char const *argv[])
{
	ifstream myfile;
	myfile.open("input.txt");
	int a, total = 0;
	while (myfile.is_open() && myfile >> a) {
		total += a;
	}
	myfile.close();
	cout << total;

	return 0;
}