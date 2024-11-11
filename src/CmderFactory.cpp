#include "CmderFactory.hpp"

namespace adas
{
    std::list<std::function<void(PoseHandler & PoseHandler)>> CmderFactory::GetCmders(const std::string &command) const noexcept
    {
        std::list<std::function<void(PoseHandler & PoseHandler)>> cmders;
        for (const auto cmd : command)
        {
            auto iter = cmderMap.find(cmd);
            if (iter != cmderMap.end())
            {
                cmders.push_back(iter->second);
            }
        }
        return cmders;
    }
}