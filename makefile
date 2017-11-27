# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 16:43:17 by gperilla          #+#    #+#              #
#    Updated: 2017/11/27 15:53:33 by gperilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

WARNINGS = -Wall -Wextra -Werror

LIB = -I libft/includes -L libft/ -lft

OBJC = main.c error.c lecture.c left4letters.c reset_map.c size_map.c resolv.c\
	   show_result.c

OBJ = $(OBJC:.c=.o)

DEP = $(patsubst %.c, .depend/%.d, $(OBJC))

COLOR = $(shell bash -c 'echo $$RANDOM')

define OK
	@$(eval COLOR=$(shell echo $$(($(COLOR)+1))))
	@tput setaf $(COLOR)
	@echo -n $1
	@tput setaf 10
	@echo ' [Compiled]'
	@tput sgr0
endef

define ISOK
	@$(eval COLOR=$(shell echo $$(($(COLOR)+1))))
	@tput setaf $(COLOR)
	@echo -n $1
	@tput setaf 10
	@echo ' [Run it you fool]'
	@tput sgr0
endef

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) $(WARNINGS) $(LIB) $(OBJ) -o $@
	@$(call ISOK, $@)

%.o: %.c .depend
	@gcc -MMD -c $(WARNINGS) $< -o $@ -MF ./.depend/$*.d
	$(call OK, $*)

.depend:
	@mkdir -p .depend

clean:
	@rm -f $(OBJ)
	@echo 'removed .o'

fclean: clean
	@rm -rf $(NAME) .depend
	@echo 'All your base are belong to us'

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
