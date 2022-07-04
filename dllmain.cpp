#include "main.hpp"

BOOL APIENTRY DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved)
{
    switch (fdwReason)
    {
    case DLL_PROCESS_ATTACH:
        DisableThreadLibraryCalls(hinstDLL);
        CreateThread(nullptr, NULL, MainThread, hinstDLL, NULL, nullptr); // Creating threads the right way ~ Omega172
        break;

    default:
        break;
    }

    return true;
}
