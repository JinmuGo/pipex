# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.fr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 14:05:59 by jgo               #+#    #+#              #
#    Updated: 2023/05/14 10:00:15 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef TOPDIR
		TOPDIR = $(abspath ..)
endif
include $(TOPDIR)/make_config/Rules.mk
include $(TOPDIR)/make_config/color_rules.mk

PIPEX = pipex
NAME = $(PIPEX)

CPPFLAGS = -I$(TOPDIR)/includes -I./includes
LDFLAGS = -L$(TOPDIR)/lib
LDLIBS = -lftprintf -lft

BONUS_HEAD = pipex_bonus.h
MANDATORY_HEAD = pipex.h

src_m = pipex.c \
		input.c	\
		error.c \
		utils.c

src_b = pipex_bonus.c \
		input_bonus.c \
		error_bonus.c \
		utils_bonus.c

src_m_add_dir = $(addprefix src_m/, $(src_m))
src_b_add_dir = $(addprefix src_b/, $(src_b))

SRCS_M_OBJS = $(src_m_add_dir:.c=.o)
SRCS_M_DEPS = $(src_m_add_dir:.c=.d)

SRCS_B_OBJS = $(src_b_add_dir:.c=.o)
SRCS_B_DEPS = $(src_b_add_dir:.c=.d)

HEAD = $(if $(filter bonus, $(MAKECMDGOALS)),$(BONUS_HEAD),$(MANDATORY_HEAD))
SRCS = $(if $(filter bonus, $(MAKECMDGOALS)),$(src_b_add_dir),$(src_m_add_dir))
OBJS = $(SRCS:.c=.o)
DEPS = $(SRCS:.c=.d)
-include $(DEPS)

all bonus: $(NAME)

$(NAME): $(OBJS)
	$(LINK.o) $^ $(LOADLIBES) $(LDLIBS) -o $@
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) link_files
	$(MAKE) files=$(HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/includes link_files

clean:
	$(MAKE) files=$(BONUS_HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	$(MAKE) files=$(MANDATORY_HEAD) src_dir=`pwd` dst_dir=$(TOPDIR)/includes unlink_files
	$(RM) $(SRCS_B_DEPS) $(SRCS_B_OBJS)
	$(RM) $(SRCS_M_DEPS) $(SRCS_M_OBJS)

fclean: clean
	$(MAKE) files=$(NAME) src_dir=`pwd` dst_dir=$(TOPDIR) unlink_files
	$(RM) $(NAME)

re: fclean
	$(MAKE) all

.PHONY: all clean fclean re bonus