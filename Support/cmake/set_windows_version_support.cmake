# set_windows_version(name version MAJOR MINOR PATCH)
function(set_windows_dll_version_support name version MAJOR MINOR PATCH)
	set(rc_file ${CMAKE_BINARY_DIR}/../../RC/${name}_Version_Info.rc)

	configure_file(
		${GRAY_LEAF_PROJECT_DIR}/Tools/Config/DLL_Version_Info.rc.in
		${rc_file}
		@ONLY
	)

	target_sources(${name} PRIVATE ${rc_file})
endfunction()