#include <iostream>
#include <unordered_map>
#include <string>
#include <stdexcept>

class InMemoryDB {
private:
    std::unordered_map<std::string, int> db; // main
    std::unordered_map<std::string, int> transaction; 
    bool inTransaction = false;

public:
    // start transaction
    void begin_transaction() {
        if (inTransaction) {
            throw std::runtime_error("Transaction already in progress");
        }
        inTransaction = true;
        transaction.clear();
    }

    // insert/update key value pair
    void put(const std::string& key, int value) {
        if (!inTransaction) {
            throw std::runtime_error("No transaction in progress");
        }
        transaction[key] = value;
    }

    // retrieve value for key
    int get(const std::string& key) {
        if (inTransaction && transaction.find(key) != transaction.end()) {
            return transaction[key];
        }
        if (db.find(key) != db.end()) {
            return db[key];
        }
        throw std::runtime_error("Key does not exist");
    }

    // commit transaction changes to main 
    void commit() {
        if (!inTransaction) {
            throw std::runtime_error("No transaction in progress");
        }
        for (const auto& [key, value] : transaction) {
            db[key] = value;
        }
        inTransaction = false;
        transaction.clear();
    }

    // rollback transaction
    void rollback() {
        if (!inTransaction) {
            throw std::runtime_error("No transaction in progress");
        }
        inTransaction = false;
        transaction.clear();
    }
};

// main
int main() {
    InMemoryDB db;

    try {
        std::cout << "Value of A: ";
        db.get("A"); // throw an error
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    try {
        db.put("A", 5); // throw an error
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    db.begin_transaction();
    db.put("A", 5);
    try {
        std::cout << "Value of A during transaction: " << db.get("A") << std::endl; // print 5
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }
    db.put("A", 6);
    db.commit();

    std::cout << "Value of A after commit: " << db.get("A") << std::endl; // print 6

    db.begin_transaction();
    db.put("B", 10);
    db.rollback();
    try {
        std::cout << "Value of B after rollback: " << db.get("B") << std::endl; // throw an error
    } catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}