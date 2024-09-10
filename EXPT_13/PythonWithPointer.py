# Function to find a substring
def substring(string, substr):
    length_str = len(string)
    length_substr = len(substr)
    
    for i in range(length_str - length_substr + 1):
        j = 0
        while j < length_substr and string[i + j] == substr[j]:
            j += 1
        if j == length_substr:
            return i  # Return index of substring
    return -1  # Substring not found

# Function to check if a string is a palindrome
def is_palindrome(string):
    return string == string[::-1]

# Function to compare two lists of characters (strings)
def compare_strings(str1, str2):
    if str1 < str2:
        return -1
    elif str1 > str2:
        return 1
    else:
        return 0

# Function to copy one list to another
def copy_list(source):
    return source[:]

# Function to reverse a list
def reverse_list(lst):
    return lst[::-1]

def main():
    string = list(input("Enter a string: "))  # Convert input string to list of characters
    print("Choose an operation:")
    print("1. Substring")
    print("2. Palindrome")
    print("3. Compare")
    print("4. Copy")
    print("5. Reverse")

    choice = int(input("Enter your choice: "))

    if choice == 1:
        substr = list(input("Enter substring to search: "))  # Convert substring input to list of characters
        index = substring(string, substr)
        if index != -1:
            print(f"Substring found at index: {index}")
        else:
            print("Substring not found")
    
    elif choice == 2:
        if is_palindrome(string):
            print("The string is a palindrome.")
        else:
            print("The string is not a palindrome.")
    
    elif choice == 3:
        str2 = list(input("Enter another string: "))  # Convert the second string input to list of characters
        result = compare_strings(string, str2)
        if result < 0:
            print("The first string is smaller.")
        elif result > 0:
            print("The second string is smaller.")
        else:
            print("Both strings are equal.")
    
    elif choice == 4:
        copied_list = copy_list(string)
        print(f"Copied string: {''.join(copied_list)}")  # Convert list of characters back to string for display
    
    elif choice == 5:
        reversed_list = reverse_list(string)
        print(f"Reversed string: {''.join(reversed_list)}")  #
