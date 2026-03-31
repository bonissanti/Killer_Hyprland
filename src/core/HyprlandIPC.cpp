#include "HyprlandIPC.hpp"

#include <cstring>
#include <print>
#include <unistd.h>

HyprlandIPC::HyprlandIPC()
{
    const char* runtime = std::getenv("XDG_RUNTIME_DIR");
    const char* signature = "HYPRLAND_INSTANCE_SIGNATURE";

    const std::string path = std::string(runtime) + "/hypr/" + std::string(signature) + "/.socket.sock";
    this->SetPath(path);
}

HyprlandIPC::~HyprlandIPC()
{
}

void HyprlandIPC::HandleMessage(const std::string& message)
{
    int socket = socket(AF_UNIX, SOCK_STREAM, 0);

    if (socket < 0)
    {
        std::print("ERROR: socket returned -1");
        return;
    }

    sockaddr_un addr = { .sun_family = AF_UNIX };
    std::strncpy(addr.sun_path, this->path.c_str(), sizeof(addr.sun_path) - 1);

    if (connect(socket, (struct sockaddr*)&addr, sizeof(addr)) == -1)
    {
        std::print("ERROR: connection failed to {}", this->path);
        close(socket);
        return;
    }

    std::string cmd = "monitors";
    send(socket, cmd.c_str(), cmd.length(), 0);

    char buffer[8192];
    ssize_t bytes_read = read(socket, buffer, sizeof(buffer) -1);

    if (bytes_read > 0)
    {
        buffer[bytes_read] = '\0';
        std::print("Received: {}", buffer);
    }
    close(socket);
}

void HyprlandIPC::SetPath(const std::string& path)
{
    this->path = path;
}
