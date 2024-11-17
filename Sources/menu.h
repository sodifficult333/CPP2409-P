# include <iostream>
# include <vector>
# include <fstream>
# include <string>
using namespace std;

// STEP 1 : 시작 단계 구현
// 전역 변수 : string 부위 배열 : 10/14 string
const string part[] = {"1. 등", "2. 가슴", "3. 어깨", "4. 하체", "5. 이두", "6. 삼두", "7. 복근"};

// Menu 클래스 : 10/30 Class
class Menu {
private:
    bool is_number(const string& str); 
public:
    int number; // 입력받은 번호를 저장할 변수
    string input; // 입력받은 명령을 저장할 변수
    string answer; // 추가할 부위를 저장할 변수
    int count; // 사용자가 입력한 부위를 추가할 때 앞에 붙을 숫자 변수
    vector<string> devide; // string 벡터 생성 : 11/06 Vector
    string path; // 파일 경로를 입력받을 string 변수

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
    void open_file();
};