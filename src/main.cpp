#include <iostream>

// pybind11 imports
#include "../pybind11/include/pybind11/embed.h"

namespace py = pybind11;

void executePy()
{
    py::print("Hello, World from Python in C++!"); // use the Python API
}

// Entry point for the C++ application
int main(int argc, char** argv)
{
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    std::cout << "Hello World from C++" << std::endl;

    executePy();

    return 0;
}