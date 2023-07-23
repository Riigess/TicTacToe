tic-tac-toe:
	mkdir build
	g++ -o build/TicTacToe src/main.cpp src/Game.cpp src/GamePiece.cpp src/Board.cpp -I ./include

clean:
	rm -rf build
