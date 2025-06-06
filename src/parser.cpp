#include "parser.h"
#include <stdexcept>

#include "ASTnode.h"


void Parser::advance() {
    currentToken = tokenr.getNextToken();
}

std::unique_ptr<ASTnode> Parser::parse() {
    advance();
    if (statement()) {
        return nullptr;
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
                auto exprNode = expr();
                double rValue = exprNode->evaluate(varMap);
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
    } else if (currentToken.kind == TokenType::PRINT) {
        advance();
        auto exprNode = expr();
        double rV = exprNode->evaluate(varMap);
        std::cout << rV << '\n';
        return true;
    } else {
        return false;
    }
}

std::unique_ptr<ASTnode> Parser::expr() {
    auto left = term();
    while (currentToken.kind == TokenType::PLUS || currentToken.kind == TokenType::MINUS) {
        TokenType op = currentToken.kind;
        advance();
        auto right = term();
        char opChar = (op == TokenType::PLUS) ? ('+') : ('-');
        left = std::make_unique<BinaryOpNode>(opChar, std::move(left), std::move(right));
    }
    return left;
}

std::unique_ptr<ASTnode> Parser::term() {
    auto left = factor();
    while (currentToken.kind == TokenType::MULT || currentToken.kind == TokenType::DIVIDE) {
        TokenType op = currentToken.kind;
        advance();
        auto right = factor();
        char opChar = (op == TokenType::MULT) ? '*' : '/';
        left = std::make_unique<BinaryOpNode>(opChar, std::move(left), std::move(right));
    }
    return left;
}

std::unique_ptr<ASTnode> Parser::factor() {
    switch (currentToken.kind)
    {
    case TokenType::NUMBER: {
        double value = currentToken.value;
        advance();
        return std::make_unique<NumberNode>(value);
    }
    case TokenType::LPAREN: {
        advance();
        auto node = expr();
        if (currentToken.kind != TokenType::RPAREN) throw std::runtime_error("Expected ')'\n");
        advance();
        return node;
    }
    case TokenType::MINUS: {
        advance();
        auto child = factor();
        return std::make_unique<BinaryOpNode>('-', std::make_unique<NumberNode>(0), std::move(child));
    }
    case TokenType::PLUS: {
        advance();
        return factor();
    }
    case TokenType::IDENTIFIER: {
        std::string name = currentToken.name;
        advance();
        return std::make_unique<VariableNode>(name);
    }
    default:
        throw std::runtime_error("UNEXPECTED TOKEN");
    }
}