CC = gcc

CFLAGS = -Wall -Wextra -Werror -IHEADERS

SOURCE = push_swap.c Utils/ft_lstnew.c Utils/ft_lstadd_back.c Utils/ft_atoi.c \
Utils/ft_lstadd_front.c Utils/ft_lstlast.c Utils/ft_lstsize.c \
fonctions_1.c fonctions_2.c fonctions_3.c sort.c sort_tab.c is_valid.c \
instructions.c

BONUS = checker_bonus/get_next_line/get_next_line.c checker_bonus/get_next_line/get_next_line_utils.c \
checker_bonus/checker.c checker_bonus/fonction_1.c checker_bonus/is_valid.c Utils/ft_atoi.c Utils/ft_lstadd_back.c Utils/ft_lstadd_front.c \
Utils/ft_lstlast.c Utils/ft_lstnew.c Utils/ft_lstsize.c checker_bonus/fonction_2.c checker_bonus/fonction_3.c checker_bonus/fonction_4.c \

O_SRC = $(SOURCE:.c=.o)

O_BONUS = $(BONUS:.c=.o)

NAME = push_swap

all: $(NAME)

$(NAME): $(O_SRC)
	$(CC) $(CFLAGS) $(O_SRC) -o $(NAME)

bonus: $(O_BONUS)
	$(CC) $(CFLAGS) $(O_BONUS) -o checker

clean:
	rm -f $(O_SRC) $(O_BONUS)

fclean: clean
	rm -f $(NAME) checker

re:	clean all