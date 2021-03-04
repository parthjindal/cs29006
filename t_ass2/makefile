CC = g++ -std=c++11
APPFILE = Application
# CCFLAGS = -D_DEBUG
DEPS = Station.o Railways.o Date.o BookingClasses.o Booking.o $(APPFILE).o

main: $(DEPS)
	$(CC) $(DEPS) -o main


Station.o: Station.cc Station.h Railways.h
	$(CC) $(CCFLAGS) -c Station.cc

Railways.o: Railways.cc Railways.h
	$(CC) $(CCFLAGS) -c Railways.cc

Date.o: Date.cc Date.h
	$(CC) $(CCFLAGS) -c Date.cc

BookingClasses.o: BookingClasses.cc BookingClasses.h
	$(CC) $(CCFLAGS) -c BookingClasses.cc

Booking.o : Booking.cc Booking.h
	$(CC) $(CCFLAGS) -c Booking.cc

$(APPFILE).o : $(APPFILE).cc Booking.h
	$(CC) $(CCFLAGS) -c $(APPFILE).cc

clean:
	rm -rf *.o