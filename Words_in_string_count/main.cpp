#include <iostream>
#include <vector>

using namespace std;

int main()
{
  vector<string> words;
  string x;
  while (cin)
  {
      cin >> x;
      words.push_back(x);
  }
  for (int i = 0; i != words.size(); i++)
  {
      cout << words[i] << endl;
  }
  return 0;
}
