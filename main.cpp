#include "il2cpp.hpp"
#include "main.hpp"
#include "Console.h"

MethodInfo* setTime;

void SetTimeScale(float f) {
	void* args[1] = { &f };

	Il2CppException* exc;
	il2cpp_runtime_invoke(setTime, nullptr, args, &exc);
}

void KeyHandlerLoop() {
	bool bExit = false, bSpeed = false;
	const float speedMultiplier = 3.f;
	
	do
	{
		/* 
		 * If you want to use Unity's native input handling for this then feel free, 
		 * but I don't see the point unless you're planning on using this on a game with a real anti-cheat.
		 * 
		 * UnityEngine.InputLegacyModule.dll.Input.GetKeyDown(KeyCode);
		 * 
		 * I've included an enum for KeyCode inside main.hpp
		 */ 
		
		if (GetAsyncKeyState(VK_F1) & 0x1) {
			bSpeed = !bSpeed;

			float timeScale = bSpeed ? speedMultiplier : 1.f; // Short hand if statements are cool ~ Omega172
			SetTimeScale(timeScale);
		}
		
		if (GetAsyncKeyState(VK_F3) & 0x1)
		{
			bSpeed = false;
			bExit = true;
		}

		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	} while (!bExit);
}

void Init()
{
	IL2CPP::Init();

	std::this_thread::sleep_for(std::chrono::milliseconds(1500));

	Il2CppDomain* domain = il2cpp_domain_get();

	if (!domain) {
		std::cout << "domain = null\n" << std::endl;
		return;
	}

	il2cpp_thread_attach(domain);

	std::cout << "IL2CPP Initialised." << std::endl;

	Il2CppImage* unityCore = il2cpp_domain_assembly_open(domain, "UnityEngine.CoreModule")->image;
	Il2CppClass* timeClass = il2cpp_class_from_name(unityCore, "UnityEngine", "Time");
	setTime = (MethodInfo*)il2cpp_class_get_method_from_name(timeClass, "set_timeScale", 1);
}

DWORD WINAPI MainThread(LPVOID lpReserved)
{
	Console con = Console::instance(true);
	con.setTitle("Universal IL2CPP Speed");
	std::cout << "Injected!" << std::endl;
	
	Init();

	KeyHandlerLoop();

	con.free();
	FreeLibraryAndExitThread((HMODULE)lpReserved, EXIT_SUCCESS); // Unload DLL ~ Omega172
	return 0;
}