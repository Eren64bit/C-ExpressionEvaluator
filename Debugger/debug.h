#pragma once
#include <string>
#include "../Tokenizer/tokens.h"

class errorHandler{
    private:
        std::string errorName;

    public:
        std::string tokenTypeToString(TokenType type);
};


