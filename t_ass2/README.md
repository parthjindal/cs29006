<!-- CS20006 Assignment 
README.md
@author Parth Jindal(19CS30033) -->

# Railway Booking System

A railway booking / reservation system designed by **Parth Jindal(19CS30033)** as an assignment in the Software Engineering Theory (CS20006) course.

## Details of Various Header and Source Files

- **Station.h**  
This is the header file for the `Station` class and contains the declarations of all the data members, constructors and member functions of the `Station` class.

- **Station.cpp**  
This is the source file for the `Station` class. It contains the implementations of all the constructors and member functions declared in `Station.h`.

- **UnitTestStation.cpp**  
This file contains the function body for the unit testing function of the `Station` class.

- **Railways.h**  
This is the header file for the singleton `Railways` class and contains the declarations of all the data members and member functions of the `Railways` class.  

- **Railways.cpp**  
This is the source file for the `Railways` class. It contains the initializations of the static constants and the function bodies of the member functions in the `Railways` class.

- **UnitTestRailways.cpp**  
This file contains the function body for the unit testing function of the `Railways` class.

- **Date.h**  
This is the header file for the `Date` class and contains the declarations of all the data members, constructors and member functions of this class.

- **Date.cpp**  
This is the source file for the `Date` class. In this file, we first initialize the static constants pf the `Date` class. Then we implement all the constructors and member functions declared in `Date.h`.

- **UnitTestDate.cpp**  
This file contains the function body for the unit testing function of the `Date` class.

- **BookingClasses.h**  
This is the header file for the hierarchy of the various booking classes (categories). The root is the abstract base class `BookingClasses`. Then we have 5 more abstract classes - `Berth`, `Seat`, `Tiers2` and `Tiers3`. At the end, we have the 7 concrete classes - `ACFirstClass`, `AC2Tier`, `FirstClass`, `AC3Tier`, `ACChairCar` `Sleeper` and `SecondSitting`. All 7 of these are singleton classes.

- **BookingClasses.cpp**  
This is the source file for the hierarchy of booking classes. It contains the implementations of all the constructors and member functions declared in `BookingClasses.h`.

- **UnitTestBookingClasses.cpp**  
This file contains the function bodies for the unit testing functions of the 7 concrete booking classes.

- **Booking.h**  
This is the header file for the `Booking` class. It contains the declarations of all the data members, constructors and member functions of this class.

- **Booking.cpp**  
This is the source file for the `Booking` class. Here, we first initialize few of the static variables. Then we implement all the constructors and member functions declared in `Booking.h`.

- **UnitTestBooking.cpp**  
This file contains the function body for the unit testing function of the `Booking` class.

- **Passenger.h**  
This is the header file for the `Passenger` class and contains the declarations of the data members of the `Passenger` class. It is just an abstract class for now. We do not have any member function apart from a pure virtual function. There is no specific need for this class in this particular assignment.

- **ApplicationTestGiven.cpp**  
The already given application file illustrating various booking scenarios. We have added a few static constant initializations at the beginning which are necessary for the project to compile and run.

- **Application.cpp**  
This is a test application file created by me to perform the application testing for the project covering various scenarios.

- **makefile**  
A simple makefile to compile and build the project.

## Compiler Used

We have used the GNU GCC compiler. The entire code is written in C++. The C++ standard followed is C++11. All libraries used are standard C++ libraries.

## Compilation and Build Instructions

To compile and build the project, ensure all the above listed files are in the same directory. Then navigate to that directory and run the following commands in the terminal:

```shell
$ make
$ ./rbs
```

Note that by default, the application file selected is `Application.cpp`. To change this, just pass the name of the application file which you want to use (without the .cpp extension) as an argument to the `make` command. For example, if we want to use the file `ApplicationTestGiven.cpp` as the application file, use the commands :

```shell
$ make APPFILE=ApplicationTestGiven
$ ./rbs
```

## Compilation and Build Instructions for Unit Testing the Individual Classes

- For unit testing the `Station` class, use the following commands :   

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp UnitTestStation.cpp -o test
$ ./test
```

- For unit testing the `Railways` class, use the following commands :  

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp UnitTestRailways.cpp -o test
$ ./test
```

- For unit testing the `Date` class, use the following commands :  

```shell
$ g++ -std=c++11 Date.cpp UnitTestDate.cpp -o test
$ ./test
```

- For unit testing the `BookingClasses` hierarchy, use the following commands :  

```shell
$ g++ -std=c++11 BookingClasses.cpp UnitTestBookingClasses.cpp -o test
$ ./test
```

- For unit testing the `Booking` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp BookingClasses.cpp Booking.cpp UnitTestBooking.cpp -o test
$ ./test
```