add_rules("mode.debug", "mode.release")
add_rules("plugin.compile_commands.autoupdate", {outputdir = ".vscode"})
add_requires("sfml", "tmxlite")

target("WordWizard")

    add_includedirs("include")
    set_kind("binary")

    add_files("src/*.cpp")
    add_packages("sfml", "tmxlite")

