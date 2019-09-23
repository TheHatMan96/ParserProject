#ifndef ValidateLexer
#define ValidateLexer

 enum tokens{
    COMMENT=258,
    WHITEPSACE=259,
    ID=260,
    DATE=261,
    IDENT=262,
    INTEGER=263,
    ADD_OP=264,// l
    MULT_OP=266,// l
    SUBT_OP=267,
    LOG_OP=268,// l
    AND_OP=269,// l
    REL_OP=270,
    ASSIGN=271,// l
    PERIOD=272,// l
    DDPERIOD=273,// l
    INCR=274,// l
    FALSE_LITERAL=275,// l
    TRUE_LITERAL=276,// l
    REAL_LITERAL=277,
    STRING_LITERAL=278,
    DATE_LITERAL=279,
    BRACKETS_LEFT=280,//l
    BRACKETS_RIGHT=281,//l
    //EMPTY,
    //MOD,// l
    //AT,//ARROBA -- l
    COMA=282,// l
    POINT_COMA=283,//l
    PARENTHESIS_LEFT=284,// l
    PARENTHESIS_RIGHT=285,// l
    DELIMITER=286,
    //DASH,
    //UNDERSCORE,
    //GREATER_THAN,// l
    //LESS_THAN,// l
    //EQUAL_EQUAL,// l
    //LESS_EQUAL,// l
    //GREATER_EQUAL,// l
    WHILE=287,// l
    IF=288,// l
    ELSE=289,// l
    RETURN=290,// l
    INICIO=291,// l
    IF_THEN=292,// l
    DO=293,// l
    END=294,// l
    EPSILON=295,
    STATIC_TKN=296,// l
    INT_TYPE=297,//l
    ANYTYPE_TYPE=298,// l
    BOOLEAN_TYPE=299,// l
    VOID_TYPE=300,// l
    REAL_TYPE=301,// l
    STRING_TYPE=302,// l
    DATE_TYPE=303,// l
    DIGIT=304,
    //DIGIT_ALONE,
    LETTER=305,
    END_OF_FILE=306,
    ERROR=307
 };

#endif
