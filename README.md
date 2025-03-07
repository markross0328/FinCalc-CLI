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

## Project Structure

The project is organized into different folders for different operating systems and feature sets:

- **Root Directory**: Contains the original source files
- **windows/full**: Windows-specific version with full functionality (arrow key navigation and system commands)
- **windows/basic**: Windows version without system-specific features (no arrow key navigation)
- **mac/basic**: Mac-compatible version without Windows-specific features

## Requirements

### Python Version
- Python 3.6 or higher
- Windows operating system (for msvcrt module) - only for the full Windows version
- Any operating system for the basic version

### C++ Version
- C++ compiler with C++11 support (e.g., GCC, Visual C++)
- Windows operating system (for conio.h) - only for the full Windows version
- Any operating system for the basic version

## Running the Python Version

### Windows Full Version (with arrow key navigation)

1. Navigate to the windows/full directory:
   ```
   cd windows/full
   ```

2. Run the Python script:
   ```
   python main.py
   ```

3. Use the arrow keys (↑ and ↓) to navigate the menu or press the corresponding number key.

### Basic Version (Mac and Windows)

1. Navigate to the mac/basic or windows/basic directory:
   ```
   cd mac/basic
   ```
   or
   ```
   cd windows/basic
   ```

2. Run the Python script:
   ```
   python main.py
   ```

3. Enter the number corresponding to your menu choice.

## Running the C++ Version

### Windows Full Version (with arrow key navigation)

#### Using Visual Studio (Windows)

1. Open Visual Studio and create a new project.
2. Add the `windows/full/main.cpp` file to your project.
3. Build and run the project (F5).

#### Using Command Line (Windows with MinGW)

1. Navigate to the windows/full directory:
   ```
   cd windows/full
   ```

2. Compile the C++ code:
   ```
   g++ main.cpp -o fincalc
   ```

3. Run the compiled executable:
   ```
   ./fincalc
   ```

### Basic Version (Mac and Windows)

#### Using Command Line (Mac with GCC/Clang)

1. Navigate to the mac/basic directory:
   ```
   cd mac/basic
   ```

2. Compile the C++ code:
   ```
   g++ main.cpp -o fincalc
   ```
   or with Clang:
   ```
   clang++ main.cpp -o fincalc
   ```

3. Run the compiled executable:
   ```
   ./fincalc
   ```

#### Using Command Line (Windows with MinGW)

1. Navigate to the windows/basic directory:
   ```
   cd windows/basic
   ```

2. Compile the C++ code:
   ```
   g++ main.cpp -o fincalc
   ```

3. Run the compiled executable:
   ```
   ./fincalc
   ```

## Version Differences

### Full Windows Version
- Uses msvcrt for arrow key navigation in the Python version
- Uses conio.h for keyboard input in the C++ version
- Uses system("cls") to clear the console

### Basic Version (Mac and Windows)
- Uses simple numeric input for menu navigation
- No system-specific libraries or commands
- Compatible with most operating systems

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

