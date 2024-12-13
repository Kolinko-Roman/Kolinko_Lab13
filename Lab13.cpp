#include <iostream>
#include <string>
using namespace std;

class Product {
protected:
    string name;
    double price;

public:
    Product(const string& name, double price) : name(name), price(price) {}

    virtual ~Product() {}

    string getName() const {
        return name;
    }

    void setName(const string& name) {
        this->name = name;
    }

    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        this->price = price;
    }

    virtual double getFinalPrice() const = 0;
};

class Discountable {
public:
    virtual double applyDiscount(double price) const = 0;
    virtual ~Discountable() {}
};

class Book : public Product, public Discountable {
public:
    Book(const string& name, double price) : Product(name, price) {}

    double applyDiscount(double price) const override {
        return price * 0.9;
    }

    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};

class Pen : public Product, public Discountable {
public:
    Pen(const string& name, double price) : Product(name, price) {}

    double applyDiscount(double price) const override {
        return price > 5 ? price - 5 : price;
    }

    double getFinalPrice() const override {
        return applyDiscount(price);
    }
};

void printProductDetails(const Product& product) {
    cout << "Назва товару: " << product.getName() << endl;
    cout << "Базова ціна: " << product.getPrice() << endl;
    cout << "Кінцева ціна: " << product.getFinalPrice() << endl;
    cout << "-------------------------" << endl;
}

int main() {
    Book book1("Java Programming", 100);
    Book book2("Python Essentials", 150);
    Pen pen1("Blue Pen", 20);
    Pen pen2("Red Pen", 4);

    printProductDetails(book1);
    printProductDetails(book2);
    printProductDetails(pen1);
    printProductDetails(pen2);

    return 0;
}
