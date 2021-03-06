CC = g++ -std=c++11
APP = Application
# CCFLAGS = -D_DEBUG
DEPS = Station.o Railways.o Date.o BookingClasses.o Booking.o $(APP).o

main: $(DEPS)
	$(CC) $(DEPS) -o main


Station.o: Station.cpp Station.h Railways.h
	$(CC) $(CCFLAGS) -c Station.cpp

Railways.o: Railways.cpp Railways.h
	$(CC) $(CCFLAGS) -c Railways.cpp

Date.o: Date.cpp Date.h
	$(CC) $(CCFLAGS) -c Date.cpp

BookingClasses.o: BookingClasses.cpp BookingClasses.h
	$(CC) $(CCFLAGS) -c BookingClasses.cpp

Booking.o : Booking.cpp Booking.h
	$(CC) $(CCFLAGS) -c Booking.cpp

$(APP).o : $(APP).cpp Booking.h
	$(CC) $(CCFLAGS) -c $(APP).cpp

clean:
	rm -rf *.o main