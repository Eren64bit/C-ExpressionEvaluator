#include <iostream>
#include <vector>

#include "tokens.h"

#include "debug.h"

#include "parser.h"


int main() {
    std::unordered_map<std::string, double> sVars;
    tokenizer t("var x = 5");
    tokenizer r("x * 2 + 3");
    
    Parser p1(t, sVars);
    Parser p2(r, sVars);

    p1.parse();
    double result = p2.parse();

    std::cout << "Sonuç: " << result << "\n";
    return 0;
}