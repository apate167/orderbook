//
// Created by amal on 10/27/19.
//

#ifndef ORDERBOOKDEMO_ORDERBOOK_H
#define ORDERBOOKDEMO_ORDERBOOK_H

#endif //ORDERBOOKDEMO_ORDERBOOK_H

#pragma once
#include <iostream>
#include <map>
#include <boost/optional.hpp>

class OrderBook{
private:
    std::map<int, int> bids, asks;
    void add(int price, int amount, bool bid);
    void remove(int price, int amount, bool bid);
public:
    struct BidAsk{
        typedef boost::optional<std::pair<int, int>> Entry;
        Entry bid, ask;
        boost::optional<int> spread() const;
    };
    bool is_empty() const;
    void add_bid(int price, int amount);
    void add_ask(int price, int amount);
    void remove_bid(int price, int amount);
    void remove_ask(int price, int amount);

    BidAsk get_bid_ask() const;

    friend std::ostream& operator<<(std::ostream& os, const OrderBook&);
};