//
// Created by amal on 10/27/19.
//

#include "stest.h"
#include <gtest/gtest.h>
#include <OrderBook.h>

TEST(orderbooktests, orderbookemptybydefault){
    OrderBook book;
    EXPECT_TRUE(book.is_empty());
}

TEST(orderbooktests, orderaddition){
    OrderBook book;
    book.add_bid(123, 456);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(456, bid.second);
}

TEST(orderbooktests, OrderBookRemoval){
    OrderBook book;
    book.add_bid(123, 456);
    book.remove_bid(123, 156);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto bid = bidask.bid.get();
    EXPECT_EQ(123, bid.first);
    EXPECT_EQ(300, bid.second);
}

TEST(orderbooktests, BidAskSpread){
    OrderBook book;
    book.add_bid(50, 100);
    book.add_ask(70, 100);
    auto bidask = book.get_bid_ask();
    EXPECT_TRUE(bidask.bid.is_initialized());
    auto spread = bidask.spread();
    EXPECT_TRUE(spread.is_initialized());
    EXPECT_EQ(20, spread.get());
}