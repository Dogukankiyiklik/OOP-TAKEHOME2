#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// operation of multiplication
class Multiplication {
private:
	int firstNumber, secondNumber, result;

public:
	// constructor
	Multiplication(int first, int second) {
		firstNumber = first;
		secondNumber = second;
		result = 0;
	}
	
	int doMultiplication() {
		result = firstNumber * secondNumber;
		return result;
	}

	void print() {
		cout << "The result of " << firstNumber << " * " << secondNumber << " is: " << result << endl;
	}
};

// operation of addition
class Addition {
private:
	int firstNumber, secondNumber, result;

public:
	// constructor
	Addition(int first, int second) {
		firstNumber = first;
		secondNumber = second;
		result = 0;
	}

	int doAddition() {
		result = firstNumber + secondNumber;
		return result;
	}

	void print() {
		cout << "The result of " << firstNumber << " + " << secondNumber << " is: " << result << endl;
	}
};

// operation of substraction
class Substraction {
private:
	int firstNumber, secondNumber, result;

public:
	// constructor
	Substraction(int first, int second) {
		firstNumber = first;
		secondNumber = second;
		result = 0;
	}

	int doSubstraction() {
		result = firstNumber - secondNumber;
		return result;
	}

	void print() {
		cout << "The result of " << firstNumber << " - " << secondNumber << " is: " << result << endl;
	}
};

// operation of reading
class fileReader {
private:
    string filePath;

public:
    // constructor
    fileReader(string path) { filePath = path; }

    void read() {
        ifstream myFile(filePath);

        // check if the file couldn't be opened
        if (!myFile) cout << "File could not be opened" << endl;

		// this variable for storing to how many numbers are in the input.txt file
        int pieceOfNumbers;
        myFile >> pieceOfNumbers;

		// this array for store the numbers
        int* numbers = new int[pieceOfNumbers];
		int* numbersOfDigit = new int[pieceOfNumbers];

		// this variable for taking the number from txt file
        int tempNumbers, digitNumber;

        for (int i = 0; i < pieceOfNumbers; i++) {
			myFile >> digitNumber;
			numbersOfDigit[i] = digitNumber;

            myFile >> tempNumbers;
            numbers[i] = tempNumbers;
        }

		char operation;
		int x, y;

		while (myFile >> operation) {

			myFile >> x >> y;

			switch (operation) {
			case 'A':
			{
				Addition resultOfAddition(numbers[x - 1], numbers[y - 1]);
				resultOfAddition.doAddition();
				resultOfAddition.print();
				break;
			}

			case 'M':
			{
				Multiplication resultOfMultiplication(numbers[x - 1], numbers[y - 1]);
				resultOfMultiplication.doMultiplication();
				resultOfMultiplication.print();
				break;
			}

			case 'S':
			{
				Substraction resultOfSubstractionn(numbers[x - 1], numbers[y - 1]);
				resultOfSubstractionn.doSubstraction();
				resultOfSubstractionn.print();
				break;
			}

			default:
				break;
			}
		}
    }
};

int main()
{
	fileReader file("input.txt");
	file.read();
}


#if 0
// Remember we are storing digits of our number into 
//each memory locations, not entire number into one memory location.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    string num1 = "99999999999999";  /* taking input as a string */
    string num2 = "999999999999999999999991";

    // creating vectors to store numbers digit
    vector <int> number1;
    vector <int> number2;
    // this vector for storing answer 
    vector <int> ans;

    // stroing into vectors
    for (int i = 0; i < num1.size(); i++)
        number1.push_back(num1[i] - '0');  /* converting from character to int (ASCII conversion) */

    for (int i = 0; i < num2.size(); i++)
        number2.push_back(num2[i] - '0');  /* converting from character to int (ASCII conversion) */

    // reversing numbers for operate math operations
    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());

    // for loop
    int maxDigit = max(number1.size(), number2.size());
    int carry = 0;
    int tempResult;

    if (number1.size() > number2.size()) {
        for (int i = 0; i < maxDigit - number2.size(); i++) {
            number2.push_back(0);
        }
    }

    int sayac = maxDigit - number1.size();

    if (number1.size() < number2.size()) {
        for (int i = 0; i < sayac; i++) {
            number1.push_back(0);
        }
    }


    for (int i = 0; i < maxDigit; i++) {
        tempResult = number1[i] + number2[i] + carry;
        ans.push_back(tempResult % 10);
        carry = tempResult / 10;
    }

    while (carry) {
        ans.push_back(carry % 10);
        carry = carry / 10;
    }

    reverse(number1.begin(), number1.end());
    reverse(number2.begin(), number2.end());
    reverse(ans.begin(), ans.end());

    while (number1[0] == 0 || number2[0] == 0) {

        if (number1[0] == 0) {
            number1.erase(number1.begin());
        }

        else if (number2[0] == 0) {
            number2.erase(number2.begin());
        }
    }

    cout << "The sum of ";
    for (auto i : number1) {
        cout << i;
    }
    cout << " and ";
    for (auto i : number2) {
        cout << i;
    }
    cout << " is: ";

    for (auto i : ans) {
        cout << i;
    }
}
#endif