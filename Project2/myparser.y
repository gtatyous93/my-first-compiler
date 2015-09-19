%{
#include <iostream>
#include <algorithm>
#include <fstream>
void yyerror(char* err_string)
{
  std::cout << "Input failed to match" << std::endl;
  exit(1);
}
extern int yylex();
extern FILE* yyin; 
int line_count =0; 
%}


%token TYPE
%token COMMAND_PRINT
%token COMMAND_RANDOM
%token ID
%token VAL_LITERAL
%token CHAR_LITERAL
%token MULTI_CHAR
%token NON_TERM_CHAR
%token STRING_LITERAL
%token NON_TERM_STRING
%token ASCII_CHAR
%token ASSIGN_ADD
%token ASSIGN_SUB
%token ASSIGN_MULT
%token ASSIGN_DIV
%token COMP_EQU
%token COMP_NEQU
%token COMP_LESS
%token COMP_LTE
%token COMP_GTR
%token COMP_GTE
%token BOOL_AND
%token BOOL_OR
%token NEW_LINE
%token EOL
%token UNKNOWN


%%

line: line line
    | statement
    | err
    | NEW_LINE {std::cout<< "Line_count: " << ++line_count <<std::endl;}
    ;

statement: expr ASCII_CHAR  {std::cout << "expression " << std::endl;}
         | cmd  ASCII_CHAR  {std::cout << "command yo " << std::endl;}
         | ASCII_CHAR
         ;

err: MULTI_CHAR {std::cout<< "multi char" <<std::endl;}
     | NON_TERM_CHAR {std::cout<< "non term char" <<std::endl;}
     | NON_TERM_STRING {std::cout<< "non term str" <<std::endl;}
     | UNKNOWN {std::cout << "unknown" << std::endl;}
     ;

decl: TYPE ID 
    | TYPE ID OPR value
    ;

OPR: ASCII_CHAR
   ;

value: VAL_LITERAL
     ;

expr: VAL_LITERAL OPR3 VAL_LITERAL {}
    ;

OPR3: ASCII_CHAR {}
   ;

cmd: COMMAND_PRINT '(' OUT ')' {}
   ;

OUT: VAL_LITERAL {}
   | ID {}
   ;
%%


int main
  (int argc, char* argv[])
{
  /*if (argc != 2)
  {
    std::cout<< "FORMATERROR: " << argv[0] << " [source filename] " <<\
    "\nprograme halted...\n";
    exit(1);
  }
  yyin = fopen(argv[1], "r");
  if (yyin == NULL)
  {
    std::cout<< "Error: input file not found!\nprograme halted...\n";
    fclose(yyin);
    exit(2);
  }*/
  yyparse();

  std::cout<< "successfully compiled!" << std::endl;
  //fclose(yyin);
  return 0;
}



