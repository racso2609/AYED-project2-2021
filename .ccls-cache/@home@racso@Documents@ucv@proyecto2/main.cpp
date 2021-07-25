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
void ReverseQueue(PriorityQueue<Client> *menu){
    if(!menu->isEmpty()){
        Client temp = menu->head()->info;

        if(menu->sizes() != 1){
            menu->dequeue();
            ReverseQueue(menu);
            menu->enqueue(temp,menu->head()->priority);

        }
    }

}
void printQueue(PriorityQueue<Client> *menu){
    if(!menu->isEmpty()){
        Client temp = menu->head()->info;
        cout<<menu->sizes()<<endl;
        cout<<" name: "<<temp.name<<" pacience: "<<temp.pacience<<endl;
        if(menu->sizes() != 1){
            menu->dequeue();
            printQueue(menu);
            menu->enqueue(temp,menu->head()->priority);

        }
    }

}

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
    char file;
    while((file = getchar())!=EOF){
        if(char(file) == '+'){
            int peopleCount;
            cin>>peopleCount;
            cout<<peopleCount<<endl;
            for(int i = 0; i<peopleCount;i++){
                Client person;
                int priority;
                cin>>person.name>>priority>>person.pacience;
                row->enqueue(person, priority);
            }

        }


    }
    printQueue(row);
    printQueue(row);
    //printMenu(allMenu);
    delete allMenu;
    delete row;
    return 0;
}
