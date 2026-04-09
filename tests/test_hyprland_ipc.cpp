#include <criterion/criterion.h>
#include "../src/core/HyprlandIPC.hpp"
#include <cstdlib>
#include <string>

Test(hyprland_ipc, set_path) {
    HyprlandIPC ipc;
    std::string new_path = "/tmp/test_socket.sock";
    ipc.SetPath(new_path);
    cr_assert_eq(ipc.GetPath(), new_path, "Path should be updated to %s, but got %s", new_path.c_str(), ipc.GetPath().c_str());
}

Test(hyprland_ipc, initialization) {
    setenv("XDG_RUNTIME_DIR", "/tmp", 1);
    HyprlandIPC ipc;
    std::string expected = "/tmp/hypr/HYPRLAND_INSTANCE_SIGNATURE/.socket.sock";
    cr_assert_eq(ipc.GetPath(), expected, "Initial path should be %s, but got %s", expected.c_str(), ipc.GetPath().c_str());
}