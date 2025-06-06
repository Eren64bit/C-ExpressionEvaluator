#pragma once

#include <iostream>
#include <vector>


enum class TokenType {
    PLUS, MINUS, MULT, DIVIDE,
    LPAREN, RPAREN,
    IDENTIFIER, VAR, ASSIGN,
    PRINT,
    NUMBER, INVALID, END_OF_FILE
    
};

class Token{
    public:
        TokenType kind;
        double value;
        std::string name;

};

class tokenizer{
    private:
        std::string input;
        size_t pos;
    public:
        tokenizer(const std::string& input) : input(input), pos(0) {}
        Token nextToken();
        std::vector<Token> fullToken();

        Token getNextToken();
        Token peek();
        Token advance(TokenType);
};

