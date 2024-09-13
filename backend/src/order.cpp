#include "order.h"

Order::Order(int id, double price, int quantity, Type type)
    : id(id), price(price), quantity(quantity), type(type) {}

int Order::getId() const { return id; }
double Order::getPrice() const { return price; }
int Order::getQuantity() const { return quantity; }
Order::Type Order::getType() const { return type; }
void Order::setQuantity(int quantity) { this->quantity = quantity; }
