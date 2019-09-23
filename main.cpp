#include <FlexLexer.h>
#include "CParser.h"
#include "ValidateLexer.h"
#include <iostream>
#include <fstream>
#include "CParser.cpp"

using namespace std;

void prueba();

int main(){
    CParser ps;
    prueba();
    ps.checkoutCorrect();
    cout<<"Probando";
    
    return 0;
}


void prueba(){
    ifstream in("PruebaL.g4");
    
    yyFlexLexer* lexer = new yyFlexLexer(&in);
    do
    {
        int token = lexer->yylex();

        if (token == 0)
            break;

        cout << token;
        cout << "= \t" << lexer->YYText() <<endl;

    } while (true);
}