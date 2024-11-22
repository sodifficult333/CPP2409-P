# include <iostream>
# include <vector>
# include <fstream>
# include <string>
using namespace std;

// STEP 1 : 시작 단계 구현
// 전역 변수 : string 부위 배열 : 10/14 string
const string part[] = {"1. 등", "2. 가슴", "3. 어깨", "4. 하체", "5. 이두", "6. 삼두", "7. 복근"};

// Caculator Class - is-a관계로 사용 : 부모클래스
class Calculator {
public:
    vector<string> name; // 항목 이름을 저장할 벡터
    vector<string> week; // 몇 주차인지 저장할 벡터
    vector<vector<string>> current_value; // 현재 주차 값을 저장할 2차원 벡터
    vector<string> first_value; // 첫 주차 값을 저장할 벡터
    vector<float> growth_rate; // 성장률을 저장할 벡터

    void cal(); // 계산기 함수
    void display(); // 결과를 출력하는 함수
};

// Menu 클래스 : 10/30 Class : 자식클래스
class Menu : public Calculator {
private:
    bool is_number(const string& str); 
public:
    int number; // 입력받은 번호를 저장할 변수
    string input; // 입력받은 명령을 저장할 변수
    string answer; // 추가할 부위를 저장할 변수
    int count; // 사용자가 입력한 부위를 추가할 때 앞에 붙을 숫자 변수
    string path; // 파일 경로를 입력받을 string 변수

    vector<string> devide; // string 벡터 생성 : 11/06 Vector
    vector<vector<string>> data; // 데이터를 저장할 2차원 벡터 : split에서 1차원 벡터를 반환하고 있으므로 2차원 벡터로 선언

    // ========================== 사용하기 편하려고 만든 기능들 ========================== //
    void next_page(); // NEXT PAGE print
    void enter(); // 이중 엔터
    void please(); // 안내문
    // ================================================================================= //

    // STEP 1.
    Menu(); // 위 string 배열을 벡터로 할당
    void print_1(); // 세부기능 1) 구현
    void print_2(); // 세부기능 2) 구현
    bool check_number_ver1(); // 번호 검사 함수 version 1 : menu.cpp에서 설명
    bool check_number_ver2(); // 번호 검사 함수 version 2 : menu.cpp에서 설명
    bool check_add(); // 추가 명령어
    void check_input(); // input 숫자 처리

    // SETP 2.
    void STEP_2(); // 단위 선택하라는 안내문 출력
    bool check_number_ver3(); // 번호 검사 함수 version 3 : menu.cpp에서 설명

    // STEP 3.
    void input_path(); // 파일 위치를 입력받기
    bool path_check(); // path가 정확한 위치인지 확인하기
    void STEP_3_print(); // STEP 3. 안내문 출력
    void STEP_3(); // STEP 3에서 반복되는 코드 함수화
    void file_read(); // 파일을 읽어 필요한 데이터를 저장하는 함수

    // STEP 4.
    void data_analysis();
};