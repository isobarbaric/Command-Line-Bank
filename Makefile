all:
	g++ -o prog main.cpp bank.cpp user.cpp
	./main
clean:
	rm main