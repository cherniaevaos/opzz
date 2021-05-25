#include "gtest/gtest.h"
#include <iostream>
#include "main.h"

using namespace std;

TEST(in, input) {
    //Сложение
    short n=0;
    const char *defaults = "1+2+5+9";
    Read(symbol, sign, defaults);
    testing::internal::CaptureStdout();
    while (n != 7){
    cout << symbol[n];
    n++;}
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1259+++");

    //Вычитание
    n=0;
    const char *defaults_1 = "1-2-5-7-1";
    Read(symbol, sign, defaults_1);
    testing::internal::CaptureStdout();
    while (n != 9){
        cout << symbol[n];
        n++;}
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "12-5-7-1-");

    //Умножение
    n = 0;
    const char *defaults_2 = "6*2*5*9";
    Read(symbol, sign, defaults_2);
    testing::internal::CaptureStdout();
    while (n != 7){
        cout << symbol[n];
        n++;}
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "62*5*9*");

    //Деление
    n = 0;
    const char *defaults_3 = "7/2/3";
    Read(symbol, sign, defaults_3);
    testing::internal::CaptureStdout();
    while (n != 5){
        cout << symbol[n];
        n++;}
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "72/3/");

    //
    n = 0;
    const char *defaults_4 = "1+3-4+2*7-3/4*7+1";
    Read(symbol, sign, defaults_4);
    testing::internal::CaptureStdout();
    while (n != 17){
        cout << symbol[n];
        n++;}
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "134-27*34/7*-1+++");

    //Скобки
    n = 0;
    const char *defaults_5 = "7-3+5*(6+1/(2*4-5)-8)+7";
    Read(symbol, sign, defaults_5);
    testing::internal::CaptureStdout();
    while (n != 19){
        cout << symbol[n];
        n++;}
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "73-56124*5-/8-+*7++");
}

TEST(out, output) {

    //Сложение
    const char *symbol_1 = "1259+++";
    testing::internal::CaptureStdout();
    cout << Write (symbol_1);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "17");

    //Вычитание
    const char * symbol_2 = "12-5-7-1-";
    testing::internal::CaptureStdout();
    cout << Write (symbol_2 );
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-14");

    //Умножение
    const char *symbol_3 = "62*5*9*";
    testing::internal::CaptureStdout();
    cout << Write (symbol_3);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "540");

    //Деление
    const char *symbol_4 = "72/3/";
    testing::internal::CaptureStdout();
    cout << Write (symbol_4);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "1");

    //
    const char *symbol_5 = "134-27*34/7*-1+++";
    testing::internal::CaptureStdout();
    cout << Write (symbol_5);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "15");

    //Скобки
    const char *symbol_6 = "75-56124*5-/8-+*7++";
    testing::internal::CaptureStdout();
    cout << Write (symbol_6);
    EXPECT_EQ(testing::internal::GetCapturedStdout(), "-1");

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
