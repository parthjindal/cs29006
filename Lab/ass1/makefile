CC = g++ -std=c++11
DEPS = main.o novel.o book.o lms.o play.o

main: $(DEPS)
	$(CC)  -o $@  $(DEPS)

main.o: main.cc book.hpp novel.hpp lms.hpp play.cc
	$(CC) -c main.cc

novel.o: novel.cc novel.hpp book.hpp
	$(CC) -c novel.cc

play.o: play.cc play.hpp book.hpp
	$(CC) -c play.cc

lms.o: lms.cc lms.hpp book.hpp
	$(CC) -c lms.cc

book.o: book.cc book.hpp
	$(CC) -c book.cc
clean:
	rm -rf *.o

