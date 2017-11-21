# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gperilla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/06 16:43:17 by gperilla          #+#    #+#              #
#    Updated: 2017/11/20 13:16:28 by gperilla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

WARNINGS = -Wall -Wextra -Werror

LIB = -L/Users/gperilla/Projets/Mylib -lft

OBJC = main.c lecture.c error.c

OBJ = $(OBJC:.c=.o)

DEP = $(patsubst %.c, .depend/%.d, $(OBJC))

define OK
	@tput setaf 255
	@echo -n $1
	@tput setaf 10
	@echo ' [Compiled]'
	@tput sgr0
endef

define ISOK
	@tput setaf 6
	@echo -n $1
	@tput setaf 10
	@echo ' [Run it you fool]'
	@tput sgr0
endef

all: $(NAME)

$(NAME): $(OBJ)
	@gcc $(WARNINGS) $(LIB) $^ -o $@
	@$(call ISOK, $@)

debug: $(OBJ)
	gcc $(LIB) $^ -o $@

%.o: %.c .depend
	@gcc -MMD -c $(WARNINGSS) $< -o $@ -MF ./.depend/$*.d
	$(call OK, $*)

.depend:
	@mkdir -p .depend

clean:
	@rm -f $(OBJ)
	@echo 'removed .o'

fclean: clean
	@rm -rf $(NAME) debug .depend
	@echo 'All your base are belong to us'

re: fclean all

.PHONY: all clean fclean re

-include $(DEP)
