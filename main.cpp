
#include <iostream>
#include <string>
#include <sstream>

// Address class definition
class Address {
  private:
    std::string street;
    std::string city;
    std::string state;
    std::string zip;

  public:
    Address();
    void init(std::string addressString);
    void printAddress();
};

// Date class definition
class Date {
  private:
    int month;
    int day;
    int year;

  public:
    Date();
    void init(std::string dateString);
    void printDate();
};

// Student class definition
class Student {
  private:
    std::string firstName;
    std::string lastName;
    Address address;
    Date birthDate;
    Date gradDate;
    int creditHours;

  public:
    Student();
    void init(std::string studentString);
    void printStudent();
    std::string getFirstName();
    std::string getLastName();
};

// ----------------------------------------
// Address class
// ----------------------------------------
Address::Address() { // constructor
    street = "";
    city = "";
    state = "";
    zip = "";
}

void Address::init(std::string addressString) { // initialize address from a string
    std::stringstream ss(addressString);

    std::getline(ss, street, ',');
    std::getline(ss, city, ',');
    std::getline(ss, state, ',');
    std::getline(ss, zip, ',');
}

void Address::printAddress() {
    std::cout << street << std::endl;
    std::cout << city << " " << state << ", " << zip << std::endl;
}

// ----------------------------------------
// Date class
// ----------------------------------------

Date::Date() { // constructor
    month = 0;
    day = 0;
    year = 0;
}

void Date::init(std::string dateString) {
// Read Date from students.csv file using getline
// dateString is a string in the format "month/day/year"
// Send the dateString to a stringstream and parse it into date field
// Need to use temp variable to hold the string value of each field before converting to int

    std::stringstream ss(dateString);
    std::string temp;

    std::getline(ss, temp, '/');
    std::stringstream(temp) >> month;

    std::getline(ss, temp, '/');
    std::stringstream(temp) >> day;

    std::getline(ss, temp, '/');
    std::stringstream(temp) >> year;

}

void Date::printDate() {
    std::string months[] = {
        "January", "February", "March", "April",
        "May", "June", "July", "August",
        "September", "October", "November", "December"
    };

    if (month >= 1 && month <= 12) { // using month - 1 as index, so month must be between 1 and 12
        std::cout << months[month - 1] << " " << day << ", " << year << std::endl;
    }
}

// ----------------------------------------
// Main function
// ----------------------------------------

void testAddress();
void testDate();
void testStudent();

void testAddress(){
  Address a;
  a.init("123 W Main St,Muncie,IN,47303");
  a.printAddress();
} // end testAddress

void testDate(){
 Date d;
 d.init("01/27/1997");
 d.printDate();
} // end testDate


int main(){
  std::cout << "Hello!" << std::endl;
  testAddress();
  testDate();
  return 0;
} // end main