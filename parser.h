#pragma once
#include "tokens.h"
#include <unordered_map>

class Parser{
private:
    tokenizer& tokenr;
    Token currentToken;

    std::unordered_map<std::string, double>& varMap;

public:

    void advance();

    Parser(tokenizer& t, std::unordered_map<std::string, double>& vars) 
        : tokenr(t), varMap(vars) {}

    double parse();
    double expr();
    double term();
    double factor();
    bool statement();

};