#include "iostream"
#include <string>
#ifndef __stack__hpp__
#include "./stack.hpp"
#endif

using namespace std;

struct Dish{
    int time;
    string name;

};

class Menu{
    public:
        Stack<Dish> *dishes = new Stack<Dish>(); 
        void printMenu(Stack<Menu> *menu){
            if(!menu->isEmpty()){
                cout<<"------------Menu----------------"<<endl;
                Menu temp = menu->top->info;

                printDishes(temp.dishes);
                if(menu->size != 1){
                    menu->pop();
                    printMenu(menu);
                    menu->push(temp);

                }
            }
        }
        void printDishes(Stack<Dish> *dishes){
            if(!dishes->isEmpty()){
                Dish temp = dishes->top->info;

                if(dishes->size != 1){
                    dishes->pop();
                    printDishes(dishes);
                    dishes->push(temp);
                }
                cout<<"name: "<<temp.name<<" time: "<<temp.name<<endl;

            }
        }


};
