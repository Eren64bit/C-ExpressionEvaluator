#ifndef DEBUG_H
    #define DEBUG_H
        #include <string>
        #include "tokens.h"

        class errorHandler{
            private:
                std::string errorName;

            public:
                std::string tokenTypeToString(TokenType type);
};
#endif

