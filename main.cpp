//
//  main.cpp
//  Color-Ball
//
//  Created by 정현민 on 2020/11/13.
//

#include <iostream>
#include <vector>

using namespace std;


vector<int> getOutput(int number, vector<int>& color, vector<int>& size)
{
  vector<int> output(number);
  

  
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
