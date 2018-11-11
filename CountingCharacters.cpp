#include <iostream>
using namespace std;

int main()
{
  int c;
  int count[26] = {0};
  while(c = cin.get(), c != EOF) {
    if(c >= 'A' && c <= 'Z') count[c-'A']++;
    else if(c >= 'a' && c <= 'z') count[c-'a']++;
  }
  for(int i = 0; i < 26; i++) {
    cout << (char)(i+'a') << " : " << count[i] << endl;
  }
  return 0;
}
