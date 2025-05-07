double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
bool isValidNumber(const std::string& input, double& number);
char getOperation();
void calculatorLoop();


int main() {
	calculatorLoop();
	return 0;
}	

double add(double a, double b) {
	return a + b;
}	

double subtract(double a, double b) {
	return a - b;
}	

double multiply(double a, double b) {
	return a * b;
}

double divide(double a, double b) {
	if (b == 0) {
		std::cerr << "Error: Division by zero is not allowed." << std::endl;
		return 0; // Return 0 or handle the error as needed
	}
	return a / b;
}

bool isValidNumber(const std::string& input, double& number) {
	try {
		number = std::stod(input);
		return true;
	}
	catch (const std::invalid_argument&) {
		std::cerr << "Invalid input. Please enter a valid number." << std::endl;
		return false;
	}
	catch (const std::out_of_range&) {
		std::cerr << "Number out of range. Please enter a smaller number." << std::endl;
		return false;
	}
}

char getOperation() {
	char operation;
	std::cout << "Enter operation (+, -, *, /): ";
	std::cin >> operation;
	return operation;
}

void calculatorLoop() {
	std::string input1, input2;
	double num1, num2;
	char operation;
	while (true) {
		std::cout << "Enter first number (or 'q' to quit): ";
		std::cin >> input1;
		if (input1 == "q") {
			break; // Exit the loop if the user enters 'q'
		}
		if (!isValidNumber(input1, num1)) {
			continue; // Skip to the next iteration if the input is invalid
		}
		std::cout << "Enter second number: ";
		std::cin >> input2;
		if (!isValidNumber(input2, num2)) {
			continue; // Skip to the next iteration if the input is invalid
		}
		operation = getOperation();
		switch (operation) {
		case '+':
			std::cout << "Result: " << add(num1, num2) << std::endl;
			break;
		case '-':
			std::cout << "Result: " << subtract(num1, num2) << std::endl;
			break;
		case '*':
			std::cout << "Result: " << multiply(num1, num2) << std::endl;
			break;
		case '/':
			std::cout << "Result: " << divide(num1, num2) << std::endl;
			break;
		default:
			std::cerr << "Invalid operation. Please enter +, -, *, or /." << std::endl;
			break;
		}
	}
}

