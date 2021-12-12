// Jordan Ballard
// Module 4 Assignment: Working with Files

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

double TempConversion(double& tempF)  // Function to convert Fahrenheit to Celsius
{
	double tempC;  // Declare variable for use within function

	tempC = (tempF - 32) * (5.0 / 9.0);  // Perform conversion

	tempF = tempC;  // Reassign variable with converted value

	return tempF;  // Return updated variable
}

void OpenCityF(ifstream& cityReadFS) // Function to open FahrenheitTemperature for reading
{
	cout << "Opening file for reading: FahrenheitTemperature.txt " << endl;

	cityReadFS.open("FahrenheitTemperature.txt");  // Use ifstream variable to use .open() function to open file for reading
	if (cityReadFS.is_open())  // Confirm file has opened
	{
		cout << "FahrenheitTemperature.txt is open." << endl;
	}
}

void OpenCityC(ofstream& cityWriteFS)  // Function to open CelsiusTemperature for writing
{
	cout << endl << "Opening file for writing: CelsiusTemperature.txt..." << endl;

	cityWriteFS.open("CelsiusTemperature.txt");  // Use ofstream variable to use .open() function to open file for writing
	if (cityWriteFS.is_open())  // Confirm file has opened
	{
		cout << "CelsiusTemperature.txt is open." << endl;
	}
}

void WriteToFile(ifstream& cityReadFS, ofstream& cityWriteFS) // Function to read FahrenheitTemperature.txt, convert, then write to CelsiusTemperature.txt
{															 
	string cityName;  // Declare variables for use within function
	double tempF;

	cout << endl << "Converting temperatures from FahrenheitTemperature.txt and writing to CelsiuTemperature.txt..." << endl;
	while (!cityReadFS.eof())  // Loop until end of file is reached
	{
		cityReadFS >> cityName >> tempF;  // Read FahrenheitTemperature.txt and store input into cityName, then tempF

		TempConversion(tempF);  // Convert Fahrenheit to Celsius

		cityWriteFS << cityName << " " << tempF << endl;  // Write new conversion to CelsiusTemperature.txt with the city name
	}

	cout << endl << "Writing to CelsiusTemperature.txt complete." << endl;
}

void CloseFiles(ifstream& cityReadFS, ofstream& cityWriteFS)  // Function to close files
{
	cout << endl << "Closing file: FahrenheitTemperature.txt..." << endl;
	cityReadFS.close();  // Close FahrenheitTemperature.txt
	cout << "File closed." << endl;

	cout << endl << "Closing file: CelsiusTemperature.txt..." << endl;
	cityWriteFS.close(); // Close CelsiusTemperature.txt
	cout << "File closed." << endl;
}

int main()
{
	ifstream cityReadFS;  // Input file stream
	ofstream cityWriteFS;  // Output file stream

	OpenCityF(cityReadFS);  // Call function to open FahrenheitTemperature.txt
	if (!cityReadFS.is_open())  // Exit main if FahrenheitTemperature fails to open
	{
		cout << "Could not open FahrenheitTemperature.txt." << endl;
		return 1;
	}

	OpenCityC(cityWriteFS);  // Call function to open CelsiusTemperature.txt
	if (!cityWriteFS.is_open())  // Exit main if CelsiusTemperature fails to open
	{
		cout << "Could not open CelsiusTemperature.txt." << endl;
		return 1;
	}

	WriteToFile(cityReadFS, cityWriteFS);  // Call function to read FahrenheitTemperature.txt and write to CelsiusTemperature.txt

	CloseFiles(cityReadFS, cityWriteFS);  // Call function to close both files

	return 0;
}