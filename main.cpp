//
//  main.cpp
//  Color-Ball
//
//  Created by 정현민 on 2020/11/13.
//

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


struct Ball
{
  int color;
  int size;
  int index;
  int catchable_size;
};

struct SumByColor
{
  int color;
  int sum;
};

bool compare_size(const Ball& first_ball, const Ball& secont_ball)
{
  if(first_ball.size > secont_ball.size)
  {
    return false;
  }
  else
  {
    return true;
  }
}

vector<int> getOutput(int number, vector<int>& color_vec, vector<int>& size_vec)
{
  vector<int> output_vec(number);

  vector<Ball> ball_vec(number);
  for(int i = 0; i < number; i++)
  {
    ball_vec[i].color = color_vec[i];
    ball_vec[i].size = size_vec[i];
    ball_vec[i].index = i;
  }
  
  sort(ball_vec.begin(), ball_vec.end(), compare_size);
    
  int sum = 0;
  
  map<int, int> color_sum_map;
  for(auto& ball : ball_vec)
  {
    output_vec[ball.index] += sum - color_sum_map[ball.color];
    sum += ball.size;
    color_sum_map[ball.color] += ball.size;
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
  
  vector<int> output = getOutput(number, color_vec, size_vec);
  for(int i = 0; i < number; i++)
    cout << output[i] << "\n";
  
  return 0;
}
