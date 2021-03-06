<!-- CS20006 Assignment 
README.md
@author Parth Jindal(19CS30033) -->

# Railway Booking System

A railway booking / reservation system designed by **Parth Jindal(19CS30033)** as an assignment in the Software Engineering Theory (CS20006) course.

## Details of Various Header and Source Files

- **Station.h**  
Header file for `Station`.

- **Station.cpp**  
Source file for `Station` class.

- **UnitTestStation.cpp**  
Unit Test file for `Station` class.

- **Railways.h**  
Header file for the singleton `Railways` class.

- **Railways.cpp**  
Source file for singletong `Railways` class.\\n
Contains Master Data of Stations and their distances.

- **UnitTestRailways.cpp**  
Unit Test file for `Railways` class.

- **Date.h**  
Header file for `Date` class.

- **Date.cpp**  
Source file for the `Date`.
Contains initialization for static consts.

- **UnitTestDate.cpp**  
Unit Test file for `Date` class.

- **BookingClasses.h**  
Header file for the hierarchy of the various booking classes (categories). The root is the abstract base class `BookingClasses`. Then we have 5 more abstract classes - `Berth`, `Seat`, `Berth2Tier` and `Berth3Tier`. At the end, we have the 7 concrete classes - `ACFirstClass`, `AC2Tier`,`FirstClass`, `AC3Tier`, `ACChairCar` `Sleeper` and `SecondSitting`. All 7 are Singleton classes.

- **BookingClasses.cpp**  
Source file for Abstract base and sub-classes `BookingClasses, Berth, Seat, Berth2Tier, Berth3Tier` and the 7 concrete classes - `ACFirstClass`, `AC2Tier`,`FirstClass`, `AC3Tier`, `ACChairCar` `Sleeper` and `SecondSitting`.

- **UnitTestBookingClasses.cpp**  
Unit Test file for the 7 concrete Booking classes.

- **Booking.h**  
Header file for the `Booking` class. 

- **Booking.cpp**  
Source file for the `Booking` class.

- **UnitTestBooking.cpp**  
Unit Test file for the `Booking` class.

- **Passenger.h**  
Header file for abstract `Passenger` class.\\n
(Not implemented,For future extensions)

- **ApplicationTestGiven.cpp**  
The already given application file illustrating various booking scenarios. We have added a few static constant initializations at the beginning which are necessary for the project to compile and run.

- **Application.cpp**  
Test Application Source file for the application.

- **makefile**  
A simple makefile to compile and build the project.

## Compiler Used

GNU GCC compiler used.\\n
C++11 Standard followed.


## Compilation and Build Instructions

To compile and build the project, ensure all the above listed files are in the same directory. Then navigate to that directory and run the following commands in the terminal:

```shell
$ make
$ ./main
```
To clean the directory of the object files and executable,run the following command in the terminal:

```shell
$ make clean
```

Note that by default, the application file selected is `Application.cpp`. To change this, just pass the name of the application file which you want to use (without the .cpp extension) as an argument to the `make` command. For example, if we want to use the file `ApplicationTest.cpp` as the application file, use the commands :

```shell
$ make APPFILE=ApplicationTest
$ ./main
```

## Compilation and Build Instructions for Unit Testing the Individual Classes

- Unit Test for `Station` class, use the following commands :   

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp UnitTestStation.cpp -o test1
$ ./test1
```

- Unit Test for `Railways` class, use the following commands :  

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp UnitTestRailways.cpp -o test2
$ ./test2
```

- Unit Test for `Date` class, use the following commands :  

```shell
$ g++ -std=c++11 Date.cpp UnitTestDate.cpp -o test3
$ ./test3
```

- Unit Test for `BookingClasses` hierarchy, use the following commands :  

```shell
$ g++ -std=c++11 BookingClasses.cpp UnitTestBookingClasses.cpp -o test4
$ ./test4
```

- Unit Test for `Booking` class, use the following commands :

```shell
$ g++ -std=c++11 Station.cpp Railways.cpp Date.cpp BookingClasses.cpp Booking.cpp UnitTestBooking.cpp -o test
$ ./test5
```