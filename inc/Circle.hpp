#pragma once
#include <iostream>
//�.�. ��� ������������ ���������� ��� ����� ����� ����� ������������ ��� #include <name.hpp>, ������� #include <iostream> ����� �������� ���

//���� ����������, ���� ������� � cpp-����.
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