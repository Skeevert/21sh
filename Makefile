# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rbednar <rbednar@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/25 13:55:36 by rbednar           #+#    #+#              #
#    Updated: 2020/08/01 17:43:58 by rbednar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

FLAGS = -Wall -Wextra #-Werror
FLAGS += -g

EDIT_LINE = 		edit_line/line_edition_start.c \
			edit_line/line_edition_utils.c \
			edit_line/prompts.c \
			edit_line/terminal_and_termcap.c \
			edit_line/sequence_route.c \
			edit_line/insert_char.c \
			edit_line/cursor_changes.c \
			edit_line/undo_paste_call.c \
			edit_line/undo.c \
			edit_line/history_proc.c \
			$(KEY_SEQUENCES)

KEY_SEQUENCES =		edit_line/key_sequences/cut_line_parts.c \
			edit_line/key_sequences/arrow_keys.c \
			edit_line/key_sequences/delete_keys.c \
			edit_line/key_sequences/jump_words.c \
			edit_line/key_sequences/jump_around_and_paste.c

LEXPARSER = 		lexparser/lexparser.c \
			lexparser/find_spec.c \
			lexparser/slice_to_blocks.c \
			lexparser/before_execution.c \
			lexparser/parser_processing.c \
			$(PATH_TREE) \
			$(EXEC) \
			$(QUOTING) \
			$(SUBSTITUTION) \
			$(ASSIGNMENT) \
			$(REDIRECTION)

PATH_TREE = 		lexparser/path_tree/ft_block.c \
			lexparser/path_tree/ft_path_help.c \
			lexparser/path_tree/ft_path.c

EXEC = 				lexparser/exec/exec_core.c \
			lexparser/exec/exec_utils.c \
			lexparser/exec/path_parse.c

QUOTING =			lexparser/quoting/quote_control.c \
			lexparser/quoting/quote_control_err.c \
			lexparser/quoting/pre_parsing_work.c \
			lexparser/quoting/pre_parsing_ansi.c

SUBSTITUTION = 		lexparser/substitution/substitution.c \
			lexparser/substitution/ft_find_var.c \
			lexparser/substitution/ft_curv_var.c \
			lexparser/substitution/param_help_func.c \
			lexparser/substitution/ft_substring_var.c \
			lexparser/substitution/tilda.c

ASSIGNMENT =		lexparser/assignment/backend_variables.c \
			lexparser/assignment/assignment.c \
			lexparser/assignment/assignment_local.c

REDIRECTION = 		lexparser/redirection/redirect.c \
			lexparser/redirection/ft_tmpfile.c \
			lexparser/redirection/redir_types_out_check.c \
			lexparser/redirection/redir_types_out_do.c \
			lexparser/redirection/redir_types_in_check.c \
			lexparser/redirection/redir_types_in_do.c \
			lexparser/redirection/fd_block.c \
			lexparser/redirection/here_doc.c \
			lexparser/redirection/here_doc_buffer.c

ENVIRONMENT =	environment/global_variables.c \
			environment/global_vars_proc.c

CD =        builtins/cd/cd.c \
			builtins/cd/cd_parser.c \
			builtins/cd/cd_change_path.c \
			builtins/cd/cd_new_path.c

BUILTINS = 			builtins/exit.c \
			builtins/setenv.c \
			builtins/unsetenv.c \
			builtins/env.c \
			builtins/echo.c \
			$(CD)

HELP_LIB =			help_lib/ft_straddsy.c \
			help_lib/ft_strrchri.c \
			help_lib/ft_issign.c \
			help_lib/ft_add_list_to_end.c \
			help_lib/ft_lstclear.c \
			help_lib/ft_lstlast.c \
			help_lib/ft_strlenchri.c \
			help_lib/ft_strchrcmp.c \
			help_lib/ft_find_token.c \
			help_lib/ft_make_techline.c \
			help_lib/ft_isoctdigit.c \
			help_lib/ft_ishexdigit.c \
			help_lib/ft_count_words_i.c \
			help_lib/ft_atoi_base.c \
			help_lib/ft_arrdel.c \
			help_lib/ft_arrshift.c \
			help_lib/ft_realloc_array.c \
			help_lib/ft_memrealloc_array.c \
			help_lib/ft_delelem_array.c \
			$(STACK_STRUCTURE) \
			$(MALLOC_FUNCTIONS)

STACK_STRUCTURE = 	help_lib/stack_structure/ft_init_stack.c \
			help_lib/stack_structure/ft_pop_stack.c \
			help_lib/stack_structure/ft_push_stack.c \
			help_lib/stack_structure/ft_clear_stack.c \
			help_lib/stack_structure/ft_last_stack.c

MALLOC_FUNCTIONS =	help_lib/malloc_functions/ft_itoa.c \
			help_lib/malloc_functions/ft_realloc.c \
			help_lib/malloc_functions/ft_strdup.c \
			help_lib/malloc_functions/ft_strjoin.c \
			help_lib/malloc_functions/ft_strndup.c \
			help_lib/malloc_functions/ft_strrejoin.c \
			help_lib/malloc_functions/ft_strsplit.c \
			help_lib/malloc_functions/ft_strshift.c \
			help_lib/malloc_functions/ft_xmalloc.c

SOURCES =	main.c \
			errno.c \
			signals.c \
			destructor.c \
			$(EDIT_LINE) \
			$(LEXPARSER) \
			$(ENVIRONMENT) \
			$(BUILTINS) \
			$(HELP_LIB)

DIR_O = objs

DIR_S = srcs

HEADERS = $(wildcard libft/includes/*.h) $(wildcard libft/ft_printf/inc/*.h)

INCLUDES = -I includes -I libft/includes -I libft/ft_printf/inc

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

LIBFT = $(addsuffix .libft , libft/)

%.libft:  $(HEADERS)
	@make -C $*

LIBS = -Llibft -lft -ltermcap

all:  $(LIBFT)	$(NAME)

$(NAME): $(OBJS)
	@make -C ./libft
	@echo "\033[32;01mCompiling 21sh...\033[0m"
	@gcc $(FLAGS) $(OBJS) -o $(NAME) $(LIBS)
	@echo "\033[32;01m21sh is ready\033[0m"

$(OBJS): $(DIR_O)/%.o: $(DIR_S)/%.c $(wildcard includes/*.h)
	@mkdir -p $(DIR_O)
	@mkdir -p $(DIR_O)/edit_line
	@mkdir -p $(DIR_O)/edit_line/key_sequences
	@mkdir -p $(DIR_O)/lexparser
	@mkdir -p $(DIR_O)/lexparser/path_tree
	@mkdir -p $(DIR_O)/lexparser/exec
	@mkdir -p $(DIR_O)/lexparser/quoting
	@mkdir -p $(DIR_O)/lexparser/assignment
	@mkdir -p $(DIR_O)/lexparser/substitution
	@mkdir -p $(DIR_O)/lexparser/redirection
	@mkdir -p $(DIR_O)/environment
	@mkdir -p $(DIR_O)/builtins
	@mkdir -p $(DIR_O)/builtins/cd
	@mkdir -p $(DIR_O)/help_lib
	@mkdir -p $(DIR_O)/help_lib/stack_structure
	@mkdir -p $(DIR_O)/help_lib/malloc_functions
	gcc $(FLAGS) -c $(INCLUDES) -o $@ $<

clean:
	@echo "\033[34mDeleting 21sh o-files\033[0m"
	@/bin/rm -Rf $(DIR_O)
	@make clean -C libft

fclean: clean
	@echo "\033[34mDeleting 21sh binary\033[0m"
	@/bin/rm -f $(NAME)
	@make fclean -C libft

re:		fclean all

.PHONY: all fclean clean re
