//task 1
#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

class FlightBooking {
public:
    void set(int id, int capacity, int reserved);
    void get();
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    double percentage(int capacity, int reserved);
    void add(int tiket);
    void cancel(int tiket);

private:
    int id = 1;
    int capacity;
    int reserved;
    string res;
};
void FlightBooking::printStatus()
{
    cout << res;
}
FlightBooking::FlightBooking(int inputId, int inputCapacity, int inputReserved)
{
    set(inputId, inputCapacity, inputReserved);
    res += "Flight " + to_string(this->id) + " : " + to_string(this->reserved) + "/" + to_string(this->capacity)+
        " " + "(" + to_string((int)percentage(this->capacity, this->reserved)) + "%) seats reserved\n";
}

void FlightBooking::set(int inputId, int inputCapacity, int inputReserved) {
    id = inputId;
    capacity = inputCapacity;
    reserved = inputReserved;
}

void FlightBooking::get() {
    cout << this->id << "/" << this->capacity << "/" << this->reserved << '\n';
}

double FlightBooking::percentage(int capacity, int reserved) {
    return reserved * 100 / capacity;
}


void FlightBooking::add(int ticket) {
    if (reserved + ticket <= capacity) {
       reserved += ticket;
       res += "Flight " + to_string(this->id) + " : " + to_string(this->reserved) + "/" + to_string(this->capacity) +
           " " + "(" + to_string((int)percentage(this->capacity, this->reserved)) + "%) seats reserved\n";
}
    else res+= "Cannot perform this operation\n";
}
void FlightBooking::cancel(int ticket) {
    if (reserved > ticket)   
    {
        reserved -= ticket;
        res += "Flight " + to_string(this->id) + " : " + to_string(this->reserved) + "/" + to_string(this->capacity) +
            " " + "(" + to_string((int)percentage(this->capacity, this->reserved)) + "%) seats reserved\n";
    }
    else res += "Cannot perform this operation\n";
}
int main() {
    int reserved = 0,
        capacity = 0;
    std::cout << "Provide flight capacity: ";
    std::cin >> capacity;
    std::cout << "Provide number of reserved seats: ";
    std::cin >> reserved;

    FlightBooking booking(1, capacity, reserved);
    string command = "";
    getline(cin, command);
    while (command != "quit") {
        command.clear();
        getline(cin, command);
        if (command.find("add") != string::npos) {
            command.erase(0, 3);
            int i = std::stoi(command);
            booking.add(i);
        }
        else if (command.find("cancel") != string::npos) {
            command.erase(0, 7);
            int i = std::stoi(command);
            booking.cancel(i);
        }
    }
    booking.printStatus();
    return 0;
}
//task 2

#include <string>
#include <iostream>
#include <algorithm>
#include <cctype>
#include <cstdlib>

using namespace std;

class FlightBooking {
public:
    FlightBooking() {
        //id = 0; capacity = 0; reserved = 0;
    }
    FlightBooking(int id, int capacity, int reserved);
    void printStatus();
    double percentage(int capacity, int reserved);
    void add(int ID,int tiket);
    void cancel(int ID,int tiket);
    void quit();
    void create(int ID, int ticket);
    void del(int ID);
string res="";
private:
    
    int i=0,g=0;
    struct xx {
        int id, capacity=0, reserved=0;
    };
    xx avia[10];
    
};


void FlightBooking::printStatus()
{
    cout << res;

}

double FlightBooking::percentage(int capacity, int reserved) {
    return reserved * 100 / capacity;
}

void FlightBooking::quit() {
    // if(com == "quit") break;
}

void FlightBooking::create(int ID,int ticket) {
    avia[i].id = ID;
    avia[i].capacity = ticket;
    i++;
    res += "Flight " + to_string(ID) + " : " + to_string(0)+"/"+to_string(ticket)+ "(" + to_string(0)+"%) seats reserved\n";
   
}

void FlightBooking::del(int ID) {
    for (int j = 0;j < 10;j++) {
        if (avia[j].id == ID) {
            avia[j].id = 0;
            avia[j].capacity = 0;
            avia[j].reserved = 0;
            g = j;
        }
    }

}

void FlightBooking::add(int ID,int ticket) {
    for (int j = 0;j < 10;j++) {
        if (avia[j].id == ID) {
            if (avia[j].reserved + ticket < avia[j].capacity) avia[j].reserved += ticket;
            g = j;
        }
    }
    res += "Flight " + to_string(ID) + " : " + to_string(avia[g].reserved) + "/" + to_string(avia[g].capacity) + "(" + to_string((int)percentage(avia[g].capacity, avia[g].reserved)) + "%) seats reserved\n";
    }


void FlightBooking::cancel(int ID,int ticket) {
    for (int j = 0;j < 10;j++) {
        if (avia[j].id == ID) {
            if (ticket < avia[j].reserved) avia[j].reserved -= ticket;
            g = j;
        }
        }
    res += "Flight " + to_string(ID) + " : " + to_string(avia[g].reserved) + "/" + to_string(avia[g].capacity) + "(" + to_string((int)percentage(avia[g].capacity, avia[g].reserved)) + "%) seats reserved\n";
    }




void get_value(string command,int& id, int& capacity) {
    char cap[20];
    size_t cp = command.copy(cap, 100, command.find(' ') + 1);
    cap[cp] = '\0';
    command.erase(command.find(' '));
    capacity = atoi(cap);
    id = stoi(command);
}


int main() {
    int reserved = 0,
        capacity = 0,
        id =0;
    FlightBooking booking;
    string command = "";
    while (command != "quit"){
        command.clear();
        getline(cin, command);
        if (command.find("add") != string::npos) {
            command.erase(0, 4);
            get_value(command, id, capacity);
            booking.add(id, capacity);
        }
        else if (command.find("cancel") != string::npos) {
            command.erase(0, 7);
            get_value(command, id, capacity);
            booking.cancel(id, capacity);
        }
        else if (command.find("create") != string::npos) {
            command.erase(0, 7);
            get_value(command, id, capacity);
            booking.create(id, capacity);
        }
        else if (command.find("delete") != string::npos) {
            command.erase(0, 7);
            booking.del(stoi(command));
        }
    }
    booking.printStatus();
    return 0;
}