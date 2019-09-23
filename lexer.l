%{
    #include <stdio.h>
    #include <stdlib.h>
    #include "ValidateLexer.h"
%}

%option c++
%option outfile="Scanner.cpp"
%option case-insensitive
%option noyywrap


COMMENT "//".*
WHITESPACE [\t\r\f"" "]
ID ({LETTER}|"_")({LETTER}|{DIGIT})*
ADD_OP [+-]
MULT_OP [*/]
LOG_OP ("||"|"&&")
REL_OP (">"|"<"|"=="|"<="|">=")
ASSIGN (":=")
PERIOD [.]
DDPERIOD ("::")
INCR ("++")
INTEGER {DIGIT}+
REAL_LITERAL {DIGIT}+"."{DIGIT}+
STRING_LITERAL ["]({LETTER}|{DIGIT}|" "|[%=@,-=()_])*["]
DATE_LITERAL {DIGIT}{DIGIT}"/"{DIGIT}{DIGIT}"/"{DIGIT}{DIGIT}{DIGIT}{DIGIT}

POINT_COMA [;]
COMA [,]
PARENTHESIS_LEFT [(]
PARENTHESIS_RIGHT [)]
BRACKETS_LEFT [{]
BRACKETS_RIGHT [}]

DIGIT [0-9]
LETTER [a-zA-Z]
DELIMITER [\t\r\f" "]


%%
"string" {return STRING_TYPE;}
"E" {return EPSILON;}
"true" {return TRUE_LITERAL;}
"false" {return FALSE_LITERAL;}
"if" {return IF;}
"else" {return ELSE;}
"return" {return RETURN;}
"while" {return WHILE;}
"do" {return DO;}
"end" {return END;}
"static" {return STATIC_TKN;}
"int" {return INT_TYPE;}
"anytype" {return ANYTYPE_TYPE;}
"bool" {return BOOLEAN_TYPE;}
"void" {return VOID_TYPE;}
"real" {return REAL_TYPE;}
"date" {return DATE_TYPE;}

{COMMENT} {return COMMENT;}
{ID} {return ID;}
{ADD_OP} {return ADD_OP;}
{MULT_OP} {return MULT_OP;}
{LOG_OP} {return LOG_OP;}
{REL_OP} {return REL_OP;}
{ASSIGN} {return ASSIGN;}
{PERIOD} {return PERIOD;}
{DDPERIOD} {return DDPERIOD;}
{INCR} {return INCR;}
{INTEGER} {return INTEGER;}
{REAL_LITERAL} {return REAL_LITERAL;}
{STRING_LITERAL} {return STRING_LITERAL;}
{DATE_LITERAL} {return DATE_LITERAL;}
{POINT_COMA} {return POINT_COMA;}
{COMA} {return COMA;}
{PARENTHESIS_LEFT} {return PARENTHESIS_LEFT;}
{PARENTHESIS_RIGHT} {return PARENTHESIS_RIGHT;}
{BRACKETS_LEFT} {return BRACKETS_LEFT;}
{BRACKETS_RIGHT} {return BRACKETS_RIGHT;}
{DELIMITER} {}
.           {printf("ERROR");}
%%


