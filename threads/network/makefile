server:
	g++ server.cpp -o server -pthread

client:
	g++ client.cpp -o client -pthread

sserver:
	g++ syncedserver.cpp -o server -pthread

sclient:
	g++ syncedclient.cpp -o client -pthread

race:
	g++ race.cpp -o main -pthread

frace:
	g++ fixedrace.cpp -o main -pthread

deadlock:
	g++ deadlock.cpp -o main -pthread

fdeadlock:
	g++ deadlockfix.cpp -o main -pthread

clean:
	rm -rf server
	rm -rf client