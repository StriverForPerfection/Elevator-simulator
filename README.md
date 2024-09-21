# Elevator simulator
Here resides a C++ program that resembles the functions and logic of an elevator demonstrated by command line graphics.
We (my two colleagues and I) built this as a project for the second semester of our first year.

## Features:
- Simulates the action and **logic** of a real life elevator.
- No matter how many people call it and wherever each of them wants to go, it can **manage all their calls** and handle all their requests as **efficiently** as possible.
- You can see the elevator's motion through floors and follow up its progress.
- You can see when a person enters and exits, and how many people exitted on each floor.
- You get a status update on every floor.
- Prone to crashes and erroneous inputs.
     
## How-to-use:
1. Just clone the repository and run program. No special software needed.
2. In spark.cpp, click 'run.'
3. Enter the number of floors and the maximum capacity of the elevator. The elevator's minimum floor is floor *zero* by default.
   
   ![image](https://github.com/user-attachments/assets/2096d634-a746-404c-9cc8-42fd6d4ee88f)
4. Enter any number of calls (each call corresponds to one person, obviously).
   
   ![image](https://github.com/user-attachments/assets/949bf175-bf0c-47ed-97d8-674a3af623db)

5. Enter the floor from which the caller calls the elevator, and whether he wants to go up or down from there (the elevator can handle the case if the caller wants to change the direction after the elevator reaches them).
   - 1 means up and -1 means down. **Seperate these two numbers by a space!**
6. If you want to proceed without adding any new calls, enter zero when prompted for new calls.
7. Resume using the application and observe the passengers being delivered to their destinations! You can add any new passengers **wherever** and **whenever** you like. Just ensure not to pass the passenger limit.

# Files:
### person.h:
A header file contains the person class to generate person objects. This object represents a person with their initial floor, call and request until they reach the final floor and exit (person object deletion occurs here).
### validation.h:
A header file that just contains code that handles the inputs of the user in case it isn't intelligible.
### Elevator.h:
A header file that contains the **majority** of the action.
It contains the elevator class to generate an elevator object.
Here, you can find the implementations of **"updateCalls()"** that handles the calls to the elevator, **"updateRequests()"** that handles the requests of people inside the elevator, **"move()"** which is responsible for making the elevator change floors according to the calls and requests, and **"shows()"** and **"animation()"** which are responsible for the elevator's neat animations in the terminal. 
### spark.cpp:
This is the file you run for the elevator simulation to start. all previous files are included here.


## Credits:
This project wasn't built by me solely. I sincerely want to thank  ***Mohammed Elsayed Hassan*** for contributing in the elevator's *logic and motion*, and ***Mohammed Shalaby*** for implementing the animation functions *all on his own*! We all contributed to building and growing this project, clarifying each other's vision about how the program should emerge, reaching a final mutual view and debugging several annoying errors along the way. I am truly **proud** of them and their work, and wish them the best.
