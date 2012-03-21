all:
	@g++ -Wall -c "main.cpp"
	@g++ -Wall -c "Bin_IO.cpp"
	@g++ -Wall -o "main" "main.o" "Bin_IO.o"
	
clean:
	@rm "main" "main.o" "Bin_IO.o"
