#include <iostream> 
#include <string> 
#include <vector> 
#include <memory>
using namespace std; 

class TicketOffice //define class 
{ 
private: 
    int flightnumber; 
    int check;// check = 1 domestic, check = 2 international 
    int price; 
    string departure; 
    string arrival; 
    string date; 
public: 
    TicketOffice(); //constructor 
    TicketOffice(int flightnumber, string departure, string arrival, 	int price, string date); 

    int getFlightnumber(); 
    void setFlightnumber(int flightnumber); 

    int getPrice(); 
    void setPrice(int price); 

    string getArrival(); 
    void setArrival(string arrival); 

    string getDeparture(); 
    void setDeparture(string departure); 

    string getDate();
    void setDate(string date); 

    void setCheck(int check); 
    int getCheck(); 

    int getCommission() // to get the money  
    { 
        return 0; 
    } 
    void display(); 
}; 

TicketOffice::TicketOffice() 
{ 
    flightnumber = 420; 
    price = 69; 
    departure = "Ha Noi "; 
    arrival = "Ho Chi Minh"; 
    date = "20200101"; 
    check = 1; 
} 

TicketOffice::TicketOffice(int flightnumber, string departure, 
string arrival, int price, string date) 
{ 
    this->flightnumber = flightnumber; 
    this->departure = departure; 
    this->arrival = arrival; 
    this->price = price; 
    this->date = date; 
} 

int TicketOffice::getFlightnumber()
{return flightnumber;} 
void TicketOffice::setFlightnumber(int flightnumber) 
{this->flightnumber = flightnumber; } 

int TicketOffice::getPrice() 
{return price; } 
void TicketOffice::setPrice(int price) 
{this->price = price;} 

string TicketOffice::getArrival() 
{return arrival;} 
void TicketOffice::setArrival(string arrival)
{this->arrival = arrival;} 

string TicketOffice::getDeparture() 
{return departure;} 
void TicketOffice::setDeparture(string departure) 
{this->departure = departure;} 

string TicketOffice::getDate() 
{return date;} 
void TicketOffice::setDate(string date) 
{this->date = date;} 

int TicketOffice::getCheck() {return check;} 
void TicketOffice::setCheck(int check)
{this->check = check;} 

void TicketOffice::display()  
{ 
    cout << "Flightnumber: " << getFlightnumber(); 
    cout << " Arrival: " << getArrival(); 
    cout << " Departure: " << getDeparture(); 
    cout << " Price: " << getPrice(); 
    cout << " Date: " << getDate(); 
    if (check = 1) 
    { 
        cout << " Domestic flight " << endl; 
    } 
    else 
    { 
        cout << " International flight " << endl; 
    } 

} 

class Domestic : public TicketOffice // children class Domestic 
{ 
private: 
    int commission; 
public: 
    Domestic(); 
    Domestic(string departure, string arrival,  
    int price, string date, int commission, int flightnumber) ; 
    int getCommission(); // overloading function for Domestic 
    void setCommission(int commission); 
    void display(); 
}; 

Domestic::Domestic() : TicketOffice() 
{commission = 0;} 
Domestic::Domestic(string departure, string arrival,  
int price, string date, int commission, int flightnumber) 
{this->commission = commission;} 

int Domestic::getCommission() 
{return (Domestic::getPrice()) * 5 / 100;} 
void Domestic::setCommission(int commission) 
{this->commission = commission;} 

void Domestic::display() 
{
    TicketOffice::display(); 
    cout << "Commission : " << getCommission() << "\n"; 
} 

class International : public TicketOffice  // children class International 
{ 
private: 
    int commission; 
public: 
    International(); 
    International(string departure, string arrival,  
    int price, string date, int commission, int flightnumber) ; 
    int getCommission(); // overloading function for International 
    void setCommission(int commission); 
    void display(); 
}; 

International::International() : TicketOffice()
{commission = 0;} 
International::International(string departure, string arrival,  
int price, string date, int commission, int flightnumber) 
{this->commission = commission;} 

int International::getCommission()
{return International::getPrice() * 7 / 100 + 100000;} 

void International::setCommission(int commission) 
{this->commission = commission;} 

void International::display() 
{ 
    TicketOffice::display(); 
    cout << "Commission() : " << getCommission() << "\n"; 
} 


void get_input(vector<TicketOffice>&p, int n1) // save data into an vector with n1 elements 
{ 
    string departure; 
    string arrival; 
    string date; 
    int price; 
    int check; 
    int flightnumber; 
    static int i = 1; 
    for (int j = 0; j < n1; j++) 
    {
        TicketOffice p1; 
        cout << "Flight number of the " << i << " flight"<< ": "; 
        cin >> flightnumber; 
        p1.setFlightnumber(flightnumber); 

        cout << "Departure of flight number " << i << ": "; 
        getline(cin >> ws, departure); 
        p1.setDeparture(departure); 

        cout << "Arrival of flight number " << i <<": "; 
        getline(cin >> ws, arrival); 
        p1.setArrival(arrival); 

        cout << "Date of flight number " << i << ": "; 
        getline(cin >> ws, date); 
        p1.setDate(date); 

        cout << "Price of flight number " << i << ": "; 
        cin >> price; 
        p1.setPrice(price); 

        cout << "Type of flight number " << i << ": "; 
        cout << "1 for domestic, 2 for international "; 
        cin >> check; 
        p1.setCheck(check); 
        p.push_back(p1);   
    } 
} 

// display option for user to choose 
void displayoption() 
{ 
    cout << "What do you want\n "; 
    cout << "1 : Add flight\n"; 
    cout << "2 : Edit flight\n"; 
    cout << "3 : Remove flight\n"; 
    cout << "4 : Find flight based on time\n"; 
    cout << "5 : Find flight based on arrival\n"; 
    cout << "6 : Find flight based on departure\n"; 
    cout << "7 : Number of domestic flights in a preiod of time\n"; 
    cout << "8 : Flight commission in a preiod of time\n"; 
    cout << "9 : Show all flights\n"; 
    cout << "10 : Exit\n"; 
} 

// display options of edit a flight information for the user to choose 
void fixingoption() 
{ 
    cout << "What do you want to change ?\n"; 
    cout << "1: Price\n"; 
    cout << "2: Departure\n"; 
    cout << "3: Arrival\n"; 
    cout << "4: Date\n "; 
    cout << "5: Exit\n "; 
} 

int main()  
{ 
    int m, n, q; 
    int flightnumber; 
    int newprice; 
    string newdeparture; 
    string newarrival; 
    string newdate; 
    vector<TicketOffice> p; 
    get_input(p, 1); 
loop:   // loop and goto make the program run until user decide to exit 
    displayoption(); 
    cin >> n; 
    if (n == 1) 
    { 
        int flightnumber, price, check; 
        string departure, arrival, date;  
        TicketOffice p1;
        cout << "Flight number: "; 
        cin >> flightnumber; 
         p1.setFlightnumber(flightnumber); 
 
        cout << "Departure: "; 
        getline(cin >> ws, departure); 
        p1.setDeparture(departure); 

        cout << "Arrival: "; 
        getline(cin >> ws, arrival); 
        p1.setArrival(arrival); 

        cout << "Date: "; 
        getline(cin >> ws, date); 
        p1.setDate(date); 

        cout << "Price: "; 
        cin >> price; 
        p1.setPrice(price); 

        cout << "Type: "; 
        cout << "1 for domestic, 2 for international "; 
        cin >> check; 
        p1.setCheck(check); 
        p.push_back(p1); 
        goto loop; // loop and goto make the program run until user decide to exit 
    } 
    else if (n == 2) 
    { 
        loop2: // loop and goto make the program run until user decide to exit 
        fixingoption(); 
        int m; 
        cin >> m; 
        if (m == 1)  
        { 
        for (int i = 0; i < p.size(); i++)  
        { 
        p.at(i).display(); 
        } 
        cout << "Please enter the flight you want to change :\n "; 
        cin >> q; 
        cout << "Please enter new price:\n "; 
        cin>>newprice; 
        p.at(q - 1).setPrice(newprice); 
        cout << "The new information is : " << endl; 
        p.at(q - 1).display(); 
        goto loop2; // loop and goto make the program run until user decide to exit 
        } 
        else if (m == 2) 
        { 
        for (int i = 0; i < p.size(); i++)  
        { 
        p.at(i).display(); 
        } 
        cout << "Please enter the flight you want to change :\n "; 
        cin >> q; 
        cout << "Please enter new departure :\n "; 
        getline(cin>> ws, newdeparture); 
        p.at(q - 1).setDeparture(newdeparture); 
        cout << "The new information is : " << endl; 
        p.at(q - 1).display(); 
        goto loop2; // loop and goto make the program run until user decide to exit 
        } 
        else if (m == 3) 
        { 
        for (int i = 0; i < p.size(); i++)  
        { 
        p.at(i).display(); 
        } 
        cout << "Please enter the flight you want to change :\n "; 
        cin >> q; 
        cout << "Please enter new arrival :\n "; 
        getline(cin>> ws, newarrival); 
        p.at(q - 1).setArrival(newarrival); 
        cout << "The new information is : " << endl; 
        p.at(q - 1).display(); 
        goto loop2; // loop and goto make the program run until user decide to exit 
        } 
        else if (m == 4) 
        { 
        cout << "Please enter the flight number you want to change :\n "; 
        cin >> q; 
        cout << "Please enter new date :\n "; 
        cin >> newdate; 
        p.at(q - 1).setDate(newdate); 
        cout << "The new information is : " << endl; 
        p.at(q - 1).display(); 
        goto loop2; 
        } 
        else if (m == 5) 
        { 
            goto loop; // loop and goto make the program run until user decide to exit 
        } 
        } 
    else if (n == 3) 
    { 
        int x; 
        cout << "Please enter flight number you want to delete : " << endl; 
        cin >> x; 
        cout << "Before delete: " << endl; 
        for (int i = 0; i < p.size(); i++)  
        { 
            p.at(i).display(); 
        } 
        p.erase(p.begin() + x - 1); 
        cout << "After delete:" << endl; 
        for (int i = 0; i < p.size(); i++)  
        { 
            p.at(i).display(); 
        } 
        goto loop; // loop and goto make the program run until user decide to exit 
    } 
    else if (n == 4)  
    { 
        string time; 
        cout << "Please enter your date : " << endl; 
        getline(cin >> ws, time); 
        for (int i = 0; i < p.size(); i++)  
        { 
            if (time == p.at(i).getDate())  
            { 
                p.at(i).display(); 
            } 
        } 
        goto loop; // loop and goto make the program run until user decide to exit 
    } 
    else if (n == 5) 
    { 
        string departure; 
        cout << "Please enter the departure : " << endl; 
        getline(cin >> ws, departure); 
        for (int i = 0; i < p.size(); i++)  
        { 
            if (departure == p.at(i).getDeparture())  
            { 
                p.at(i).display(); 
            } 
        } 
    goto loop; // loop and goto make the program run until user decide to exit 
    }
    else if (n == 6) 
    { 
        string arrival; 
        cout << "Please enter the arrival : " << endl; 
        getline(cin >> ws, arrival); 
        for (int i = 0; i < p.size(); i++)  
        { 
            if (arrival == p.at(i).getArrival())  
            { 
                p.at(i).display(); 
            } 
        } 
        goto loop; // loop and goto make the program run until user decide to exit 
    } 
    else if (n == 7)  
    { 
        int count = 0; 
        string date1; 
        string date2; 
        cout << "Start date : " << endl; 
        getline(cin >> ws, date1); 
        int time1= stoi(date1, nullptr, 10); 
        cout << "End date : " << endl; 
        getline(cin >> ws, date2); 
        int time2= stoi(date2, nullptr, 10); 
        for (int i = 0; i < p.size(); i++)  
        { 
            int time = stoi(p.at(i).getDate()); 
            if (p.at(i).getCheck() == 1)  
            { 
                if (time <= time2 && time >= time1) 
                { 
                    count++; 
                } 
            } 
        } 
        cout << "Number of flight in the period of time is : " << count << endl; 
        goto loop; // loop and goto make the program run until user decide to exit 
    } 
    else if (n == 8)  
    { 
        int sum = 0; 
        int count = 0; 
        string date1; 
        string date2; 
        cout << "Start date : " << endl; 
        getline(cin >> ws, date1); 
        int time1= stoi(date1, nullptr, 10); 
        cout << "End date : " << endl; 
        getline(cin >> ws, date2); 
        int time2= stoi(date2, nullptr, 10); 
        for (int i = 0; i < p.size(); i++) 
        { 
            int time = stoi(p.at(i).getDate()); 
            if (time <= time2 && time >= time1)  
            { 
                sum += p.at(i).getCommission();
            } 
        }
        cout << "Sum of commission in the period of time is : " << sum<< endl; 
        goto loop; // loop and goto make the program run until user decide to exit 
    }
    else if(n==9) 
    { 
        for(int i=0; i<p.size(); i++) 
        { 
            p.at(i).display(); 
        } 
        goto loop; // loop and goto make the program run until user decide to exit 
    } 
    else if (n == 10)  
    { 
        return 0; // end program 
    } 
} 