#include "PoseHandler.hpp"

namespace adas
{
    PoseHandler::PoseHandler(const Pose &pose) noexcept : pose(pose) {}

    void PoseHandler::Move(void) noexcept
    {
        if (pose.heading == 'E') { pose.x += 1; }
        else if (pose.heading == 'W') { pose.x -= 1; }
        else if (pose.heading == 'N') { pose.y += 1; }
        else if (pose.heading == 'S') { pose.y -= 1; }
    }

    void PoseHandler::TurnLeft(void) noexcept
    {
        if (pose.heading == 'E') { pose.heading = 'N'; }
        else if (pose.heading == 'W') { pose.heading = 'S'; }
        else if (pose.heading == 'N') { pose.heading = 'W'; }
        else if (pose.heading == 'S') { pose.heading = 'E'; }
    }

    void PoseHandler::TurnRight(void) noexcept
    {
        if (pose.heading == 'E') { pose.heading = 'S'; }
        else if (pose.heading == 'W') { pose.heading = 'N'; }
        else if (pose.heading == 'N') { pose.heading = 'E'; }
        else if (pose.heading == 'S') { pose.heading = 'W'; }
    }

    void PoseHandler::Fast(void) noexcept
    {
        isfast = !isfast;
    }

    bool PoseHandler::isFast(void) const noexcept
    {
        return isfast;
    }

    Pose PoseHandler::Query(void) const noexcept
    {
        return pose;
    }
}