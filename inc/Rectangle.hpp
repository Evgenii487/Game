#pragma once
#include <iostream> 
//�.�. ��� ������������ ���������� ��� ����� ����� ����� ������������ ��� #include <name.hpp>, ������� #include <iostream> ����� �������� ���

//���� ����������, ���� ������� � cpp-����.
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
