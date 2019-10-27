//
// Created by amal on 10/27/19.
//

#include "OrderBook.h"

bool OrderBook::is_empty() const {
    return bids.empty() && asks.empty();
}

void OrderBook::add_bid(int price, int amount) {
    add(price, amount, true);
}

void OrderBook::add_ask(int price, int amount) {
    add(price, amount, false);
}

void OrderBook::add(int price, int amount, bool bid) {
    if(bid)
        bids[price] += amount;
    else
        asks[price] += amount;
}

std::ostream &operator<<(std::ostream& os, const OrderBook& book) {
    // Two ways to print order books
    // Print the bids from highest to lowest
    // Go through the map reverse
    if(book.is_empty())
        os << "ORDER BOOK EMPTY";

    for(auto i=book.bids.rbegin(); i!=book.bids.rend(); ++i){
        os << i->first << "\t" << i->second << std::endl;
    }

    os << std::endl;

    for(auto i=book.asks.rbegin(); i!=book.asks.rend(); ++i){
        os << i->first << "\t" << i->second << std::endl;
    }

    return os;
}

OrderBook::BidAsk OrderBook::get_bid_ask() const {
    BidAsk result;
    auto best_bid = bids.rbegin();
    if(best_bid != bids.rend())
        result.bid = *best_bid;

    auto best_ask = asks.begin();
    if(best_ask != asks.end())
        result.ask = *best_ask;

    return result;
}

void OrderBook::remove(int price, int amount, bool bid) {
    auto table = bid? bids : asks;
    auto it = table.find(price);
    if(it !=  table.end()){
        it->second -= amount;
        if(it->second ==0){
            table.erase(it);
        }
    }
}

void OrderBook::remove_bid(int price, int amount) {
    remove(price, amount, true);
}

void OrderBook::remove_ask(int price, int amount) {
    remove(price, amount, false);
}

boost::optional<int> OrderBook::BidAsk::spread() const {
    boost::optional<int> result;
    if(bid.is_initialized() && ask.is_initialized())
        result = ask.get().first - bid.get().first;
    return result;
}
