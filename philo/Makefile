NAME = philo

SRCS= deadcontrol.c helperutils.c init.c loop.c main.c philoutils.c
OBJS = deadcontrol.o helperutils.o init.o loop.o main.o philoutils.o

FLAGS = -Wall -Wextra -Werror -g -pthread
FLAGS_DATARACE = -fsanitize=thread -g

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -o $(NAME) $(OBJS) $(FLAGS)

clean:
	rm -f $(OBJS)

fclean:clean
	rm -f $(NAME)

data_race:
	@gcc $(FLAGS_DATARACE) $(SRCS) -o $(NAME)

re: clean all

.PHONY : all clean fclean re 