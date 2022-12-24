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
    inputFiles.push_back("district_four.wav");
    inputFiles.push_back("severe_tire_damage.wav");

    EXPECT_NO_THROW
    ({
        soundProcessor::SoundProcessor soundProcessor("config.txt",
                                                      "a.wav",
                                                      inputFiles);

        soundProcessor.start();
    });
}
int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}