NAME		= s21_sprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
SRCS		= s21_sprintf.c s21_parse_flag.c \
				s21_flag_proc.c s21_processor.c s21_proc_char.c \
				s21_proc_string.c s21_proc_pointer.c s21_proc_int.c \
				s21_proc_uint.c s21_proc_hex.c s21_proc_percent.c \
				s21_isdigit.c s21_itoa.c s21_strlcpy.c s21_strdup.c s21_strlen.c
OBJS		= ${SRCS:.c=.o}
HEADER		= s21_sprintf.h
LIBC		= ar rcs
RM			= rm -f

all:		${NAME}
${NAME}:	${OBJS}
			cp ${NAME}
			${LIBC} ${NAME} ${OBJS}
			
link:
clean: 
	rm -rf *.o *.gch *.a


dick:
	gcc -Wall -Werror -Wextra s21_sprintf.c s21_parse_flag.c s21_flag_proc.c s21_processor.c s21_proc_char.c s21_proc_string.c s21_proc_pointer.c s21_proc_int.c s21_proc_uint.c s21_proc_hex.c s21_proc_percent.c s21_isdigit.c \
	s21_itoa.c s21_strlcpy.c s21_strdup.c s21_strlen.c s21_strcat.c s21_proc_float.c -o test