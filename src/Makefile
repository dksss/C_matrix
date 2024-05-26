FLAGS = -Wall -Werror -Wextra -std=c11
FUNC_FILES = funcs/*.c
TEST_FILES = tests/*.c

OS := $(shell uname -s)

ifeq ($(OS), Linux)
	LIB = -lcheck -lm -lrt -lpthread -lsubunit
	OPEN = google-chrome
else
	LIB = -lcheck -lm -lpthread
	OPEN = open
endif

all: clean test gcov_report

matrix.a:
	gcc $(FLAGS) $(FUNC_FILES) -c
	ar rcs matrix.a *.o
	ranlib matrix.a
	rm *.o

test: clean
	gcc $(FLAGS) --coverage -o test $(FUNC_FILES) $(TEST_FILES) $(LIB)
	./test

gcov_report: test
	lcov -t "matrix_test" -o coverage.info --no-external -c -d .
	genhtml -o report coverage.info
	$(OPEN) report/index.html

clean:
	rm -rf test matrix.a *.gcno *.info *.gcda *.dSYM report RESULT_VALGRIND.txt

clang:
	clang-format -style=Google -n $(FUNC_FILES) $(TEST_FILES)

valgrind: clean test
	CK_FORK=no valgrind -s  --track-origins=yes --tool=memcheck --leak-check=full --show-leak-kinds=all --log-file=RESULT_VALGRIND.txt ./test
