#include "SyntaxTree.h"
#include <iostream>

void AST_ROOT::AddChild 
  (AST* child)
{
  _children.push_back(child);
}
void ID_NODE::print
  (void) 
{

}

int ID_NODE::process
  (void)
{
  int out_id = symbol_table.search(_name)->id;
  if (out_id == -1)
  {
    out_id = GetID();
    symbol_table.search(_name)->id = out_id;
  }
  return out_id;
}

void VAL_NODE::print
  (void) 
{

}

int VAL_NODE::process
  (void)
{
  int out_id = GetID();
  TubeIC_out << "val_copy " << _val << " s" << out_id << std::endl;
  return out_id;
}

OPR_NODE::OPR_NODE
  (std::string opr, AST* LHS, AST* RHS)
  : _opr (opr)
{
  _children.push_back(LHS);
  _children.push_back(RHS);
}

void OPR_NODE::print
  (void) 
{

}

int OPR_NODE::process
  (void)
{
  int lhs = _children[0]->process();
  int rhs = _children[1]->process();

  if      (_opr == "+")   {TubeIC_out << "add s";}
  else if (_opr == "-")   {TubeIC_out << "sub s";}
  else if (_opr == "*")   {TubeIC_out << "mult s";}
  else if (_opr == "/")   {TubeIC_out << "div s";}
  else if (_opr == "==")  {TubeIC_out << "test_equ s";}
  else if (_opr == "!=")  {TubeIC_out << "test_nequ s";} 
  else if (_opr == "<")   {TubeIC_out << "test_less s";}
  else if (_opr == "<=")  {TubeIC_out << "test_lte s";}
  else if (_opr == ">")   {TubeIC_out << "test_gtr s";}
  else if (_opr == ">=")  {TubeIC_out << "test_gte s";}
  else if (_opr == "=")   {TubeIC_out << "val_copy s" << rhs       \
                           << " s" << lhs << std::endl; return lhs;}
  else if (_opr == "+=")  {TubeIC_out << "add s"<<lhs << " s"<<rhs \
                           <<" s"<<lhs <<std::endl;     return lhs;}
  else if (_opr == "-=")  {TubeIC_out << "sub s"<<lhs << " s"<<rhs \
                           <<" s"<<lhs <<std::endl;     return lhs;}
  else if (_opr == "*=")  {TubeIC_out << "mult s"<<lhs << " s"<<rhs \
                           <<" s"<<lhs <<std::endl;     return lhs;}
  else if (_opr == "/=")  {TubeIC_out << "div s"<<lhs << " s"<<rhs \
                           <<" s"<<lhs <<std::endl;     return lhs;}
  else {std::cout << "Internal Compiler ERROR!!" << std::endl;}

  int out_id = GetID();
  TubeIC_out << lhs << " s"<<rhs << " s"<<out_id << std::endl;
  return out_id;
}

BOOL_NODE::BOOL_NODE
  (std::string opr, AST* LHS, AST* RHS)
  : _opr (opr)
{
  _children.push_back(LHS);
  _children.push_back(RHS);
}

void BOOL_NODE::print
  (void) 
{

}

int BOOL_NODE::process
  (void)
{
  int lhs = _children[0]->process();
  int out_id = GetID(); 
  int label_id = GetLabelID();
  if      (_opr == "&&")  
  {
    TubeIC_out << "test_nequ s"<< lhs << " 0 s" << out_id<< std::endl;
    TubeIC_out << "jump_if_0 s" << out_id<< " end_bool_" << label_id<< std::endl;
  }
  else if (_opr == "||")   
  {
    TubeIC_out << "test_nequ s"<< lhs << " 0 s" << out_id<< std::endl;
    TubeIC_out << "jump_if_n0 s" << out_id<< " end_bool_" << label_id<< std::endl;
  }
  int rhs = _children[1]->process();
  TubeIC_out << "test_nequ s"<< rhs << " 0 s" << out_id<< std::endl;
  TubeIC_out << "end_bool_" << label_id << ":" << std::endl;
  return out_id;
}

////////////////////////////
void PRINT_CMD_NODE::print
  (void)
{
}

void PRINT_CMD_NODE::AddChild 
  (AST* child)
{
  _children.push_back(child);
}

int PRINT_CMD_NODE::process
  (void)
{
  
  for (int i=0; i<_children.size(); i++)
  {
    int out_id = _children[i]->process();
    TubeIC_out << "out_val s" << out_id << std::endl;
  }
  TubeIC_out << "out_char " << "'\\n'" << std::endl;
  return -1;
}

RAND_CMD_NODE::RAND_CMD_NODE
  (AST* expr)
{
  _children[0] = expr;
}

void RAND_CMD_NODE::print
  (void)
{}

int RAND_CMD_NODE::process
  (void)
{
  int expr_id  = _children[0]->process();
  int out_id = GetID();
  TubeIC_out << "random s" << expr_id << " s" << out_id << std::endl;
  return out_id;
}


UMINUS_NODE::UMINUS_NODE
  (AST* expr)
{
  _children.push_back(expr);
}

int UMINUS_NODE::process
  (void)
{
  int expr = _children[0]->process();
  int out_id = GetID();
  TubeIC_out << "mult -1 s"<< expr <<" s"<< out_id << std::endl;
  return out_id;
}

void UMINUS_NODE::print
  (void)
{
  
}

void DECL_NODE::print
  (void)
{
}

void DECL_NODE::AddChild 
  (AST* child)
{
  _children.push_back(child);
}

int DECL_NODE::process
  (void)
{
  
  for (int i=0; i<_children.size(); i++)
  {
    _children[i]->process();
  }
  return -1;
}


