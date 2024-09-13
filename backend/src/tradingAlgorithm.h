#ifndef TRADINGALGORITHM_H
#define TRADINGALGORITHM_H

#include "order.h"
#include <vector>

class TradingAlgorithm {
public:
    void processMatching(std::vector<Order>& buyOrders, std::vector<Order>& sellOrders);
};

#endif
