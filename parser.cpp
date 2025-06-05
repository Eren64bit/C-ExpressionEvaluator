#include "parser.h"
#include <stdexcept>


void Parser::advance() {
    currentToken = tokenr.getNextToken();
}

double Parser::parse() {
    if (statement()) {
        return 0;
    }
    return expr();
}

bool Parser::statement() {
    if (currentToken.kind == TokenType::VAR) {
        advance();
        if (currentToken.kind == TokenType::IDENTIFIER) {
            std::string varName = currentToken.name;
            advance();
            if (currentToken.kind == TokenType::ASSIGN) {
                advance();
                double rValue = expr();
                varMap[varName] = rValue;
                return true;
            } else {
                throw std::runtime_error("Expected '=' after variable name\n");
                return false;
            }
        } else {
            throw std::runtime_error("Expected Variable name after Var\n");
            return false;
        }
    } else {
        return false;
    }
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
    case TokenType::IDENTIFIER: {
        std::string name = currentToken.name;
        advance();
        auto it = varMap.find(name);
        if (it != varMap.end()) {
            return it->second;
        } else {
            throw std::runtime_error("Undefined variable: " + name);
        }
    }
    default:
        throw std::runtime_error("UNEXPECTED TOKEN");
    }
}