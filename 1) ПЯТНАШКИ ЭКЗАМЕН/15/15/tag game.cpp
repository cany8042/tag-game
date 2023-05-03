//Изначально игра будет инициализироваться как решенная, а перед началом игры мы будем перемешивать плашки
//с помощью случайных ходов.
#include <SFML/Graphics.hpp>
#include "Game.h"

int main()
{
	// Создаем окно размером 600 на 600 
	sf::RenderWindow window(sf::VideoMode(600, 600), "tag game");
	window.setFramerateLimit(60);

	//Объявляем новый шрифт
	sf::Font font;
	font.loadFromFile("calibri.ttf"); 

	// Текст с обозначением клавиш
	sf::Text text("F2 - New Game / Esc - Exit / Control - Arrow Keys ", font, 20);
	text.setFillColor(sf::Color::Cyan);
	text.setPosition(5.f, 5.f);

	// Создаем объект игры
	Game game;
	game.setPosition(50.f, 50.f);

	// Счетчик случайных ходов для перемешивания головоломки
	sf::Event event;
	int move_counter = 0;	

	while (window.isOpen())
	{
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
			if (event.type == sf::Event::KeyPressed)
			{
				// Получаем нажатую клавишу - выполняем соответствующее действие
				if (event.key.code == sf::Keyboard::Escape) window.close();
				if (event.key.code == sf::Keyboard::Left) game.Move(Direction::Left);
				if (event.key.code == sf::Keyboard::Right) game.Move(Direction::Right);
				if (event.key.code == sf::Keyboard::Up) game.Move(Direction::Up);
				if (event.key.code == sf::Keyboard::Down) game.Move(Direction::Down);
				// Новая игра
				if (event.key.code == sf::Keyboard::F2)
				{
					game.Init();
					move_counter = 100;
				}
			}
		}

		// Если счетчик ходов больше нуля, продолжаем перемешивать головоломку
		if (move_counter-- > 0) game.Move((Direction)(rand() % 4));

		// Выполняем необходимые действия по отрисовке
		window.clear();
		window.draw(game);
		window.draw(text);
		window.display();
	}

	return 0;
}