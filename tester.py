import subprocess
import random

n_tests = int(input("Enter the number of tests: "))
n_numbers = int(input("Enter the number of numbers: "))
threshold = 5500  # Adjust this threshold as needed

for _ in range(n_tests):
    rand_ints = random.sample(range(-500, 500), n_numbers)
    input_list = ' '.join(map(str, rand_ints))
    bash_command = f"./push_swap {input_list} | wc -l"
    
    # Capture the output of the subprocess
    result = subprocess.run(bash_command, shell=True, capture_output=True, text=True)
    
    # Check if the test failed (result is greater than the threshold)
    if int(result.stdout.strip()) > threshold:
        print(f"Failed Test:")
        print(f"Test input: {input_list}")
        print(f"Test result: {result.stdout.strip()}")
        print("-" * 30)
