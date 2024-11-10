/* 1차. 메뉴 기능 */
// 24.11.06 * 오늘 배운 vector의 기능을 사용해 메뉴판 생성

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
    int count; // 부위를 벡터에 추가할 때 앞에 붙을 숫자 변수
    vector<string> devide; // 동적 string 벡터 생성

    Menu() { // Menu 객체 생성과 동시에 벡터에 추가
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
            
            // 정보 입력으로 넘어가기 입력 예정





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
            cout << devide[number - 1] << "을/를 선택하셨습니다.";
            enter();

            // 정보 입력으로 넘어가기 추가 예정




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
};

int main() {
    Menu menu;
    menu.print_1();

    while(1) { // 무한반복문
        if(menu.check_number_ver1()) // True
            continue; // 다시 반복
        else // False
            break; // 반복문 나가기
    }

    // 세부 기능 2 실행
    while(1) {
        cout << "'/add' 또는 번호를 입력하세요. ";
        cin >> menu.input;
        if(menu.check_add()) // add 입력시
            continue; // 다시 처음으로
        menu.check_input();
        if(menu.check_number_ver2()) // 알맞은 번호 입력시
            break; // 반복문 탈출
        else
            continue; // 다시 처음으로
    }
    return 0;
}