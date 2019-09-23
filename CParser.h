#ifndef __CParser__
#define __CParser__

#include <FlexLexer.h>
#include "ValidateLexer.h"
#include <fstream>
#include <iostream>
#include <string>



using namespace std;


class CParser{
    
    public:
    CParser(){
    in=ifstream("PruebaL.g4");
    in2=ifstream("PruebaL.g4");
    l = new yyFlexLexer(&in);
    l2 = new yyFlexLexer(&in2);
    lookahead = l->yylex();

    if(lookahead !=0)
        lh_token = l->YYText();  
    }

    ~CParser(){
        delete l;
    }
    void checkoutCorrect();//check code 
    void gooble_token();//get all tokens below
    bool match(tokens tn);//make match tokens

    //GRAMMAR

    bool program();
    bool opt_funct_decl();
    bool func_head();
    bool funct_name();
    bool funct_type();
    bool decl_type();
    bool param_list_opt();
    bool decl_param();
    bool body();
    bool stmt_list();
    bool stmts();
    bool stmt();
    bool if_stmt();
    bool while_stmt();
    bool return_stmt();
    bool expr_stmt();
    bool assign_stmt();
    bool bool_expr();
    bool constant();

    private:
    ifstream in;
    ifstream in2;
    yyFlexLexer *l;
    yyFlexLexer * l2;//lexer
    int lookahead;// look next token
    string lh_token;//content    
};

#endif