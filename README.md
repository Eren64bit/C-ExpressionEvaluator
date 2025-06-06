# C++ Expression Evaluator

This project is a simple **expression evaluator** written in C++. It can parse and evaluate mathematical expressions, handle variables, and supports basic assignment statements using an Abstract Syntax Tree (AST).

## Features

- **Arithmetic operations:** Addition, subtraction, multiplication, division, and parentheses.
- **Variables:** Define and use variables with the `var` keyword (e.g., `var x = 5`).
- **Print command:** Output values using the `print` keyword (e.g., `print x`).
- **Assignment:** Assign values to variables.
- **Error handling:** Detects and reports invalid tokens, undefined variables, and syntax errors.
- **REPL interface:** Enter expressions interactively in the terminal.
- **AST-based evaluation:** Expressions are parsed into an AST for correct operator precedence and extensibility.

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
- `src/tokens.cpp`, `include/tokens.h` — Token definitions and tokenizer implementation.
- `src/parser.cpp`, `include/parser.h` — Parser and AST construction.
- `src/ASTnode.cpp`, `include/ASTnode.h` — AST node classes and evaluation logic.
- `include/debug.h` — (Optional) Debugging utilities.
- `CMakeLists.txt` — CMake build configuration.

## Building

**With CMake (recommended):**
```sh
mkdir build
cd build
cmake ..
make
./CPPExpressionEvaluator
```

**Or with g++ (if you prefer manual compilation):**
```sh
g++ src/main.cpp src/tokens.cpp src/parser.cpp src/ASTnode.cpp -Iinclude -o program
./program
```

## Usage

Run the program and type expressions or assignments. Type `exit` or `quit` to leave.

## License

MIT License

---

**Note:**  
This project is for educational purposes and demonstrates basic concepts of tokenization, parsing, and AST-based evaluation in C++. It can be extended with more features such as functions, more operators, or improved error messages.