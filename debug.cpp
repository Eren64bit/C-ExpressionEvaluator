#include "debug.h"

/*PLUS, MINUS, MULT, DIVIDE,
    LPAREN, RPAREN,
    NUMBER, INVALID, END_OF_FILE*/

std::string errorHandler::tokenTypeToString(TokenType type) {

    switch (type)
    {
    case TokenType::NUMBER:
        return "NUMBER";
    case TokenType::PLUS:
        return "PLUS";
    case TokenType::MINUS:
        return "MINUS";
    case TokenType::MULT:
        return "MULTIPICATION";
    case TokenType::DIVIDE:
        return "DIVIDE";
    case TokenType::LPAREN:
        return "LEFTPAREN";
    case TokenType::RPAREN:
        return "RIGHTPAREN";
    case TokenType::INVALID:
        return "INVALID";
    case TokenType::END_OF_FILE:
        return "EOF";
    default:
        return "UNKNOWN";
    }

}