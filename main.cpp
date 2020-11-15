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
};

bool compare_size(const Ball& first_ball, const Ball& secont_ball)
{
  if (first_ball.size == secont_ball.size)
  {
    return first_ball.color < secont_ball.color;
  }
  else
  {
    return first_ball.size < secont_ball.size;
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
  
//  for(auto ball : ball_vec)
//  {
//    cout << " -color : " << ball.color;
//    cout << " -size : " << ball.size;
//    cout << " -index : " << ball.index;
//    cout << endl;
//  }
  
  int sum = 0;
  map<int, int> color_sum_map;
  for(int i = 0; i < number; i++)
  {
    for(int j = i; j < number; j++)
    {
      if (ball_vec[i].size != ball_vec[j].size)
      {
        break;
      }
      sum += ball_vec[j].size;
      color_sum_map[ball_vec[j].color] += ball_vec[j].size;
    }
    output_vec[ball_vec[i].index] = sum - color_sum_map[ball_vec[i].color];
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
    cout << output[i] << endl;
  
  return 0;
}
