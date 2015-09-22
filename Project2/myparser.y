%{
#include <iostream>
#include <algorithm>
#include <fstream>
//#include "symbol_table.h"

extern int yylex();
extern FILE* yyin; 
extern char* yytext;
int line_count =0; 
//use map that maps from string to struct with some preoperties
void yyerror
  (char* err_string)
{
  std::cout << "Error (line " << ++line_count << "): syntax error" << std::endl;
  exit(1);
}
%}
%union 
{
  char* lexeme;
}

%token <lexeme> TYPE
%token COMMAND_PRINT
%token COMMAND_RANDOM
%token <lexeme> ID
%token VAL_LITERAL
%token CHAR_LITERAL
%token MULTI_CHAR
%token NON_TERM_CHAR
%token STRING_LITERAL
%token NON_TERM_STRING
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
%token UNKNOWN

%left '-' '+'
%left '*' '/'
%nonassoc UMINUS

%%

line: line line
    | NEW_LINE {std::cout<< "Line_count: " << ++line_count <<std::endl;}
    | err
    | statement
    | {std::cout << "epsilon" << std::endl;}
    ;

err: MULTI_CHAR {std::cout<< "multi char" <<std::endl;}
   | NON_TERM_CHAR {std::cout<< "non term char" <<std::endl;}
   | NON_TERM_STRING {std::cout<< "non term str" <<std::endl;}
   | UNKNOWN {std::cout << "unknown" << std::endl;}
   ;

statement: something ';'
         | ';'
         ;

something: decl {std::cout << "decl"<<std::endl;} 
         | expr {std::cout << "expr" << std::endl;}  
         | cmd  {std::cout << "cmd" << std::endl;} 
         ;

decl: TYPE ID {std::cout << "Typbe, ID: " << $1 << ", " << $2 <<std::endl;}
    | TYPE ID '=' value {/*check, add to the symbol tree*/}
    ;

value: value opr1 value
     | term
     ;
opr1: '+'
    | '-'
    | '*'
    | '/'
    ;
term: VAL_LITERAL
    | ID {/*check if id is in symbol tree. if not halt*/}
    | COMMAND_RANDOM '(' value ')'
    | '(' term ')'
    ;

expr: ID opr2 value {/*check if ID is in symbol table*/}
    ;
opr2: '='
    | ASSIGN_ADD
    | ASSIGN_SUB
    | ASSIGN_MULT
    | ASSIGN_DIV
    ;
cmd: COMMAND_PRINT '(' value ')' 
   ;
%%


int main
  (int argc, char* argv[])
{
  if (argc != 2)
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
  }
  std::cout << "#rules: " << YYNRULES << std::endl;
  yyparse();

  std::cout<< "successfully compiled!" << std::endl;
  //fclose(yyin);
  return 0;
}




