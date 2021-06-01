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

    std::ifstream inFile(pyFile);

    std::ostringstream ss;
    
    // Read the whole main file
    ss << inFile.rdbuf();

    // Convert the read stream to std string
    std::string pyContent = ss.str();

    // std::cout << "Python file is: " << pyContent << std::endl;

    inFile.close();

    // Return read contents
    return pyContent;
}

void executePy()
{
    // Get main.py file contents
    std::string py_str = readMainPyFile();

    // Execute the main python file
    py::exec(py_str);
}

// Entry point for the C++ application
int main(int argc, char** argv)
{
    py::scoped_interpreter guard{}; // start the interpreter and keep it alive

    std::cout << "Hello World from C++" << std::endl;

    executePy();

    return 0;
}