class Person
{
    public:
    int initialFloor;
    int destinationFloor;
    int direction;          //1 for up and -1 for down
     
    bool arrived = false;

    //

    Person(int initialFloor = -5, int destinationFloor = -5, int direction = -5)
    {
        this-> initialFloor = initialFloor;
        this-> destinationFloor = destinationFloor;
        this-> direction = direction;
    }

    bool operator<(Person p2)
    {
        if(initialFloor < p2.initialFloor)
        return true;
        else
        return false;
    }
};