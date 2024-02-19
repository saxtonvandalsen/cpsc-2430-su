main: main.o CovidDB.o
	g++ -o main main.o CovidDB.o
main.o: main.cpp CovidDB.h WHO-COVID-data.csv
	g++ -c -Wall -pedantic -std=c++11 main.cpp
CovidDB: CovidDB.cpp CovidDB.h
	g++ -c -Wall -pedantic -std=c++11 CovidDB.cpp