#include <iostream>
#include <cmath>
#include <limits>
#include <string>

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

// Calculates interest rate required to achieve a given future value from a present value.
double calculate_interest_rate(double fv, double pv, double n, double pmt = 0) {
    if (pmt != 0) {
        throw std::invalid_argument("Payment must be zero for interest rate calculation.");
    }
    if (n <= 0) {
        throw std::invalid_argument("Number of periods must be greater than zero.");
    }
    if (pv <= 0) {
        throw std::invalid_argument("Present value must be greater than zero.");
    }
    // Returns percentage interest rate.
    return 100 * (pow(fv / pv, 1 / n) - 1);
}

// Calculates number of periods required to achieve a given future value from a present value.
double calculate_number_of_years(double fv, double pv, double i, double pmt = 0) {
    if (pmt != 0) {
        throw std::invalid_argument("Payment must be zero for calculating number of periods.");
    }
    if (i == 0) {
        throw std::invalid_argument("Interest rate cannot be zero for calculating number of periods.");
    }
    if (fv <= 0 || pv <= 0) {
        throw std::invalid_argument("Future and present values must be greater than zero.");
    }
    return log(fv / pv) / log(1 + i);
}

// Display menu options
void display_menu() {
    std::cout << "\n===== FinCalc-CLI =====" << std::endl;
    std::cout << "Select an option by entering the corresponding number:" << std::endl << std::endl;
    std::cout << "1. Calculate Future Value" << std::endl;
    std::cout << "2. Calculate Present Value" << std::endl;
    std::cout << "3. Calculate Interest Rate" << std::endl;
    std::cout << "4. Calculate Number of Years" << std::endl;
    std::cout << "5. Exit" << std::endl << std::endl;
}

// Get menu selection from user
int menu_selection() {
    int choice;
    while (true) {
        display_menu();
        std::cout << "Enter your choice (1-5): ";
        std::cin >> choice;
        
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number." << std::endl;
            continue;
        }
        
        if (choice >= 1 && choice <= 5) {
            return choice;
        } else {
            std::cout << "Invalid choice. Please enter a number between 1 and 5." << std::endl;
        }
    }
}

int main() {
    while (true) {
        try {
            int choice = menu_selection();
            
            if (choice == 5) {
                std::cout << "Goodbye!" << std::endl;
                break;
            }
            
            std::cout << "\n========================================\n" << std::endl;
            
            double pv, fv, i, n, pmt, result;
            
            switch (choice) {
                case 1:
                    std::cout << "Calculate Future Value" << std::endl;
                    pv = getDouble("Enter the present value: ", true);
                    i = getDouble("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ");
                    n = getDouble("Enter the number of years: ", true);
                    pmt = getDouble("Enter the payment (enter 0 if none): ");
                    result = calculate_future_value(pv, i, n, pmt);
                    std::cout << "Future Value: " << result << std::endl;
                    break;
                    
                case 2:
                    std::cout << "Calculate Present Value" << std::endl;
                    fv = getDouble("Enter the future value: ", true);
                    i = getDouble("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ");
                    n = getDouble("Enter the number of years: ", true);
                    pmt = getDouble("Enter the payment (enter 0 if none): ");
                    result = calculate_present_value(fv, i, n, pmt);
                    std::cout << "Present Value: " << result << std::endl;
                    break;
                    
                case 3:
                    std::cout << "Calculate Interest Rate" << std::endl;
                    fv = getDouble("Enter the future value: ", true);
                    pv = getDouble("Enter the present value: ", true);
                    n = getDouble("Enter the number of years: ", true);
                    pmt = getDouble("Enter the payment (must be 0 for this calculation): ");
                    if (pmt != 0) {
                        std::cout << "Error: Payment must be 0 for interest rate calculation." << std::endl;
                    } else {
                        result = calculate_interest_rate(fv, pv, n, pmt);
                        std::cout << "Interest Rate: " << result << "%" << std::endl;
                    }
                    break;
                    
                case 4:
                    std::cout << "Calculate Number of Years" << std::endl;
                    fv = getDouble("Enter the future value: ", true);
                    pv = getDouble("Enter the present value: ", true);
                    i = getDouble("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ");
                    pmt = getDouble("Enter the payment (must be 0 for this calculation): ");
                    if (pmt != 0) {
                        std::cout << "Error: Payment must be 0 for calculating number of years." << std::endl;
                    } else if (i == 0) {
                        std::cout << "Error: Interest rate cannot be zero for calculating number of years." << std::endl;
                    } else {
                        result = calculate_number_of_years(fv, pv, i, pmt);
                        std::cout << "Number of Years: " << result << std::endl;
                    }
                    break;
            }
            
        } catch (const std::exception& e) {
            std::cout << "An error occurred: " << e.what() << std::endl;
        }
        
        std::cout << "\n========================================" << std::endl;
        
        std::string cont;
        std::cout << "\nDo you want to perform another calculation? (y/n): ";
        std::cin >> cont;
        
        if (cont != "y" && cont != "Y") {
            std::cout << "Goodbye!" << std::endl;
            break;
        }
    }
    
    return 0;
} 