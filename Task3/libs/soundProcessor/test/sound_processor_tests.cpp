#include "gtest/gtest.h"
#include "soundProcessor.h"

TEST(constructor_tests, soundProcessor)
{
    std::vector<std::string> inputFiles;
    try {
        soundProcessor::SoundProcessor("config.txt", "output.txt", inputFiles);
    }

    catch(const soundProcessor::NotFileInput& e)
    {
        EXPECT_STREQ(e.what(), "not input file");
    }
}

TEST(start_test, correct)
{
    std::vector<std::string> inputFiles;
    inputFiles.push_back("C:Users/Yana228/LABS_NSU/Task3/examples/district_four.wav");
    inputFiles.push_back("C:Users/Yana228/LABS_NSU/Task3/examples/severe_tire_damage.wav");

    EXPECT_NO_THROW
    ({
        soundProcessor::SoundProcessor soundProcessor("C:Users/Yana228/LABS_NSU/Task3/examples/config.txt",
                                                      "C:Users/Yana228/LABS_NSU/Task3/examples/a.wav",
                                                      inputFiles);

        soundProcessor.start();
    });
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}