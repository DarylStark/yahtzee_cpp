all: game

# Targets

game: ../build/game

# Linking

../build/game: ../build/die.o ../build/dieset.o ../build/entity.o ../build/main.o ../build/player.o ../build/scorecard.o ../build/scorecardentry.o ../build/yathzee.o
	g++ -o ../build/game ../build/*.o

# Object files

../build/main.o: main.cpp
	g++ -o ../build/main.o -c main.cpp

../build/die.o: die.cpp
	g++ -o ../build/die.o -c die.cpp

../build/dieset.o: dieset.cpp
	g++ -o ../build/dieset.o -c dieset.cpp

../build/entity.o: entity.cpp
	g++ -o ../build/entity.o -c entity.cpp

../build/player.o: player.cpp
	g++ -o ../build/player.o -c player.cpp

../build/scorecard.o: scorecard.cpp
	g++ -o ../build/scorecard.o -c scorecard.cpp

../build/scorecardentry.o: scorecardentry.cpp
	g++ -o ../build/scorecardentry.o -c scorecardentry.cpp

../build/yathzee.o: yathzee.cpp
	g++ -o ../build/yathzee.o -c yathzee.cpp