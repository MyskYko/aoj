#include <iostream>
using namespace std;

int main()
{
  int n,rank;
  char mark;
  bool cards[52] = {0};
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> mark >> rank;
    switch(mark) {
    case 'S':
      break;
    case 'H':
      rank += 13;
      break;
    case 'C':
      rank += 13*2;
      break;
    case 'D':
      rank += 13*3;
      break;
    default:
      break;
    }
    cards[rank-1] = 1;
  }
  for(int i = 0; i < 52; i++) {
    if(cards[i] == 0) {
      switch(i/13) {
      case 0:
	cout << "S";
	break;
      case 1:
	cout << "H";
	break;
      case 2:
	cout << "C";
	break;
      case 3:
	cout << "D";
	break;
      default:
	break;
      }
      cout << " ";
      cout << i%13+1 << endl;
    }
  }
  
  return 0;
}
