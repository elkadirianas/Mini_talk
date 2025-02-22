CC = cc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

CLIENT = client
SERVER = server


all : $(CLIENT) $(SERVER)

%.o : %.c minitalk.h
	$(CC) $(CFLAGS) -c $< -o $@


$(CLIENT): client.o utils.o
	$(CC) $(CFLAGS) client.o utils.o -o $@

$(SERVER): server.o utils.o
	$(CC) $(CFLAGS) server.o utils.o -o $@

clean :
	$(RM)  client.o utils.o server.o

fclean : clean
	$(RM) $(CLIENT) $(SERVER) 

re : fclean all