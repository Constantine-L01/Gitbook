# Lambda Expressions

## Capture Clause

*(Source: https://docs.microsoft.com/en-us/cpp/cpp/lambda-expressions-in-cpp?view=msvc-160)*

1. The lambda function can introduce or access variables of enclosing scope, and whether the accessing of variables of enclosing scope is by reference or by value is determined by **capture clause**. 
2. `[ ]` indicates that no variables in the enclosing scope are accessed.
3. `[&]` is captured by reference.
4. `[=]` is captured by value. 
