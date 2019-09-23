#include <FlexLexer.h>
#include "ValidateLexer.h"
#include "CParser.h"

void CParser::checkoutCorrect(){
  if(program()){
    cout <<"Everything is okay \n";
  }
  else{
    cout <<"There's something wrong on your code dude \n";
  }        
}

void CParser::gooble_token(){
  lookahead = l->yylex();
  lh_token = l->YYText();

}

bool CParser::match(tokens tn){
    if(tn == lookahead){
      lookahead = l->yylex();
      lh_token = l->YYText();
      return true;
    }
    return false;
}

bool CParser::program(){
    return opt_funct_decl();
}

bool CParser::opt_funct_decl(){
    if(func_head()){
      return body();
    }
    else{
      return false;
    }
}

bool CParser::func_head(){
    if(funct_name()){
      if(!match(PARENTHESIS_LEFT)){
        cout <<"You are missing a parenthesis to OPEN FUNC_HEAD"<<endl;
        return false;
      }
      if(!param_list_opt()){
        return false;
      }
      if(!match(PARENTHESIS_RIGHT)){
        cout <<"You are missing a parenthesis to CLOSE FUNC_HEAD" <<endl;
        return false;
      }
      return true;
    }else{
      return false;
    }
}

bool CParser::funct_name(){
  if(funct_type()){
    if(!match(ID)){
      cout<< "You are missing a FUNCTION-NAME"<<endl;
      return false;
    }
    return true;
  }else{
    return false;
  }
}

bool CParser::funct_type(){
  if(!match(STATIC_TKN)){
    cout<< "You are missing a STATIC in the function DECLARATION-TYPE"<<endl;
    return false;
  }
  if(decl_type()){
    return true;
  }else{
    cout<<"You are missing a DECLARATION-TYPE after STATIC-TKN";
    return false;
  }
 
}

bool CParser::decl_type(){
  if(lookahead == VOID_TYPE || lookahead== INT_TYPE
    || lookahead == ANYTYPE_TYPE || lookahead == BOOLEAN_TYPE
    || lookahead == REAL_TYPE || lookahead == DATE_TYPE
    || lookahead == STRING_TYPE ){
      gooble_token();
      return true;
  }else{
    return false;
  }
}

bool CParser::param_list_opt(){
  if(lookahead == PARENTHESIS_RIGHT){
    return true;
  }
    if(decl_param()){
      if(lookahead == PARENTHESIS_RIGHT){
        return true;
    }
    if(!match(COMA)){
      cout<<"You are missing a COMA"<<endl;
      return false;
    }
    if(lookahead != PARENTHESIS_RIGHT){
      return param_list_opt();
    }else{
      cout<<"You are putting a COMA beside a PARETHESIS "<<endl;
      return false;
    }  
  }
  else{
    return false;
  }
}

bool CParser::decl_param(){
    if(decl_type()){
      if(!match(ID)){
        cout<<"You are missing a ID"<<endl;
        return false;
      }
      return true;
    }else{
      cout<<"You are missing a DECLARATION-TYPE";
      return false;
    }
}

bool CParser::body(){
  if(!match(BRACKETS_LEFT)){
    cout<<"You are missing a BRACKET to OPEN"<<endl;
    return false;
  }
  if(stmt_list()){
    if(!match(BRACKETS_RIGHT)){
      cout<<"You are missing a BRACKET to CLOSE -"<<endl;
      return false;
    }
      return true;
  }else{
      return false;
  }
}

bool CParser::stmt_list(){
  return stmts();
}

bool CParser::stmts(){
  if(lookahead == BRACKETS_RIGHT){
    return true;
  }
  return stmt();
}

bool CParser::stmt(){
  if(lookahead == WHILE){
    return while_stmt();
  }
  if(lookahead == RETURN){
    return return_stmt();
  }

  if(expr_stmt()){
    if(lookahead != BRACKETS_RIGHT)
      return stmt();
    return true;
  }else{
    return false;
  }
}

bool CParser::if_stmt(){
  if(!match(IF)){
    cout<<"You are missing a statement"<<endl;
    return false;
  }
  if(!match(PARENTHESIS_LEFT)){
    cout<<"You are missing a parenthesis to OPEN IF_STMT"<<endl;
    return false;
  }
  if(bool_expr()){
    if(!match(PARENTHESIS_RIGHT)){
      cout<<"You are missing a parenthesis to CLOSE IF_STMT"<<endl;
      return false;
    }
    return body();
  }
  else{
    return false;
  }
}

bool CParser::while_stmt(){
  if(!match(WHILE)){
    cout<<"You are missing a statement"<<endl;
    return false;
  }
  if(!match(PARENTHESIS_LEFT)){
    string bt= l->YYText();
    cout<<"You are missing a parenthesis to OPEN IF_STMT"<<endl;
    return false;
  }
  if(bool_expr()){
    if(!match(PARENTHESIS_RIGHT)){
      cout<<"You are missing a parenthesis to CLOSE IF_STMT"<<endl;
      return false;
    }
    return body();
  }
  else{
    return false;
  }
}

bool CParser::return_stmt(){
  if(!match(RETURN)){
    cout<<"You are missing a statement"<<endl;
    return false;
  }
  if(lookahead == POINT_COMA){
    gooble_token();
    return true;
  }else{
    if(constant()){
      if(!match(POINT_COMA)){
        cout<<"You are missing a POINT_COMA"<<endl;
        return false;
      }
      return true;
    }
    else{
      return false;
    }
  }
}

bool CParser::expr_stmt(){
  if(assign_stmt()){
    if(!match(POINT_COMA)){
      cout<<"You are missing a POINT_COMA"<<endl;
      return false;
    }
    return true;
  }
  else{
    return false;
  }
}

bool CParser::assign_stmt(){
  if(decl_type()){
      
    if(!match(ID)){
      cout<<"You are missing a ID"<<endl;
      return false;
    }
    if(!match(ASSIGN)){
      cout<<"You are missing a parenthesis to ASSIGN_STMT"<<endl;
      return false;
    }
    return constant();
  }else{
    cout<<"You are missing a parenthesis to ASSIGN-OPERATION"<<endl;
    return false;
  }
}

bool CParser::bool_expr(){
  if(lookahead == TRUE_LITERAL || lookahead == FALSE_LITERAL){
      gooble_token();
      return true;
  }
  if(constant()){
    if(!match(LOG_OP)){
      cout<<"Expected logical comparators '&&' or '||')"<<endl;
      return false;
    }
    return constant();
  }
  else{
    return false;
  }
}

bool CParser::constant(){
  if(lookahead == INTEGER || lookahead == REAL_LITERAL
    || lookahead == DATE_LITERAL || lookahead == STRING_LITERAL ){
    gooble_token();
    return true;
  }
  else{
    return false;
  }
}






    




























