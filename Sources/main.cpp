#include "menu.h"
using namespace std;

int main() {
    Menu menu;
    
    // STEP 1 실행
    menu.print_1();
    while(menu.check_number_ver1()) {} // STEP 1에서 잘못 입력한 경우 반복
    if(menu.number == 1) { // 1 선택 - STEP 2로 진행
        // STEP 2
        menu.STEP_2(); // STEP 2 안내문 출력
        while(menu.check_number_ver3()) {} // STEP 2에서 잘못 입력한 경우 반복
        // STEP 3
        menu.STEP_3(); // STEP 3 실행
        menu.file_read(); // 파일 읽기
    }
    else if (menu.number == 2) { // 2 선택 - 세부기능 2)로 진행
        menu.print_2(); // 세부기능 2)의 안내 메세지 출력
        // 세부 기능 2)실행
        while(true) {
            cout << "'/add' 또는 번호를 입력하세요. ";
            cin >> menu.input;
            if(menu.check_add()) // add 입력시
                continue; // 다시 처음으로
            menu.check_input(); // int형인지 확인하고 int형 변환
            if(menu.check_number_ver2()) { // 알맞은 번호 입력시 STEP 2 실행
                // STEP 2
                menu.STEP_2();
                while(menu.check_number_ver3()) {} // STEP 2에서 잘못 입력한 경우 반복
                // STEP 3
                menu.STEP_3(); // STEP 3 실행
            }
        }
    }
    return 0;
}