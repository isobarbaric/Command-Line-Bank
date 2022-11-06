all:
	g++ -o prog main.cpp utilities/bank.cpp utilities/user.cpp
	./main
clean:
	rm main
	rm prog