#pragma once
#include <iostream> 
//Т.к. все подключенные библиотеки для этого файла также подключаются при #include <name.hpp>, поэтому #include <iostream> можно оставить тут

//Файл заголовков, тела функций в cpp-шках.
namespace rec {
	class Rectangle {
	private:
		int x, y, width, lenght;
		float speed = 3.0;
	public:
		int getX();
		void setX(int valueX);
		int getY();
		void setY(int valueY);
		int getWidth();
		void setWidth(int valueWidth);
		int getLenght();
		void setLenght(int valueLenght);
		void moveRight();
		void moveLeft();
		void moveUp();
		void moveDown();
	};
}
