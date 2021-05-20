#pragma once

#define DO_API(r, n, p) typedef r (* n##_t) p; inline n##_t n
#define INIT_API(h, n) n = reinterpret_cast<n##_t>(GetProcAddress(h, #n))

#include <Windows.h>
#include <il2cpp-api-types.h>
#include <il2cpp-api-functions.h>
#include <il2cpp-class-internals.h>
#include <il2cpp-object-internals.h>

namespace IL2CPP {
	static void Init() {
		auto assembly = LoadLibraryA("GameAssembly.dll");

		if (!assembly) {
			return;
		}

		INIT_API(assembly, il2cpp_domain_get);
		INIT_API(assembly, il2cpp_domain_get_assemblies);
		INIT_API(assembly, il2cpp_domain_assembly_open);
		INIT_API(assembly, il2cpp_class_from_name);
		INIT_API(assembly, il2cpp_class_from_type);
		INIT_API(assembly, il2cpp_class_get_method_from_name);
		INIT_API(assembly, il2cpp_class_get_property_from_name);
		INIT_API(assembly, il2cpp_class_from_il2cpp_type);
		INIT_API(assembly, il2cpp_class_get_methods);
		INIT_API(assembly, il2cpp_class_get_field_from_name);
		INIT_API(assembly, il2cpp_field_get_value);
		INIT_API(assembly, il2cpp_field_get_value_object);
		INIT_API(assembly, il2cpp_type_get_object);
		INIT_API(assembly, il2cpp_runtime_invoke);
		INIT_API(assembly, il2cpp_runtime_invoke_convert_args);
		INIT_API(assembly, il2cpp_string_new);
		INIT_API(assembly, il2cpp_thread_attach);
		INIT_API(assembly, il2cpp_value_box);
		INIT_API(assembly, il2cpp_object_new);
		INIT_API(assembly, il2cpp_object_unbox);
		INIT_API(assembly, il2cpp_runtime_object_init);
	}
}
