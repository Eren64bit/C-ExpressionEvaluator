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

    std::unique_ptr<ASTnode> parse();
    std::unique_ptr<ASTnode> expr();
    std::unique_ptr<ASTnode> term();
    std::unique_ptr<ASTnode> factor();
    bool statement();

};