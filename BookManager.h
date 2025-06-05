#pragma once
#include <vector>
#include <string>

#include "Book.h"

using namespace std;
class BookManager {
private:
    vector<Book> books; // 책 목록 저장

    Book* findBookByTitle (const string& title);
    Book* findBookByAuthor (const string& author);

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;

    Book* getBookByTitle (const string& title);
    Book* getBookByAuthor (const string& author);
};