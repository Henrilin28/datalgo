//
//  expr.h
//  datalgo
//
//  Created by Iyed Bennour on 19/11/14.
//  Copyright (c) 2014 Iyed Bennour. All rights reserved.
//

#ifndef __datalgo__expr__
#define __datalgo__expr__

#include <stdio.h>
#include <assert.h>
#include <string>
#include <vector>
#include <memory>


enum class Operation { ADD = 0, MINUS, MULT, DIV };
const Operation ops[] = {Operation::ADD, Operation::MINUS, Operation::MULT, Operation::DIV};

std::string opToString(Operation op);

class IExpr {
public:
  virtual int eval() = 0;
  static std::shared_ptr<IExpr> create(int value);
  static std::shared_ptr<IExpr> create(std::shared_ptr<IExpr>& l, std::shared_ptr<IExpr>& r, Operation op);
  virtual std::string toString() = 0;
};

class BinExpr : public IExpr{
public:
  BinExpr(std::shared_ptr<IExpr>& _exprL, std::shared_ptr<IExpr>& _exprR, Operation _op);
  virtual int eval();
  std::string toString();
private:
  Operation op;
  std::shared_ptr<IExpr> exprL;
  std::shared_ptr<IExpr> exprR;
};

class TerminalExpr : public IExpr {
public:
  TerminalExpr(int val);
  int eval();
  std::string toString();
private:
  int value;
};

std::vector<std::shared_ptr<IExpr>> find_solution(std::vector<std::shared_ptr<IExpr>>, std::shared_ptr<IExpr> sofar, int target);

#endif /* defined(__datalgo__expr__) */
