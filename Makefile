NAME = philo

SOURCES = philomain.c helperfuncs/helperfuncs.c
COMPILE = gcc -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	$(COMPILE) $(SOURCES) -o philo

clean:
	rm -rf $(NAME)

fclean: clean

re: fclean all