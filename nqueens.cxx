//
//  nqueens.h
//  datalgo
//  Created by Iyed Bennour on 07/12/2014.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <set>
#include <cmath>


std::set<std::vector<int>> solve(int n)
{
	
  class place_queens
  {
    int queens;

  public:

    place_queens(int _n): queens(_n){}

    std::set<std::vector<int>> operator()(int moves)
    {
      if(moves == 0) return std::set<std::vector<int>>{{}};
      else {
        std::set<std::vector<int>> solutions = this->operator()(moves - 1);
        std::set<std::vector<int>> nexts;
        for (auto v : solutions) {
          for (auto col = 0; col < queens; ++col) {
            if (is_safe(col, v)) {
              std::vector<int> next(v.size());
              std::copy(v.begin(), v.end(), next.begin());
              next.push_back(col);
              nexts.insert(next);
            }
          }
        }
        return nexts;
      }

    }

    bool is_safe(int col, const std::vector<int>& positions)
    {
      int row = positions.size();
      if (positions.empty()) {
        return true;
      }
      else {
        for(int i = 0; i < positions.size(); ++i){
          if( col == positions[i]
                   || std::abs(row - i) == std::abs(col - positions[i]) ) {
            return false;
          }
        }
      }
      return true;
    }
    
  };
  
  return place_queens(n)(n);
}

bool test_nqueens()
{

  auto is_solution = [&](const std::vector<int>& positions) {
    for (int i = 0; i < positions.size(); ++i) {
      for (int j = 0; j < positions.size(); ++j){
        if (i != j) {
          if (positions[i] == positions[j]){
            return false;
          }
          if(std::abs(i - j) == std::abs(positions[i] - positions[j])) {
            return false;
          }
        }
      }
    }
    return true;
  };

  bool ret = true;

  std::set<std::vector<int>> solutions = solve(8);

  for (auto &e: solutions) {
    if (!is_solution(e))
      ret = false;
  }
  return ret;
}

