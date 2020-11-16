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
  return first_ball.size < secont_ball.size;
}

vector<int> getOutput(int number, vector<int>& color_vec, vector<int>& size_vec)
{
  /* Ball vector 선언 후 값 대입 */
  vector<Ball> ball_vec(number);
  for(int i = 0; i < number; i++)
  {
    ball_vec[i].color = color_vec[i];
    ball_vec[i].size = size_vec[i];
    ball_vec[i].index = i;
  }
  
  /* 공을 size 오름차순으로 정렬 */
  sort(ball_vec.begin(), ball_vec.end(), compare_size);
  
  /* prefix sum */
  int sum = 0;
  int i = 0;
  int j = 0;
  map<int, int> color_sum_map;
  vector<int> output_vec(number);
  while(i < number)
  {
    while(ball_vec[i].size > ball_vec[j].size)
    {
      sum += ball_vec[j].size;
      color_sum_map[ball_vec[j].color] += ball_vec[j].size;
      j++;
    }
    output_vec[ball_vec[i].index] = sum - color_sum_map[ball_vec[i].color];
    i++;
  }
  
  return output_vec;
}

int main()
{
//  ios_base :: sync_with_stdio(false);
//  cin.tie(NULL);
//  cout.tie(NULL);
  int number;
  cin >> number;
  
  vector<int> color_vec(number);
  vector<int> size_vec(number);
  
  for(int i = 0; i < number; i++)
  {
//    scanf("%d %d", &color_vec[i], &size_vec[i]);
    cin >> color_vec[i] >> size_vec[i];
  }
  
  vector<int> output_vec = getOutput(number, color_vec, size_vec);
  for(int i = 0; i < number; i++)
  {
//    printf("%d\n", output_vec[i]);
    cout << output_vec[i] << "\n";
  }
  
  return 0;
}
