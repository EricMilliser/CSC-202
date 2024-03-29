/*
Author:  Eric Milliser
Date written: 03/25/24
Assignment:   <Module1 exercise1 part1
Short Desc: cube class to calculate the volume and validate user input
*/





#include <iostream>
#include <string>
#include <iomanip>




char validYesNo(std::string input) //valaidation for yes or no
{
	char response; //declare a char variable

	response = tolower(input[0]); //set response to the first letter of the parameter input


	while (response != 'y' && response != 'n') //while it is not one of the choices
	{
		std::cout << "Please enter [Y]es or [N]o: "; //reporompt
		std::getline(std::cin, input); //get line

		response = tolower(input[0]); //set to lower
	}

	return response; //return respones
}



int inputValid(int input, int param1, int param2) //validate input function within parameters
{
	bool checkFail = std::cin.fail(); //set to wether the input failed or not

	while (checkFail == true || (input < param1 || input > param2)) //while the conditions of not within the valuse or there was input failure
	{
		if (checkFail == true) //checking for input falure
		{

			///clear and ignore whitespace, then reprompt and validate
			std::cin.clear();
			std::cin.ignore(100, '\n');
			std::cout << ("You entered something that was not a number. Please Try again.") << std::endl;
			std::cin >> input; 
			checkFail = std::cin.fail();
		}
		if (input < param1 || input > param2) //prompt until within range
		{
			std::cout << ("Please enter something within the range ") << param1 << " to " << param2 << std::endl;
			std::cin >> input;
			checkFail = std::cin.fail();
		}
	}

	return input;
}




class Cube //class cube
{
private:
	//private declarations
	int length = 0;
	int width = 0;
	int height = 0;
	std::string color = "null";


public:

	//setter and getters for each variable.
	int getLength()
	{
		return length;
	}


	int getWidth()
	{
		return width;
	}

	int getHeight()
	{
		return height;
	}


	std::string getColor()
	{
		return color;
	}


	void setLength(int l)
	{
		length = l;
	}

	void setWidth(int w)
	{
		width = w;
	}

	void setHeight(int h)
	{
		height = h;
	}

	void setColor(std::string c)
	{
		color = c;
	}
		

	int calculateVolume()
	{
		int volume = length * width * height;

		return volume;
	}

		
};