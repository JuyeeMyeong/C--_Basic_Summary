#include <vector>
#include <string>

#include "Book.h"

using namespace std;
class BookManager {
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author);

    // 모든 책 출력 메서드
    void displayAllBooks() const;
};