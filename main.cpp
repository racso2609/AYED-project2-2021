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
    int  pacience,priority,entryTime,exitTime;
    Menu clientMenu;
    Stack<Dish> chosenDishes;

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
        cout<<" name: "<<temp.name<<" pacience: "<<temp.pacience<<" Priority: "<<temp.priority<<"Start time"<<temp.entryTime/60<<":"<<temp.entryTime%60<<"exit Time: "<<int(temp.exitTime/60)<<":"<<int(temp.exitTime%60)<<endl;
        while(!temp.chosenDishes.isEmpty()){
            cout<<temp.chosenDishes.top->info.name<<"->"<<temp.chosenDishes.top->info.time<<endl;
            temp.chosenDishes.pop();
        }
        if(menu->sizes() > 1){
            menu->dequeue();
            printQueue(menu);
            menu->enqueue(temp,menu->head()->priority);

        }
    }

}

void printClient(PriorityQueue<Client> *menu){
    printQueue(menu);
    ReverseQueue(menu);
}

void MenuDecission(Client &client, Menu menus,int &actualTime){
    client.clientMenu= menus;
    int prepareTime=0;
    while(!client.clientMenu.dishes->isEmpty()){
        int decission = rand()%2;
        cout<<decission<<endl;
        if(decission){
            client.chosenDishes.push(client.clientMenu.dishes->top->info);
            prepareTime+=client.chosenDishes.top->info.time;
        }
        client.clientMenu.dishes->pop();
    }
    client.exitTime = actualTime + prepareTime;


}

void processSolution(Client &client, int &actualTime, Menu menus){// while inteads menu decission and put again menus on stack depend prepare time 
    string priority = client.priority == 1?" VIP ": " ";
    string Toprint = client.name + priority+"Entro al Local";
    cout<<"["<<int(client.entryTime/60)<<':'<<int(client.entryTime%60)<<"]"<<Toprint<<endl;
    if(actualTime >client.entryTime+client.pacience){
        client.exitTime = actualTime;
    }
    MenuDecission(client, menus, actualTime);
}

string printDishes(Client &temp){
    string toPrint=" salio con ";
    if(temp.chosenDishes.isEmpty()){
        toPrint = " salio sin nada";
    }
    while(!temp.chosenDishes.isEmpty()){
        toPrint+= temp.chosenDishes.top->info.name+" ";
        temp.chosenDishes.pop();
        //cout<<"aquii"<<endl;
    }
    //exit->enqueue(person, 0);
    return toPrint;

}

int main(){

    srand(42);
    int menuQuantity, dishesQuantity,hourInMinutes=540;
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
    PriorityQueue<string> *exit = new PriorityQueue<string>;

    PriorityQueue<Menu> *returnedMenu = new PriorityQueue<Menu>; 
    char file;
    while((file = getchar())!=EOF){
        if(char(file) == '+' || char (file) == '-'){
            hourInMinutes += 1;
        }


        if(char(file) == '+'){
            int peopleCount;
            cin>>peopleCount;
            for(int i = 0; i<peopleCount;i++){
                 if(allMenu->isEmpty()){
                    while(!returnedMenu->isEmpty()){
                        Menu fillMenu =returnedMenu->head()->info;
                        allMenu->push(fillMenu);
                        returnedMenu->dequeue();
                    }

                }
                Client person;
                int priority;
                cin>>person.name>>priority>>person.pacience;
                person.priority = priority;
                person.entryTime = hourInMinutes-1;
                Menu menu = allMenu->top->info;

                processSolution(person, hourInMinutes, menu);
                cout<<"proceesSolution succesfully"<<endl;
                // returnedMenu->enqueue(menu,0);
                // cout<<"proceesSolution enquee menu"<<endl;

                row->enqueue(person, priority);
                if(!allMenu->isEmpty()){
                    allMenu->pop();
                cout<<"proceesSolution pop menu"<<endl;
                }
            }
        }

    }

    while(!exit->isEmpty()){
        cout<<exit->head()->info<<endl;
        exit->dequeue();
    }
    //printClient(exit);

    delete  returnedMenu;
    delete allMenu;
    delete  exit;
    delete row;
    return 0;
}
