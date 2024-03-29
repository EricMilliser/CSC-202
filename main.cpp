/*
Author:  Eric Milliser
Date written: 03/25/24
Assignment:   <Module1 exercise1 part1
Short Desc: cube class to calculate the volume and validate user input
*/


#include <iostream>
#include <iomanip>
#include <string>
#include "headerMethods.h"




int main() //main function
{//begin main

	//declarations
	Cube newCube; //class cube to store input variables

	int input, volume; //interget input and volumes
	std::string stringInput; //standard string input variable
	bool complete = false; //flag control variable
	char yesNo; // sentinal control variable


	std::cout << "M01 Programming Assignment Part 1" << std::endl;


	while (complete == false) //while the program is not complete
	{

		//NOTE: I used std:: at the start of everything as I have had many
		//errors befoer that have gotten in the way of the program.
		std::cout << "Please enter the length of the Cube: "; //prompt length input
		std::cin >> input; //input
		input = inputValid(input, 0, 2147483647); //validate the input within the range of integer and not negatvie
		newCube.setLength(input); //set the longth using the setter

		std::cout << "Please enter the width of the Cube: "; //prompt width input
		std::cin >> input; //input
		input = inputValid(input, 0, 2147483647); //validate input
		newCube.setWidth(input); //set width

		std::cout << "Please enter the height of the Cube: "; //prompt height
		std::cin >> input; //input
		input = inputValid(input, 0, 2147483647); //validate
		newCube.setHeight(input); //set

		std::cout << "Please enter the color of the Cube: "; //prompt color
		std::cin.ignore(100, '\n'); //ignore the whitespace
		std::getline(std::cin, stringInput); //get the line for a color
		newCube.setColor(stringInput); ///set the colore


		//OUT PUT THE DETAILS OF THE CUBE
		std::cout << std::endl;
		std::cout << "Length of the cube is: " << newCube.getLength() << std::endl;
		std::cout << "Width of the cube is: " << newCube.getWidth() << std::endl;
		std::cout << "Height of the cube is: " << newCube.getHeight() << std::endl;
		std::cout << "Color of the cube is: " << newCube.getColor() << std::endl;
		std::cout << "Volume of the cube is: " << newCube.calculateVolume() << std::endl;
		std::cout << std::endl;

		std::cout << "Do you wish to change any of these variables ([Y}es or [N]o?): "; //prompt to see if the user wishes to change anything
		std::getline(std::cin, stringInput); //getline for yes or no
		yesNo = validYesNo(stringInput); //validate if it is yes or no

		while (yesNo == 'y') //while the user wishes to change something
		{
			//menu choices to change something
			std::cout << "What do you wish to change? " << std::endl;
			std::cout << "1. Length" << std::endl;
			std::cout << "2. Width" << std::endl;
			std::cout << "3. Height" << std::endl;
			std::cout << "4. Color" << std::endl;
			std::cin >> input; //input the choice
			input = inputValid(input, 1, 4); //validate that it is one of the choices

			switch (input) //switch user choice
			{
			case 1: //case 1: change length
			{
				std::cout << "Please enter the length of the Cube: ";
				std::cin >> input;
				input = inputValid(input, 0, 2147483647);
				newCube.setLength(input);
				break;
			}
			case 2: //case 2: change width
			{
				std::cout << "Please enter the width of the Cube: ";
				std::cin >> input;
				input = inputValid(input, 0, 2147483647);
				newCube.setWidth(input);
				break;
			}
			case 3: //case 3: change height
			{
				std::cout << "Please enter the height of the Cube: ";
				std::cin >> input;
				input = inputValid(input, 0, 2147483647);
				newCube.setHeight(input);
				break;
			}
			case 4: //case 4: change color
			{
				std::cout << "Please enter the color of the Cube: ";
				std::cin.ignore(100, '\n');
				std::getline(std::cin, stringInput);
				newCube.setColor(stringInput);
				break;
			}
			}
			
			//display information again
			std::cout << std::endl;
			std::cout << "Length of the cube is: " << newCube.getLength() << std::endl;
			std::cout << "Width of the cube is: " << newCube.getWidth() << std::endl;
			std::cout << "Height of the cube is: " << newCube.getHeight() << std::endl;
			std::cout << "Color of the cube is: " << newCube.getColor() << std::endl;
			std::cout << "Volume of the cube is: " << newCube.calculateVolume() << std::endl;
			std::cout << std::endl;


			//prompt to change again
			std::cout << "Do you wish to change any of these variables ([Y}es or [N]o?): ";
			std::getline(std::cin, stringInput); //input string
			yesNo = validYesNo(stringInput); //validate if yes or no
		}
	
		complete = true; //set flag to true

	}
	
	
	return 0; //return 0 and end

}