
#include "TestDnaSequence.h"
//*********** GOOGLE TEST************

TEST(DnaSequenceTests, ComperDna) {
    DnaSequence dnaSequence1("TTTTTT");
    DnaSequence dnaSequence2("AGCTAAAA");
    ASSERT_FALSE(dnaSequence1 == dnaSequence2);
    ASSERT_TRUE(dnaSequence1 != dnaSequence2);


    //failed test
//    ASSERT_FALSE(dnaSequence1!= dnaSequence2);
//    ASSERT_TRUE(dnaSequence1 == dnaSequence2);
//    EXPECT_FALSE(dnaSequence1!= dnaSequence2);
//    EXPECT_TRUE(dnaSequence1 == dnaSequence2);




}

TEST(DnaSequenceTests, DnaFailedEQ) {
    DnaSequence dnaSequence1("TTTTTT");
    DnaSequence dnaSequence2("AGCTAAAA");
    DnaSequence dnaSequence3(dnaSequence1);


//	ASSERT_NE :: val1 == val2
    ASSERT_NE(dnaSequence1.GetDnaSequence(), dnaSequence2.GetDnaSequence());
    ASSERT_NE(dnaSequence1.GetDnaSequence(), dnaSequence3.GetDnaSequence());

}

TEST(DnaSequenceTests, DnaException) {
//    ASSERT_ANY_THROW- statement throws an exception of any type
    ASSERT_ANY_THROW(DnaSequence dnaSequence4("PPPPP"));

}

TEST(DnaSequenceTests, DnaSequenceGetSlice) {

    DnaSequence dnaSequence("AGAAAAA");
    DnaSequence real_ans("AGA");
    DnaSequence my_ans(dnaSequence.getSlice(0, 3));

    ASSERT_TRUE(my_ans == real_ans);
    ASSERT_ANY_THROW(dnaSequence.getSlice(0, 100));

}

TEST(DnaSequenceTests, DnaSequenceFindSubsequence) {

    DnaSequence dnaSequence("AGACACACG");
    DnaSequence sub_dna("CACAC");
    size_t real_ans = 3;
    size_t my_ans = dnaSequence.FindSubsequence(sub_dna);

    ASSERT_TRUE(my_ans == real_ans);
//    ASSERT_ANY_THROW(dnaSequence.getSlice(0,100));

}


TEST(DnaSequenceTests, DnaSequenceGetPairing) {

    DnaSequence dnaSequence("GTGC");
    DnaSequence real_ans("GCAC");

    DnaSequence my_ans = dnaSequence.getPairing();

    ASSERT_TRUE(my_ans == real_ans);

}

TEST(DnaSequenceTests, DnaSequenceCountOccurrencesSubsequence) {

    DnaSequence dnaSequence("AGAGAGAGAGAG");
    DnaSequence sub_dna("AG");
    size_t real_ans = 6;
    size_t my_ans = dnaSequence.CountOccurrencesSubsequence(sub_dna);

    ASSERT_TRUE(my_ans == real_ans);

}

TEST(DnaSequenceTests, DnaSequenceWriteDnaSequenceToFile) {
    const char *file_name = "input.txt";
    WriteDnaSequenceToFile(file_name,"AAAAAATTTTCCCTTATCTGAGAGAGATGTGGTG");
    DnaSequence dna_file(ReadDnaSequenceFromFile(file_name));
    DnaSequence real_ans("AAAAAATTTTCCCTTATCTGAGAGAGATGTGGTG");
    ASSERT_TRUE(dna_file == real_ans);


}
TEST(DnaSequenceTests, DnaSequenceReadFile) {
    const char *file_name = "input.txt";
    DnaSequence dna_file(ReadDnaSequenceFromFile(file_name));
    DnaSequence real_ans("AAAAAATTTTCCCTTATCTGAGAGAGATGTGGTG");
    ASSERT_TRUE(dna_file == real_ans);


}
//
TEST(DnaSequenceTests, DnaSequenceFindAllSubsequence) {

    DnaSequence dnaSequence("AGAGAGAGAGAG");
    DnaSequence sub_dna("AG");
    size_t real_ans[] = {0, 2, 4, 6, 8, 10};
    size_t my_ans[6];
    dnaSequence.FindAllSubsequence(sub_dna, my_ans);
   for(int i=0;i<6;++i)
   {
       ASSERT_TRUE(my_ans[i] == real_ans[i]);

   }
//    std::cout < "my_ans " << (int)my_ans[0] << std::endl;


//    EXPECT_THAT(my_ans, ElementsAre(0,2,4,6,8,10));
//    ASSERT_THAT(my_ans, ContainerEq(real_ans));

}
//****** DISABLED Test *****

TEST(DnaSequenceTests, DISABLED_DnaExceptionFailed) {
    ASSERT_ANY_THROW(DnaSequence dnaSequence4("TTTTT"));

}

TEST(DnaSequenceTests, DISABLED_DnaFailedEQFailed) {
    DnaSequence dnaSequence1("TTTTTT");
    DnaSequence dnaSequence2("AGCTAAAA");
    DnaSequence dnaSequence3(dnaSequence1);


//ASSERT_EQ: val1 == val2
    ASSERT_EQ(dnaSequence1.GetDnaSequence(), dnaSequence2.GetDnaSequence());
    ASSERT_EQ(dnaSequence1.GetDnaSequence(), dnaSequence3.GetDnaSequence());


}


TEST(DnaSequenceTests, DISABLED_ComperDnaFailed) {
    DnaSequence dnaSequence1("TTTTTT");
    DnaSequence dnaSequence2("AGCTAAAA");


    //failed test
    ASSERT_FALSE(dnaSequence1 != dnaSequence2);
    ASSERT_TRUE(dnaSequence1 == dnaSequence2);
    EXPECT_FALSE(dnaSequence1 != dnaSequence2);
    EXPECT_TRUE(dnaSequence1 == dnaSequence2);
}

//*********** my TEST************
void print(std::string message) {
    std::cout << message << std::endl;
}

void test_dna() {

//    ******* test CTOR *****
    print("********************\n*    test CTOR     *\n*********************\n ");
    DnaSequence dnaSequence("AGCTAAAA");
    std::cout << dnaSequence;
    DnaSequence dnaSequence1("TTTTTT");
    std::cout << dnaSequence1;


    char c[] = "AAAA";

    DnaSequence dnaSequence2(c);
    std::cout << dnaSequence2;

//    ******* test copy CTOR *****
    print("**************************\n    test copy CTOR     \n**************************\n ");

    DnaSequence dnaSequence3(dnaSequence2);
    std::cout << dnaSequence3;

    dnaSequence3 = dnaSequence;
    std::cout << dnaSequence3;

    //********* test assignment operator *****
    print("**************************\n    test assignment operator     \n**************************\n ");
    dnaSequence3 = "TATATAA";
    std::cout << dnaSequence3;


    dnaSequence3 = dnaSequence1;
    std::cout << dnaSequence3;

//********* test operator == *****
    print("**************************\n    test operator ==     \n**************************\n ");

    std::cout << "dnaSequence3 == dnaSequence3   " << (dnaSequence3 == dnaSequence3) << std::endl;
    std::cout << "dnaSequence3 == dnaSequence2   " << (dnaSequence3 == dnaSequence2) << std::endl;

    //********* test operator != *****
    print("**************************\n    test operator !=      \n**************************\n ");

    std::cout << "\ndnaSequence3!= dnaSequence3   " << (dnaSequence3 != dnaSequence3) << std::endl;
    std::cout << "dnaSequence3 != dnaSequence2   " << (dnaSequence3 != dnaSequence2) << std::endl;


    //********* test operator [] *****
    print("**************************\n    test operator []      \n**************************\n ");
    dnaSequence3[1] = 'A';//set value
//    Nucleotide nucleotide = dnaSequence3[1];//get value
    std::cout << "dnaSequence3[1]   " << dnaSequence3[1] << std::endl;


    //********* test exception*****
    print("**************************\n    test exception -invalid nucleotide     \n**************************\n ");

    try {
        DnaSequence dnaSequence4("PPPPP");
    }
    catch (char const *e) {
        print("catch exception -invalid nucleotide");
    }

//   *******test  getSlice
    print("**************************\n  test  getSlice    \n**************************\n ");
    std::cout << "dnaSequence3 " << dnaSequence3;
    std::cout << "dnaSequence3.getSlice(1,3) " << dnaSequence3.getSlice(1, 3);


    //************* FindSubsequence************
    print("**************************\n  test  FindSubsequence    \n**************************\n ");


    DnaSequence dnaSequence9("AGACACACG");
    DnaSequence sub_dna("CACAC");
    size_t real_ans = 3;
    size_t my_ans = dnaSequence9.FindSubsequence(sub_dna);

    std::cout << "real_ans " << real_ans << "  my_ans" << my_ans << std::endl;

    //************* getPairing************
    print("**************************\n  test  getPairing    \n**************************\n ");
    DnaSequence dnaSequence11("GTGC");
    DnaSequence real_ans1("GCAC");

    DnaSequence my_ans1 = dnaSequence.getPairing();
    std::cout << "real_ans1  " << real_ans1 << ", my_ans1 " << my_ans1 << std::endl;
//************* getPairing************
//    print("**************************\n  test  ReadDnaSequenceFromFile    \n**************************\n ");
//    const char *file_name = "input.txt";
//    std::string str = ReadDnaSequenceFromFile(file_name);
//    DnaSequence dna_file(str);
//    std::cout << dna_file;
}
