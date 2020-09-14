#pragma once

class Set
{
private:
	bool sorted;
	std::string sortType;

	sf::Vector2u windowSize;

	// LICZBY:
	std::vector<unsigned short> unsortedSet;

	// presort jest implementowany za pomoc¹ 2 tablic zawieraj¹cych w ka¿dym indeksie 2 liczby:

	// indeksy prostok¹tów, które bêd¹ ze sob¹ zamieniane w danym kroku wizualizacji:
	std::vector<std::pair<short, short> > swaps;
	// je¿eli w danym kroku nic siê nie zmieni para bêdzie zawiera³a -1 i -1

	// indeksy prostok¹tów, które bêd¹ pokolorowane w danym kroku wizualizacji:
	std::vector<std::pair<short, short> > colored;
	// w ka¿dym kroku jakieœ 2 prostok¹ty s¹ pokolorowane

	unsigned step; // aktualnie wizualizowany krok sortowania

	// PROSTOK¥TY:
	std::vector<sf::RectangleShape> rectangles;

	// szerokoœæ i wysokoœæ prostok¹ta:
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
	const std::string& getSortType() const; // zwraca aktualny sposób sortowania
	int getStep() const; // zwraca aktualnie wykonywany kork sortowania

	// predicates:
	bool isSorted() const;

	// modifiers:
	void setSortType(const std::string& sortType); // zmienia sposób sortowania ORAZ RESETUJE ZBIÓR I PROSTOK¥TY

	// other methods:
	void restart(); // resetuje zbiór i prostok¹ty
	void update();
	void render(sf::RenderTarget& target);
};
