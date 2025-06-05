#include <iostream>

#include "BorrowManager.h"

// main에서 책을 추가할 때 초기화 호출하여 map에 책 제목과 수량을 넣는 함수
void BorrowManager::initializeStock (const Book& book, int quantity)
{
    if (stock.count(book.title)) // 책이 있는 재고면 수량을 추가가
    {
        stock[book.title] += quantity;
    } else
    {
        stock[book.title] = quantity;
    }
}

void BorrowManager::borrowBook (const string& title)
{
    if (!stock.count(title)) // 없는 책일 때 
    {
        cout << "There's no such book named " << title << endl;
        return;
    }

    if(stock[title] > 0) // 재고가 있고 빌려줄 수량이 있을 때 
    {
        --stock[title];
        cout << "You borrowed " << title << endl;
        cout << "Stock left: " << stock[title] << endl;
    } else
    {
        cout << "There's no stock left for " << title << endl;
    }
}

void BorrowManager::returnBook (const string& title)
{
    if (stock.count(title)) // 재고에 있는 책이면 반납을 받음음
    {
        ++stock[title];
        cout << "You returned " << title << endl;
        cout << "Stock left: " << stock[title] << endl;
    } else
    {
        cout << "There's no such book named " << title << endl;
    }
    
}

void BorrowManager::displayStock() const
{
    cout << "책 재고 목록: " << endl;
    for(const auto& pair : stock)
    {
        const string& title = pair.first;
        const int& quantity = pair.second;

        cout << "Book Title: " << title << endl;
        cout << "Stock: " << quantity << endl;
    }
}