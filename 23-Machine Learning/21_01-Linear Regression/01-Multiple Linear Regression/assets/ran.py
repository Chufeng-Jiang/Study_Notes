import numpy as np

# Generate a 1000x5 matrix with random values between 0 and 99
random_matrix = np.random.uniform(0, 99, (80, 35))

# Round to 2 decimal places
random_matrix = np.round(random_matrix, 4)

# Print the matrix (optional)
print(random_matrix)

# Define the file path where you want to save the CSV file
file_path = 'random_matrix.txt'

# Save the matrix to a CSV file
np.savetxt(file_path, random_matrix, delimiter=',')

print(f"Matrix saved to {file_path}")

