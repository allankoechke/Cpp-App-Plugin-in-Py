# This is the main python file to be executed from C++ side
# It does nothing special, just gets and prints the current
# working directory for the application 

import os
import sys

# Solves error that there is no parent package
# sys.path.append( os.path.dirname( os.path.dirname( os.path.abspath(__file__) ) ) )
# print(os.path.abspath(__file__))
p = "/mnt/sda8/Workspace/Cplusplus/Cpp/Cpp-App-Plugin-in-Py/py/main.py"
sys.path.append( os.path.dirname( os.path.dirname( p ) )  )
__package__= "py"

# print(">> ", os.path.dirname( p )  )
# print(">> ", os.path.dirname( os.path.dirname( p ) ) )

from .pymod.cdir import getCurrentDirectory

if __name__ == "__main__":
    print("Running on python side")

    print("Current working directory is: ", getCurrentDirectory())

    print("Ending python code!")