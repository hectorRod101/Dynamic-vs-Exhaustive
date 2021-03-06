///////////////////////////////////////////////////////////////////////////////
// gnomes_algs.hpp
//
// Algorithms that solve the greedy gnomes problem.
//
// All of the TODO sections for this project reside in this file.
//
// This file builds on gnomes_types.hpp, so you should familiarize yourself
// with that file before working on this file.
//
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cassert>

#include "gnomes_types.hpp"

namespace gnomes {

// Solve the greedy gnomes problem for the given grid, using an exhaustive
// search algorithm.
//
// This algorithm is expected to run in exponential time, so the grid's
// width+height must be small enough to fit in a 64-bit int; this is enforced
// with an assertion.
//
// The grid must be non-empty.
path greedy_gnomes_exhaustive(const grid& setting) {

  // grid must be non-empty.
  assert(setting.rows() > 0);
  assert(setting.columns() > 0);
  
  // Compute maximum path length, and check that it is legal.
  const size_t max_steps = setting.rows() + setting.columns() - 2;
  assert(max_steps < 64);

  auto maxlen = setting.rows() + setting.columns() - 2;
  path best(setting);
  for(int len=0;len<maxlen;len++)
    for(int bits=0;bits<2^len-1;bits++){
      path candidate(setting);
      //candidate.add_step(STEP_DIRECTION_START);//do i need to set it to start?
      for(int k=0;k<len-1;k++){
        int bit = (bits>>k) & 1;
        if(bit == 1){
          candidate.add_step(STEP_DIRECTION_RIGHT);
          if(candidate.total_gold()>best.total_gold())//is valid step is already asserted
            best=candidate;
        }
        else{
          candidate.add_step(STEP_DIRECTION_DOWN);
          if(candidate.total_gold()>best.total_gold())
            best=candidate;
        }
      }
    }
  return best;
}

// Solve the greedy gnomes problem for the given grid, using a dynamic
// programming algorithm.
//
// The grid must be non-empty.
path greedy_gnomes_dyn_prog(const grid& setting) {

  // grid must be non-empty.
  assert(setting.rows() > 0);
  assert(setting.columns() > 0);
  
  auto r=setting.rows();
  auto c=setting.columns()

  step_direction a[setting.rows()][setting.columns()];
  //base case
  a[0][0]={STEP_DIRECTION_START};
  /*general cases
  for(int i=0;i<r;i++)
    for(int j=0;c-1;j++){
      //if(setting[i][j]=='X')
        //a[i][j]=
      //from_above = from left = none
      //if(i>0 && a[i-1][j])
      
    }*/
  
  path best(setting);
  return path(setting);
}

}
