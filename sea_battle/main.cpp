#include <iostream>
#include "field.h"


int main() {
    field playerOne,playerTwo;
    int flag= true;
    bool hit= false;
    bool turn=true;
    coordinate input{};
    std::cout<<"Hello ,let's play!!!\nPlayer one turn!\n";
    playerOne.show();
    playerOne.initShip();
    std::cout<<"player two turn!\n";
    playerTwo.show();
    playerTwo.initShip();

    while(flag){

        if(turn){
            std::cout<<"First player turn! \n";
            playerOne.show();
            input.init();
            if(playerTwo.kill_ship(input)){
                hit= true;
                playerOne.kill_counter++;
                std::cout<<"\ayour shot has reached the target!!"<<"\nyou can try again!!! ";
                playerOne.add_hitfield(input,hit);
            }else{
                hit=false;
                std::cout<<"OOOps";
                playerOne.add_hitfield(input,hit);
                turn= false;
            }

        }else{
            std::cout<<"Second player turn!!\n";
            playerTwo.show();
            input.init();
            if(playerOne.kill_ship(input)){
                hit= true;
                playerTwo.kill_counter++;
                std::cout<<"\ayour shot has reached the target!!"<<"\nyou can try again!!! ";
                playerTwo.add_hitfield(input, hit);

            }else{
                hit= false;
                std::cout<<"OOOps";
                playerTwo.add_hitfield(input,hit);
                turn= true;
            }

        }

        if((playerOne.kill_counter==20)||(playerTwo.kill_counter==20)){
            if(playerOne.kill_counter==10){
                std::cout << "game over!!\n" << "win player one!";
                flag = false;
            }else {
                std::cout << "game over!!\n" << "win player two!";
                flag = false;
            }
        }
    }


    return 0;
}
