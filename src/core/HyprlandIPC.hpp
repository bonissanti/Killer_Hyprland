//
// Created by bbro on 3/27/26.
//

#ifndef GTK_HYPRLANDIPC_HPP
#define GTK_HYPRLANDIPC_HPP
#include <string>
#include <sys/socket.h>
#include <sys/un.h>

class HyprlandIPC
{
    private:
    std::string path;

    public:
    HyprlandIPC();
    ~HyprlandIPC();
    void HandleMessage(const std::string& message);

    void SetPath(const std::string& path);

};

#endif //GTK_HYPRLANDIPC_HPP
