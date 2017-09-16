#include "Card.h"
#include "Enums.h"

Card::Card(CardNames cardName) {
    cardName = cardName;
}

CardNames Card::getCardName() {
    return cardName;
}

/*LocationNames LocationCard::getCardLocation() {
    return cardName;
}*/
