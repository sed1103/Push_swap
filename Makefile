NAME = push_swap
BONUS_NAME = checker

SRCS =  src/main.c \
	src/swap.c \
	src/rotate.c \
    src/reverse_rotate.c \
	src/push.c \
	src/mini_sort.c \
	src/ft_validation.c \
	src/ft_strjoin.c \
	src/ft_split.c \
	src/ft_lstclear.c \
	src/ft_issorted.c \
	src/ft_checknums.c \
	src/ft_atoi.c \
	src/butterfly.c \
	src/add_stack.c \
	src/ft_strlen.c

BONUS_SRCS = src/checker.c \
	     src/get_next_line.c \
	     src/get_next_line_utils.c \
		src/swap.c \
		src/rotate.c \
		src/reverse_rotate.c \
		src/push.c \
		src/mini_sort.c \
		src/ft_validation.c \
		src/ft_strjoin.c \
		src/ft_split.c \
		src/ft_lstclear.c \
		src/ft_issorted.c \
		src/ft_checknums.c \
		src/ft_atoi.c \
		src/butterfly.c \
		src/add_stack.c \
		src/ft_strlen.c \
 
OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)	

CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME)

%.o: %.c Includes/push_swap.h Makefile
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)

# test: $(NAME)
# 	$(eval ARG = $(shell jot -r 100 0 2000000))
# 	./push_swap $(ARG) | ./checker_Mac $(ARG)
# 	@echo -n "Instructions: "
# 	@./push_swap $(ARG) | wc -l

# test_my: $(NAME) $(BONUS_NAME)
# 	$(eval ARG = $(shell jot -r 500 0 2000000))
# 	./push_swap $(ARG) | ./checker $(ARG)
# 	@echo -n "Instructions: "
# 	@./push_swap $(ARG) | wc -l

re: fclean all bonus

.PHONY: all clean fclean re