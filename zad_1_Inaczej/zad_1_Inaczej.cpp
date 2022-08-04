//Zad 1.
//Program lista zakupów
//Stwórz program, który będzie od użytkownika wczytywał nazwy produktów spożywczych oraz ilość do kupienia
// (dla uproszczenia bez jednostki miary).
//- dla pewności zamień duże litery na małe
//- gdy uzytkownik poraz drugi wprowadzi ten sam produkt, zapytaj się go co chce zrobić :
//a) nadpisac(zamieniamy starą wartość na nową)
//b) zsumowac(sumujemy obie wartości)
//c) pominac(zostawiamy pierwszą wartość)
//
//Następnie zapisz dane do pliku lista_zakupow.txt
//np :
//jablko 4
//ziemniaki 3
//kiszony ogorek 1
//smietana 1
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <sstream>

struct ShoppingList
{
    std::string _product;
    int _quantity;
    ShoppingList(std::string product, int quantity) : _product(product), _quantity(quantity) {};
};

void zad1()
{
    std::string product;
    std::string quantity;
    std::string oneItem;
    std::vector<ShoppingList> shoppingList;

    std::cout << "Podaj nazwę produktu ('0' kończy wprowadzanie) : ";
    std::getline(std::cin, product);

    while (product != "0")
    {
        std::getline(std::cin, quantity);
        std::for_each(product.begin(), product.end(), [](char& c) {c = tolower(c); });
        std::for_each(quantity.begin(), quantity.end(), [](char& c) {c = tolower(c); });
        shoppingList.emplace_back(product, stoi(quantity));
        std::cout << "Podaj nazwę produktu ('0' kończy wprowadzanie) : ";
        std::getline(std::cin, product);
    }
   // std::for_each(shoppingList.begin(), shoppingList.end(), [](char& c) {c = tolower(c); });
  
    // posortuj
    std::sort(shoppingList.begin(), shoppingList.end());
    std::unique(shoppingList.begin(), shoppingList.end());
    // usuń duplikaty

    std::ofstream fout("lista_zakupow.txt");
    if (!fout.is_open())
    {
        std::cout << "nie udalo sie otworzyc pliku";
        return;
    }
    for (auto it = shoppingList.begin(); it != shoppingList.end(); ++it)
    {
        fout << it->_product << ", " << it->_quantity << '\n';
    }
    fout.close();
}

int main()
{
    zad1();
}