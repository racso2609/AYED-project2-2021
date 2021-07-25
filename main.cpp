#include "iostream"
#include "./models/list.hpp"
#include "./models/stack.hpp"
#include "./models/priority.hpp"
#include "./models/Menu.hpp"
#include <stdlib.h>
#include <stdio.h>
#include <string>

using namespace std;


struct Client{
    string name;
    int  pacience;
};



int main(){

    srand(42);
    int menuQuantity, dishesQuantity;
    cin>>menuQuantity;
    Stack<Menu> *allMenu = new Stack<Menu>(); 
    for(int i =0; i<menuQuantity;i++){
        cin>>dishesQuantity;
        Menu menu;
        for(int j=0;j<dishesQuantity;j++){
            Dish newDish;
            cin>>newDish.name >>newDish.time;
            menu.dishes->push(newDish);
        } 
        allMenu->push(menu);
    }
    PriorityQueue<Client> *row = new PriorityQueue<Client>();

    while(getchar()!=EOF){
        char add;
        cin>>add;
        if(add == '+'){
            int peopleCount;
            cin>>peopleCount;
            for(int i = 0; i<peopleCount;i++){
                Client person;
                int priority;
                cin>>person.name>>priority>>person.pacience;
                row->enqueue(person, priority);
            }
        }

    }
    //printMenu(allMenu);
    delete allMenu;
    delete row;
    return 0;
}
