//
// Created by yhzhan on 3/4/2020.
//

#include "gtest/gtest.h"
#include "Number.h"
#include "Operator.h"
#include "common.h"

#define BASIC_FAST_COMP(val1, val2) \
    EXPECT_EQ(fast::operator*(Number(val1), Number(val2)), basic::operator*(Number(val1), Number(val2)));

TEST(TestNumber, Ctor) { // 12/2/2020 -> 737761
    EXPECT_EQ(Number().value(), std::vector<Digit>({}));
    EXPECT_TRUE(Number().isZero());
    EXPECT_EQ(Number().size(), 0);
    EXPECT_EQ(Number(std::vector<Digit>()).value(), std::vector<Digit>({}));
    EXPECT_TRUE(Number(std::vector<Digit>()).isZero());
    EXPECT_EQ(Number(std::vector<Digit>()).size(), 0);


    EXPECT_EQ(Number("0").value(), std::vector<Digit>({}));
    EXPECT_TRUE(Number("0").isZero());
    EXPECT_EQ(Number("0").size(), 0);
    EXPECT_EQ(Number("00").value(), std::vector<Digit>({}));
    EXPECT_TRUE(Number("00").isZero());
    EXPECT_EQ(Number("00").size(), 0);
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0)})).value(), std::vector<Digit>({}));
    EXPECT_TRUE(Number(std::vector<Digit>({Digit(0)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0)})).size(), 0);
    EXPECT_EQ(Number(std::vector<Digit>({Digit::Zero,Digit::Zero})).value(), std::vector<Digit>({}));
    EXPECT_TRUE(Number(std::vector<Digit>({Digit::Zero,Digit::Zero})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit::Zero,Digit::Zero})).size(), 0);

    EXPECT_EQ(Number("1").value(), std::vector<Digit>({Digit(1)}));
    EXPECT_TRUE(!Number("1").isZero());
    EXPECT_EQ(Number("1").size(), 1);
    EXPECT_EQ(Number("01").value(), std::vector<Digit>({Digit(1)}));
    EXPECT_TRUE(!Number("01").isZero());
    EXPECT_EQ(Number("01").size(), 1);

    EXPECT_EQ(Number(std::vector<Digit>({Digit(1)})).value(), std::vector<Digit>({Digit(1)}));
    EXPECT_TRUE(!Number(std::vector<Digit>({Digit(1)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(1)})).size(), 1);
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0),Digit(1)})).value(), std::vector<Digit>({Digit(1)}));
    EXPECT_TRUE(!Number(std::vector<Digit>({Digit(0),Digit(1)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0),Digit(1)})).size(), 1);

    EXPECT_EQ(Number(std::vector<Digit>({Digit(1),Digit(2)})).value(), std::vector<Digit>({Digit(1),Digit(2)}));
    EXPECT_TRUE(!Number(std::vector<Digit>({Digit(1),Digit(2)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(1),Digit(2)})).size(), 2);
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0),Digit(1),Digit(2)})).value(), std::vector<Digit>({Digit(1),Digit(2)}));
    EXPECT_TRUE(!Number(std::vector<Digit>({Digit(0),Digit(1),Digit(2)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0),Digit(1),Digit(2)})).size(), 2);

    EXPECT_EQ(Number("123").value(), std::vector<Digit>({Digit(1),Digit(2),Digit(3)}));
    EXPECT_TRUE(!Number("123").isZero());
    EXPECT_EQ(Number("123").size(), 3);
    EXPECT_EQ(Number("0123").value(), std::vector<Digit>({Digit(1),Digit(2),Digit(3)}));
    EXPECT_TRUE(!Number("0123").isZero());
    EXPECT_EQ(Number("0123").size(), 3);
    EXPECT_EQ(Number(std::vector<Digit>({Digit(1),Digit(2),Digit(3)})).value(), std::vector<Digit>({Digit(1),Digit(2),Digit(3)}));
    EXPECT_TRUE(!Number(std::vector<Digit>({Digit(1),Digit(2),Digit(3)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(1),Digit(2),Digit(3)})).size(), 3);
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0),Digit(1),Digit(2),Digit(3)})).value(), std::vector<Digit>({Digit(1),Digit(2),Digit(3)}));
    EXPECT_TRUE(!Number(std::vector<Digit>({Digit(0),Digit(1),Digit(2),Digit(3)})).isZero());
    EXPECT_EQ(Number(std::vector<Digit>({Digit(0),Digit(1),Digit(2),Digit(3)})).size(), 3);
}

TEST(TestNumber, Equal) { // 12/2/2020 -> 737761
    EXPECT_EQ(Number(), Number::Zero);
    EXPECT_EQ(Number("0"), Number::Zero);
    EXPECT_EQ(Number("01"), Number("1"));
    EXPECT_EQ(Number("001"), Number("1"));
    EXPECT_EQ(Number("123"), Number("123"));
    EXPECT_EQ(Number("123456"), Number("123456"));
}

TEST(TestNumber, Add){ // 12/2/2020 -> 737761)
    EXPECT_EQ(Number("0")+Number("0"), Number("0"));
    EXPECT_EQ(Number("0")+Number("1"), Number("1"));
    EXPECT_EQ(Number("1")+Number("2"), Number("3"));
    EXPECT_EQ(Number("1")+Number("23"), Number("24"));
    EXPECT_EQ(Number("7")+Number("23"), Number("30"));
    EXPECT_EQ(Number("7")+Number("24"), Number("31"));
    EXPECT_EQ(Number("12")+Number("23"), Number("35"));
    EXPECT_EQ(Number("12")+Number("234"), Number("246"));
    EXPECT_EQ(Number("99")+Number("299"), Number("398"));
    EXPECT_EQ(Number("123")+Number("456"), Number("579"));
    EXPECT_EQ(Number("123")+Number("4567"), Number("4690"));
    EXPECT_EQ(Number("897")+Number("456"), Number("1353"));
    EXPECT_EQ(Number("897")+Number("4567"), Number("5464"));
}

TEST(TestVector, Basic) { // 12/2/2020 -> 737761)
    std::vector<int> vec{1,2,3};
    EXPECT_EQ(*(vec.end()-1), 3);
    EXPECT_EQ(*(vec.end()-2), 2);
    EXPECT_EQ(*(vec.end()-3), 1);
}
TEST(TestNumberDigit, Add){ // 12/2/2020 -> 737761)
    EXPECT_EQ(Number("0")+Digit("0"), Number("0"));
    EXPECT_EQ(Number("0")+Digit("1"), Number("1"));
    EXPECT_EQ(Number("0")+Digit("2"), Number("2"));
    EXPECT_EQ(Number("0")+Digit("3"), Number("3"));
    EXPECT_EQ(Number("0")+Digit("4"), Number("4"));
    EXPECT_EQ(Number("0")+Digit("5"), Number("5"));
    EXPECT_EQ(Number("0")+Digit("6"), Number("6"));
    EXPECT_EQ(Number("0")+Digit("7"), Number("7"));
    EXPECT_EQ(Number("0")+Digit("8"), Number("8"));
    EXPECT_EQ(Number("0")+Digit("9"), Number("9"));
    EXPECT_EQ(Number("1")+Digit("0"), Number("1"));
    EXPECT_EQ(Number("1")+Digit("1"), Number("2"));
    EXPECT_EQ(Number("1")+Digit("2"), Number("3"));
    EXPECT_EQ(Number("1")+Digit("3"), Number("4"));
    EXPECT_EQ(Number("1")+Digit("4"), Number("5"));
    EXPECT_EQ(Number("1")+Digit("5"), Number("6"));
    EXPECT_EQ(Number("1")+Digit("6"), Number("7"));
    EXPECT_EQ(Number("1")+Digit("7"), Number("8"));
    EXPECT_EQ(Number("1")+Digit("8"), Number("9"));
    EXPECT_EQ(Number("1")+Digit("9"), Number("10"));
}

TEST(TestDigit, Add){ // 12/2/2020 -> 737761)
    EXPECT_EQ(Digit("0")+Digit("0"), Number("0"));
    EXPECT_EQ(Digit("0")+Digit("1"), Number("1"));
    EXPECT_EQ(Digit("1")+Digit("2"), Number("3"));
    EXPECT_EQ(Digit("2")+Digit("3"), Number("5"));
    EXPECT_EQ(Digit("5")+Digit("5"), Number("10"));
    EXPECT_EQ(Digit("5")+Digit("6"), Number("11"));
}

TEST(TestDigit, Quotient){ // 12/2/2020 -> 737761)
    EXPECT_EQ(Digit("0")*Digit("0"), Number("0"));
    EXPECT_EQ(Digit("0")*Digit("1"), Number("0"));
    EXPECT_EQ(Digit("1")*Digit("2"), Number("2"));
    EXPECT_EQ(Digit("2")*Digit("3"), Number("6"));
    EXPECT_EQ(Digit("5")*Digit("5"), Number("25"));
    EXPECT_EQ(Digit("5")*Digit("6"), Number("30"));
    EXPECT_EQ(Digit("9")*Digit("8"), Number("72"));
    EXPECT_EQ(Digit("9")*Digit("9"), Number("81"));
}

TEST(TestNumber, Quotient) { // 12/2/2020 -> 737761
    using namespace basic;
    EXPECT_EQ(Number("0") * Number("0"), Number("0"));
    EXPECT_EQ(Number("0") * Number("1"), Number("0"));
    EXPECT_EQ(Number("1") * Number("1"), Number("1"));
    EXPECT_EQ(Number("1") * Number("2"), Number("2"));
    EXPECT_EQ(Number("2") * Number("3"), Number("6"));
    EXPECT_EQ(Number("3") * Number("5"), Number("15"));
    EXPECT_EQ(Number("30") * Number("15"), Number("450"));
    EXPECT_EQ(Number("15") * Number("15"), Number("225"));
    EXPECT_EQ(Number("15") * Number("28"), Number("420"));
    EXPECT_EQ(Number("15") * Number("73"), Number("1095"));
    EXPECT_EQ(Number("1234") * Number("5678"), Number("7006652"));
    EXPECT_EQ(Number("8") * Number("89"), Number("712"));
    EXPECT_EQ(Number("87") * Number("789"), Number("68643"));
    EXPECT_EQ(Number("87654") * Number("56789"), Number("4977783006"));
    EXPECT_EQ(Number("876054") * Number("56789"), Number("49750230606"));
    EXPECT_EQ(Number("876012354") * Number("56785679"), Number("49744956334278366"));
    EXPECT_EQ(Number("87601235466001273658") * Number("56785679036256846534"),
            Number("4974495640351908290013949935666642801372"));

    EXPECT_EQ(Number("3141592653589793238462643383279502884197169399375105820974944592")
              * Number("2718281828459045235360287471352662497757247093699959574966967627"),
              Number("8539734222673567065463550869546574495034888535765114961879601127067743044893204848617875072216249073013374895871952806582723184"));
}

TEST(TestNumber, SpecialCase) { // 12/2/2020 -> 737761
    EXPECT_EQ(basic::operator*(Number("197239123192367891823"), Number("2374294723974239472980820342070")),
              Number("468303809556944138860115343667517783527119615893610"));
}

TEST(TestNumber, CompareTwoQuotient) { // 12/2/2020 -> 737761
    BASIC_FAST_COMP("1", "2");
    BASIC_FAST_COMP("7891823", "80820342071");
    BASIC_FAST_COMP("197239123192367891823", "2374294723974239472980820342070");
    BASIC_FAST_COMP("9999999999999923843276197239123192367891823", "89289184932843289732782374294723974239472980820342070");
}
