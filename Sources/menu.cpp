/* 1차. 메뉴 기능 */
// 24.11.06 * 오늘 배운 vector의 기능을 사용해 STEP 1. 만들기
// 24.11.07 * STEP 1. 완성하기 : 주석 변경을 깜빡함
// 24.11.10 * STEP 1. 수정하기 + STEP 2. 만들기

# include <iostream>
# include <vector>
using namespace std;

// STEP 1 : 시작 단계 구현
// 전역 변수 : string 부위 배열
string part[] = {"1. 등", "2. 가슴", "3. 어깨", "4. 하체", "5. 이두", "6. 삼두", "7. 복근"};
// Menu 클래스
class Menu {
private:
    bool is_number(const string& str) {
        if (str.empty())
            return false;
        for (char ch : str) {
            if (!isdigit(ch)) {
                return false;
            }
        }
        return true;
    }
public:
    int number; // 입력받은 번호를 저장할 변수
    string input; // 입력받은 명령을 저장할 변수
    string answer; // 추가할 부위를 저장할 변수
    int count; // 사용자가 입력한 부위를 추가할 때 앞에 붙을 숫자 변수
    vector<string> devide; // 동적 string 벡터 생성

    Menu() { // Menu 객체 생성과 동시에 부위를 벡터에 추가
        for (int i = 0; i < 7; i++) {
            devide.push_back(part[i]);
        }
    }
    // 세부기능 1)
    void print_1() {
        enter();
        cout << "성장치를 측정하는 프로그램입니다." << endl;
        cout << "아래의 선택사항 중 하나를 번호로 입력하세요.";
        enter();
        cout << "  1. 종합적으로 계산";
        enter();
        cout << "  2. 분할적으로 계산" << endl;
        enter();
    }

    // 세부기능 2)
    void print_2() {
        enter();
        cout << "아래의 선택사항 중 하나를 번호를 입력하세요." << endl;
        cout << "추가하고 싶은 목록이 있다면 '/add'를 입력하세요.";
        enter();
        for (auto& e:devide) {
            cout << "  " << e;
            enter();
        }
    }

    // 세부기능 3)
    
    // NEXT PAGE print
    void next_page() {
        cout << "┌─────────────────── < NEXT PAGE > ───────────────────┐" << endl;
    }
    // 이중 Enter
    void enter() {
        cout << endl;
        cout << endl;
    }

    // 안내문
    void please() {
        number = 0; // 매 질문턴이 반복될 때마다 number값 초기화
        cout << "번호를 입력하세요. : ";
    }

    // 번호 검사하는 함수 : version 1
    bool check_number_ver1() {
        please(); // 안내문 출력

        // number 변수 검사
        // 오류 방지
        if (!(cin >> number)) { // 입력 : int(X)
            cin.clear(); // 오류 초기화
            cin.ignore(10000, '\n'); // 값 무시
            enter();
            cout << "다시 입력하세요." << endl;
            return true; // true반환 : 다시 반복
        }
        if(number == 1) { // 입력 : 1
            enter();
            next_page();
            return false; // false반환 : 반복문 탈출
        }
        else if(number == 2) { // 입력 : 2
            enter();
            next_page();
            print_2(); // 세부기능 2) 출력
            return false; // false반환 : 반복문 탈출
        }
        else { // 입력 : 1과 2를 제외한 '숫자들'
            enter();
            cout << "다시 입력하세요." << endl;
            return true; // true반환 : 다시 반복
        }
    }
    // version 2
    bool check_number_ver2() {
        if (number >= 1 && number <= devide.size()) {
            enter();
            cout << devide[number - 1] << "(을/를) 선택하셨습니다.";
            enter();
            return true;
        }
        else {
            enter();
            cout << "다시 입력하세요." << endl;
            return false;
        }
    }

    // 추가 명령어
    bool check_add() {
        if (input == "/add") {
            enter();
            cout << "한글이 깨지기 때문에 영어로 입력바랍니다." << endl;
            cout << "추가할 항목을 입력하세요 : ";
            cin >> answer;
            count = devide.size() + 1; // 인덱스 오차
            devide.push_back(to_string(count) + ". " + answer); // 다음 인덱스에 추가
            enter();
            print_2();
            return true;
        }
        return false;
    }

    // input 숫자 처리
    void check_input() {
        if(is_number(input)) { // 숫자인지 확인
            number = stoi(input); // 숫자로 변환하여 number에 저장
        }
    }

    // STEP 2.
    // 단위 선택 안내문 출력
    void STEP_2() {
        enter();
        cout << "주기를 선택하세요." << endl;
        cout << "1달 주기로 입력을 원하시면 1번, 1주 주기로 입력을 원하시면 2번을 선택해주세요."; // 폰서비스 내용과 비슷하게
        enter();
        cout << "  1. 달";
        enter();
        cout << "  2. 주" << endl;
        enter();
    }

    void number_clear() {
        number = 0; // 기존에 선택 값을 초기화하고 입력받기 위함.
    }

    bool check_number_ver3() {
        while(true) {
            please(); // 번호를 입력해 달라는 안내문
        
            // 위 방법과 똑같은 방법으로 int형이 아닌 문자가 들어올 시 오류를 초기화하고 입력값 무시
            if(!(cin >> number)) {
                cin.clear();
                cin.ignore(10000, '\n');
                enter();
                cout << "다시 입력하세요." << endl;
                return true;
            }

            if(number == 1) { // 입력한 숫자가 1
                // 정보 입력 단계로 넘어가기
                return false;

            }
            else if(number == 2) { // 입력한 숫자가 2
                // 정보 입력 단계로 넘어가기
                return false;
            
            }
            else { // 그 외의 다른 숫자들 처리
                enter();
                cout << "다시 입력하세요." << endl;
                return true;
            }
        }
    }
};

int main() {
    Menu menu;
    
    // STEP 1 실행
    menu.print_1();

    while(menu.check_number_ver1()) {} // STEP 1에서 잘못 입력한 경우 반복
        
    if(menu.number == 1) { // STEP 1 : 1 선택 - STEP 2.로 진행
        // STEP 2 실행
        menu.STEP_2(); // STEP 2 안내문 출력
        while(menu.check_number_ver3()) {} // STEP 2에서 잘못 입력한 경우 반복
        
        // STEP 3 실행 : 추후 기입
        cout << " STEP 3" << endl;
        return 0;
    }
    else if (menu.number == 2) { // STEP 1 : 2 선택 - 세부기능 2)로 진행
        menu.print_2(); // 세부기능 2)의 안내 메세지 출력
        // 세부 기능 2 실행
        while(true) {
            cout << "'/add' 또는 번호를 입력하세요. ";
            cin >> menu.input;
            if(menu.check_add()) // add 입력시
                continue; // 다시 처음으로

            menu.check_input(); // int형인지 확인하고 int형 변환

            if(menu.check_number_ver2()) { // 알맞은 번호 입력시
                // STEP 2 실행
                menu.STEP_2();
                menu.number_clear(); // 기존 number 초기화
                while(menu.check_number_ver3()) {} // STEP 2에서 잘못 입력한 경우 반복
                
                // STEP 3 실행 : 추후 기입
                cout << "STEP 3" << endl;
                return 0;
            }    
        }
    }
    return 0;
}