//
//  main.cpp
//  Color-Ball
//
//  Created by 정현민 on 2020/11/13.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<pair<int, int>> makePairVector(int number, vector<int>& color, vector<int>& size)
{
  vector<pair<int, int>> size_color_pair(number);
  
  for(int i = 0; i < number; i++)
  {
    size_color_pair[i] = make_pair(size[i], color[i]);
  }
  return size_color_pair;
}



vector<int> getOutput(int number, vector<int>& color, vector<int>& size)
{
  vector<int> output(number);
  
  vector<pair<int, int>> size_color_pair = makePairVector(number, color, size);
  
  sort(size_color_pair.begin(), size_color_pair.end());
  
  for(int i = 0 ; i < number; i++)
  {
//    cout << size_color_pair[i].first << ", " << size_color_pair[i].second << endl;
    for (int j = i + 1; j < number; j++)
    {

    }
  }
  
  
  return output;
}

int main()
{
  int number;
  cin >> number;
  
  vector<int> color(number);
  vector<int> size(number);
  
  for(int i = 0; i < number; i++)
    cin >> color[i] >> size[i];
  
  vector<int> output = getOutput(number, color, size);
  for(int i = 0; i < number; i++)
    cout << output[i] << endl;
  
  return 0;
}
