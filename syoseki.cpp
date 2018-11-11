#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

struct person {
  int expence;
  std::string name;

  bool operator<( const person& right ) const {
    return expence > right.expence;
    }
};


int main() {
  int i, j;
  int N, M;
  std::string name;
  int expence;
  std::vector<person> people;

  std::cin >> N;

  for(i = 0; i < N; i++) {
    std::cin >> name;
    person p;
    p.name = name;
    p.expence = 0;
    people.push_back(p);
  }

  std::cin >> M;
  for(i = 0; i < M; i++) {
    std::cin >> name >> expence;
    for(j = 0; j < N; j++) {
      if(people[j].name == name) {
	people[j].expence += expence;
      }
    }
  }

  std::sort(people.begin(), people.end());

  for(i = 0; i < N; i++) {
    std::cout << people[i].name << std::endl;
  }
  
}
