#include "gtest/gtest.h"
#include "reader.h"
#include "writer.h"

TEST(constructor_tests, copy_file) {
    {
        reader::Reader reader;
        const std::string path = "C:/Users/Yana228/LABS_NSU/Task3/examples/district_four.wav";
        reader.load(path);

        const std::string path1 = "C:/Users/Yana228/LABS_NSU/Task3/examples/a.wav";
        writer::Writer writer(path1);

        while (true) {
            wav::SampleBuffer buffer;
            if (!reader.readSample(&buffer)) break;
            writer.writeSample(&buffer);
        }

        writer.writeHeader();
    }

    reader::Reader reader1;
    reader::Reader reader2;
    reader1.load("C:/Users/Yana228/LABS_NSU/Task3/examples/district_four.wav");
    reader2.load("C:/Users/Yana228/LABS_NSU/Task3/examples/a.wav");

    while (true)
    {
        wav::SampleBuffer buffer1;
        wav::SampleBuffer buffer2;
        if (!reader1.readSample(&buffer1) || !reader2.readSample(&buffer2)) break;
        EXPECT_EQ(buffer1, buffer2);
    }
}

int main(int argc, char **argv)
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}