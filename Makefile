NAME = server

FLAGS = -Wall -Wextra -Werror

GARBAGE = *.o */*.o *.gch */*.gch *.out */*.out

SRCS = server.c \
		client.c

# Colors variables
OBJS = $(SRCS:.c=.o)

GREEN = \033[0;32m

RED = \033[0;31m

BLUE = \033[0;34m

END = \033[0m

# Rules
.c.o:
	@echo "$(GREEN)###$(BLUE) Exec .c.o rule$(GREEN)###$(END)"
	@cc -c -g $(SRCS) -I ./

all: $(OBJS)
	@echo "$(GREEN)###$(BLUE) Exec all rule $(GREEN)###$(END)"

debug: re
	@echo "$(GREEN)###$(BLUE) Exec debug rule$(GREEN)###$(END)"
	@cc $(FLAGS) -g main.c -L. -lftprintf && ./a.out | cat -e

clean: $(OBJS)
	@rm -rf $(OBJS) $(GARBAGE)
	@echo "$(RED)#Cleaned $(END) $(GARBAGE)"

fclean: clean
	@rm -rf $(NAME) */*.a
	@echo "$(RED)#Cleaned $(END) $(NAME)"

re: fclean
	@make all

.PHONY: all clean fclean re bonus