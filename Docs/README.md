# Garden Monitoring System

This project implements a garden monitoring system that collects data related to temperature, humidity, light intensity, and soil moisture in a garden environment. The system uses Arduino (or similar microcontrollers) to gather data from various sensors and logs the data into a CSV file. The data is then visualized and analyzed using Python.

## Features

- **Data Collection**: Collects data from various sensors: temperature, humidity, light intensity, and soil moisture.
- **Data Logging**: Saves the collected data into a CSV file for future analysis.
- **Data Visualization**: Visualizes the data with graphs, showing trends over time.
- **Basic Statistics**: Calculates and displays the mean and standard deviation of the collected data.
- **Python Integration**: Uses Python for data analysis and visualization, leveraging libraries like Pandas and Matplotlib.

## Components

- **Arduino or Microcontroller**: Used to collect data from sensors.
- **Sensors**:
  - Temperature Sensor (e.g., DHT11/DHT22)
  - Humidity Sensor (e.g., DHT11/DHT22)
  - Light Intensity Sensor (e.g., LDR)
  - Soil Moisture Sensor
- **CSV File**: `garden_log.csv` stores the data collected over time.
- **Python Scripts**:
  - `data_collector.ino` (Arduino code to read sensors and log data)
  - `data_visualizer.py` (Python code to visualize and analyze the data)

## Installation

### 1. **Set Up the Arduino Environment**

You need to install the Arduino IDE to upload the code to your Arduino board.

1. Download and install the [Arduino IDE](https://www.arduino.cc/en/software).
2. Connect your Arduino to your computer using a USB cable.
3. Install necessary libraries (e.g., DHT sensor library, Adafruit sensor libraries).

### 2. **Install Python Libraries**

You'll need Python and the following libraries to run the data analysis script:

```bash
pip install pandas matplotlib
```

### 3. **Upload Arduino Code**

Upload the `data_collector.ino` code to your Arduino to start collecting data from the sensors. This code will log data to the `garden_log.csv` file on your computer or a connected SD card.

### 4. **Run Python Code**

Once you have the CSV data, you can use the `data_visualizer.py` script to visualize and analyze it.

Run the Python script by executing the following command in your terminal:

```bash
python data_visualizer.py
```

## Project Structure

```
Garden-Monitoring-System/
│
├── data_collector.ino         # Arduino code to collect data from sensors
├── data_visualizer.py         # Python script to visualize and analyze the data
├── garden_log.csv             # CSV file containing the garden data (example data included)
├── README.md                 # Project documentation
```

## CSV File Structure

The `garden_log.csv` file contains the following columns:

- **Timestamp**: The time of data collection (in seconds).
- **Temperature (°C)**: The temperature of the garden in degrees Celsius.
- **Humidity (%)**: The humidity level in the garden.
- **Light Intensity**: The light intensity in the garden.
- **Soil Moisture**: The soil moisture level.

### Example `garden_log.csv`

```csv
Timestamp, Temperature (°C), Humidity (%), Light Intensity, Soil Moisture
1, 18, 55, 449, 343
2, 23, 63, 319, 478
3, 20, 42, 462, 256
...
```

## How to Use

### 1. **Collect Data**

Upload the Arduino code to your microcontroller. The code will start reading the sensors and logging data into the `garden_log.csv` file. The data will be saved periodically with a timestamp.

### 2. **Visualize Data**

After collecting enough data, run the `data_visualizer.py` script to generate visualizations and see trends in temperature, humidity, light intensity, and soil moisture over time.

### 3. **View Statistics**

The script will also print basic statistics like the mean and standard deviation for each parameter, helping you analyze the data.

## Example Output

When you run the `data_visualizer.py` script, you should see:

- A graph showing the temperature, humidity, light intensity, and soil moisture over time.
- Printed statistics in the terminal, like:

```
Basic Statistics:
Temperature: Mean = 22.4°C, Std Dev = 4.5°C
Humidity: Mean = 48.5%, Std Dev = 10.3%
Light Intensity: Mean = 435.3, Std Dev = 155.2
Soil Moisture: Mean = 315.7, Std Dev = 121.7
```

## Future Enhancements

- **Real-time Monitoring**: Use a real-time dashboard to monitor data as it is collected.
- **Alerts**: Set thresholds for critical conditions (e.g., high temperature, low soil moisture) and receive alerts via email or SMS.
- **Database Integration**: Store the data in a database for more robust querying and reporting.
- **Weather Forecast API**: Integrate a weather forecast API to compare real-time data with weather predictions.

