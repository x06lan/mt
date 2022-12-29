b:
	gcc server.c -o ./build/server.o -lunp
	gcc client.c -o ./build/client.o -lunp
	gcc talk_server.c -o ./build/talk_server.o -lunp
	gcc talk_client.c -o ./build/talk_client.o -lunp
	gcc pi_server.c -o ./build/pi_server.o -lunp
	gcc pi_client.c -o ./build/pi_client.o -lunp
	gcc udp_server.c -o ./build/udp_server.o -lunp
	gcc udp_client.c -o ./build/udp_client.o -lunp
	gcc udp_server.c -o ./build/udp_server.o -lunp
	gcc 10half_c.c -o ./build/10_c.o -lunp
	gcc 10half_s.c -o ./build/10_s.o -lunp
client:
	sudo ./build/client.o 127.0.0.1 14
server:
	sudo ./build/server.o 127.0.0.1 14
t_client:
	sudo ./build/talk_client.o 127.0.0.1 13
t_server:
	sudo ./build/talk_server.o 127.0.0.1 13

pclient:
	sudo ./build/pi_client.o 127.0.0.1 13
pserver:
	sudo ./build/pi_server.o 127.0.0.1 13
udp_s:
	sudo ./build/udp_server.o 127.0.0.1 13
udp_c:
	sudo ./build/udp_client.o 127.0.0.1 sent_file.jpg 
half_c:
	sudo ./build/10_c.o 127.0.0.1 13
half_s:
	sudo ./build/10_s.o 127.0.0.1 13
