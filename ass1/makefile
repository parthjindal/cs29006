CC = g++
DEPS = main.o novel.o book.o logger.o

main: $(DEPS)
	$(CC)  -o $@  $(DEPS)

main.o: main.cc book.hpp novel.hpp logger.hpp
	$(CC) -c main.cc

novel.o: novel.cc novel.hpp book.hpp logger.hpp
	$(CC) -c novel.cc

book.o: book.cc book.hpp logger.hpp
	$(CC) -c book.cc

logger.o: logger.cc logger.hpp
	$(CC) -c logger.cc

clean:
	rm -rf *.o

