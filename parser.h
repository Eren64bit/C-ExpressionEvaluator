#pragma once
#include "tokens.h"
#include <unordered_map>

class Parser{
private:
    tokenizer& tokenr;
    Token currentToken;

    std::unordered_map<std::string, double> varMap;

public:

    void advance();

    Parser(tokenizer& t) : tokenr(t) {}

    double parse();
    double expr();
    double term();
    double factor();
    bool statement();

};