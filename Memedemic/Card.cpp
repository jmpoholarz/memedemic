#include "Card.h"
#include "Enums.h"

Card::Card(CardNames cardName) {
    this -> cardName = cardName;
}

CardNames Card::getCardName() {
    return cardName;
}
