#pragma once
#include "PoseHandler.hpp"
#include <functional>

namespace adas
{
    // // 定义一个虚基类ICommand，完成DoOperate动作
    // class ICommand
    // {
    // public:
    //     virtual void DoOperate(PoseHandler &poseHandler) const noexcept = 0;
    //     virtual ~ICommand() noexcept = default;
    // };
    // // 定义一个嵌套类MoveCommand，完成Move动作
    // class MoveCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         if (poseHandler.isFast())
    //             poseHandler.Move();
    //         poseHandler.Move();
    //     }
    // };
    // // 定义一个嵌套类TurnLeftCommand，完成TurnLeft动作
    // class TurnLeftCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         if (poseHandler.isFast())
    //             poseHandler.Move();
    //         poseHandler.TurnLeft();
    //     }
    // };
    // // 定义一个嵌套类TurnRightCommand，完成TurnRight动作
    // class TurnRightCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         if (poseHandler.isFast())
    //             poseHandler.Move();
    //         poseHandler.TurnRight();
    //     }
    // };
    // // 定义一个嵌套类FastCommand，完成Fast动作
    // class FastCommand final : public ICommand
    // {
    // public:
    //     void DoOperate(PoseHandler &poseHandler) const noexcept override
    //     {
    //         poseHandler.Fast();
    //     }
    // };

    class MoveCommand final
    {
    public:
        // 定义函数对象operate，接受参数PoseHandler，返回void
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.isFast())
                poseHandler.Move();
            poseHandler.Move();
        };
    };
    class TurnLeftCommand final
    {
    public:
        // 定义函数对象operate，接受参数PoseHandler，返回void
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.isFast())
                poseHandler.Move();
            poseHandler.TurnLeft();
        };
    };
    class TurnRightCommand final
    {
    public:
        // 定义函数对象operate，接受参数PoseHandler，返回void
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            if (poseHandler.isFast())
                poseHandler.Move();
            poseHandler.TurnRight();
        };
    };
    class FastCommand final
    {
    public:
        // 定义函数对象operate，接受参数PoseHandler，返回void
        const std::function<void(PoseHandler &PoseHandler)> operate = [](PoseHandler &poseHandler) noexcept
        {
            poseHandler.Fast();
        };
    };
    
}