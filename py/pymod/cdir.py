# This file is used as an external python module to be imported
# to the main.py file. 
# 
# Nothing fancy going on here, just one function

import os

# Returns the current working directory
def getCurrentDirectory():
    return os.getcwd()