def substring(string, substr):
    """Function to find a substring."""
    for i in range(len(string)):
        j = 0
        while j < len(substr) and i + j < len(string) and string[i + j] == substr[j]:
            j += 1
        if j == len(substr):
            return i
    return -1  # Substring not found


def is_palindrome(string):
    """Function to check if a string is a palindrome."""
    return string == string[::-1]


def compare_strings(str1, str2):
    """Function to compare two strings."""
    if str1 < str2:
        return -1  # str1 is smaller
    elif str1 > str2:
        return 1  # str2 is smaller
    else:
        return 0  # Both strings are equal


def copy_string(source):
    """Function to copy one string to another."""
    return source[:]


def reverse_string(string):
    """Function to reverse a string."""
    return string[::-1]


def main():
    string = input("Enter a string: ")
    print("Choose an operation:")
    print("1. Substring")
    print("2. Palindrome")
    print("3. Compare")
    print("4. Copy")
    print("5. Reverse")
    
    choice = int(input("Enter your choice: "))
    
    if choice == 1:
        substr = input("Enter substring to search: ")
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
        str2 = input("Enter another string: ")
        result = compare_strings(string, str2)
        if result < 0:
            print("The first string is smaller.")
        elif result > 0:
            print("The second string is smaller.")
        else:
            print("Both strings are equal.")
    
    elif choice == 4:
        copy = copy_string(string)
        print(f"Copied string: {copy}")
    
    elif choice == 5:
        reversed_str = reverse_string(string)
        print(f"Reversed string: {reversed_str}")
    
    else:
        print("Invalid choice. Please choose a valid operation.")


if __name__ == "__main__":
    main()
