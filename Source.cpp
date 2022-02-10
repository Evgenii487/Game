#include <SFML/Graphics.hpp>

#include <Rectangle.hpp> //���������� ���� ������������� �����-���������, #include <iostream> ����� ������, �.�. ��� ������� � hpp-����.
#include <Circle.hpp>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // ����� �� ������������ ������� ��� ������� ����������.

using namespace std;

int main()
{
	srand(time(NULL)); // ����� ������� ������.
	setlocale(LC_ALL, "Rus");
	int const windowX = 800;
	int const windowY = 600;
	int score = 0;

	sf::Font font;
	font.loadFromFile("fonts/Elfboyclassic.ttf"); //�������� ������ �� ����� fonts � ���������� font.

	rec::Rectangle playerSettings; //���������� � ����� ���������� � ����� ��������������-������, ����� ����� �� ����������� � �������� ��������������.
	playerSettings.setWidth(75);
	playerSettings.setLenght(100);
	playerSettings.setX((windowX - playerSettings.getWidth()) / 2); //����������� ��� ����������.
	playerSettings.setY((windowY - playerSettings.getLenght()) / 2);

	cir::Circle coinSettings; // ���������� � �����-�������.
	coinSettings.setRadius(20);
	coinSettings.setX(rand() % windowX - coinSettings.getRadius() * 2); //��������� ���������� x � y.
	coinSettings.setY(rand() % windowY - coinSettings.getRadius() * 2); 
	/*������� rand() ���������� ��������� �����, �.�. ��� ����� ���������� �� 0 �� ���� ���� ������ ������� ������� �� ������� �� ���������� ������.
	������� ������� ������, ����� ������� �� ���������� ���������� �� �����. (��� ����� ������ ����������)*/

	sf::RenderWindow window(sf::VideoMode(windowX, windowY), L"Coin Collector"); //������� ����.
	window.setFramerateLimit(120); //���������� ������ � �������

	while (window.isOpen()) {

		sf::RectangleShape player; //������� ��� ������������� �� ���������� �� ������ Rectangle.
		player.setSize(sf::Vector2f(playerSettings.getWidth(), playerSettings.getLenght()));
		player.setFillColor(sf::Color::Red);
		player.setPosition(playerSettings.getX(), playerSettings.getY());

		sf::CircleShape coin; //���������� ��� �����.
		coin.setRadius(coinSettings.getRadius());
		coin.setFillColor(sf::Color::Yellow);
		coin.setPosition(coinSettings.getX(), coinSettings.getY());

		sf::Text scoreText; //������� ����� ��� �����.
		scoreText.setFont(font); //��������� ����� �� ���������� font.
		scoreText.setCharacterSize(70); 
		scoreText.setFillColor(sf::Color::Cyan);
		scoreText.setString("Score:" + std::to_string(score)); //������������ ����� � ������ � ���������� �������.
		scoreText.setPosition(5, -30);

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			//�������� �� Escape � �������

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //���� W ������, ����������� if (����������).
				playerSettings.moveUp();
				if (playerSettings.getY() < 0) //����� ���������� ����� ������� ���������� ������ �������, ������������� ��� �� 0, �.�. ������ ��� 0 ����� �� �� ������, �.� �� ������� �������� �� ����.
					playerSettings.setY(0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //���������� � ASD.
				playerSettings.moveLeft();
				if (playerSettings.getX() < 0)
					playerSettings.setX(0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				playerSettings.moveDown();
				if (playerSettings.getY() > windowY - playerSettings.getLenght()) //�� ������� ���������� ���� �������� ������ ��������������, ����� �� �� ������� �� ����.
					playerSettings.setY(windowY - playerSettings.getLenght());
			}
				
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				playerSettings.moveRight();
				if (playerSettings.getX() > windowX - playerSettings.getWidth()) //���������� � �������.
					playerSettings.setX(windowX - playerSettings.getWidth());
			}
			
			/*���� �������, ������� ���������� "�����������" �� ����� � ��������.
			������ �� x, ������ �� y*/
			if (coinSettings.getX() > playerSettings.getX() && coinSettings.getX() < playerSettings.getX() + playerSettings.getWidth() || coinSettings.getX() + coinSettings.getRadius() * 2 > playerSettings.getX() && coinSettings.getX() + coinSettings.getRadius() * 2 + coinSettings.getRadius() * 2 < playerSettings.getX() + playerSettings.getWidth()) {
				if (coinSettings.getY() > playerSettings.getY() && coinSettings.getY() < playerSettings.getY() + playerSettings.getLenght() || coinSettings.getY() + coinSettings.getRadius() * 2 > playerSettings.getY() && coinSettings.getY() + coinSettings.getRadius() * 2 + coinSettings.getRadius() * 2 < playerSettings.getY() + playerSettings.getLenght()) {
					coinSettings.setX(rand() % windowX - coinSettings.getRadius() * 2); //���� ������� ���������, �� ������������� ����� ��������� ���������� ��� ������
					coinSettings.setY(rand() % windowY - coinSettings.getRadius() * 2);
					score++; //��������� 1 � ��������
					scoreText.setString("Score:" + std::to_string(score)); //��������� ������� �� ������ � ����� ���������
				}
			}
				
		}
		window.clear();
		//��������� ����
		window.draw(player);
		window.draw(coin);
		window.draw(scoreText);

		window.display();
	}

	return 0;
}


