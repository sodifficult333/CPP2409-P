#include "menu.h"
using namespace std;

int main() {
    Menu menu;
    
    // STEP 1 실행
    menu.Print_1();
    while(menu.Check_Number_Ver1()) {} // STEP 1에서 잘못 입력한 경우 반복
    if(menu.number == 1) { // 1 선택 - STEP 2로 진행
        // STEP 2
        menu.Step_2(); // STEP 2 안내문 출력
        while(menu.Check_Number_Ver3()) {} // STEP 2에서 잘못 입력한 경우 반복
        // STEP 3
        menu.Step_3(); // STEP 3 실행
    }
    else if (menu.number == 2) { // 2 선택 - 세부기능 2)로 진행
        menu.Print_2(); // 세부기능 2)의 안내 메세지 출력
        // 세부 기능 2)실행
        while(true) {
            cout << "'/add' 또는 번호를 입력하세요. ";
            cin >> menu.input;
            if(menu.Check_Add()) // add 입력시
                continue; // 다시 처음으로
            menu.Check_Input(); // int형인지 확인하고 int형 변환
            if(menu.Check_Number_Ver2()) { // 알맞은 번호 입력시 STEP 2 실행
                // STEP 2
                menu.Step_2();
                while(menu.Check_Number_Ver3()) {} // STEP 2에서 잘못 입력한 경우 반복
                // STEP 3
                menu.Step_3(); // STEP 3 실행
                break;
            }
        }
    }
    return 0;
}