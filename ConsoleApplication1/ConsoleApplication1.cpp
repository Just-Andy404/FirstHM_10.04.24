/*
Создать класс Overcoat (верхняя одежда). Реализовать
перегруженные операторы:
1. Проверка на равенство типов одежды (операция "==").
2. Операцию присваивания одного объекта другому (операция "=").
3. Сравнение по цене двух пальто одного типа (операция ">").
*/
#include <iostream>
#include <cstring>

using namespace std;

class Overcoat {
private:
    char* type;  
    double price; 

public:
    Overcoat() : type(nullptr), price(0.0) {}

    Overcoat(const char* t, double p ) {
        type = new char[strlen(t) + 1];
        strcpy_s(type, strlen(t) + 1, t);
        price = p;
    }

    Overcoat(const Overcoat& other) {
        type = new char[strlen(other.type) + 1];
        strcpy_s(type, strlen(other.type) + 1, other.type);
        price = other.price;
    }

    Overcoat& operator=(const Overcoat& right) {
        if (this != &right) {
            delete[] type;
            type = new char[strlen(right.type) + 1];
            price = right.price;
            strcpy_s(this->type, strlen(right.type) + 1, right.type);
        }
        return *this;
    }

    ~Overcoat() {
        if (this->type != nullptr)
        {
            delete[] type;
        }
        else
        {
            cout << "Error";
        }
    }

    bool operator==(const Overcoat& right) const {
        return this->type == right.type;
    }

    bool operator>(const Overcoat& right) const {
        return price > right.price;
    }

    void display() const {
        cout << "Type: " << type << ", Price: " << price << endl;
    }
};

int main() {
    Overcoat coat1("Jacket", 150);
    Overcoat coat2("Jacket", 200);
    Overcoat coat3("Trench", 180);

    coat3 = coat1;
    coat3.display();

    cout << "Coat1 and Coat2 are " << (coat1 == coat2 ? "of the same type." : "of different types.") << endl;

    if (coat1 == coat3) { 
        cout << "Coat2 is " << (coat2 > coat1 ? "more" : "less") << " expensive than Coat1." << endl;
    }

    return 0;
}
