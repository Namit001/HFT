#ifndef ORDER_H
#define ORDER_H

class Order {
public:
    enum class Type { BUY, SELL };

    // Constructor
    Order(int id, double price, int quantity, Type type);

    // Accessors
    int getId() const;
    double getPrice() const;
    int getQuantity() const;
    Type getType() const;
    void setQuantity(int quantity);

    // Equality operator
    bool operator==(const Order& other) const;

private:
    int id;
    double price;
    int quantity;
    Type type;
};

// Implementation of equality operator
inline bool Order::operator==(const Order& other) const {
    return id == other.id &&
           price == other.price &&
           quantity == other.quantity &&
           type == other.type;
}

#endif
