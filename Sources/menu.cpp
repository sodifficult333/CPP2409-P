#include "menu.h"
// ============================================================ 편하게 사용하려고 만든 구간 ===================================================================== //
void Menu::Next_Page() { // NEXT PAGE print
    cout << "┌─────────────────── < NEXT PAGE > ───────────────────┐" << endl;
}
void Menu::Enter() { // 이중 Enter
    cout << endl << endl;
}
void Menu::Please() { // 안내문
    number = 0; // 매 질문턴이 반복될 때마다 number값 초기화
    cout << "번호를 입력하세요. : ";
}
// ============================================================================================================================================================= //

bool Menu::Is_Number(const string& str) { // 문자열이 숫자인지 확인하는 함수
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
void Menu::Print_1() { // 세부기능 1) 사용 문구
    Enter();
    cout << "성장치를 측정하는 프로그램입니다." << endl;
    cout << "아래의 선택사항 중 하나를 번호로 입력하세요.";
    Enter();
    cout << "  1. 종합적으로 계산";
    Enter();
    cout << "  2. 분할적으로 계산" << endl;
    Enter();
}
void Menu::Print_2() { // 세부기능 2) 사용 문구
    Enter();
    cout << "아래의 선택사항 중 하나를 번호를 입력하세요." << endl;
    cout << "추가하고 싶은 목록이 있다면 '/add'를 입력하세요.";
    Enter();
    for (auto& e:devide) { // 벡터 주소값을 받아 출력
        cout << "  " << e;
        Enter();
    }
}
bool Menu::Check_Number_Ver1() { // 번호 검사하는 함수 : version 1 - 세부기능 1) 사용
    Please(); // 안내문 출력
    cin >> input;
    // 숫자 구분
    if(input == "1" || input == "2") { // 입력 : 1 or 2
        Enter();
        Next_Page();
        return false; // false반환 : 반복문 탈출
    }
    else { // 입력 : 1과 2를 제외한 '숫자들'
        Enter();
        cout << "다시 입력하세요." << endl;
        return true; // true반환 : 다시 반복
    }
}
bool Menu::Check_Number_Ver2() { // version 2 - 세부기능 2-1) 사용
    if(number >= 1 && number <= devide.size()) { // 벡터 사이즈 안의 번호를 입력시 출력하고 반복문 빠져나오기
        Enter();
        cout << devide[number - 1] << "(을/를) 선택하셨습니다.";
        Enter();
        return true;
    }
    else { // 벡터 사이즈 밖의 번호 입력시 반복
        Enter();
        cout << "다시 입력하세요." << endl;
        return false;
    }
}
bool Menu::Check_Add() { // 추가 명령어 - 세부기능 2-1) 사용
    if (input == "/add") { // '/add' 명령어 입력시 안내문을 출력하고 부위 입력받기
        Enter();
        cout << "한글이 깨지기 때문에 영어로 입력바랍니다." << endl;
        cout << "추가할 항목을 입력하세요 : ";
        cin >> answer;
        count = devide.size() + 1; // 인덱스 오차
        devide.push_back(to_string(count) + ". " + answer); // 다음 인덱스에 추가하기
        Enter();
        Print_2(); // 추가한 목록 다시 보여주기
        return true;
    }
    return false;
}
void Menu::Check_Input() { // input 숫자 처리
    if(Is_Number(input)) { // 숫자인지 확인
        number = stoi(input); // 숫자로 변환하여 number에 저장
    }
}

// STEP 2.
void Menu::Step_2() { // 단위 선택 안내문 출력
    Enter();
    cout << "주기를 선택하세요." << endl;
    cout << "1달 주기로 분석을 원하시면 1번, 1주 주기로 분석을 원하시면 2번을 선택해주세요.";
    Enter();
    cout << "  1. 달";
    Enter();
    cout << "  2. 주" << endl;
    Enter();
}
bool Menu::Check_Number_Ver3() { // version 3 - STEP 2 사용
    Please(); // 번호를 입력해 달라는 안내문
    cin >> input;
    // 입력한 숫자가 1 or 2이면 반복문 빠져나오기
    if(input == "1" || input == "2") { return false; }
    else { // 그 외의 다른 숫자들 처리
        Enter();
        cout << "다시 입력하세요." << endl;
        return true; // 반복
    }
}

// STEP 3.
void Menu::Input_Path() { // 경로 입력받기
    if(cin.peek() == '\n') // 버퍼 안에 줄바꿈 문자가 있다면
        cin.ignore(); // 무시하기
    getline(cin, path); // 파일 경로 입력받기
}
bool Menu::Path_Check() { // 경로가 올바른지 확인
    ifstream file(path); // 입력받은 경로로 파일을 열어보기
    if(!file.is_open()) { // 파일이 열리지 않을 시 반복
        Enter();
        cout << "올바른 경로를 입력해주세요." << endl;
        return true; // 반복문 반복
    }
    return false;
}
void Menu::Step_3_Print() { // STEP 3. 안내문 출력
    Enter();
    Next_Page();
    Enter();
    cout << "미리 준비한 파일의 경로를 입력해주세요." << endl;
    cout << "경로에 한글이 포함될 경우 문제가 발생할 수 있습니다." << endl;
    Enter();
}
void Menu::Step_3() { // STEP 3 실행 함수
    Step_3_Print();
    while(1) {
        cout << "파일 경로를 입력하세요: ";
        Input_Path(); // 경로를 입력받는다.
        if(Path_Check()) { // 입력한 경로가 올바르지 않다면
            continue; // 다시 입력받는다.
        }
        break; // 올바르면 그만둔다.
    }
    Data_Analysis(path); // 데이터 분석
}

// STEP 4.
void Calculator::Data_Analysis(const string& path) { // 한 줄씩 출력하는 함수
    string line; // 한줄 저장할 string 변수
    ifstream file(path); // 파일 경로 열기
    while (getline(file, line)) { // 한줄씩 반복
        stringstream ss(line);
        string value; // 구분한 값을 저장할 변수
        vector<string> data_row; // 구분한 열 데이터를 저장할 1차원 벡터
        while (getline(ss, value, ',')) {
            data_row.push_back(value); // 쉼표를 통해 구분하여 데이터에 push back
        }
        data.push_back(data_row); // 구분한 열 데이터를 2차원 벡터에 추가
    }

    file.close(); // 파일 닫기

    // 이름 저장
    for (int i = 1; i < data[0].size(); i++) {
        name.push_back(data[0][i]);
    }

    // 주 저장
    for (int i = 1; i < data.size(); i++) {
        week.push_back(data[i][0]);
    }

    // current_value 데이터 추가
    for (int i = 1; i < data.size(); i++) {
        current_value.push_back({});
        for (int j = 1; j < data[0].size(); j++) {
           current_value.back().push_back(atof(data[i][j].c_str()));
        }
    }
    
    // first_value 데이터 추가
    for (int i = 0; i < current_value[0].size(); i++) {
        first_value.push_back(current_value[0][i]);
    }

    Cal(); // 계산 진행
    Display(); // 결과 표기
}
void Calculator::Cal() { // 계산기 함수
    growth_rate.clear(); // 호출 될 때마다 결과값 초기화
    float rate; // 계산 결과값이 저장될 float 변수
    for (auto& row : current_value) {
        for (int j = 0; j < row.size(); j++) {
            // 증가한 비율 계산 : 현재주 - 이전주 / 이전주 * 100
            if (first_value[j] != 0) // 분모가 0이 아닐 경우 : 계산 진행
                rate = ((row[j]) - first_value[j]) / first_value[j] * 100;
            else
                rate = 0; // 분모가 0일 경우 : 0
            growth_rate.push_back(rate); // 결과값 push_back
        }
    }
}
void Calculator::Display() { // 결과를 출력하는 함수
    cout << endl << endl;
    cout << "< 성장률 계산 결과 >" << endl << endl;
    auto growth_rate_start = growth_rate.begin(); // 벡터의 시작값을 변수에 저장 (auto로 타입 자동 선정)
    for (auto& i : week) {
        cout << "[ " << i << " ]" << endl; // 몇 주차인지 나타내는 반복문
        for (int j = 0; j < name.size(); ++j) {
            // 종목과 성장률을 나타내는 반복문 : fixed << setprecision(2) : 소수 2번째 자리까지 표기
            cout << name[j] << ": " << fixed << setprecision(2) << *growth_rate_start << "%" << endl;
            ++ growth_rate_start; // 값 증가
        }
        cout << endl;
    }
    Graph_Cal(growth_rate); // 그래프 비율을 계산하고
    Graph_Print(growth_rate, graph_rate); // 그 비율을 가지고 그래프 출력
}

// STEP 5.
void Calculator::Graph_Cal(vector<float> growth_rate) { // 그래프 비율 계산 함수
    float max_rate = 0; // 초기 최대 비율 0

    cout << endl << endl;
    cout << "< 그래프 >" << endl << endl;
    for (int i = 0; i < growth_rate.size(); i++) {
        if(fabs(growth_rate[i]) > max_rate) { // ||결과값|| 중 제일 큰 것을 저장
            max_rate = fabs(growth_rate[i]); // fabs는 float 절대값 처리
        }
    }
    for (int i = 0; i < growth_rate.size(); i++) {
        float temp_graph_rate = (growth_rate[i] / max_rate) * 20; // 그래프 비율 : (비율 / 가장 큰 비율) * 20(칸)
        graph_rate.push_back(static_cast<int>(round(temp_graph_rate))); // round()함수로 반올림 후 int형으로 배열에 저장
    }
}
void Calculator::Graph_Print(vector<float> growth_rate, vector<int> graph_rate) { // 그래프 출력 함수
    int all_bar = 40; // 총 표기할 칸 수 40
    int right_bar = all_bar / 2; // 오른쪽 칸 20
    int left_bar = all_bar / 2; // 왼쪽 칸 20
    auto graph_rate_start = graph_rate.begin(); // 그래프 비율 벡터의 시작값 저장
    auto growth_rate_start = growth_rate.begin(); // 성장 비율 벡터의 시작값 저장

    for (auto& i : week) {
        cout << "[ " << i << " ]" << endl; // 몇 주차인지 나타내는 반복문
        for (int j = 0; j < name.size(); ++j) {
            cout << name[j] << ": "; // 종목 이름 출력
            if (*graph_rate_start < 0) { // 성장률이 음수일 때 그래프 그리기
                for (int k = 0; k < left_bar; k++) { // 왼쪽 칸 수만큼 반복 20
                    if (k < left_bar - abs(*graph_rate_start)) // 성장률이 음수이므로 절대값 처리
                        cout << "□";
                    else
                        cout << "■";
                }
            }
            else {
                for (int k = 0; k < left_bar; k++)
                    cout << "□";
            }
            cout << "|"; // 칸 나누기 : 음수 | 양수
            for (int k = 0; k < right_bar; k++) {
                if (k < *graph_rate_start && *graph_rate_start > 0) // 성장률이 양수일 때 그래프 그리기
                    cout << "■";
                else
                    cout << "□";
            }
            cout << " (" << fixed << setprecision(2) << *growth_rate_start << "%)" << endl; // 성장 비율을 소수 2번째자리까지 출력
            growth_rate_start ++; // 다음 성장률로 업데이트
            graph_rate_start ++; // 다음 그래프 비율로 업데이트
        }
        cout << endl; // 줄바꿈
    }
}
