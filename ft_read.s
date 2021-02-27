# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_read.s                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 14:34:53 by nayache           #+#    #+#              #
#    Updated: 2021/02/25 14:51:04 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern __errno_location
global ft_read

section .text

ft_read:
		mov rax, 0
		syscall
		cmp rax, 0
		jl error
		ret
error:
		mov rdi, rax
		neg rdi
		call __errno_location
		mov [rax], rdi
		mov rax, -1
		ret
