//
//  main.cpp
//  Color-Ball
//
//  Created by 정현민 on 2020/11/13.
//

#include <iostream>
#include <vector>

using namespace std;


vector<int> getOutput(int number, vector<int>& color_vec, vector<int>& size_vec)
{
  vector<int> output_vec(number);
  
  for(int i = 0; i < number; i++)
  {
    for(int j = 0; j < number; j++)
    {
      if (color_vec[i] != color_vec[j] && size_vec[i] > size_vec[j])
      {
        output_vec[i] += size_vec[j];
      }
    }
  }
  
  return output_vec;
}

int main()
{
  int number;
  cin >> number;
  
  vector<int> color_vec(number);
  vector<int> size_vec(number);
  
  for(int i = 0; i < number; i++)
    cin >> color_vec[i] >> size_vec[i];
  
  vector<int> output_vec = getOutput(number, color_vec, size_vec);
  for(int i = 0; i < number; i++)
    cout << output_vec[i] << endl;
  
  return 0;
}
