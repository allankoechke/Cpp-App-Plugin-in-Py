#include <iostream>
#include <fstream>
#include <sstream>

// pybind11 imports
#include "../pybind11/include/pybind11/embed.h"

namespace py = pybind11;

std::string readMainPyFile()
{
    // File path for the main python file
    std::string pyFile = "../py/main.py";

    // Return read contents
    return pyFile;
}

void executePy()
{
    // Get main.py file contents
    std::string py_str = readMainPyFile();

    py::object scope = py::module_::import("__main__").attr("__dict__");

    // Execute the main python file
    py::eval_file(py_str, scope);
}

// Entry point for the C++ application
int main(int argc, char** argv)
{
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    std::cout << "Hello World from C++" << std::endl;

    executePy();

    return 0;
}