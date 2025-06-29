#include <iostream>
#include <string>

#include "BookManager.h"
#include "BorrowManager.h"

using namespace std;

int main() {
    BookManager manager;
    BorrowManager rentalManager;

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl; // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl; // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 종료" << endl; // 프로그램 종료
        cout << "4. 책 대여" << endl; // 책 제목을 입력받아서 대여
        cout << "5. 책 반납" << endl; // 책 제목을 입력받아서 반납
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            // 1번 선택: 책 추가
            // 사용자로부터 책 제목과 저자명을 입력받아 BookManager에 추가합니다.
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title); // 제목 입력 (공백 포함)
            cout << "책 저자: ";
            getline(cin, author); // 저자명 입력 (공백 포함)
            manager.addBook(title, author); // 입력받은 책 정보를 추가

            Book* addedBook = manager.getBookByTitle(title); // Book Manager에 추가된 책을 기반으로 책 대여 재고 초기화 (기본 3권씩)
            if (addedBook != nullptr)
            {
                rentalManager.initializeStock(*addedBook);
            }

        } else if (choice == 2) {
            // 2번 선택: 모든 책 출력
            // 현재 BookManager에 저장된 책 목록을 출력합니다.
            manager.displayAllBooks();

            // 현재 책 재고 목록을 출력합니다.
            rentalManager.displayStock();
        } else if (choice == 3) {
            // 3번 선택: 종료
            // 프로그램을 종료하고 사용자에게 메시지를 출력합니다.
            cout << "프로그램을 종료합니다." << endl;
            break; // while 루프 종료
        } else if (choice == 4) {
            // 4번 선택: 책 대여 
            string title;
            cout << "찾는 책 제목: ";
            cin.ignore();
            getline(cin, title);
            rentalManager.borrowBook(title);

        } else if (choice == 5) {
            // 5번 선택: 책 반납 
            string title;
            cout << "반납할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            rentalManager.returnBook(title);
        } else {
            // 잘못된 입력 처리
            // 메뉴에 없는 번호를 입력했을 경우 경고 메시지를 출력합니다.
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}