CC = g++ -std=c++11
APPFILE = Application.cc

DEPS = Station.o Railways.o Date.o BookingClasses.o Booking.o App.o

main: $(DEPS)
	$(CC) $(DEPS) -o main


Station.o: Station.cc Station.h Railways.h
	$(CC) -c Station.cc

Railways.o: Railways.cc Railways.h
	$(CC) -c Railways.cc

Date.o: Date.cc Date.h
	$(CC) -c Date.cc

BookingClasses.o: BookingClasses.cc BookingClasses.h
	$(CC) -c BookingClasses.cc

Booking.o : Booking.cc Booking.h
	$(CC) -c Booking.cc

App.o: $(APPFILE) Booking.h
	$(CC) -c $(APPFILE)