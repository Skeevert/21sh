# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbednar <rbednar@student.21school.ru>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/14 18:21:57 by rbednar           #+#    #+#              #
#    Updated: 2020/06/03 18:16:54 by rbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = 	ft_buf/ft_buf_new.c \
		ft_buf/ft_do_buf_empty.c \
		ft_atoi_pf.c \
		ft_help_double.c \
		ft_buf/ft_buf_add.c \
		ft_itoa_base.c \
		ft_fract.c \
		ft_double.c \
		ft_itoa_pf.c \
		ft_ldoublecheck.c \
		ft_num_dig.c \
		ft_itoa_base_ll.c \
		ft_param/ft_param_nul.c \
		ft_printf.c \
		ft_str/ft_memnew_pf.c \
		ft_lnum/ft_lnum.c \
		ft_str/ft_memset_pf.c \
		ft_percent.c \
		ft_str/ft_strjoin_pf.c \
		ft_str/ft_strndup_pf.c \
		ft_str/ft_write_to_buff.c \
		ft_str/ft_strnew_pf.c \
		ft_type/ft_c.c \
		ft_param/ft_param_add.c \
		ft_str/ft_strlen_pf.c \
		ft_type/ft_color.c \
		ft_type/ft_f.c \
		ft_type/ft_d_up.c \
		ft_type/ft_f_up.c \
		ft_type/ft_d.c \
		ft_type/ft_o_null.c \
		ft_type/ft_prcnt.c \
		ft_type/ft_p.c \
		ft_type/ft_o_up.c \
		ft_type/ft_o.c \
		ft_type/ft_u_up.c \
		ft_type/ft_x_null.c \
		ft_type/ft_u.c \
		ft_type/ft_s.c \
		ft_type/ft_x.c \
		ft_type/ft_x_up.c

DIR_O = objs

DIR_S = src

OBJ = $(addprefix $(DIR_O)/,$(SRC:.c=.o))

INC = ./inc

FLAGS = -Wall -Wextra -Werror

$(NAME) : $(OBJ)
	@echo "\033[32;01mCompiling ft_printf...\033[0m"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "\033[32;01mlibftprintf.a done\033[0m"

$(OBJ):	$(DIR_O)/%.o: $(DIR_S)/%.c $(INC)/ft_printf.h
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/ft_buf
	@mkdir -p $(DIR_O)/ft_lnum
	@mkdir -p $(DIR_O)/ft_param
	@mkdir -p $(DIR_O)/ft_str
	@mkdir -p $(DIR_O)/ft_type
	@gcc $(FLAGS) -c -I $(INC) -o $@ $<

all : $(NAME)

clean :
	@/bin/rm -Rf $(OBJ) $(DIR_O)

fclean : clean
	@/bin/rm -f $(NAME)

re : fclean all
