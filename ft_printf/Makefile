NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

GARBAGE = *.o */*.o *.gch */*.gch *.out */*.out

SRCS = ft_printf.c \
		ft_alter_c.c \
		ft_alter_s.c \
		ft_alter_p.c \
		ft_alter_d.c \
		ft_alter_u.c \
		ft_alter_x.c \
		ft_addchar_i.c \
		ft_dlen.c \
		ft_addnbr_base.c

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
	@cd ./libft && \
	make fclean bonus && \
	cp libft.a ../$(NAME) && \
	rm libft.a && \
	cd ../
	@make .c.o
	@ar rc $(NAME) $(OBJS)
	@echo "$(GREEN)#Created: $(END) $(NAME)"
	@make clean
	@ranlib $(NAME)

debug: re
	@echo "$(GREEN)###$(BLUE) Exec debug rule$(GREEN)###$(END)"
	@cc $(FLAGS) -g main.c -L. -lftprintf && ./a.out | cat -e
#	@cc $(FLAGS) -g main.c $(SRCS) && ./a.out | cat -e

# bonus: $(SRCS) += $(OBJS)
# bonus:
# 	@echo "$(GREEN)#Added: $(END) $(BONUS)"
# bonus: .c.o
# 	@echo "$(GREEN)###$(BLUE) Exec Bonus rule$(GREEN)###$(END)"
# 	@make re

# bonus-debug: bonus
# 	@echo "$(GREEN)###$(BLUE) Debugging Bonus Files$(GREEN)###$(END)"
# 	@cc $(FLAGS) -g main.c $(SRCS) && ./a.out | cat -e

clean: $(OBJS)
	@rm -rf $(OBJS) $(GARBAGE)
	@echo "$(RED)#Cleaned $(END) $(GARBAGE)"

fclean: clean
	@rm -rf $(NAME) */*.a
	@echo "$(RED)#Cleaned $(END) $(NAME)"

re: fclean
	@make all

.PHONY: all clean fclean re bonus