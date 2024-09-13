#include <iostream>
#include "orderBook.h"
#include "order.h"

int main() {
    OrderBook orderBook;

    // Example usage
    orderBook.addOrder(Order(1, 100.0, 10, Order::Type::BUY));
    orderBook.addOrder(Order(2, 100.0, 10, Order::Type::SELL));
    orderBook.processMatching();
    orderBook.displayOrders();

    return 0;
}
