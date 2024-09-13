#include "tradingAlgorithm.h"
#include <iostream>

void TradingAlgorithm::processMatching(std::vector<Order>& buyOrders, std::vector<Order>& sellOrders) {
    auto itBuy = buyOrders.begin();
    while (itBuy != buyOrders.end()) {
        auto itSell = sellOrders.begin();
        while (itSell != sellOrders.end()) {
            if (itBuy->getPrice() >= itSell->getPrice() && itBuy->getQuantity() == itSell->getQuantity()) {
                std::cout << "Matched Buy at " << itBuy->getPrice() << " with Sell at " << itSell->getPrice() << " for quantity: " << itBuy->getQuantity() << std::endl;
                itBuy = buyOrders.erase(itBuy);
                itSell = sellOrders.erase(itSell);
                break;
            } else {
                ++itSell;
            }
        }
        if (itBuy != buyOrders.end()) {
            ++itBuy;
        }
    }
}
