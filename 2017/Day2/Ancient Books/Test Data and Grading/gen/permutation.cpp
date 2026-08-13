#include <algorithm>
#include <iostream>
#include <cstdlib>
using namespace std;
const string input_secret = "f58fb993-f209-43d7-9391-c46c61f180b9";
const int MAX = 1000000;
int p[MAX];
int main(int argc, char *argv[]) 
{
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);
	for (int i = 0; i < n; i++)
		p[i] = i;
	while (k--)
		next_permutation(p, p + n);
	cout << input_secret << "\n";
	cout << n << " " << 0 << "\n";
	for (int i = 0; i < n; i++)
	{
		cout << p[i];
		if (i + 1 < n)
			cout << " ";
		else
			cout << "\n";
	}
	return 0;
}
