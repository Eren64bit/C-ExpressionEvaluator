#include <iostream>
#include <vector>

#include "tokens.h"

#include "debug.h"

#include "parser.h"


int main() {
    tokenizer t("3 + (4 * 5) - 6 / 2");
    Parser p(t);

    p.advance();
    double result = p.expr();

    std::cout << "Result: " << result << "\n";
    return 0;
}