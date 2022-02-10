#include <Rectangle.hpp> 

namespace rec { //Пространство имён rec (просили сделать вместе с разбивкой на файлы).
	int Rectangle::getX() {
		return x;
	}
	void Rectangle::setX(int valueX) {
		x = valueX;
	}
	int Rectangle::getY() { 
		return y;
	}
	void Rectangle::setY(int valueY) {
		y = valueY;
	}
	int Rectangle::getWidth() {
		return width;
	}
	void Rectangle::setWidth(int valueWidth) {
		width = valueWidth;
	}
	int Rectangle::getLenght() {
		return lenght;
	}
	void Rectangle::setLenght(int valueLenght) {
		lenght = valueLenght;
	}
	// Функции get - получают значения из класса, функции set - задают значения в классе. 

	void Rectangle::moveRight() { 
		x = x + speed;
	}
	void Rectangle::moveLeft() {
		x = x - speed;
	}
	void Rectangle::moveUp() {
		y = y - speed;
	}
	void Rectangle::moveDown() {
		y = y + speed;
	}
	// Выше функции движения прямоугольница
}

