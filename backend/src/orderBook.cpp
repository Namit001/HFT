#include "OrderBook.h"
#include <iostream>

void OrderBook::addOrder(const Order& order) {
    if (order.getType() == Order::Type::BUY) {
        buyOrders.push_back(order);
    } else {
        sellOrders.push_back(order);
    }
    processMatching();  // Attempt to match orders after adding a new one
}

void OrderBook::displayOrders() const {
    std::cout << "Buy Orders:\n";
    for (const auto& order : buyOrders) {
        std::cout << "Price: " << order.getPrice()
                  << ", Quantity: " << order.getQuantity() << "\n";
    }
    std::cout << "\nSell Orders:\n";
    for (const auto& order : sellOrders) {
        std::cout << "Price: " << order.getPrice()
                  << ", Quantity: " << order.getQuantity() << "\n";
    }
}

void OrderBook::processMatching() {
    std::vector<Order> matchedOrders;
    for (auto& buyOrder : buyOrders) {
        for (auto it = sellOrders.begin(); it != sellOrders.end(); ) {
            if (buyOrder.getPrice() >= it->getPrice() && buyOrder.getQuantity() == it->getQuantity()) {
                // Order matches
                std::cout << "Matched Buy at " << buyOrder.getPrice()
                          << " with Sell at " << it->getPrice()
                          << " for quantity: " << buyOrder.getQuantity() << "\n";
                matchedOrders.push_back(buyOrder);
                it = sellOrders.erase(it);  // Remove matched sell order
                break;
            } else {
                ++it;
            }
        }
    }
    // Optionally remove matched buy orders from the buyOrders list
    for (const auto& order : matchedOrders) {
        buyOrders.erase(std::remove(buyOrders.begin(), buyOrders.end(), order), buyOrders.end());
    }
}
