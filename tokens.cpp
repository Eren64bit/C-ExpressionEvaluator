#include "tokens.h"
#include <bits/stdc++.h>

/*PLUS, MINUS, MULT, DIVIDE,
    LPAREN, RPAREN,
    NUMBER, INVALID, END_OF_FILE*/

Token tokenizer::advance(TokenType type) {
    pos++;
    return {type, 0.0};
}

Token tokenizer::getNextToken() {
    return nextToken();
}

Token tokenizer::peek() {
    size_t oldPos = pos;
    Token t = nextToken();
    pos = oldPos;
    return t;
}

Token tokenizer::nextToken() {
while (pos < input.size() && std::isspace(static_cast<unsigned char>(input[pos])))
    ++pos;
    if (pos >= input.size())
        return {TokenType::END_OF_FILE, 0};

    char ch = input[pos];
    if (ch == '$' || ch == '#' || ch == '@') return advance(TokenType::INVALID);
    if (ch == '+') return advance(TokenType::PLUS);
    if (ch == '-') return advance(TokenType::MINUS);
    if (ch == '*') return advance(TokenType::MULT);
    if (ch == '/') return advance(TokenType::DIVIDE);
    if (ch == '(') return advance(TokenType::LPAREN);
    if (ch == ')') return advance(TokenType::RPAREN);
    if (ch == '=') return advance(TokenType::ASSIGN);
    if (std::isdigit(ch)) {
        std::string temp;
        while (pos < input.size() && (std::isdigit(input[pos]) || input[pos] == '.')) {
            temp += input[pos++];
        }
        try
        {
            return {TokenType::NUMBER, std::stod(temp)};
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }
    if (std::isalpha(ch)) {
        std::string temp;
        while (pos < input.size() &&
       (std::isalnum(static_cast<unsigned char>(input[pos])) || input[pos] == '_')) {
            temp += input[pos++];
        }

        std::string upperTemp = temp;
        std::transform(upperTemp.begin(), upperTemp.end(), upperTemp.begin(), ::toupper);
        if (upperTemp == "VAR")
            return {TokenType::VAR, 0};

        return {TokenType::IDENTIFIER, 0, temp};
    }

    pos++;
    return {TokenType::INVALID, 0};

}

std::vector<Token> tokenizer::fullToken() {
    std::vector<Token> v;
    Token t;
    do
    {
        t = nextToken();
        v.push_back(t);
    } while (t.kind != TokenType::END_OF_FILE);
    

    return v;
}

