# FinCalc-CLI

FinCalc-CLI is an interactive, command-line financial calculator written in both Python and C++. It offers robust error handling and supports both arrow-key and number-based menu navigation to compute future value, present value, interest rate, and number of years.

## Features

- Calculate future value of investments
- Calculate present value of investments
- Determine interest rate needed to reach a target value
- Calculate the number of years required to reach a target value
- Interactive menu with arrow key navigation
- Robust error handling for invalid inputs
- Available in both Python and C++ implementations

## Getting Started

### Clone the Repository

To get a local copy of this project, run the following command in your terminal:

```
git clone https://github.com/markross0328/FinCalc-CLI
cd FinCalc-CLI
```

## Requirements

### Python Version
- Python 3.6 or higher
- Windows operating system (for msvcrt module)

### C++ Version
- C++ compiler with C++11 support (e.g., GCC, Visual C++)
- Windows operating system (for conio.h)

## Running the Python Version

1. Ensure you have Python installed on your system. You can download it from [python.org](https://www.python.org/downloads/).

2. Open a command prompt or terminal in the project directory.

3. Run the Python script:
   ```
   python main.py
   ```

4. Use the arrow keys (↑ and ↓) to navigate the menu or press the corresponding number key.

5. Follow the prompts to input values for your financial calculations.

## Running the C++ Version

### Using Visual Studio (Windows)

1. Open Visual Studio and create a new project.
2. Add the `main.cpp` file to your project.
3. Build and run the project (F5).

### Using Command Line (Windows with MinGW)

1. Open a command prompt in the project directory.

2. Compile the C++ code:
   ```
   g++ main.cpp -o fincalc
   ```

3. Run the compiled executable:
   ```
   ./fincalc
   ```

## Usage

1. Select a calculation type from the menu.
2. Enter the required values when prompted.
3. View the calculation result.
4. Choose whether to perform another calculation or exit.

## Notes

- Both versions provide identical functionality but are implemented in different programming languages.
- The C++ version may offer better performance for complex calculations.
- The Python version may be easier to modify or extend.

## License

This project is open source. Please recommend or commit additional functionality to the program. 

