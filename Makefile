all:
	g++ -o main main.cpp utilities/bank.cpp utilities/user.cpp
clean:
	rm main
	rm prog