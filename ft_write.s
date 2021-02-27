# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_write.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nayache <nayache@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/25 14:34:40 by nayache           #+#    #+#              #
#    Updated: 2021/02/25 14:50:34 by nayache          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

extern __errno_location
global ft_write

section .text

ft_write:
		mov rax, 1
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
