#include <gtest/gtest.h>
#include "../Frame.hpp"
#include "../BowlingGame.hpp"
#include "../Player.hpp"

//Frame Class Tests

TEST(FrameTest, Strike) {
    Frame f(10, 0);
    EXPECT_TRUE(f.isStrike());
    EXPECT_FALSE(f.isSpare());
    EXPECT_EQ(f.getTotal(), 10);
}

TEST(FrameTest, Spare) {
    Frame f(5, 5);
    EXPECT_TRUE(f.isSpare());
    EXPECT_FALSE(f.isStrike());
    EXPECT_EQ(f.getTotal(), 10);
}

TEST(FrameTest, OpenFrame) {
    Frame f(3, 4);
    EXPECT_FALSE(f.isStrike());
    EXPECT_FALSE(f.isSpare());
    EXPECT_EQ(f.getTotal(), 7);
}

TEST(FrameTest, ThirdRoll) {
    Frame f(10, 10, 10);
    EXPECT_EQ(f.getThird(), 10);
    EXPECT_EQ(f.getTotal(), 30);
}

//BowlingGame Class Tests

TEST(BowlingGameTest, AllStrikes) {
    BowlingGame game;
    for (int i = 0; i < 9; ++i) {
        game.addFrame(Frame(10));
    }
    game.addFrame(Frame(10, 10, 10));
    EXPECT_EQ(game.calculateScore(), 290);
}

TEST(BowlingGameTest, AllSpares) {
    BowlingGame game;
    for (int i = 0; i < 9; ++i) {
        game.addFrame(Frame(5, 5));
    }
    game.addFrame(Frame(5, 5, 5));
    EXPECT_EQ(game.calculateScore(), 150);
}

TEST(BowlingGameTest, AllOpenFrames) {
    BowlingGame game;
    for (int i = 0; i < 10; ++i) {
        game.addFrame(Frame(3, 4));
    }
    EXPECT_EQ(game.calculateScore(), 70);
}

TEST(BowlingGameTest, MixedFrames) {
    BowlingGame game;
    game.addFrame(Frame(1, 4));
    game.addFrame(Frame(4, 5));
    game.addFrame(Frame(6, 4));
    game.addFrame(Frame(5, 5));
    game.addFrame(Frame(10));
    game.addFrame(Frame(0, 1));
    game.addFrame(Frame(7, 3));
    game.addFrame(Frame(6, 4));
    game.addFrame(Frame(10));
    game.addFrame(Frame(2, 8, 6));

    EXPECT_EQ(game.calculateScore(), 133);
}

//Player Class Tests

TEST(PlayerTest, ScoreComputation) {
    Player p("Alice");
    p.playFrame(10);
    p.playFrame(4, 6);
    p.playFrame(5, 3);
    for (int i = 3; i < 9; ++i)
        p.playFrame(0, 0);
    p.playFrame(10, 10, 10);

    EXPECT_EQ(p.getName(), "Alice");
    EXPECT_EQ(p.getScore(), 73);
}

//Corner Cases

TEST(BowlingGameTest, InvalidFrameCount) {
    BowlingGame game;
    for (int i = 0; i < 10; ++i)
        game.addFrame(Frame(4, 5));

    EXPECT_THROW(game.addFrame(Frame(1, 1)), std::runtime_error);
}

TEST(FrameTest, CornerCase) {
    Frame f1(0, 0);
    EXPECT_EQ(f1.getTotal(), 0);
    EXPECT_FALSE(f1.isStrike());
    EXPECT_FALSE(f1.isSpare());

    Frame f2(6, 4);
    EXPECT_TRUE(f2.isSpare());
    EXPECT_FALSE(f2.isStrike());
}
