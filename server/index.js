const express = require('express');
const app = express();
const cors = require('cors');

// CORS configuration
const corsOptions = {
  origin: 'http://localhost:3001', // Replace with your frontend URL
  methods: 'GET,POST',
  credentials: true,
};

// Apply CORS middleware with options
app.use(cors(corsOptions));
app.use(express.json());

let orders = [];

// Route to add a new order
app.post('/orders', (req, res) => {
  const order = req.body;
  orders.push(order);
  // Process order matching
  processMatching();
  res.status(201).send({ message: 'Order added successfully!' });
});

// Route to get all orders
app.get('/orders', (req, res) => {
  res.send(orders);
});

// Function to process and match orders
function processMatching() {
  let matchedOrders = [];
  let unmatchedOrders = [...orders]; // Start with all orders

  for (let i = 0; i < unmatchedOrders.length; i++) {
    let orderA = unmatchedOrders[i];
    for (let j = i + 1; j < unmatchedOrders.length; j++) {
      let orderB = unmatchedOrders[j];
      if (orderA.type !== orderB.type && 
          orderA.price === orderB.price) {
        const matchedQuantity = Math.min(orderA.quantity, orderB.quantity);
        matchedOrders.push({ buy: orderA, sell: orderB, quantity: matchedQuantity });
        
        // Update quantities
        if (orderA.quantity > matchedQuantity) {
          orderA.quantity -= matchedQuantity;
        } else {
          unmatchedOrders.splice(i, 1);
          i--;
        }

        if (orderB.quantity > matchedQuantity) {
          orderB.quantity -= matchedQuantity;
        } else {
          unmatchedOrders.splice(j, 1);
          j--;
        }

        break; // Move to next orderA
      }
    }
  }

  // Log matched orders
  console.log('Matched Orders:', matchedOrders);
  // Update orders with unmatched orders
  orders = unmatchedOrders;
}

const PORT = 5000;
app.listen(PORT, () => {
  console.log(`Server is running on port ${PORT}`);
});
