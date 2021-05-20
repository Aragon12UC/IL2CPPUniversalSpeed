#include "main.hpp"

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call != DLL_PROCESS_ATTACH) {
        return false;
    }

    if (AllocConsole()) {
        FILE* pFile = nullptr;
        freopen_s(&pFile, "CONOUT$", "w", stdout);

        SetConsoleTitleW(L"Universal IL2CPP Speed");
    }

    std::thread mainThread(&main);
    mainThread.detach();

    DisableThreadLibraryCalls(hModule);

    cout << "Injected." << endl;

    return true;
}

