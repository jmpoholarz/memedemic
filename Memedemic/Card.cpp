#include "Card.h"
#include "Enums.h"

Card::Card(CardNames cardName) {
    this -> cardName = cardName;
}

Card::~Card() {
}

CardNames Card::getCardName() {
    return cardName;
}

bool Card::equals(Card card) {
    if (this -> cardName == card.getCardName()) {
        return true;
    }

    return false;
}

bool Card::equals(CardNames card) {
    if (this -> cardName == card) {
        return true;
    }

    return false;
}
