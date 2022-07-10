#! /usr/bin/python3

import subprocess
import sys


def main():
    test_name = sys.argv[1]
    rtest_name = "r" + test_name
    subprocess.run(["make"])
    subprocess.run(["diff", 
                    f"<(make {rtest_name})",
                    f"<(make {test_name})"])

if __name__ == "__main__":
    main()
