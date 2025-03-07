
#include <iostream>
#include <cmath>
#include <conio.h>    // For _getch()
#include <cstdlib>    // For system("cls")
#include <limits>
#include <cctype>

// Helper function to get validated double input.
double getDouble(const std::string& prompt, bool positive = false, bool nonzero = false) {
    double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a numeric value." << std::endl;
            continue;
        }
        if (positive && value < 0) {
            std::cout << "Value must be positive. Try again." << std::endl;
            continue;
        }
        if (nonzero && value == 0) {
            std::cout << "Value must be non-zero. Try again." << std::endl;
            continue;
        }
        return value;
    }
}

// Calculates future value given a present value, interest rate, number of periods, and periodic payment.
double calculate_future_value(double pv, double i, double n, double pmt = 0) {
    if (n < 0) {
        throw std::invalid_argument("Number of periods cannot be negative.");
    }
    if (i == 0) {
        return pv + pmt * n;
    }
    return pv * pow(1 + i, n) + pmt * (pow(1 + i, n) - 1) / i;
}

// Calculates present value required to achieve a given future value.
double calculate_present_value(double fv, double i, double n, double pmt = 0) {
    if (n < 0) {
        throw std::invalid_argument("Number of periods cannot be negative.");
    }
    if (i == 0) {
        return fv - pmt * n;
    }
    return (fv - pmt * (pow(1 + i, n) - 1) / i) / pow(1 + i, n);
}

// Calculates the interest rate (as a percentage) required to grow a present value to a future value over n periods.
double calculate_interest_rate(double fv, double pv, double n) {
    if (n <= 0) {
        throw std::invalid_argument("Number of periods must be greater than zero.");
    }
    if (pv <= 0) {
        throw std::invalid_argument("Present value must be greater than zero.");
    }
    return 100 * (pow(fv / pv, 1.0 / n) - 1);
}

// Calculates the number of periods required to grow a present value to a future value at a given interest rate.
double calculate_number_of_periods(double fv, double pv, double i) {
    if (i <= 0) {
        throw std::invalid_argument("Interest rate must be greater than zero.");
    }
    if (fv <= 0 || pv <= 0) {
        throw std::invalid_argument("Future and present values must be greater than zero.");
    }
    return log(fv / pv) / log(1 + i);
}

// Displays the menu with the current selection highlighted.
void display_menu(const char* options[], int numOptions, int selected) {
    system("cls"); // Clear the screen on Windows
    std::cout << "Use arrow keys or number keys to select an option, then press ENTER:\n\n";
    for (int i = 0; i < numOptions; i++) {
        if (i == selected) {
            std::cout << "-> ";
        } else {
            std::cout << "   ";
        }
        std::cout << "(" << (i + 1) << ") - " << options[i] << "\n";
    }
}

// Allows the user to choose an option using arrow keys or number keys.
int menu_selection(const char* options[], int numOptions) {
    int selected = 0;
    bool enterPressed = false;
    while (!enterPressed) {
        display_menu(options, numOptions, selected);
        int key = _getch();
        if (key == 224) { // Arrow keys
            key = _getch();
            if (key == 72) { // Up arrow
                selected = (selected - 1 + numOptions) % numOptions;
            } else if (key == 80) { // Down arrow
                selected = (selected + 1) % numOptions;
            }
        } else if (key == 13) { // Enter key
            enterPressed = true;
        } else if (isdigit(key)) {
            int num = key - '0';
            if (num >= 1 && num <= numOptions) {
                selected = num - 1;
                enterPressed = true;
            }
        }
    }
    return selected;
}

int main() {
    const int numOptions = 4;
    const char* options[numOptions] = {
        "Calculate Future Value",
        "Calculate Present Value",
        "Calculate Interest Rate",
        "Calculate Number of Periods"
    };

    bool userUsing = true;
    char cont;
    while (userUsing) {
        int selected = menu_selection(options, numOptions);
        system("cls");
        try {
            switch (selected) {
                case 0: { // Future Value
                    std::cout << "Calculate Future Value\n";
                    double pv = getDouble("Enter the present value: ", true);
                    double i = getDouble("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ");
                    double n = getDouble("Enter the number of periods: ", true);
                    double pmt = getDouble("Enter the periodic payment (enter 0 if none): ");
                    double fv = calculate_future_value(pv, i, n, pmt);
                    std::cout << "The future value is: " << fv << std::endl;
                    break;
                }
                case 1: { // Present Value
                    std::cout << "Calculate Present Value\n";
                    double fv = getDouble("Enter the target future value: ", true);
                    double i = getDouble("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ");
                    double n = getDouble("Enter the number of periods: ", true);
                    double pmt = getDouble("Enter the periodic payment (enter 0 if none): ");
                    double pv = calculate_present_value(fv, i, n, pmt);
                    std::cout << "The present value required is: " << pv << std::endl;
                    break;
                }
                case 2: { // Interest Rate
                    std::cout << "Calculate Interest Rate\n";
                    double pv = getDouble("Enter the present value: ", true);
                    double fv = getDouble("Enter the target future value: ", true);
                    double n = getDouble("Enter the number of periods: ", true);
                    double rate = calculate_interest_rate(fv, pv, n);
                    std::cout << "The interest rate required is: " << rate << "%" << std::endl;
                    break;
                }
                case 3: { // Number of Periods
                    std::cout << "Calculate Number of Periods\n";
                    double pv = getDouble("Enter the present value: ", true);
                    double fv = getDouble("Enter the target future value: ", true);
                    double i = getDouble("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ");
                    double n = calculate_number_of_periods(fv, pv, i);
                    std::cout << "The number of periods required is: " << n << std::endl;
                    break;
                }
                default:
                    std::cout << "Invalid selection." << std::endl;
                    break;
            }
        } catch (const std::exception& ex) {
            std::cout << "An error occurred: " << ex.what() << std::endl;
        }
        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> cont;
        cont = std::tolower(cont);
        userUsing = (cont == 'y');
    }
    return 0;
}
