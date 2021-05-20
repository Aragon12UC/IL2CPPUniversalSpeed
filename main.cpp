#include "il2cpp.hpp"
#include "main.hpp"

MethodInfo* setTime;

bool bSpeed;

const float speedMultiplier = 3.f;

void SetTimeScale(float f) {
	void* args[1] = { &f };

	Il2CppException* exc;
	il2cpp_runtime_invoke(setTime, nullptr, args, &exc);
}

void keyHandler() {
	for (;;) {
		/* 
		 * If you want to use Unity's native input handling for this then feel free, 
		 * but I don't see the point unless you're planning on using this on a game with a real anti-cheat.
		 * 
		 * UnityEngine.InputLegacyModule.dll.Input.GetKeyDown(KeyCode);
		 * 
		 * I've included an enum for KeyCode inside main.hpp
		 */ 
		if (GetAsyncKeyState(VK_F1) & 1) {
			bSpeed = !bSpeed;

			float timeScale = bSpeed ? speedMultiplier : 1.f;
			SetTimeScale(timeScale);
		}

		Sleep(1);
	}
}

void main() {
	IL2CPP::Init();

	Sleep(1500);

	Il2CppDomain* domain = il2cpp_domain_get();

	if (!domain) {
		cout << "domain = null\n" << endl;
		return;
	}

	il2cpp_thread_attach(domain);

	cout << "IL2CPP Initialised." << endl;

	Il2CppImage* unityCore = il2cpp_domain_assembly_open(domain, "UnityEngine.CoreModule")->image;
	Il2CppClass* timeClass = il2cpp_class_from_name(unityCore, "UnityEngine", "Time");
	setTime = (MethodInfo*)il2cpp_class_get_method_from_name(timeClass, "set_timeScale", 1);

	keyHandler();
}