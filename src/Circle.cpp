#include <Circle.hpp>

namespace cir { //Пространство имён cir (просили сделать вместе с разбивкой на файлы).
	int Circle::getRadius() {
		return radius;
	}
	void Circle::setRadius(int valueRadius) {
		radius = valueRadius;
	}
	int Circle::getX() {
		return x;
	}
	void Circle::setX(int valueX) {
		x = valueX;
	}
	int Circle::getY() {
		return y;
	}
	void Circle::setY(int valueY) {
		y = valueY;
	}
	// Функции get - получают значения из класса, функции set - задают значения в классе.
}