#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


#include "../include/tokens.h"
#include "../include/parser.h"
#include "../include/ASTnode.h"
#include "../include/debug.h"

int main() {
    std::unordered_map<std::string, double> varMap;
    std::string line;

    std::cout << "> ";
     while (std::getline(std::cin, line)) {
         if (line.empty()) continue;
         if (line == "exit" || line == "quit") break;
         
        try
        {
            tokenizer t{line};
            Parser p{t, varMap};

            auto ast = p.parse();
            if (ast) {
                double result = ast->evaluate(varMap);
                std::cout << result << '\n';
            } else {
                std::cout << "[OK]\n";
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << "error:" << e.what() << '\n';
        }
        
        std::cout << "> ";
     }

    return 0;
}