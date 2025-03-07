import math
import msvcrt
import os

def get_float(prompt, positive=False, nonzero=False):
    """Prompt the user for a floating-point number with optional checks."""
    while True:
        try:
            value = float(input(prompt))
            if positive and value < 0:
                print("Value must be positive. Try again.")
                continue
            if nonzero and value == 0:
                print("Value must be non-zero. Try again.")
                continue
            return value
        except ValueError:
            print("Invalid input. Please enter a numeric value.")

def calculate_future_value(present_value, interest_rate, years, pmt=0):
    if years < 0:
        raise ValueError("Number of years cannot be negative.")
    if interest_rate == 0:
        return present_value + pmt * years 
    return present_value * (1 + interest_rate)**years + pmt * ((1 + interest_rate)**years - 1) / interest_rate

def calculate_present_value(future_value, interest_rate, years, pmt=0):
    if years < 0:
        raise ValueError("Number of years cannot be negative.")
    if interest_rate == 0:
        return future_value - pmt * years
    return (future_value - pmt * ((1 + interest_rate)**years - 1) / interest_rate) / (1 + interest_rate)**years

def calculate_interest_rate(future_value, present_value, years, pmt=0):
    if pmt != 0:
        raise ValueError("Payment must be zero for interest rate calculation.")
    if years <= 0:
        raise ValueError("Number of years must be greater than zero.")
    if present_value <= 0:
        raise ValueError("Present value must be greater than zero.")
    # Returns percentage interest rate.
    return 100 * ((future_value / present_value)**(1 / years) - 1)

def calculate_number_of_years(future_value, present_value, interest_rate, pmt=0):
    if pmt != 0:
        raise ValueError("Payment must be zero for calculating number of years.")
    if interest_rate == 0:
        raise ValueError("Interest rate cannot be zero for calculating number of years.")
    if future_value <= 0 or present_value <= 0:
        raise ValueError("Future and present values must be greater than zero.")
    return math.log(future_value / present_value) / math.log(1 + interest_rate)

def display_menu(options, selected_index):
    os.system('cls')  # Clear the screen on Windows
    print("Use the arrow keys or number keys to select an option, then press ENTER to confirm.\n")
    for i, option in enumerate(options):
        if i == selected_index:
            print("-> (" + str(i + 1) + ") - " + option)
        else:
            print("   " + option)

def menu_selection():
    options = [
        "Calculate Future Value", 
        "Calculate Present Value", 
        "Calculate Interest Rate", 
        "Calculate Number of Years"
    ]
    selected_index = 0
    while True:
        display_menu(options, selected_index)
        key = msvcrt.getch()
        
        # Handle arrow key input
        if key == b'\xe0':
            key = msvcrt.getch()
            if key == b'H':  # Up arrow
                selected_index = (selected_index - 1) % len(options)
            elif key == b'P':  # Down arrow
                selected_index = (selected_index + 1) % len(options)
        # Handle Enter key
        elif key in [b'\r', b'\n']:
            break
        # Handle number key input (e.g., '1' for first option)
        elif key.isdigit():
            num = int(key.decode())
            if 1 <= num <= len(options):
                selected_index = num - 1
                break
    return selected_index

def main():
    while True:
        try:
            choice = menu_selection()
            os.system('cls')
            if choice == 0:
                print("Calculate Future Value")
                pv = get_float("Enter the present value: ", positive=True)
                ir = get_float("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ")
                yrs = get_float("Enter the number of years: ", positive=True)
                pmt = get_float("Enter the payment (enter 0 if none): ")
                result = calculate_future_value(pv, ir, yrs, pmt)
                print("Future Value: {:.2f}".format(result))
            elif choice == 1:
                print("Calculate Present Value")
                fv = get_float("Enter the future value: ", positive=True)
                ir = get_float("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ")
                yrs = get_float("Enter the number of years: ", positive=True)
                pmt = get_float("Enter the payment (enter 0 if none): ")
                result = calculate_present_value(fv, ir, yrs, pmt)
                print("Present Value: {:.2f}".format(result))
            elif choice == 2:
                print("Calculate Interest Rate")
                fv = get_float("Enter the future value: ", positive=True)
                pv = get_float("Enter the present value: ", positive=True)
                yrs = get_float("Enter the number of years: ", positive=True)
                pmt = get_float("Enter the payment (must be 0 for this calculation): ")
                if pmt != 0:
                    print("Error: Payment must be 0 for interest rate calculation.")
                else:
                    result = calculate_interest_rate(fv, pv, yrs, pmt)
                    print("Interest Rate: {:.2f}%".format(result))
            elif choice == 3:
                print("Calculate Number of Years")
                fv = get_float("Enter the future value: ", positive=True)
                pv = get_float("Enter the present value: ", positive=True)
                ir = get_float("Enter the interest rate (as a decimal, e.g., 0.08 for 8%): ")
                pmt = get_float("Enter the payment (must be 0 for this calculation): ")
                if pmt != 0:
                    print("Error: Payment must be 0 for calculating number of years.")
                elif ir == 0:
                    print("Error: Interest rate cannot be zero for calculating number of years.")
                else:
                    result = calculate_number_of_years(fv, pv, ir, pmt)
                    print("Number of Years: {:.2f}".format(result))
            else:
                print("Invalid selection.")
        except Exception as e:
            print("An error occurred: " + str(e))
        
        cont = input("\nDo you want to perform another calculation? (y/n): ").strip().lower()
        if cont != 'y':
            print("Goodbye!")
            break

if __name__ == "__main__":
    main()
