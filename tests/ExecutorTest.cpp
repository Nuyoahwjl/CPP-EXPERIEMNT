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

    // 测试用例1
    TEST(ExecutorTest, should_return_init_pose_when_without_command)
    {
        // given给定测试条件
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'})); // 给定初始姿态

        // when

        // then
        const Pose target = {0, 0, 'E'};
        ASSERT_EQ(executor->Query(), target);
    }

    // 测试用例2
    TEST(ExecutorTest, should_return_default_pose_when_init_and_command)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor()); // 没有给定初始姿态

        // when

        // then
        const Pose target = {0, 0, 'N'};
        ASSERT_EQ(executor->Query(), target);
    }

    // 测试用例3, 测试Execute方法,朝向E,起点(0,0),执行M命令,期望结果为(1,0,E)
    TEST(ExecutorTest, should_return_x_plus_1_given_command_is_M_and_facing_is_E)
    {
        // given
        std::unique_ptr<Executor> executor(Executor::NewExecutor({0, 0, 'E'}));

        // when
        executor->Execute("M");

        // then
        const Pose target = {1, 0, 'E'};
        ASSERT_EQ(executor->Query(), target);
    }
}