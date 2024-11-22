#include "menu.h"
// ============================================================ 편하게 사용하려고 만든 구간 ===================================================================== //
void Menu::next_page() { // NEXT PAGE print
    cout << "┌─────────────────── < NEXT PAGE > ───────────────────┐" << endl;
}
void Menu::enter() { // 이중 Enter
    cout << endl << endl;
}
void Menu::please() { // 안내문
    number = 0; // 매 질문턴이 반복될 때마다 number값 초기화
    cout << "번호를 입력하세요. : ";
}
// ============================================================================================================================================================= //

bool Menu::is_number(const string& str) { // 문자열이 숫자인지 확인하는 함수
    if (str.empty()) // 문자열이 비어있는지 확인 // 4주차 Condition
        return false; // false 반환
    for (char ch : str) { // 문자열 배열 반복 // 5주차 Loop and Array
        if (!isdigit(ch)) { // 현재 문자가 숫자가 아닌지 확인
            return false; // 숫자가 아니면 false 반환
        }
    }
    return true; // 둘 다 해당되지 않으면 true 반환 : 다시 반복
}

//STEP 1.
Menu::Menu() { // Menu 객체 생성과 동시에 부위를 벡터에 추가
    for (int i = 0; i < 7; i++) {
        devide.push_back(part[i]); // 전역변수로 사용한 배열을 추가
    }
}
void Menu::print_1() { // 세부기능 1) 사용 문구
    enter();
    cout << "성장치를 측정하는 프로그램입니다." << endl;
    cout << "아래의 선택사항 중 하나를 번호로 입력하세요.";
    enter();
    cout << "  1. 종합적으로 계산";
    enter();
    cout << "  2. 분할적으로 계산" << endl;
    enter();
}
void Menu::print_2() { // 세부기능 2) 사용 문구
    enter();
    cout << "아래의 선택사항 중 하나를 번호를 입력하세요." << endl;
    cout << "추가하고 싶은 목록이 있다면 '/add'를 입력하세요.";
    enter();
    for (auto& e:devide) { // 벡터 주소값을 받아 출력
        cout << "  " << e;
        enter();
    }
}
bool Menu::check_number_ver1() { // 번호 검사하는 함수 : version 1 - 세부기능 1) 사용
    please(); // 안내문 출력

    // int형이 아닌 문자 입력시 오류 방지
    if (!(cin >> number)) { // 입력 : int(X)
        cin.clear(); // 오류 초기화
        cin.ignore(10000, '\n'); // 값 무시
        enter();
        cout << "다시 입력하세요." << endl;
        return true; // true반환 : 다시 반복
    }

    // 숫자 구분
    if(number == 1) { // 입력 : 1
        enter();
        next_page();
        return false; // false반환 : 반복문 탈출
    }
    else if(number == 2) { // 입력 : 2
        enter();
        next_page();
        return false; // false반환 : 반복문 탈출
    }
    else { // 입력 : 1과 2를 제외한 '숫자들'
        enter();
        cout << "다시 입력하세요." << endl;
        return true; // true반환 : 다시 반복
    }
}
bool Menu::check_number_ver2() { // version 2 - 세부기능 2-1) 사용
    if(number >= 1 && number <= devide.size()) { // 벡터 사이즈 안의 번호를 입력시 출력하고 반복문 빠져나오기
        enter();
        cout << devide[number - 1] << "(을/를) 선택하셨습니다.";
        enter();
        return true;
    }
    else { // 벡터 사이즈 밖의 번호 입력시 반복
        enter();
        cout << "다시 입력하세요." << endl;
        return false;
    }
}
bool Menu::check_add() { // 추가 명령어 - 세부기능 2-1) 사용
    if (input == "/add") { // '/add' 명령어 입력시 안내문을 출력하고 부위 입력받기
        enter();
        cout << "한글이 깨지기 때문에 영어로 입력바랍니다." << endl;
        cout << "추가할 항목을 입력하세요 : ";
        cin >> answer;
        count = devide.size() + 1; // 인덱스 오차
        devide.push_back(to_string(count) + ". " + answer); // 다음 인덱스에 추가하기
        enter();
        print_2(); // 추가한 목록 다시 보여주기
        return true;
    }
    return false;
}
void Menu::check_input() { // input 숫자 처리
    if(is_number(input)) { // 숫자인지 확인
        number = stoi(input); // 숫자로 변환하여 number에 저장
    }
}

// STEP 2.
void Menu::STEP_2() { // 단위 선택 안내문 출력
    enter();
    cout << "주기를 선택하세요." << endl;
    cout << "1달 주기로 분석을 원하시면 1번, 1주 주기로 분석을 원하시면 2번을 선택해주세요.";
    enter();
    cout << "  1. 달";
    enter();
    cout << "  2. 주" << endl;
    enter();
}
bool Menu::check_number_ver3() { // version 3 - STEP 2 사용
    while(true) {
        please(); // 번호를 입력해 달라는 안내문
        // 위 방법과 똑같은 방법으로 int형이 아닌 문자가 들어올 시 오류를 초기화하고 입력값 무시
        if(!(cin >> number)) {
            cin.clear();
            cin.ignore(10000, '\n');
            enter();
            cout << "다시 입력하세요." << endl;
            continue;
        }
        // 입력한 숫자가 1 or 2이면 반복문 빠져나오기
        if(number == 1 || number == 2) { return false; }
        else { // 그 외의 다른 숫자들 처리
            enter();
            cout << "다시 입력하세요." << endl;
            continue;
        }
    }
}

// STEP 3.
void Menu::input_path() { // 경로 입력받기
    if(cin.peek() == '\n') // 버퍼 안에 줄바꿈 문자가 있다면
        cin.ignore(); // 무시하기
    getline(cin, path); // 파일 경로 입력받기
}
bool Menu::path_check() { // 경로가 올바른지 확인
    ifstream file(path); // 입력받은 경로로 파일을 열어보기
    if(!file.is_open()) { // 파일이 열리지 않을 시 반복
        enter();
        cout << "올바른 경로를 입력해주세요." << endl;
        return true; // 반복문 반복
    }
    return false;
}
void Menu::STEP_3_print() { // STEP 3. 안내문 출력
    enter();
    next_page();
    enter();
    cout << "미리 준비한 파일의 경로를 입력해주세요." << endl;
    cout << "경로에 한글이 포함될 경우 문제가 발생할 수 있습니다." << endl;
    enter();
}
void Menu::STEP_3() { // STEP 3 실행 함수
    STEP_3_print();
    while(1) {
        cout << "파일 경로를 입력하세요: ";
        input_path(); // 경로를 입력받는다.
        if(path_check()) { // 입력한 경로가 올바르지 않다면
            continue; // 다시 입력받는다.
        }
        break; // 올바르면 그만둔다.
    }
    file_read();
}
vector<string> split(const string& str, char separated) { // split 구현 함수
    vector<string> store_vec; // 구분 후 저장할 벡터
    string token; // 기본 빈 문자열 : 얘를 통해 전달
    for (char ch:str) { // 구분할 문자열의 주소를 ch에 주고
        if (ch == separated) { // 구분할 문자와 같은 문자가 있을때
            if (!token.empty()) // 토큰이 비어있지 않으면
                store_vec.push_back(token); // 벡터에 추가
            token.clear(); // 토큰 초기화
        }
        else token += ch; // 토큰에 구분한 문자열을 넣기
    }
    if (!token.empty()) { store_vec.push_back(token); } // 마지막 토큰 추가
    return store_vec; // 구분 후 완성된 벡터를 반환
}
void Menu::file_read() { // 한 줄씩 출력하는 함수
    string line; // 한줄 저장할 string 변수
    ifstream file(path); // 파일 경로 열기
    char separated = ','; // 쉼표를 통해 구분
    while (getline(file, line)) { // 한줄씩 반복
        data.push_back(split(line, separated)); // 쉼표를 통해 구분하여 데이터에 push back
    }
    file.close();

    // check
    cout << "Data after reading file:" << endl;
    for (const auto& row:data) { // 데이터 열을 읽어옴
        for (const auto& col : row) { // 데이터 행을 읽어옴
            cout << col << " "; // 출력
        }
        cout << endl; // 줄 구분
    }

    data_analysis();
}

// STEP 4.
void Menu::data_analysis() { // 데이터 분석 함수
    const int FIRST_DATA_INDEX = 1; // 첫 데이터 위치는 (1,1)부터 위치 : 헤더를 건너뛰고 시작

    // 데이터 유효성 검사 : 1,1 이하인 파일, 빈 공간이 있는 자료 전부 종료
    if (data.size() <= FIRST_DATA_INDEX || data[FIRST_DATA_INDEX].size() <= FIRST_DATA_INDEX) {
        enter();
        cout << "유효하지 않는 파일입니다." << endl;
        return; // 함수 종료
    }
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data[i].size(); j++) {
            if (data[i][j] == " " || data[i][j].empty()) { // 빈 문자열이나 빈 공간이 존재하는 경우
                cout << "빈 공간이 존재합니다." << endl;
                return; // 함수 종료
            }

        }
    }
    // 첫 주차 (FLOAT)데이터 저장
    for (int i = FIRST_DATA_INDEX; i < data[FIRST_DATA_INDEX].size(); i++) {
        first_value.push_back(data[FIRST_DATA_INDEX][i]);
    }
    // 나머지 (FLOAT)데이터 전부 저장
    for (int i = FIRST_DATA_INDEX; i < data.size(); i++) {
        vector<string> Week_Data; // 한 주치 데이터를 current 2차원 벡터에 옮겨줄 벡터
        for (int j = FIRST_DATA_INDEX; j < data[i].size(); j++) {
            Week_Data.push_back(data[i][j]);
        }
        current_value.push_back(Week_Data); // current_value 벡터로 값을 옮겨주기
    }
    // 주(week) 데이터 저장
    for (int i = FIRST_DATA_INDEX; i < data.size(); i++) {
        week.push_back(data[i][0]); // 각 행의 첫 번째 값: week를 저장
    }
    // 종목(name) 데이터 저장
    for (int i = FIRST_DATA_INDEX; i < data[FIRST_DATA_INDEX].size(); i++) {
        name.push_back(data[0][i]); // 각 행의 첫 번째 열: name을 저장
    }
    cal(); // 위 값을 계산
    display(); // 결과 출력
}

void Calculator::cal() { // 계산기 함수
    growth_rate.clear(); // 함수 호출이 일어날 때마다 계산을 해야하므로 첫 부분에 클리어 구비
    // first_value float형변환 : 계산 진행을 위해
    vector<float> first_value_float; // 위와 같은 방식의 반복문
    for (const auto& value : first_value) {
        first_value_float.push_back(atof(value.c_str())); // atof는 char*만 가능하여 c_str()으로 변환
    }
    // current_value float형변환 : 계산 진행을 위해
    vector<vector<float>> current_value_float;
    for (const auto& row : current_value) { // 위와 동일한 방식으로 진행
        vector<float> week_data;
        for (const auto& value : row) {
            week_data.push_back(atof(value.c_str()));
        }
        current_value_float.push_back(week_data);
    }
    for (int i = 0; i < current_value.size(); i++) {
        for (int j = 0; j < current_value[i].size(); j++) {
            // 현재주 - 이전주 / 이전주 * 100
            if (first_value_float[j] != 0) // 분모가 0이 아닐 경우 : 계산 진행
                growth_rate.push_back(((current_value_float[i][j]) - first_value_float[j]) / first_value_float[j] * 100);
            else
                growth_rate.push_back(0); // 분모가 0일 경우 : 0으로 push
        }
    }
}
void Calculator::display() { // 결과를 출력하는 함수
    for (int i = 0; i < name.size(); i++)
        cout << name[i] << " = " << growth_rate[i] << "%" << endl;   
}
