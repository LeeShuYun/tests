# .SILENT:
LIBFT_DIR=libft
LIBFT_OBJS=libft/*.o
NAME=libftprintf.a
CC=cc
CFLAGS=-Wall -Werror -Wextra
XFLAG=-Wconversion
TESTFILE=test
PRINTF_SOURCES = ft_printnbr.c \
	ft_printhex.c \
	ft_printptr.c \
	ft_printstr.c \
	ft_printchar.c \
	ft_printunbr.c \
	ft_printf.c

PRINTF_OBJECTS = $(PRINTF_SOURCES:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

# $(PRINTF_NAME): $(LIBFT_BONUS_OBJS) $(LIBFTNAME) $(PRINTF_OBJECTS)
# 	make -C $(LIBFT_DIR) all
# 	@echo "Compiling libftprintf.a with libft.a ..."
# 	ar rcs $(PRINTF_NAME) $(LIBFTNAME)
# 	@echo "Finished compiling libftprintf."

$(NAME): $(PRINTF_OBJECTS)
	@echo "<<Making library>>"
	make -C $(LIBFT_DIR)
	ar -rcs $(NAME) $(LIBFT_OBJS) $(PRINTF_OBJECTS)
	@echo "Finished compiling library."

all: $(NAME)

clean:
	@echo "<<Cleaning up .o files>>"
	rm -f $(PRINTF_OBJECTS) $(LIBFT_DIR)/*.o

fclean: clean
	@echo "<<Cleaning up .a files>>"
	rm -f $(NAME) $(LIBFT_DIR)/*.a

re: fclean all

#https://gcc.gnu.org/onlinedocs/gcc/Link-Options.html
# -L. is used to tell that the static library libftprintf.a is in the current folder,
# -lftprintf to search for library 'libftprintf.a'
test: re
	$(CC) $(CFLAGS) -g -o $(TESTFILE) test_maketest.c -L. -lftprintf libft/libft.a

teststrict: re $(PRINTF_OBJECTS)
	$(CC) $(CFLAGS) $(XFLAG) $(PRINTF_OBJECTS) -g -o $(TESTFILE) testmain.c -L. -lftprintf

testprint: testclean test
	./$(TESTFILE) a

testhex: testclean test
	./$(TESTFILE) x

testptr: testclean test
	./$(TESTFILE) p

testchar: testclean test
	./$(TESTFILE) c

teststr: testclean test
	./$(TESTFILE) s

testunbr: testclean test
	./$(TESTFILE) u

testnbr: testclean test
	./$(TESTFILE) i

testclean:
	rm -f $(TESTFILE)


# https://cylab.be/blog/271/unit-testing-c-code
# gcc -o executable -std=c11 -Wall -ggdb3 main.c
# --ggdb3 -> valgrind prints exact line of mem loss
# https://gcc.gnu.org/onlinedocs/gcc/Debugging-Options.html
# gcno:version 'B05*', prefer 'B14*' because different version of gcov and gcc
debug: $(PRINTF_SOURCES) dclean fclean all
	gcc -fPIE -fprofile-arcs -ftest-coverage -ggdb3 -o $(TESTFILE) test_makedebug.c $(PRINTF_SOURCES) $(LIBFT_OBJS) $(LIBFT_BONUS_OBJS)
	./$(TESTFILE) 0
	gcov -c -p *.gcda *.gcno

#restrained debug option
# -Og runs some extra compiler passes that collect info useful for debugging
rdebug: $(PRINTF_SOURCES)
	gcc -Wall -Werror -Wextra -fprofile-arcs -ftest-coverage -Og $(PRINTF_SOURCES) -o $(TESTFILE)
	./$(TESTFILE)
	gcov -c -p *.gcda *.gcno

dclean: fclean
	rm -f libft/*.o printf/*.o $(TESTFILE) *.gcov *.gcda *.gcno a.out

#running under Memcheck for memory leaks
#https://valgrind.org/docs/manual/quick-start.html
valgrind: debug
	valgrind --leak-check=yes ./$(TESTFILE)

# #shows symbols used in each function - check for forbidden functions
normcheck:
	nm -u $(TESTFILE)

# # helper functions should show as t (static)
# # the number in front is memory address (offset) of helper_function inside the binary file.
# # this address might be in hexadecimal format, depending on the settings and platform.
staticfcheck:
	nm $(NAME)

.PHONY: all clean fclean re
