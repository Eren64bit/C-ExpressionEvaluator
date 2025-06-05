#include "debug.h"

/*PLUS, MINUS, MULT, DIVIDE,
    LPAREN, RPAREN,
    NUMBER, INVALID, END_OF_FILE*/

std::string errorHandler::tokenTypeToString(TokenType type) {

    switch (type)
    {
    case TokenType::PLUS:
        return "PLUS";
        break;
    case TokenType::MINUS:
        return "MINUS";
        break;
    case TokenType::MULT:
        return "MULTIPICATION";
        break;
    case TokenType::DIVIDE:
        return "DIVIDE";
        break;
    case TokenType::LPAREN:
        return "LEFTPAREN";
        break;
    case TokenType::RPAREN:
        return "RIGHTPAREN";
        break;
    case TokenType::INVALID:
        return "INVALID";
        break;
    case TokenType::END_OF_FILE:
        return "EOF";
        break;
    default:
        break;
    }

}