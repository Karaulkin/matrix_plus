GCC=gcc
SRC=s21_matrix_oop.cpp
OBJ=s21_matrix_oop.o
CFLAGS=--std=c++17 -lstdc++ -lm
TESTFLAGS=-lgtest -lgcov
GCOVFLAGS=--coverage -fprofile-arcs -ftest-coverage 
HTML=lcov -t tests -o rep.info -c -d ./
OS = $(shell uname)

all: clean gcov_report

clean:
	rm -rf *.o *.a *.so *.gcda *.gcno *.gch rep.info *.html *.css tests report *.txt *.dSYM

tests: s21_matrix_oop.a
	$(GCC) -g tests.cpp s21_matrix_oop.a $(CFLAGS) $(TESTFLAGS) -o tests
	./tests

s21_matrix_oop.a: clean
	$(GCC) $(GCOVFLAGS) -c $(SRC)
	ar rcs s21_matrix_oop.a $(OBJ)
	ranlib s21_matrix_oop.a


gcov_report: tests
	$(HTML)
	genhtml -o report rep.info
	open report/index.html

check: tests
	clang-format -style="{BasedOnStyle: Google}" -i *.cpp *.h
	cppcheck --enable=all --suppress=missingIncludeSystem --inconclusive --check-config $(SRC) *.h

ifeq ($(OS), Darwin)
	leaks --atExit -- tests
else
	CK_FORK=no valgrind --vgdb=no --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./test
endif