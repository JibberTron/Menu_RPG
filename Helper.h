#pragma once
#include <iostream>
#include <string>
#include <random>

namespace Helper
{
	
	static bool IsInteger(char* _input)
	{
		if (std::isdigit(*_input) || *_input < '0')
		{
			printf("%s", "True");
			return true;
		}
		else {
			printf("%s", "False");
			return false;
		}
	}

	static void PrintIntegerBinary(int* _num)
	{
		unsigned int binary[32];
		unsigned int  index= 0;
		for (index; index < 32; ++index)
		{
			binary[index] = *_num % 2;
			*_num /= 2;
		}
		for (int j = index - 1; j >= 0; --j)
		{
			printf("%u", binary[j]);
		}		
	}

	// i made this to where for the size send the sizeof(array) to be passed as the _size parameter
	static void BubbleSort(int* _arr, int _size )
	{
		_size /=  4;

		bool bWasSwapped;
		
		do {
			bWasSwapped = false;
			for (int i = 1; i < _size; ++i)
			{
				if (_arr[i - 1] > _arr[i])
				{
					std::swap(_arr[i - 1], _arr[i]);
					bWasSwapped = true;
				}
			}
			_size -= 1;
		} while (bWasSwapped);	
	}

	static void CleanInputBuffer()
	{
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
	}

	static void ClearConsoleWindow()
	{
		system("cls");
	}

	static void PauseConsoleWindow()
	{
		printf("%s", "\n\nPress Enter to continue");
		std::cin.get();
	}
	static bool IsPositiveInteger(char* _array)
	{
		int length = strlen(_array) + 1;
		bool bIsPositive = false;
		for (int i = 0; i < length -  1; ++i)
		{
			int val = _array[i];
			if ( val > 0)
			{
				printf("\n");
				std::cout << val << " is greater than 0\n";
				bIsPositive = true;
			}
			else{
				printf("\n");
				std::cout << val << " is less than 0\n";
				bIsPositive = false;
				break;
			}		
		}
		return bIsPositive;
	}

	template<typename T>
	static T RandomNumberGenerator(T _min, T _max)
	{
		static std::mt19937 gen{ std::random_device{}() };

		if constexpr(std::is_integral_v<T>)
		{
			std::uniform_int_distribution<T> dist(_min, _max);
			return dist(gen);
		}
		else if constexpr (std::is_floating_point_v<T>)
		{
			std::uniform_real_distribution<T> dist(_min, _max);
			return dist(gen);
		}
	}

	static void PrintIntegerHex(int* _num)
	{
		int byte = 0;
		std::string display = " ";
		for (int i = 0; i < 32; ++i)
		{

			byte = *_num % 16;
			std::string byteString = std::to_string(byte);

			switch (byte)
			{
			case 10:
				byteString = "A";
				break;
			case 11:
				byteString = "B";
				break;
			case 12:
				byteString = "C";
				break;
			case 13:
				byteString = "D";
				break;
			case 14:
				byteString = "E";
				break;
			case 15:
				byteString = "F";
				break;

			default:
				break;
			}
			if (byte > 0)
			{
				display = byteString + display;
				*_num /= 16;
			}
		}
		std::cout << display;
	}

	static void PrintIntegerOct(int* _num)
	{
		int byte = 0;
		std::string octString = " ";

for (int i = 0; i < 32; ++i)
{
	byte = *_num % 8;
	std::string insideString = std::to_string(byte);

	octString = insideString + octString;
	*_num /= 8;
}
std::cout << octString;
	}

	static void UserInputBool(bool* _value)
	{
		if (*_value == true)
		{
			printf("%s", "True\n");
		}
		else if (*_value == false)
		{
			printf("%s", "False\n");
		}
		else {
			printf("%s", "Please enter a valid value, True or 1, False or 0\n");
		}
	}

	static void IntegerSwap(int& _intA, int& _intB)
	{
		int placeholder = _intA;
		_intA = _intB;
		_intB = placeholder;
	}

	static bool IsEven(int* _num)
	{
		if (*_num % 2 == 0)
		{
			return true;
		}
		else {
			return false;
		}
	}

	static int GetMaxValue(int* _num1, int* _num2)
	{
		if (*_num1 >= *_num2)
		{
			return *_num1;
		}
		else {
			return *_num2;
		}
	}

	static int GetMinValue(int* _num1, int* _num2)
	{
		if (*_num1 <= *_num2)
		{
			return *_num1;
		}
		else {
			return *_num2;
		}
	}

	static void ClampInteger(int* _value, int _min, int _max)
	{
		if (*_value > _max)
		{
			*_value = _max;
		}
		else if (*_value < _min)
		{
			*_value = _min;
		}
	}

	static void MemoryLeakDetector()
	{
		// Change this number to the line number the Output window shows you
		// to follow a memory leak. Put -1 to disable.
#define MEMORY_LEAK_LINE  -1

		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		_CrtSetBreakAlloc(MEMORY_LEAK_LINE);
		_CrtDumpMemoryLeaks();
	}

	static bool ValidateRange(int _value, int _min, int _max)
	{
		bool bIsInRange = false;
		int userinput;
		
		do {
			printf("%s", "Value: ");
			std::cin >> userinput;
			_value = userinput;
			if (userinput > _max || userinput < _min)
			{
				printf("%s", "Please choose value in range\n");
				bIsInRange = false;
			}
			else {
				bIsInRange = true;
			}
		} while (!bIsInRange);
		return bIsInRange;
	}

	static int GetMenuChoice(int& _min, int& _max)
	{
		std::cout << "Please choose from given values\n";
		int userChoice;
		do {
			std::cout << "Choice: ";
			std::cin >> userChoice;
			if (userChoice > _max || userChoice < _min)
			{
				std::cout << "Please choose a valid value\n";
			}
		} while (userChoice > _max || userChoice < _min);
		return userChoice;
	}

}
