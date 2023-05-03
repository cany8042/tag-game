#pragma once
//подключаем библиотеку Graphics.
#include <SFML/Graphics.hpp>

// Oбъявляем константы:
// Размер игрового поля в плашках.
// Размер массива.
// Размер игрового поля в пикселях.
// Размер плашки в пикселях.
const int SIZE = 4;						
const int ARRAY_SIZE = SIZE * SIZE;		
const int FIELD_SIZE = 500;				
const int CELL_SIZE = 120;	

//объявляем свой тип enum
//определяющий направление перемещения плашки.
enum class Direction { Left = 0, Right = 1, Up = 2, Down = 3 };

//Создаем класс.
class Game : public sf::Drawable, public sf::Transformable
{
protected:
	//"Это массив elements, содержащий целочисленные значения
	//соответствующие состоянию игрового поля.
	int elements[ARRAY_SIZE];

	//Переменные, которые будут вычисляться каждый ход
	//"индекс в массиве, соответствующий свободной ячейке".
    int empty_index;

	//Признак того, что головоломка решена.
	bool solved;

	//Переменная font, определяеи шрифт,
	//который будет использоваться при выводе текста
	sf::Font font;
public:
	Game();
	void Init();
	bool Check();
	void Move(Direction direction);
public:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};
