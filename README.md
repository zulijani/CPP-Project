### Author: Matteo Zulijani

This is a C++ project I did in my Object Oriented Programmaing class (prog1003)

This was not a graded project. However you did need to complete this project  
to go to the exam. Reason for this not being graded, was that it was the same  
curriculum as the exam.

### How I compile it?
I use WSL/ubuntu for this, so I compile it like this: g++ -o program *.cpp

### What is this about
In this project you have Tour-Operators ("turoperatorer" in Norwegian), Cities ("Byer"),  
and Attractions ("Attraksjoner") in the Cities.

| Command | Description |
|---------|------------|
| T A  | Write all tour-operators |
| T 1  | Write everything about a single tour-operator |
| T N  | Create a new tour-operator |
| T E* | Change something about a new tour-operator |
| T O  | Create a tour scheme/schedule - Probably the most difficult function |
| T F  | Delete a tour-operator |
| B A  | Write all cities |
| B 1  | Write everything about a single city |
| B N  | Create a new city |
| B F  | Delete a city |
| A N  | Create a new attraction |
| A F  | Delete an attraction |
| Q    | Quit / avslutt |


PS!: When writing a touroperator or a city in the functions (T1, TE, B1), you only need to write  
     characters of that given name so that it is unique in the program. Like if you are searching info
     about New York, you only need to write "n" as input, as long as "n" is unique, and other cities do  
     start with "n".
