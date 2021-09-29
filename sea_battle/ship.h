
#ifndef SEA_BATTLE_SHIP_H
#define SEA_BATTLE_SHIP_H

class ship {
public:
    int size;
    int number;
    int build;
    int destroy;

    ship() {
        size = 0;
        number = 0;
        build = 0;
        destroy = 0;
    }

    ship(int ship_size, int number_of_ship) {
        size = ship_size;
        number = number_of_ship;
        build = 0;
        destroy = 0;
    }
};


#endif //SEA_BATTLE_SHIP_H
