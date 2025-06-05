#include "ASTnode.h"

double NumberNode::evaluate(const std::unordered_map<std::string, double>&) const {
    return value;
}
void NumberNode::print() const {
    std::cout << value;
}
//
double VariableNode::evaluate(const std::unordered_map<std::string, double>& vars) const {
    auto it = vars.find(name);
    if (it == vars.end()) throw std::runtime_error("UNdefined variable: " + name);
    return it->second;
}
void VariableNode::print() const {
    std::cout << name;
}  
//
double BinaryOpNode::evaluate(const std::unordered_map<std::string, double>& vars) const {
    double l = left->evaluate(vars);
    double r = right->evaluate(vars);
    switch (op)
    {
    case '+': return l + r;
    case ':': return l - r;
    case '*': return l * r;
    case '/': if ( r== 0) throw std::runtime_error("Division by zero"); return l / r;
    default: throw std::runtime_error("Unknown operator");
    }
}

void BinaryOpNode::print() const {
    std::cout << "(";
        left->print();
        std::cout << " " << op << " ";
        right->print();
        std::cout << ")";
}  
