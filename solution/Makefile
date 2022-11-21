NAME =  philo

ODIR = obj
SDIR = src

SRC =		./src/actions.c\
			./src/error.c\
			./src/init.c\
			./src/main.c\
			./src/banquet.c\
			./src/check.c\
			./src/utils.c\
			./src/parse_utils/ft_atoi.c\
			./src/parse_utils/input_utils.c\

OBJ =	$(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRC))

CC = cc
CFLAGS = -Wall -Werror -Wextra -pthread #-fsanitize=thread

all:	$(NAME)

$(NAME):$(ODIR) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	echo "done;"

$(ODIR)/%.o: $(SDIR)/%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(ODIR)

rmdir:
	rm -rf $(NAME).dSYM 

fclean: clean rmdir
	-rm $(NAME) 

re: fclean all

$(ODIR):
	mkdir -p $(ODIR)