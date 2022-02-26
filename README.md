# C++11 Concepts

Below are the C++11 new features

# Inititalizer lists

## Member types

## member type	     =>          definition

value_type	         =>         The template parameter (T)

reference	           =>         const T&

const_reference	     =>         const T&

size_type	           =>         size_t

iterator	           =>         const T*

const_iterator	     =>         const T*


# Automation type deduction
# Rvalue references and move constructors

The reason why we are talking about temporary objects is because they are rvalue expressions, and whenever a temporary object is created, memory is allocated for that object, and the result from an expression is copied into it. The act of copying data into temporary objects is what can cause seemingly hidden performance issues within a C++ application, and are what move semantics aim to address.

## Move Semantics

Move semantics aim to avoid the copying of data from temporary objects by instead stealing the memory location of where the object resides. This behaviour is implemented through the use of a move constructor and move assignment operator that act only on rvalue references.

## std::move

It is wise to only use std::move on lvalues that we know aren’t going to get used anywhere else in the code, such as if they are local to the function in which a move constructor is being called.


# constexpr – Generalized constant expressions

There are two ways to resolve constant. Two ways are compile time and run time constant. 

### Run Time Constant : If const variable is assigned with variable which takes input at run time (after program launched).
### Compile Time Constant : If const variable is assigned with hardcoded value
### Constexpr keyword is added to assign value to constant variable by evaluating expression or function at compile time.

# Modification to the definition of plain old data
# Uniform initialization
# Range-based for loop
# Lambda functions and expressions
# Alternative function syntax
# Explicit overrides and final
# A constant null pointer, nullptr
# Strongly typed enumerations
# Right angle bracket not being treated as an operator at appropriate places
# Variadic templates
# Multithreading memory model
# Added Hash tables to the STL
# Added Regular expressions to the Standard Library
# Added General-purpose smart pointers like shared_ptr, weak_ptr, etc.
