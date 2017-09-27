#pragma once
#include "Enums.h"

class Card {
public:
	Card(CardNames);
	~Card();

    CardNames getCardName();
    bool equals(Card);
    bool equals(CardNames);
private:
    CardNames cardName;
};

class EventCard: public Card {
};

class LocationCard: public Card {
};
