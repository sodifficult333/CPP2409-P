# include <iostream>
# include <vector>
# include <string>
# include <fstream> // 파일을 읽어오기
# include <sstream> // 파일 구분하기
# include <cstdlib> // atof로 형변환하기
# include <iomanip> // setprecision으로 소수점 표기하기
# include <cmath> // 절대값 구현하기 + round() 반올림 함수
using namespace std;

// STEP 1 : 시작 단계 구현
// 전역 변수 : string 부위 배열 : 10/14 string
const string part[] = {"1. 등", "2. 가슴", "3. 어깨", "4. 하체", "5. 이두", "6. 삼두", "7. 복근"};

// Caculator Class - is-a관계로 사용 : 부모클래스
class Calculator {
protected:
    vector<vector<string>> data; // 데이터 원본을 저장할 벡터
    vector<string> name; // 종목:이름을 저장할 벡터
    vector<string> week; // 주차를 저장할 벡터
    vector<vector<float>> current_value; // 현재 주차 값을 저장할 2차원 벡터
    vector<float> first_value; // 첫 주차 값을 저장할 벡터
    vector<float> growth_rate; // 성장률을 저장할 벡터
    vector<int> graph_rate; // 그래프 비율을 저장할 벡터
public:
    // STEP 4.
    void Data_Analysis(const string& path); // 데이터 파일 분석 함수
    void Cal(); // 계산기 함수
    void Display(); // 결과를 출력하는 함수

    // STEP 5.
    void Graph_Cal(vector<float> growth_rate); // 그래프 비율 계산 함수
    void Graph_Print(vector<float> growth_rate, vector<int> grapth_rate); // 그래프 출력 함수
};

// Menu 클래스 : 10/30 Class : 자식클래스
class Menu : public Calculator {
private:
    bool Is_Number(const string& str);  // 입력된 string이 int형인지 확인하는 함수
    string answer; // 추가할 부위를 저장할 변수
    int count; // 사용자가 입력한 부위를 추가할 때 앞에 붙을 숫자 변수
    string path; // 파일 경로를 입력받을 string 변수
    vector<string> devide; // string 벡터 생성 : 11/06 Vector
    vector<vector<string>> data; // 데이터를 저장할 2차원 벡터 : split에서 1차원 벡터를 반환하고 있으므로 2차원 벡터로 선언
public:
    int number; // 입력받은 번호를 저장할 변수
    string input; // 입력받은 명령을 저장할 변수
    // ========================== 사용하기 편하려고 만든 기능들 ========================== //
    void Next_Page(); // NEXT PAGE print
    void Enter(); // 이중 엔터
    void Please(); // 안내문
    // ================================================================================= //

    // STEP 1.
    Menu(); // 위 string 배열을 벡터로 할당
    void Print_1(); // 세부기능 1) 구현
    void Print_2(); // 세부기능 2) 구현
    bool Check_Number_Ver1(); // 번호 검사 함수 version 1 : menu.cpp에서 설명
    bool Check_Number_Ver2(); // 번호 검사 함수 version 2 : menu.cpp에서 설명
    bool Check_Add(); // 추가 명령어
    void Check_Input(); // input 숫자 처리

    // SETP 2.
    void Step_2(); // 단위 선택하라는 안내문 출력

    // STEP 3.
    void Input_Path(); // 파일 위치를 입력받기
    bool Path_Check(); // path가 정확한 위치인지 확인하기
    void Step_3_Print(); // STEP 3. 안내문 출력
    void Step_3(); // STEP 3에서 반복되는 코드 함수화
};