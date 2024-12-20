import pandas as pd
import matplotlib.pyplot as plt

# Load the CSV data into a DataFrame
def load_data(file_path):
    """Loads the garden data from a CSV file."""
    try:
        return pd.read_csv(file_path, encoding='utf-8')  # Try UTF-8 first
    except UnicodeDecodeError:
        return pd.read_csv(file_path, encoding='utf-16')  # Try UTF-16 if UTF-8 fails
    except FileNotFoundError:
        print(f"Error: The file at {file_path} was not found.")
        raise

# Plot the data
def plot_data(df):
    """Plots the garden data."""
    plt.figure(figsize=(10, 6))

    # Plot Temperature
    plt.subplot(2, 2, 1)
    plt.plot(df['Timestamp'], df['Temperature (°C)'], color='red', label='Temperature (°C)')
    plt.xlabel('Timestamp')
    plt.ylabel('Temperature (°C)')
    plt.title('Temperature Over Time')
    plt.grid(True)

    # Plot Humidity
    plt.subplot(2, 2, 2)
    plt.plot(df['Timestamp'], df['Humidity (%)'], color='blue', label='Humidity (%)')
    plt.xlabel('Timestamp')
    plt.ylabel('Humidity (%)')
    plt.title('Humidity Over Time')
    plt.grid(True)

    # Plot Light Intensity
    plt.subplot(2, 2, 3)
    plt.plot(df['Timestamp'], df['Light Intensity'], color='green', label='Light Intensity')
    plt.xlabel('Timestamp')
    plt.ylabel('Light Intensity')
    plt.title('Light Intensity Over Time')
    plt.grid(True)

    # Plot Soil Moisture
    plt.subplot(2, 2, 4)
    plt.plot(df['Timestamp'], df['Soil Moisture'], color='purple', label='Soil Moisture')
    plt.xlabel('Timestamp')
    plt.ylabel('Soil Moisture')
    plt.title('Soil Moisture Over Time')
    plt.grid(True)

    # Display the plots
    plt.tight_layout()
    plt.show()

# Calculate basic statistics
def print_statistics(df):
    """Prints basic statistics of the garden data."""
    print("\nBasic Statistics:")
    print(f"Temperature: Mean = {df['Temperature (°C)'].mean():.2f}°C, Std Dev = {df['Temperature (°C)'].std():.2f}")
    print(f"Humidity: Mean = {df['Humidity (%)'].mean():.2f}%, Std Dev = {df['Humidity (%)'].std():.2f}")
    print(f"Light Intensity: Mean = {df['Light Intensity'].mean():.2f}, Std Dev = {df['Light Intensity'].std():.2f}")
    print(f"Soil Moisture: Mean = {df['Soil Moisture'].mean():.2f}, Std Dev = {df['Soil Moisture'].std():.2f}")

if __name__ == "__main__":
    # Path to your CSV file
    file_path = r'C:\Users\Eli\Desktop\MY PROJECTS\smart-garden-monitoring-system\SmartGarden\Data\garden_log.csv'

    # Load the data
    df = load_data(file_path)

    # Print statistics
    print_statistics(df)

    # Visualize the data
    plot_data(df)
