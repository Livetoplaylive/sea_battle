#ifndef SEA_BATTLE_FIELD_H
#define SEA_BATTLE_FIELD_H

#include <list>
#include <iterator>
#include "ship.h"
struct coordinate { ;
    int head_h;
    int head_v;

    coordinate() {

        head_v = 0;
        head_h = 0;
    }
    void init(){
        std::cout<<"\nenter the horizontal: ";
        std::cin>>head_h;
        std::cout<<"\nenter the vertical: ";
        std::cin>>head_v;
    }
};
class field {
private:
    static const int F_SIZE = 11;
    char your_field[F_SIZE][F_SIZE]{};
    char hit_field[F_SIZE][F_SIZE]{};
    bool isFull= false;

    ship oneDeck{1, 4};
    ship twoDeck{2, 3};
    ship threeDeck{3, 2};
    ship fourDeck{4, 1};
    std::list<ship> t;
    std::list<ship>::const_iterator i_t = t.begin();


    bool canBuild(coordinate, coordinate &, int, char);


    bool input_correct(coordinate &);

    void build(coordinate, coordinate, char, ship &);

public:
    int kill_counter{};
    bool kill_ship( coordinate x);
    void add_hitfield(coordinate a,bool isCorrect){
        input_correct(a);
        if(isCorrect){
            hit_field[a.head_h][a.head_v]='X';
        }else{
            hit_field[a.head_h][a.head_v]='0';
        }

    }

    void show();

    void initShip();

    field();
};

bool field::kill_ship(coordinate x) {

    input_correct(x);
    if(your_field[x.head_h][x.head_v]=='@'){
        your_field[x.head_h][x.head_v]='X';
        return true;
    }
    else{
        return false;
    }
}

void field::show() {
    if(isFull){
        std::cout << "your field" << "\t\t\t\t\t\t\t\t\t\t\t\t\thit field\n\n";;
        for (int i = 0; i < F_SIZE; ++i) {
            for (int j = 0; j < F_SIZE; ++j) {
                std::cout << your_field[i][j] << "\t";
            }
            std::cout << "\t\t\t\t";
            for (int j = 0; j < F_SIZE; ++j) {
                std::cout << hit_field[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
    else{
        std::cout << "your field\n\n";
        std::cout << "Navigation:\n";
        std::cout << "HEAD->in order to determinate the position of the first deck\n"
                     "DIRECTION->in order to determine the direction\n\n";

        for (int i = 0; i < F_SIZE; ++i) {
            for (int j = 0; j < F_SIZE; ++j) {
                std::cout << your_field[i][j] << "\t";
            }
            std::cout << "\n";
        }
    }
}

void field::initShip() {

    coordinate begin, end;
    char dir{};
    //ship temp;
    do {
        while (i_t->number > i_t->build) {
            std::cout << "Enter the coordinate of the "<< i_t->size<< " deck ship\n";
            std::cout << "HEAD: ";
            std::cin >> begin.head_h >> begin.head_v;
            std::cout << "Enter the direction: ";
            std::cin >> dir;

            if (!input_correct(begin)) {
                std::cout << "input uncorrected try again";
                return;
            }

            if (canBuild(begin, end, i_t->size, dir)) {

                build(begin, end, dir, const_cast<ship &>(*i_t));
            } else {
                std::cout << "I can't build ship there select new place\n";
            }
            show();
        }
        i_t++;
    } while (i_t != t.end());
    isFull=true;
}

void field::build(coordinate begin, coordinate end, char dir, ship &s_i) {

    switch (dir) {
        case 'h':
            for (int i = end.head_v; i <= begin.head_v; ++i)
                your_field[begin.head_h][i] = '@';
            s_i.build++;
            break;
        case 'j':
            for (int i = begin.head_h; i <= end.head_h; ++i)
                your_field[i][begin.head_v] = '@';
            s_i.build++;
            break;
        case 'k':
            for (int i = end.head_h; i <= begin.head_h; ++i)
                your_field[i][begin.head_v] = '@';
            s_i.build++;
            break;
        case 'l':
            for (int i = begin.head_v; i <= end.head_v; ++i)
                your_field[begin.head_h][i] = '@';
            s_i.build++;
            break;
    }
}
//work
bool field::canBuild(coordinate begin, coordinate &end, int _size, char dir) {

    switch (dir) {
        case 'h':
            //left;
            end.head_h = begin.head_h;
            end.head_v = begin.head_v - (_size - 1);
            for (int i = end.head_v; i <= begin.head_v; ++i) {
                if (your_field[begin.head_h][i] == ' ') {
                    continue;
                } else {
                    std::cout << "I can't build ship there select new place\n";
                    return false;
                }
            }
            return true;

        case 'j':
            //down;
            end.head_v = begin.head_v;
            end.head_h = begin.head_h + (_size - 1);
            if (end.head_h > 10) {
                std::cout << "I can't build ship there select new place\n";
                return false;
            }
            for (int i = begin.head_h; i <= end.head_h; ++i) {
                if (your_field[i][begin.head_v] == ' ') {
                    continue;
                } else {
                    std::cout << "I can't build ship there select new place\n";
                    return false;
                }
            }
            return true;

        case 'k':
            //up;
            end.head_v = begin.head_v;
            end.head_h = begin.head_h - (_size - 1);
            for (int i = end.head_h; i <= begin.head_h; ++i) {
                if (your_field[i][begin.head_v] == ' ') {
                    continue;
                } else {
                    std::cout << "I can't build ship there select new place\n";
                    return false;
                }
            }
            return true;

        case 'l':
            //right;
            end.head_h = begin.head_h;
            end.head_v = begin.head_v + (_size - 1);
            if (end.head_v > 10) {
                std::cout << "I can't build ship there select new place\n";
                return false;
            }
            for (int i = begin.head_v; i <= end.head_v; ++i) {
                if (your_field[begin.head_h][i] == ' ') {
                    continue;
                } else {
                    std::cout << "I can't build ship there select new place\n";
                    return false;
                }
            }
            return true;

        default:
            std::cout << "Really!?";
            return false;

    }

}

field::field() {
    t.push_front(oneDeck);
    t.push_front(twoDeck);
    t.push_front(threeDeck);
    t.push_front(fourDeck);
    //инкримент итератора потому что без него выводился лишний обьект в листе

    i_t++;
    char temp(48);
    char temp_a(48);
    for (int i = 0; i < F_SIZE; ++i) {
        for (int j = 0; j < F_SIZE; ++j) {
            if (i == 0 && j == 0) {
                your_field[i][j] = ' ';
                hit_field[i][j] = ' ';
                continue;
            }
            if (i == 0) {
                your_field[i][j] = temp;
                hit_field[i][j] = temp;
                temp++;
            } else if (j == 0) {
                your_field[i][j] = temp_a;
                hit_field[i][j] = temp_a;
                temp_a++;
            } else {
                your_field[i][j] = ' ';
                hit_field[i][j] = ' ';
            }
        }
    }
}
//work
bool field::input_correct(coordinate &a) {
    if ((a.head_h < 0 || a.head_h > 10) ||
        (a.head_v < 0 || a.head_v > 10)) {
        std::cout << "Bad coordinate!\nShip can't be spawned!\n Try to spawn it again\n";
        return false;
    } else {
        a.head_v++;
        a.head_h++;
    }
    return true;
}

#endif //SEA_BATTLE_FIELD_H
