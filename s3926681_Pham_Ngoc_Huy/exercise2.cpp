/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author:  Pham Ngoc Huy
    ID: s3926681   
    Compiler used : Homebrew GCC 13.2.0) 13.2.0
    Created  date: 13/01/2024
    Acknowledgement:  W3School
*/


#include <iostream>

using namespace std;


class City
{
 public:
    string name;
    float stayingDays;
    City* nextCity;

 public: 
    // constructor: 
    City(string name, int days)
    : name(name), stayingDays(days), nextCity(nullptr) {};

};   


class TripPlanner {
private:
    City* head;

public:
    //constructor
    TripPlanner() : head(nullptr) {}

    void addCity(string name, int days) {
        City* newCity = new City(name, days);
        newCity->nextCity = head;
        head = newCity;
    };

    void printTripPlan() {
        City* currentCity = head;
        while (currentCity != nullptr) {
            cout << currentCity->name << "\t " << currentCity->stayingDays << " days" << endl;
            currentCity = currentCity->nextCity;
        }
    }

    void updateTripPlan(string cityName, int newStayingDays) {
        City* currentCity = head;
        City* prevCity = nullptr;

        while (currentCity != nullptr && currentCity->name != cityName) {
            prevCity = currentCity;
            currentCity = currentCity->nextCity;
        }

        if (currentCity == nullptr) {
            cout << "City not found in the trip plan." << endl;
            return;
        }

        int daysDiff = newStayingDays - currentCity->stayingDays;
        currentCity->stayingDays = newStayingDays;

        if (newStayingDays == 0) {
            if (prevCity == nullptr) {
                head = currentCity->nextCity;
            } else {
                prevCity->nextCity = currentCity->nextCity;
            };

            delete currentCity;
            cout << "Removed from the trip plan." << endl;
        } else {
            cout << "Updated. There will be a total of " << newStayingDays + daysDiff << " days staying in this and next cities in the trip." << endl;
        }
    }

    ~TripPlanner() {
        City* currentCity = head;
        while (currentCity != nullptr) {
            City* nextCity = currentCity->nextCity;
            delete currentCity;
            currentCity = nextCity;
        }
    }
};

int main() {
    TripPlanner trip;

    trip.addCity("Can Tho", 3);
    trip.addCity("Da Lat", 2);
    trip.addCity("Nha Trang", 4);
    trip.addCity("Da Nang", 3);
    trip.addCity("Hue", 5);

    cout << "Initial trip plan:" << endl;
    trip.printTripPlan();

    string cityName;
    int newStayingDays;

    cout << "Enter the city name: ";
    cin >> cityName;

    cout << "Update the number of staying days: ";
    cin >> newStayingDays;

    trip.updateTripPlan(cityName, newStayingDays);

    cout << "Updated trip plan:" << endl;
    trip.printTripPlan();

    return 0;
}

