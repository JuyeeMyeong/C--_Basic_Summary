#include <iostream>

#include "BookManager.h"


void BookManager::addBook(const string& title, const string& author) {
    books.push_back(Book(title, author)); // push_back 사용
    cout << "책이 추가되었습니다: " << title << " by " << author << endl;
}

    // 모든 책 출력 메서드
void BookManager::displayAllBooks() const {
    if (books.empty()) {
        cout << "현재 등록된 책이 없습니다." << endl;
        return;
    }

    cout << "현재 도서 목록:" << endl;
    for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
        cout << "- " << books[i].title << " by " << books[i].author << endl;
    }
}

// 제목으로 책 찾기 메서드 
Book* BookManager::findBookByTitle (const string& title)
{
    for(Book& book : books)
    {
        if (book.title == title)
        {
            return &book;
        }
    }
}

Book* BookManager::getBookByTitle (const string& title)
{
    return findBookByTitle(title);
}

// 작가로 책 찾기 메서드 
Book* BookManager::getBookByAuthor (const string& author)
{
    for(Book& book : books)
    {
        if (book.author == author)
        {
            return &book;
        }
    }
}

Book* BookManager::getBookByAuthor (const string& author)
{
    return findBookByAuthor(author);
}
