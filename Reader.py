import numpy as np
import pandas as pd

# Replace 'file_path' with the actual path to your .npy file
file_path = 'C:/Users/pc/OneDrive/Documents/Visual Studio 2022/Repos/Simulator/GATE_Data/Simulations_OneMaterial/GateData/Water/positrons_8.npy'
data = np.load(file_path)

print(data)
print(data.shape)

# Convert the numpy array to a DataFrame for easier csv export
df = pd.DataFrame(data.reshape(-1, data.shape[-1]))

# Define the CSV file path
csv_file_path = 'C:/Users/pc/OneDrive/Documents/Visual Studio 2022/Repos/Simulator/GATE_Data/Simulations_OneMaterial/GateData/Water/positrons_8_data.csv'

# Save the DataFrame to a CSV file
df.to_csv(csv_file_path, index=False)

csv_file_path