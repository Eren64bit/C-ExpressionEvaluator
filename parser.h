#pragma once
#include "tokens.h"

class Parser{
private:
    tokenizer& tokenr;
    Token currentToken;

    
public:

    void advance();

    Parser(tokenizer& t) : tokenr(t) {}


    double expr();
    double term();
    double factor();


};