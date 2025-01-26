#include "pch.h"
#include <string>
#include "./src/Calculator.h"
#include "./src/Calculator.cpp"
#include "./src/Bin.cpp"
#include "./src/Hex.cpp"
#include "./src/Oct.cpp"

//FloatToBin
TEST(FloatToBinTest, ConvertsPositiveIntegerToBinary) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToBin(5.0), "101");
    EXPECT_EQ(Calc.FloatToBin(8.0), "1000");
    EXPECT_EQ(Calc.FloatToBin(15.0), "1111");
}

TEST(FloatToBinTest, ConvertsZeroToBinary) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToBin(0.0), "0");
}

TEST(FloatToBinTest, HandlesEdgeCases) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToBin(1.0), "1");
    EXPECT_EQ(Calc.FloatToBin(2.0), "10");
    EXPECT_EQ(Calc.FloatToBin(3.0), "11");
}

//ExpBinToDec
TEST(ExpBinToDecTest, ConvertsBinaryExponentWithOperators) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpBinToDec("110+101"), "6+5");
    EXPECT_EQ(Calc.ExpBinToDec("111-10"), "7-2");
    EXPECT_EQ(Calc.ExpBinToDec("101*10"), "5*2");
}

TEST(ExpBinToDecTest, HandlesComplexExpressions) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpBinToDec("1001+1100-11"), "9+12-3");
    EXPECT_EQ(Calc.ExpBinToDec("1010*1010"), "10*10");
}

TEST(ExpBinToDecTest, ConvertsBinaryWithoutOperators) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpBinToDec("110"), "6");
    EXPECT_EQ(Calc.ExpBinToDec("101"), "5");
}

TEST(ExpBinToDecTest, HandlesEmptyInput) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpBinToDec(""), "");
}

TEST(ExpBinToDecTest, HandlesInvalidCharacters) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpBinToDec("101a"), "Invalid argument");
    EXPECT_EQ(Calc.ExpBinToDec("111@"), "Invalid argument");
}

//HexCharToDec
TEST(HexCharToDecTest, ConvertsHexCharactersToDecimal) {
    Calculator Calc;
    EXPECT_EQ(Calc.HexCharToDec('0'), 0);
    EXPECT_EQ(Calc.HexCharToDec('A'), 10);
    EXPECT_EQ(Calc.HexCharToDec('F'), 15);
    EXPECT_EQ(Calc.HexCharToDec('9'), 9);
}

TEST(HexCharToDecTest, HandlesLowercaseCharacters) {
    Calculator Calc;
    EXPECT_EQ(Calc.HexCharToDec('a'), 10);
    EXPECT_EQ(Calc.HexCharToDec('f'), 15);
    EXPECT_EQ(Calc.HexCharToDec('b'), 11);
}

TEST(HexCharToDecTest, ReturnsZeroForInvalidCharacters) {
    Calculator Calc;
    EXPECT_EQ(Calc.HexCharToDec('G'), 0);
    EXPECT_EQ(Calc.HexCharToDec('z'), 0);
    EXPECT_EQ(Calc.HexCharToDec('%'), 0);
}

//FloatToHex
TEST(FloatToHexTest, ConvertsPositiveIntegerToHex) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToHex(10.0), "a");
    EXPECT_EQ(Calc.FloatToHex(255.0), "ff");
    EXPECT_EQ(Calc.FloatToHex(16.0), "10");
}

TEST(FloatToHexTest, ConvertsZeroToHex) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToHex(0.0), "0");
}

TEST(FloatToHexTest, IgnoresFractionalPart) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToHex(15.99), "f");
    EXPECT_EQ(Calc.FloatToHex(255.99), "ff");
}

//ExpHexToDec
TEST(ExpHexToDecTest, ConvertsHexExpressionWithOperators) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpHexToDec("A+B"), "10+11");
    EXPECT_EQ(Calc.ExpHexToDec("F*2"), "15*2");
    EXPECT_EQ(Calc.ExpHexToDec("1C-10"), "28-16");
}

TEST(ExpHexToDecTest, HandlesComplexExpressions) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpHexToDec("A+B*C"), "10+11*12");
    EXPECT_EQ(Calc.ExpHexToDec("FF+10-1"), "255+16-1");
}

TEST(ExpHexToDecTest, ConvertsHexWithoutOperators) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpHexToDec("A"), "10");
    EXPECT_EQ(Calc.ExpHexToDec("FF"), "255");
}

TEST(ExpHexToDecTest, HandlesEmptyInput) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpHexToDec(""), "");
}

TEST(ExpHexToDecTest, HandlesInvalidCharacters) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpHexToDec("A+G"), "Invalid argument");
    EXPECT_EQ(Calc.ExpHexToDec("FF@"), "Invalid argument");
}

//FloatToOct
TEST(FloatToOctTest, ConvertsPositiveIntegerToOct) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToOct(10.0), "12");
    EXPECT_EQ(Calc.FloatToOct(255.0), "377");
    EXPECT_EQ(Calc.FloatToOct(8.0), "10");
}

TEST(FloatToOctTest, ConvertsZeroToOct) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToOct(0.0), "0");
}

TEST(FloatToOctTest, IgnoresFractionalPart) {
    Calculator Calc;
    EXPECT_EQ(Calc.FloatToOct(15.99), "17");
    EXPECT_EQ(Calc.FloatToOct(255.99), "377");
}

//ExpOctToDec
TEST(ExpOctToDecTest, ConvertsOctExpressionWithOperators) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpOctToDec("12+7"), "10+7");
    EXPECT_EQ(Calc.ExpOctToDec("17*2"), "15*2");
    EXPECT_EQ(Calc.ExpOctToDec("37-10"), "31-8");
}

TEST(ExpOctToDecTest, HandlesComplexExpressions) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpOctToDec("12+7*10"), "10+7*8");
    EXPECT_EQ(Calc.ExpOctToDec("377+10-1"), "255+8-1");
}

TEST(ExpOctToDecTest, ConvertsOctWithoutOperators) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpOctToDec("12"), "10");
    EXPECT_EQ(Calc.ExpOctToDec("377"), "255");
}

TEST(ExpOctToDecTest, HandlesEmptyInput) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpOctToDec(""), "");
}

TEST(ExpOctToDecTest, HandlesInvalidCharacters) {
    Calculator Calc;
    EXPECT_EQ(Calc.ExpOctToDec("12+G"), "Invalid argument");
    EXPECT_EQ(Calc.ExpOctToDec("377@"), "Invalid argument");
}

//ApplyOperation
TEST(ApplyOperationTest, HandlesBasicOperations) {
    Calculator Calc;
    EXPECT_EQ(Calc.applyOperation(5, 3, '+'), 8);
    EXPECT_EQ(Calc.applyOperation(5, 3, '-'), 2);
    EXPECT_EQ(Calc.applyOperation(5, 3, '*'), 15);
    EXPECT_EQ(Calc.applyOperation(6, 3, '/'), 2);
}

TEST(ApplyOperationTest, HandlesDivisionByZero) {
    Calculator Calc;
    EXPECT_EQ(Calc.applyOperation(5, 0, '/'), std::numeric_limits<float>::infinity());
}

//precedence
TEST(PrecedenceTest, CorrectPrecedenceValues) {
    Calculator Calc;
    EXPECT_EQ(Calc.precedence('+'), 1);
    EXPECT_EQ(Calc.precedence('-'), 1);
    EXPECT_EQ(Calc.precedence('*'), 2);
    EXPECT_EQ(Calc.precedence('/'), 2);
    EXPECT_EQ(Calc.precedence('^'), 0); 
}

//Compute
TEST(CalculatorTest, EvaluatesSimpleExpressions) {
    Calculator Calc;
    EXPECT_EQ(Calc.Compute("3+5"), 8);
    EXPECT_EQ(Calc.Compute("10-4"), 6);
    EXPECT_EQ(Calc.Compute("7*6"), 42);
    EXPECT_EQ(Calc.Compute("8/2"), 4);
}

TEST(CalculatorTest, HandlesOperatorPrecedence) {
    Calculator Calc;
    EXPECT_EQ(Calc.Compute("3+5*2"), 13);
    EXPECT_EQ(Calc.Compute("10-4/2"), 8);
    EXPECT_EQ(Calc.Compute("7*(6+2)"), 56);
}

TEST(CalculatorTest, HandlesParentheses) {
    Calculator Calc;
    EXPECT_EQ(Calc.Compute("(3+5)*2"), 16);
    EXPECT_EQ(Calc.Compute("10-(4/2)"), 8);
    EXPECT_EQ(Calc.Compute("(7*6)+(8/2)"), 46);
}

TEST(CalculatorTest, HandlesFloatingPointNumbers) {
    Calculator Calc;
    EXPECT_FLOAT_EQ(Calc.Compute("3.5+2.5"), 6.0);
    EXPECT_FLOAT_EQ(Calc.Compute("10.5-4.2"), 6.3);
    EXPECT_FLOAT_EQ(Calc.Compute("7.5*2"), 15.0);
    EXPECT_FLOAT_EQ(Calc.Compute("8.4/2"), 4.2);
}

TEST(CalculatorTest, HandlesComplexExpressions) {
    Calculator Calc;
    EXPECT_EQ(Calc.Compute("3+(5*2)-8"), 5);
    EXPECT_EQ(Calc.Compute("10-(4/2)+7*3"), 29);
    EXPECT_EQ(Calc.Compute("(7*(6+2))-5+8/2"), 55);
}

TEST(CalculatorTest, HandlesEmptyInput) {
    Calculator Calc;
    EXPECT_EQ(Calc.Compute(""), 0);
}