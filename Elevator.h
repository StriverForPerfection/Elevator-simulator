#include <iostream>
#include <algorithm>
#include "Person.h"
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Validation.h"

using namespace std;

enum Direction {UP = 1, DOWN = -1};

class Elevator
{
    private:

    int totalPeopleOverall = 0;
    int maxCapacity;
    static int minFloor;
    int maxFloor;
       
    bool doorClose = true;
    int elevatorCurrentDirection = 1;

    int peopleInside = 0;
    int initialFloor = 0;
    int elevatorCurrentFloor = 0;

    vector<Person> calls{};                //Vector containg all pending calls.

    vector<Person> currentRequests{};      //All requests in the elevator's current direction.
    vector<Person> oppositeRequests{};     //All requests in the elevator's opposite direction.

    vector<Person*> People{};              //Vector to generate new people/requests.

    public:
    void setMaxCapacity()
    {
        cout<< "Enter the maximum capacity of the elevator: ";
        cin>> maxCapacity;

        validateInput(maxCapacity);
    }
    
    ~Elevator()
    {
        cout<< "Elevator destroyed.";
    }

    void setMaxFloor()
    {
        int n;
        cout << "Enter the number of floors of the building: ";
        cin >> n;

        validateInput(n);
        
        maxFloor = n;
    }

    void updateCalls()
    {
        int callNum = 0;
        cout<< "Are there any new calls? ";
        cin>> callNum;

        validateInput(callNum);

        for(int i = totalPeopleOverall; i < totalPeopleOverall + callNum ; i++)    //These boundaries allow each object created to have a different name. There was an issu with the loop creating objets starting with index zero every time, and thus having the same name. This was solved by making a variable that stores an ever-increasing integer to declare different-named objects continuously.
        {   
            People.push_back(new Person);  //<3
   
            cout<< "Enter the caller's current floor and his desired direction: ";
            cin>> People[i]->initialFloor >> People[i]->direction;

            validateInput(People[i]->initialFloor, People[i]->direction);

            calls.push_back(*People[i]);   
        }
        totalPeopleOverall += callNum;
    }

    void updateRequests()
    {

        int saveCallsCapacity = calls.capacity(); // Erasing an element from the vector changes its size while iterating, thus the size shall be saved in a separate variable.


        for(int i = 0; i < saveCallsCapacity; i++)
        {
            doorClose = false;

            if(elevatorCurrentFloor == calls[i].initialFloor)
            {   
                if(i == 0) animation();

                cout<< "Where do you want to go, sir? ";
                cin>> calls[i].destinationFloor;

                validateInput(calls[i].destinationFloor);

                if((calls[i].destinationFloor - elevatorCurrentFloor) * elevatorCurrentDirection >= 1)
                {
                    currentRequests.push_back(calls[i]);
                    peopleInside ++;
                }
                else if((calls[i].destinationFloor - elevatorCurrentFloor) * elevatorCurrentDirection <= 1)
                {
                    oppositeRequests.push_back(calls[i]);
                    peopleInside ++;
                }
                
                calls.erase(calls.begin() + i);     //This built-in function erases by a pointer, not the index directly.
            }
        }
        
        calls.shrink_to_fit();
        doorClose = true;

        int saveRequestCapacity = currentRequests.size();   // Erasing an element from the vector changes its size while iterating, thus the size shall be saved in a separate variable.


        for(int i = 0; i < saveRequestCapacity; i++)
        {
            if(elevatorCurrentFloor == currentRequests[i].destinationFloor)
            {

                doorClose = false;
                currentRequests.erase(currentRequests.begin() + i);     //This built-in function erases by a pointer, not the index directly.
                
                if(i == 0) animation();

                cout<< "A person has exited the elevator.\n";
                peopleInside--;
            }
        }
        doorClose = true;
    }

     void move()
     {

        updateStatus();
        updateCalls();
        updateRequests();
        
        doorClose = true;

        if(!currentRequests.empty() || !oppositeRequests.empty()||!calls.empty())
        {
            
            if (!currentRequests.empty())
                {
                    elevatorCurrentFloor += elevatorCurrentDirection;
                    cout << "sc. 1\n";
                }
            else if (currentRequests.empty() && (!oppositeRequests.empty() || !calls.empty()))
            {                   
                bool littleFlag = true;

                for(int j = 0; j < calls.size(); j++)
                {
                    if ( (calls[j].initialFloor - elevatorCurrentFloor) * elevatorCurrentDirection > 0  )
                    {
                        elevatorCurrentFloor += elevatorCurrentDirection;
                        littleFlag = false;
                        break;
                    }
                }

                if(littleFlag == true)
                {
                    cout << "sc. 2a.\n";
                    elevatorCurrentDirection *= -1;
                    elevatorCurrentFloor += elevatorCurrentDirection;
                    currentRequests.swap(oppositeRequests);
                }
            }    
        
            animation();

        }                         
    }


    string show(int elevator_status)
    {
        string completed_shape;


        vector <string> blocks(maxFloor, "|       |");
        vector <string> edges(maxFloor+1,"+-------+");

        //print the elevator inbetween 2 floors if it is moving up
        if ( (elevator_status == 1) && (elevatorCurrentFloor!=maxFloor) ){
            edges[elevatorCurrentFloor] = "+-[|||]-+";
        }

        //print the elevator inbetween 2 floors if it is moving down
        else if ( (elevator_status == -1 ) && (elevatorCurrentFloor != 0)  ){
            edges[elevatorCurrentFloor+1] = "+-[|||]-+";
        }

        //print the elevator opened in particular floor
        else if ( (doorClose == false) ){
            blocks[elevatorCurrentFloor] = "| [   ] |";
        }

        //print the elevator closed in particular floor
        else if ( (doorClose == true) ){
        blocks[elevatorCurrentFloor] = "| [|||] |";
        }


        for(int n = 2*maxFloor ; n >= 0 ; n--){
            if (n%2 == 0)
                completed_shape+=edges[n/2]+"\n";

            else
                completed_shape+= blocks[(n-1)/2]+ "     " + to_string((n-1)/2) + "\n";
        }

        return completed_shape;
    }

void const animation()
{
    int elevator_status;

    if(currentRequests.empty() && oppositeRequests.empty() && calls.empty())
    {
        elevator_status = 0;
        cout<<"\n"<<show(elevator_status);
    }
  
  else{
    elevator_status=elevatorCurrentDirection;
    cout<< show(elevator_status);
    auto timeout = 3s;
    this_thread::sleep_for(timeout);
    elevator_status = 0;
    cout<<"\n"<<show(elevator_status);
  }
}

    void updateStatus()
    {
        auto delay = 1.28s;
        this_thread::sleep_for(delay);
            cout << "=======================================================\n";
            cout << "The current floor is: " << elevatorCurrentFloor << " and number of people in elevator is: " << peopleInside <<"\n";
            cout << "number of calls is :"<<calls.size();
            cout << "\nThe direction of the elevator is: " << elevatorCurrentDirection << "\n";
            cout << "=======================================================\n";
    }

};