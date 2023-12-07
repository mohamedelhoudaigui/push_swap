import subprocess
import random

n_tests = int(input("Enter the number of tests: "))
n_numbers = int(input("Enter the number of numbers: "))

for _ in range(n_tests):
    rand_ints = random.sample(range(0, 2147483647), n_numbers)
    bash_command = f"./push_swap {' '.join(map(str, rand_ints))} | wc -l"
    subprocess.run(bash_command, shell=True)

#checker_Mac {' '.join(map(str, rand_ints))}