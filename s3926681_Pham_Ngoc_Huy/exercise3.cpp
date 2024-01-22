/*
    RMIT University Vietnam
    Course: EEET2482/COSC2082
    Semester: 2023-3
    Lab Assessment: 2
    Author: Pham Ngoc Huy
    ID: s3926681
    Compiler used: (Homebrew GCC 13.2.0) 13.2.0
    Created  date: 13/01/2024
    Acknowledgement: W3sscholl

*/


#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Product {
public:
    string name;
    double price;
    int stockQuantity;

    Product (string n, double p, int quantity) :
     name(n), price(p), stockQuantity(quantity) {}
};

class Customer {
public:
    string name;
    double lastBill;
    int earningPoints;

    Customer(string n) : name(n), lastBill(0.0), earningPoints(0) {}

    void returnLastPurchase() {
        lastBill = 0.0;
        earningPoints = 0;
    }
};

class RetailShop {
private:
    string shopName;
    vector<Product> products;
    map< string, Customer> customers;

public:
    RetailShop(string name) : shopName(name) {}

    void addProduct(string name, double price, int stockQuantity) {
        products.emplace_back(name, price, stockQuantity);
    }

    void printBill(const Customer& customer, const vector<pair<string, int>>& purchasedItems) {
        double totalCost = 0.0;
        cout << "Bill for customer " << customer.name << ":" << endl;

        for (const auto& item : purchasedItems) {
            string productName = item.first;
            int quantity = item.second;

            for (const auto& product : products) {
                if (product.name == productName) {
                    if (product.stockQuantity >= quantity) {
                        double cost = product.price * quantity;
                        totalCost += cost;

                        cout << productName << " (Qty: " << quantity << ") - $ " << cost << endl;

                        // Update customer's earning points
                        customer.earningPoints += static_cast<int>(cost);
                    } else {
                        cout << "Not enough stock for " << productName << ". Skipped from the bill." << endl;
                    }
                    break;
                }
            }
        }

        customer.lastBill = totalCost;
        cout << "Total Cost: $ " << totalCost << endl;
        cout << "Earning Points: " << customer.earningPoints << endl;
    }

    void returnProduct(const Customer& customer) {
        if (customer.lastBill > 0.0) {
            cout << "Returning products from the last purchase for customer " << customer.name << "." << endl;
            customer.returnLastPurchase();
            cout << "Last purchase returned successfully." << endl;
        } else {
            cout << "No previous purchase found for customer " << customer.name << "." << endl;
        }
    }

    void generateSaleReport() {
        double totalRevenue = 0.0;
        string bestSellingProduct;
        double maxRevenue = 0.0;

        cout << "Sale Report for " << shopName << ":" << endl;

        for (const auto& product : products) {
            double revenue = (product.price * (product.stockQuantity - 1));
            totalRevenue += revenue;

            if (revenue > maxRevenue) {
                maxRevenue = revenue;
                bestSellingProduct = product.name;
            }

            cout << product.name << " - Revenue: $ " << revenue << "\t" << endl;
        }

        cout << "Total Revenue: $ " << totalRevenue << endl;
        cout << "Best Selling Product: " << bestSellingProduct << endl;
    }
};

int main() {
    RetailShop shop("MyShop");

    shop.addProduct("Product1", 10.0, 50);
    shop.addProduct("Product2", 20.0, 30);
    shop.addProduct("Product3", 15.0, 40);

    Customer customer1("John");
    Customer customer2("Alice");

    vector<pair<string, int>> purchase1 = {{"Product1", 2}, {"Product2", 1}};
    vector<pair<string, int>> purchase2 = {{"Product3", 3}, {"Product1", 1}};

    shop.printBill(customer1, purchase1);
    shop.printBill(customer2, purchase2);

    shop.returnProduct(customer1);

    shop.generateSaleReport();

    return 0;
}
