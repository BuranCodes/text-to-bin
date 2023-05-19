# Text to Binary Conversion

Description:
This repo has Python script and C file (comes with CMakeLists.txt) that allow you to convert a given text into its binary representation.
It takes input from the user, converts each character in the input text to its corresponding binary representation, and displays the result.

Function:
- Python:

  - `def txtbin(txt)`: This function takes a string `txt` as input and converts it into binary representation. It iterates over each character in the input text, converts its ASCII value to binary using a while loop, and appends the binary representation to the `bintxt` variable. Finally, it prints the resulting binary representation.

- C:

  - `void txtbin(const char *txt, size_t len)`: This function takes a character array `txt` and its length `len` as input. It converts the text into binary representation and displays the result. The function uses dynamic memory allocation to create the necessary output and temporary strings. It iterates over each character in the input text, converts its ASCII value to binary using a while loop, and appends the binary representation to the `bintxt` variable. Finally, it reverses the order of the binary representation and prints the resulting binary output.
  
Usage:
1. Run the script or binary compiled from included C code.
2. Enter any text when prompted.
3. The program will convert the text into binary and display the result.

Example:

```
Enter any text to convert into binary: Hello

The resulting binary of said text is: 01001000 01100101 01101100 01101100 01101111
```
