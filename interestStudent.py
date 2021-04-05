##################################################################
# Student contributions to the interest calculator
#
# You are free to add additional utility functions as you see fit,
# but you must implement each of the following functions while
# adhering to the specifications given in the project description
##################################################################

#---------------------------------------------------------------------------------

def greeting():     # Greet the user at the beginning of the session
    print("This interest calculator will ask you to select an interest rate, \nfollowed by a principal value. It will then calculate and display \nthe principal, interest rate, and balance after one year. You will \nthen be invited to execute the process again or terminate.")

#---------------------------------------------------------------------------------

def getRate(choices):                                       # Get a percentage rate from a list of random integers
    noSelection = True                                      # Start with a variable saying that the user hasn't selected a percentage rate
    while noSelection:                                      # While the user hasn't selected a rate, do the following:
        answers = ('A', 'B', 'C', 'D', 'E', 'F', 'G')       # List of acceptable answers

        print("\nPlease select an interest rate: ")         # Ask the user to pick a percentage rate

        posRate = []                                        # Create empty list to hold possible rates for each session
        posAns = []                                         # Create empty list to hold possible answers for each session

        for i in range(len(choices)):                       # For every integer in our random list, do the following:
            posRate.append(choices[i])                      # Add the acceptable percentage rates to the empty rate-list
            posAns.append(answers[i])                       # Add the acceptable answers to the empty answer-list
            print(f"{posAns[i]})  {posRate[i]}% ")          # Print these answers and their respective rates

        userInput = input(f"Enter A-{posAns[-1]}: ")        # Ask the user to pick a percentage rate within the range of acceptable answers

        if userInput.upper() not in posAns:                 # If they picked incorrectly,
            print("That is not a valid selection.")         # Tell them, and prompt them again for a different answer
        else:                                               # If they picked a correct answer,
            noSelection = False                             # End the while-loop
            r = answers.index(userInput.upper())            # Find the index of their answer
            rate = posRate[r]                               # Find that same index in our percentage rates

    return (float(rate) / 100)                              # Take that percentage-rate index, divide by 100 to get our decimal, and return it

#---------------------------------------------------------------------------------

def getPrincipal(limit):                                                                # User inputs a principal greater than zero and less than a random limit 
    p = True                                                                            # Variable stating whether or not a principal has been picked
    while p:                                                                            # While there is no principal, do the following: 
        principal = input(f"\nEnter the principal (limit {limit}):")                    # Ask the user for a principal that is less than the limit

        if not isinstance(principal, (float, int)):                                     # If that input isn't a number, (it will always be a string)
            try:
                if principal[0] == "$":                                                 # If the 1st char of that string is a dollar sign,
                    principal = principal[1::]                                          # Remove it, leaving just the numbers

                principal = float(principal)                                            # Convert that string into a float

                if principal <= 0:                                                      # If the user's input is less than or equal to zero,
                    print("You must enter a positive amount.")                          # Reject that input and loop again

                elif principal > limit:                                                 # If the user's input is greater than the limit,
                    print(f"The principal can be at most {limit}.")                     # Reject that input and loop again

                elif str(principal)[::-1].find('.') > 2:                                # Find the decimal in the float, and if there's more than 2 decimals,
                    print("The principal must be specified in dollars and cents.")      # Reject that input and loop again

                else:                                                                   # Otherwise (assuming the input was correct), 
                    p = False                                                           # Declare that a principal has been picked, ending the loop

            except IndexError:                                                          # If the user puts in a blank input,
                print("Please enter a number.")                                         # Reject that input and loop again

            except ValueError:                                                          # If the user inputs anything that cannot be a number,
                print("Please enter a number.")                                         # Reject that input and loop again

    return principal                                                                    # Return the principal

#---------------------------------------------------------------------------------

def computeBalance(principal, rate):                # Calculate the final annual balance using the principal and percentage rate
    balance = principal + (principal * rate)        # Balance formula
    return balance                                  # Return the balance

#---------------------------------------------------------------------------------

def displayTable(principal, rate, balance):                                                                             # Display table showing the principal, percentage rate, and ending balance
    h1 = 'Initial Principal'                                                                                            # Header 1
    h2 = 'Interest Rate'                                                                                                # Header 2
    h3 = 'End of Year Balance'                                                                                          # Header 3

    print(f"{h1:{len(h1)+2}} {h2:{len(h2)+2}} {h3}")                                                                    # Print the headers and format their spacing
    print('=' * (len(h1) + len(h2) + len(h3) + 6) )                                                                     # Print a dividing line
    print(f"${principal:<{len(h1)+1}.2f} {rate:<{len(h2)+2}.2f} ${balance:<{len(h3)+1}.2f}\n")                          # Print the data and format it

    months = ('Jan', 'Feb', 'Mar', 'Apr','May', 'Jun', 'Jul', 'Aug', 'Sep', 'Oct', 'Nov', 'Dec')                        # Months in the year

    h4 = 'Month'                                                                                                        # Header 4
    h5 = 'Starting Balance'                                                                                             # Header 5
    h6 = 'APR'                                                                                                          # Header 6
    h7 = 'Ending Balance'                                                                                               # Header 7

    print(f"{h4:{len(h4)+2}} {h5:{len(h5)+3}} {h6:{len(h6)+4}} {h7}")                                                   # Print the headers and format their spacing
    print('=' * (len(h4) + len(h5) + len(h6) + len(h7) + 12) )                                                          # Print a dividing line

    for i in range(len(months)):                                                                                        # For every month in the year, do the following:
        startMonth = principal + (principal * (rate / 12 * i))                                                          # Calculate the balance at the start of the month
        endMonth = principal + (principal * (rate / 12 * (i + 1)))                                                      # Calculate the balance at the end of the month
        print(f"{months[i-1]:7} ${startMonth:<{len(h5)+2}.2f} {rate:<{len(h6)+4}.2f} ${endMonth:<{len(h7)}.2f}")        # Print the data and format it

#---------------------------------------------------------------------------------

def askYesNo(prompt):                           # Ask the user if they want to run the program again
    repeat = True                               # Create a variable declaring whether or not the user wants to repeat the program
    while repeat:                               # If they haven't decided, do the following:
        another = input(prompt)                 # Prompt the user
        print()                                 # Blank newline
        try:
            if another[0].upper() == 'Y':       # If the user affirmed that they want to run it again,
                return True                     # Run it again
            elif another[0].upper() == 'N':     # If they declined,
                return False                    # End the program
            else:                               # Otherwise, assuming their input didn't confirm 'yes' or 'no,'
                continue                        # Ask again
        except IndexError:                      # If the user gave an incorrect input,
            continue                            # Ask again
#---------------------------------------------------------------------------------
