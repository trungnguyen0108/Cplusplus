
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int countOfString(string s, int K)
{
	int N = s.length();
	int res = 0;
	int count = 0;
	int freq[N + 1] = {0};

	freq[0] = 1;
	
	for (int i = 0; i < N; i++)
	{
		count += (s[i] - '0');
		if (count >= K)
		{
			res += freq[count - K];
		}
		freq[count]++;
	}
	return res;
}

int main()
{
	std::fstream inFile("SUBSTR.INP");
	string s;
	int binary;

	int K;
	inFile >> K;

	while(!inFile.eof())
	{
		inFile >> binary;
	}
	s = to_string(binary);

	std::ofstream outFile("SUBSTR.OUT");
	outFile << countOfString(s, K);
	outFile.close();

	inFile.close();
}
