#pragma once
#include <iostream>
//Т.к. все подключенные библиотеки для этого файла также подключаются при #include <name.hpp>, поэтому #include <iostream> можно оставить тут

//Файл заголовков, тела функций в cpp-шках.
namespace cir {
	class Circle {
	private:
		int x, y, radius;
	public:
		int getRadius();
		void setRadius(int valueRadius);
		int getX();
		void setX(int valueX);
		int getY();
		void setY(int valueY);
	};
}