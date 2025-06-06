#pragma once

#include <memory>

#include "tokens.h"
#include <unordered_map>

class ASTnode {
public:
    virtual ~ASTnode() {}
    virtual double evaluate(const std::unordered_map<std::string, double>& vars) const = 0;
    virtual void print() const = 0;


};


class NumberNode : public ASTnode {
public:
    double value;
    NumberNode(double val) : value(val) {}

    double evaluate(const std::unordered_map<std::string, double>&) const override;

    void print() const override;
};


class VariableNode : public ASTnode {
public:
    std::string name;
    VariableNode(const std::string& n) : name(n) {}

    double evaluate(const std::unordered_map<std::string, double>& vars) const override;

    void print() const override;
};

class BinaryOpNode : public ASTnode {
public:
    char op;
    std::unique_ptr<ASTnode> left;
    std::unique_ptr<ASTnode> right;

    BinaryOpNode(char oper, std::unique_ptr<ASTnode> l, std::unique_ptr<ASTnode> r)
        : op(oper), left(std::move(l)), right(std::move(r)) {}


    double evaluate(const std::unordered_map<std::string, double>& vars) const override;

    void print() const override;
};