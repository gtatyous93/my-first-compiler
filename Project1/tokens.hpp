/*
 * Yousef GTAT
 * CSE450
 * Sept 14, 2015
 *
 */

#ifndef TOKENS_GUARD_HPP
#define TOKENS_GUARD_HPP

#define TYPE            (1)
#define COMMAND_PRINT   (2)
#define COMMAND_RANDOM  (3)
#define ID              (4)
#define VAL_LITERAL     (5)
#define CHAR_LITERAL    (6)
#define STRING_LITERAL  (7)
#define ASCII_CHAR      (8)
#define ASSIGN_ADD      (9)
#define ASSIGN_SUB      (10)
#define ASSIGN_MULT     (11)
#define ASSIGN_DIV      (12)
#define COMP_EQU        (13)
#define COMP_NEQU       (14)
#define COMP_LESS       (15)
#define COMP_LTE        (16)
#define COMP_GTR        (17)
#define COMP_GTE        (18)
#define BOOL_AND        (19)
#define BOOL_OR         (20)
#define WHITESPACE      (21)
#define COMMENT         (22)
#define MULTI_LINE_COMMENT (23)
#define UNKNOWN         (24)
#define EOL             (25)
#define NON_TERM_STRING (26)
#define NON_TERM_CHAR   (27)
#define MULTI_CHAR      (28)
#define EXIT            (29)

/*
enum TOKENS_T
{
  TYPE = 1,
  COMMAND_PRINT,
  COMMAND_RANDOM, 
  ID,
  VAL_LITERAL,
  CHAR_LITERAL,
  STRING_LITERAL,
  ASCII_CHAR,
  ASSIGN_ADD,
  ASSIGN_SUB,
  ASSIGN_MULT,
  ASSIGN_DIV,
  COMP_EQU,
  COMP_NEQU,
  COMP_LESS,
  COMP_LTE,
  COMP_GTR,
  COMP_GTE,
  BOOL_AND,
  BOOL_OR,
  WHITESPACE,
  COMMENT,
  UNKNOWN,          
  EOL
};
*/

#endif /* TOKENS_GUARD_HPP */
