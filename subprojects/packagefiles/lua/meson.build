project('lua', 'c', version: '5.2.4', license: 'MIT')

cc = meson.get_compiler('c')

system_deps = [
    cc.find_library('dl', required: false),
    cc.find_library('m', required: false)
]

if host_machine.system() == 'windows'
	readline_dep = []

    if get_option('default_library') != 'static'
        add_project_arguments('-DLUA_BUILD_AS_DLL', language: 'c')
    endif
else
	readline_dep = cc.find_library('readline')
endif

subdir('src')

lua_dep = declare_dependency(link_with: lua_lib, include_directories: src_inc)
