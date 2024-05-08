# TL1
This C program implements a finite automaton to analyze words in a text file based on their composition of letters and digits. It reads input from a file (test.txt) and classifies each word into one of two categories: accepted or rejected, according to predefined rules.

Features:

    Implements a finite automaton with six states (q0 to q5).
    Classifies words based on the presence of letters (L) and digits (C).
    Utilizes file I/O for reading input from a text file.
    Handles various symbols as word delimiters (e.g., space, punctuation, newline).
    Outputs the classification of each word along with the transitions between states.

Usage:

    Ensure a text file named test.txt is present in the same directory as the executable.
    Run the program.
    Check the console output for word classifications and state transitions.

Note:

    Words containing both letters and digits are classified as rejected (q5).
    Words classified as accepted are those consisting entirely of letters (q2) or digits (q4).

File Structure:

    automaton.c: Main C source code file containing the finite automaton implementation.
    test.txt: Input text file used for word analysis.
