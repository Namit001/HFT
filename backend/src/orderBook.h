#ifndef ORDERBOOK_H
#define ORDERBOOK_H

#include "order.h"
#include "tradingAlgorithm.h"
#include <vector>

class OrderBook {
public:
    void addOrder(const Order& order);
    void displayOrders() const;
    void processMatching();  // Add this method for processing orders

private:
    std::vector<Order> buyOrders;
    std::vector<Order> sellOrders;
    TradingAlgorithm tradingAlgorithm;
};

#endif
