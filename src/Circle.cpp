#include <Circle.hpp>

namespace cir { //������������ ��� cir (������� ������� ������ � ��������� �� �����).
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
	// ������� get - �������� �������� �� ������, ������� set - ������ �������� � ������.
}