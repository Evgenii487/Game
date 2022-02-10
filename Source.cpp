#include <SFML/Graphics.hpp>

#include <Rectangle.hpp> //Подключаем наши дополнителные файлы-заголовки, #include <iostream> можно убрать, т.к. они указаны в hpp-шках.
#include <Circle.hpp>

#pragma comment(linker, "/SUBSYSTEM:windows /ENTRY:mainCRTStartup") // Чтобы не отображалась консоль при запуске приложения.

using namespace std;

int main()
{
	srand(time(NULL)); // Чтобы работал рандом.
	setlocale(LC_ALL, "Rus");
	int const windowX = 800;
	int const windowY = 600;
	int score = 0;

	sf::Font font;
	font.loadFromFile("fonts/Elfboyclassic.ttf"); //Загрузка шрифта из папки fonts в переменную font.

	rec::Rectangle playerSettings; //Записываем в класс информацию о нашем прямоугольнике-игроке, чтобы потом их исползовать в создании прямоугольника.
	playerSettings.setWidth(75);
	playerSettings.setLenght(100);
	playerSettings.setX((windowX - playerSettings.getWidth()) / 2); //Располагаем его посередине.
	playerSettings.setY((windowY - playerSettings.getLenght()) / 2);

	cir::Circle coinSettings; // Аналогично к круге-монетке.
	coinSettings.setRadius(20);
	coinSettings.setX(rand() % windowX - coinSettings.getRadius() * 2); //Случайная координата x и y.
	coinSettings.setY(rand() % windowY - coinSettings.getRadius() * 2); 
	/*Функция rand() генерирует случайное число, т.к. нам нужны координаты от 0 до края окна просто возьмем остаток от деления на разрешение экрана.
	Минусую диаметр монеты, чтобы монетки не появлялись наполовину за краем. (Все равно иногда появляются)*/

	sf::RenderWindow window(sf::VideoMode(windowX, windowY), L"Coin Collector"); //Создаем окно.
	window.setFramerateLimit(120); //Количество кадров в секунду

	while (window.isOpen()) {

		sf::RectangleShape player; //Создаем сам прямоугольник со значениями из класса Rectangle.
		player.setSize(sf::Vector2f(playerSettings.getWidth(), playerSettings.getLenght()));
		player.setFillColor(sf::Color::Red);
		player.setPosition(playerSettings.getX(), playerSettings.getY());

		sf::CircleShape coin; //Аналогично для круга.
		coin.setRadius(coinSettings.getRadius());
		coin.setFillColor(sf::Color::Yellow);
		coin.setPosition(coinSettings.getX(), coinSettings.getY());

		sf::Text scoreText; //Создаем текст для счёта.
		scoreText.setFont(font); //Загружаем шрифт из переменной font.
		scoreText.setCharacterSize(70); 
		scoreText.setFillColor(sf::Color::Cyan);
		scoreText.setString("Score:" + std::to_string(score)); //Конвертируем число в строку и складываем счётчик.
		scoreText.setPosition(5, -30);

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				window.close();
			//Закрытие на Escape и крестик

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) { //Пока W нажата, выполняется if (управление).
				playerSettings.moveUp();
				if (playerSettings.getY() < 0) //Когда координата после нажатия становится меньше единицы, устанавливаем его на 0, т.е. меньше чем 0 стать он не сможет, т.е не забудет заходить за края.
					playerSettings.setY(0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) { //Аналогично с ASD.
				playerSettings.moveLeft();
				if (playerSettings.getX() < 0)
					playerSettings.setX(0);
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
				playerSettings.moveDown();
				if (playerSettings.getY() > windowY - playerSettings.getLenght()) //Из крайней координаты окна вычитаем длинну прямоугольника, чтобы он не заходил за края.
					playerSettings.setY(windowY - playerSettings.getLenght());
			}
				
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
				playerSettings.moveRight();
				if (playerSettings.getX() > windowX - playerSettings.getWidth()) //Аналогично с шириной.
					playerSettings.setX(windowX - playerSettings.getWidth());
			}
			
			/*Ниже условие, которое определяет "столкнулись" ли игрок с монеткой.
			Первое по x, второе по y*/
			if (coinSettings.getX() > playerSettings.getX() && coinSettings.getX() < playerSettings.getX() + playerSettings.getWidth() || coinSettings.getX() + coinSettings.getRadius() * 2 > playerSettings.getX() && coinSettings.getX() + coinSettings.getRadius() * 2 + coinSettings.getRadius() * 2 < playerSettings.getX() + playerSettings.getWidth()) {
				if (coinSettings.getY() > playerSettings.getY() && coinSettings.getY() < playerSettings.getY() + playerSettings.getLenght() || coinSettings.getY() + coinSettings.getRadius() * 2 > playerSettings.getY() && coinSettings.getY() + coinSettings.getRadius() * 2 + coinSettings.getRadius() * 2 < playerSettings.getY() + playerSettings.getLenght()) {
					coinSettings.setX(rand() % windowX - coinSettings.getRadius() * 2); //Если условие выполнено, то устанавливаем новые случайные координаты для монеты
					coinSettings.setY(rand() % windowY - coinSettings.getRadius() * 2);
					score++; //Добавляем 1 к счетчику
					scoreText.setString("Score:" + std::to_string(score)); //Обновляем счетчик на экране с новым значением
				}
			}
				
		}
		window.clear();
		//Отрисовка ниже
		window.draw(player);
		window.draw(coin);
		window.draw(scoreText);

		window.display();
	}

	return 0;
}


