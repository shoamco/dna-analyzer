
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

/**** dna-analyzer-design ****/
TEST(DnaSequenceTests, getCommand) {

}
void test_dna(){
    std::cout<<"in test getCommand !!!!!\n";
    CommandLineInterface commandLine;
    commandLine.GetCommand();
}

