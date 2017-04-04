#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

const int NO_MEMBER = -1;

struct Elephant{
  int id;
  int weight;
  int IQ;
};

bool cmpWeight(const Elephant &a, const Elephant &b){
  return a.weight <= b.weight;
}

void printLIS(const vector<Elephant> &elephants,  
              const vector<int> &LISprevious,
              int index ){
  if( LISprevious[index] != NO_MEMBER ) printLIS( elephants, LISprevious, LISprevious[index] );
  printf("%d\n", elephants[index].id);
}

int main(){
  vector<Elephant> elephants;
  Elephant e;
  while( scanf("%d%d", &(e.weight), &(e.IQ)) != EOF ){
    e.id = elephants.size() + 1;
    elephants.push_back(e);
  }

  sort(elephants.begin(), elephants.end(), cmpWeight);

  vector<int> LISlength(elephants.size(), 1);
  vector<int> LISprevious(elephants.size(), NO_MEMBER);

  int maxLength = 0, maxIndex = NO_MEMBER;
  for( int i = 0 ; i < elephants.size() ; ++i ){
    for( int j = i + 1 ; j < elephants.size() ; ++j ){
      if( elephants[i].weight < elephants[j].weight &&
          elephants[i].IQ > elephants[j].IQ ){
        if( LISlength[i] + 1 > LISlength[j] ){
          LISlength[j] = LISlength[i] + 1;
          LISprevious[j] = i;
        }
      }
    }
    if( LISlength[i] > maxLength ){
      maxLength = LISlength[i];
      maxIndex = i;
    }
  }

  printf("%d\n", maxLength);
  printLIS(elephants, LISprevious, maxIndex);

  return 0;
}
