#pragma once

class Set
{
private:
	bool sorted;
	std::string sortType;

	sf::Vector2u windowSize;

	// LICZBY:
	std::vector<unsigned short> unsortedSet;

	// presort jest implementowany za pomoc� 2 tablic zawieraj�cych w ka�dym indeksie 2 liczby:

	// indeksy prostok�t�w, kt�re b�d� ze sob� zamieniane w danym kroku wizualizacji:
	std::vector<std::pair<short, short> > swaps;
	// je�eli w danym kroku nic si� nie zmieni para b�dzie zawiera�a -1 i -1

	// indeksy prostok�t�w, kt�re b�d� pokolorowane w danym kroku wizualizacji:
	std::vector<std::pair<short, short> > colored;
	// w ka�dym kroku jakie� 2 prostok�ty s� pokolorowane

	unsigned step; // aktualnie wizualizowany krok sortowania

	// PROSTOK�TY:
	std::vector<sf::RectangleShape> rectangles;

	// szeroko�� i wysoko�� prostok�ta:
	float rectWidth;
	float rectMinHeight;

	sf::Color rectColor;

	// private methods:
	void makeRandomNumbers(int size);
	void makeRectanglesUnsorted();
	void makePresort();

	// presort methods:
	void makeBubblePresort();

	void makeSelectionPresort();

	void makeHeapPresort();
	void heapify(int n, int i, std::vector<unsigned short>& v);

	void makeQuickPresort(int start, int end, std::vector<unsigned short>& v);
	int partition(int start, int end, std::vector<unsigned short>& v);

public:
	// constructor:
	Set(unsigned short size, sf::Vector2u windowSize, sf::Color rectColor);

	// accessors:
	const std::string& getSortType() const; // zwraca aktualny spos�b sortowania
	int getStep() const; // zwraca aktualnie wykonywany kork sortowania

	// predicates:
	bool isSorted() const;

	// modifiers:
	void setSortType(const std::string& sortType); // zmienia spos�b sortowania ORAZ RESETUJE ZBI�R I PROSTOK�TY

	// other methods:
	void restart(); // resetuje zbi�r i prostok�ty
	void update();
	void render(sf::RenderTarget& target);
};
