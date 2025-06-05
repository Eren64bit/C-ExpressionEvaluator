#include "parser.h"
#include <stdexcept>

void Parser::advance() {
    currentToken = tokenr.getNextToken();
}

double Parser::expr() {
    double rs = term();
    while (currentToken.kind == TokenType::PLUS || currentToken.kind == TokenType::MINUS) {
        TokenType op = currentToken.kind;
        advance();
        double rhs = term();
        if (op == TokenType::PLUS) 
            rs += rhs;
        else
            rs -= rhs;
    }
    return rs;
}

double Parser::term() {
    double rs = factor();
    while (currentToken.kind == TokenType::MULT || currentToken.kind == TokenType::DIVIDE) {
        TokenType op = currentToken.kind;
        advance();
        double rhs = factor();
        if (op == TokenType::MULT)
            rs *= rhs;
        else {
            if (rhs == 0.0) throw std::runtime_error("Cannot divide by zero");
            rs /= rhs;
        }
    }
    return rs;
}
//3*5*7 --> 15*7 --> 4 + 5 + 7
//(3+4)+4*5
//3 + 4 * 5
double Parser::factor() {
    switch (currentToken.kind)
    {
    case TokenType::NUMBER: {
        double value = currentToken.value;
        advance();
        return value;
    }
    case TokenType::LPAREN: {
        advance();
        double value = expr();
        if (currentToken.kind != TokenType::RPAREN) throw std::runtime_error("Expected ')'\n");
        advance();
        return value;
    }
    case TokenType::MINUS: {
        advance();
        return -factor();
    }
    case TokenType::PLUS: {
        advance();
        return factor();
    }
    default:
        throw std::runtime_error("UNEXPECTED TOKEN");
    }
}}