# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgo <jgo@student.42seoul.kr>               +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 20:10:46 by jgo               #+#    #+#              #
#    Updated: 2022/11/23 14:36:42 by jgo              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

include ./config/Rules.mk
include ./config/color_rules.mk

PIPEX = pipex
NAME = $(PIPEX)

all bonus clean fclean re:
	$(MAKE) TOPDIR=`pwd` -C lib $@
	$(MAKE) TOPDIR=`pwd` -C src $@

$(PIPEX):
	$(MAKE) TOPDIR=`pwd` -C lib
	$(MAKE) TOPDIR=`pwd` -C src $@

.PHONY: all clean fclean re bonus