# C++ Expression Evaluator

This project is a simple **expression evaluator** written in C++. It can parse and evaluate mathematical expressions, handle variables, and supports basic assignment statements.

## Features

- **Arithmetic operations:** Addition, subtraction, multiplication, division, and parentheses.
- **Variables:** Define and use variables with `var` keyword (e.g., `var x = 5`).
- **Assignment:** Assign values to variables.
- **Error handling:** Detects and reports invalid tokens, undefined variables, and syntax errors.
- **REPL interface:** Enter expressions interactively in the terminal.

## Example Usage

```
> var x = 5
[OK]
> x + 3 * (2 + 1)
14
> var y = x * 2
[OK]
> y + 1
11
> quit
```

## How It Works

- **Tokenizer:** Converts input strings into a sequence of tokens (numbers, operators, identifiers, etc.).
- **Parser:** Builds an Abstract Syntax Tree (AST) from the tokens using recursive descent parsing.
- **AST Nodes:** Each node represents a number, variable, or operation. The tree structure allows for correct operator precedence and evaluation.
- **Evaluator:** Traverses the AST to compute the result.

## File Structure

- `main.cpp` — Entry point and REPL loop.
- `tokens.h/cpp` — Token definitions and tokenizer implementation.
- `parser.h/cpp` — Parser and AST construction.
- `ASTnode.h/cpp` — AST node classes and evaluation logic.
- `debug.h` — (Optional) Debugging utilities.

## Building

Compile with g++ (or any C++17 compatible compiler):

```sh
g++ main.cpp tokens.cpp parser.cpp ASTnode.cpp -o program
```

## Usage

Run the program:

```sh
./program
```

Type expressions or assignments, and see the results. Type `exit` or `quit` to leave.

## License

MIT License

---

**Note:**  
This project is for educational purposes and demonstrates basic concepts of tokenization, parsing, and AST-based evaluation in C++. It can be extended with more features such as functions, more operators, or improved error messages.
