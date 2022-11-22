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
CFLAGS = -Wall -Werror -Wextra -pthread -g -fsanitize=thread

all:	$(NAME)

$(NAME):$(ODIR) $(OBJ)
	@echo "\033[1;33mcompiling $(NAME)...\033[0m"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) 
	@echo "\033[1;32mDONE;\033[0m"
	@echo "\033[1;37mexe: ./philo [n_philo] [time_death] [time_eat] [time_sleep] [dinners]\033[0m"

$(ODIR)/%.o: $(SDIR)/%.c
	@$(CC) $(CFLAGS) -c $^ -o $@

clean:
	@-rm -rf -f $(ODIR)
	@echo "cleaned directory"

fclean: clean
	@-rm -f $(NAME) 

re: fclean all

$(ODIR):
	@mkdir $(ODIR)
