#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include "Executor.hpp"

namespace adas
{
    // 重载Pose的==
    bool operator==(const Pose &lhs, const Pose &rhs)
    {
        return std::tie(lhs.x, lhs.y, lhs.heading) == std::tie(rhs.x, rhs.y, rhs.heading);
    }

    // 下面两个测试用例是为了测试Executor类的NewExecutor方法
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始姿态

        // when

        // then
        const Pose target = {0, 0, 'E'};
        ASSERT_EQ(executor->Query(), target);
    }

    TEST(ExecutorTest, should_return_default_pose_when_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor()); // 没有给定初始姿态

        // when

        // then
        const Pose target = {0, 0, 'N'};
        ASSERT_EQ(executor->Query(), target);
    }
}