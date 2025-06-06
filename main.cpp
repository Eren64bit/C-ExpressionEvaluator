#include <iostream>
#include <vector>
#include <string>

#include "tokens.h"

#include "debug.h"

#include "parser.h"
#include <ASTnode.h>


int main() {
    std::unordered_map<std::string, double> varMap;
    std::string line;

    while (std::getline(std::cin, line)) {
        std::cout << "> ";
        if (line.empty()) continue;
        if (line == "exit" || line == "quit") break;
        try
        {
            tokenizer t{line};
            Parser p{t, varMap};

            if(p.statement()) {
                std::cout << "[OK]\n";
            } else {
                auto ast = p.expr();
                double result = ast->evaluate(varMap);
                std::cout << result << '\n';
        }
        }
        catch(const std::exception& e)
        {
            std::cerr << "error:" << e.what() << '\n';
        }
        
        
    }

    return 0;
}