#include <iostream>
#include <string>
#include <vector>
using namespace std;

void TableBuilding(string p, vector<int>& table)
{
	int m = p.size();
	table.push_back(-1);
	table.reserve(m);
	int k = -1;
	for(int i = 1; i < m; i++)
	{
		while(k > -1 && p[k+1] != p[i])
			k = table[k];
		if(p[k+1] == p[i])
			k++;
		table[i] = k;
	}

}

vector<int>& kmp(string p, string t)
{
	int n = t.size(); //length for the text to be matched
	int m = p.size(); //length for the matching pattern
	vector<int> result;
	vector<int> table;
	TableBuilding(p, table);
	int q = -1; //last index of character matched 
	for(int i = 0; i < n; i++)
	{
		while(q > -1 && p[q+1] != t[i])
			q = table[q];
		if(p[q+1] == t[i])
			q++;
		if(q == m-1)
		{
			result.push_back(i-m+1);
			cout << "Pattern occurs with start point " << i-m+1 << ".\n";
			q = table[q];
		}
	}
}

int main(int argc, char* argv[])// for test
{
	kmp(argv[1], argv[2]);
	return 0;
}
